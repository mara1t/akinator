#include "ak.h"


HeadTree::HeadTree(int size_)
{
    size = 0;
}

HeadTree::~HeadTree()
{
    size = 0;
}



/*
/
/
/
*/
int MakeAkinator(Node *root)
{

    while (1) {
        char *play = new char[4];
        int next_step = 0;

        printf("do you want to play?\n");

        while (next_step != 1) {
            scanf("%s", play);
            if (strcmp(play, "no") == 0) {
                printf("game stopped\n");
                return 0;
            }
            else if (strcmp(play, "yes") != 0) {
                printf("you should write yes/no\n");
            }
            else {
                next_step = 1;
            }
        }

        assert(root != NULL);
        Node *node = root;
        

        while (node->left != NULL && node->right != NULL) {
            
            char *tmp_ans = new char [4];
            printf("is it %s?\n", node->data);
            
            scanf("%s", tmp_ans);

            if (strcmp(tmp_ans, "yes") == 0) {
                
                node = node->left;
            }
            else if (strcmp(tmp_ans, "no") == 0) {
                
                node = node->right;
            }
            else {
                printf("here err\n");
            }
            delete[] tmp_ans;
        }

        if (node->left == NULL && node->right == NULL) {
        
            char *tmp_ans = new char [4];
            printf("is it %s?\n", node->data);

            scanf("%s", tmp_ans);
            
            if (strcmp(tmp_ans, "yes") == 0) {
                printf("GOOD GAME!!!\n");
                delete[] tmp_ans;
                delete[] play;
                return 0;    
            }
            else if (strcmp(tmp_ans, "no") == 0) {
                Insert(node);
            }
            delete[] tmp_ans;
        }
        else {
            printf("error\n");
        }
        
        delete[] play;
    }

    

    return 0;
}

int Insert(Node *tmp_root)
{
    //char *tmp_ask = new char [20];
    //char *new_elem = new char [20];

    printf("Who is it?\n");

    tmp_root->left = new Node;
    (tmp_root->left)->data = new char [20];
    tmp_root->right = new Node;
    (tmp_root->right)->data = new char [20];
    scanf("%s", (tmp_root->left)->data);

    strcpy((tmp_root->right)->data, tmp_root->data);

    printf("What's the difference from another?\n");
    scanf("%s", tmp_root->data);

    tmp_root->left->left = NULL;
    tmp_root->left->right = NULL;
    
    tmp_root->right->left = NULL;
    tmp_root->right->right = NULL;

    return 0;
}



int PrintSkobki(Node *node, FILE *skobki) 
{
    assert(node != NULL);

    if (node->left == NULL && node->right == NULL) {
        fprintf(skobki, "{ %s }\n", node->data);    
    }
    else if (node->left != NULL && node->right != NULL) {
        fprintf(skobki, "{ %s\n", node->data);
        PrintSkobki(node->left, skobki);
        PrintSkobki(node->right, skobki);
        fprintf(skobki, "}\n");
    }
    else if (node->left != NULL) {
        
        printf("left:node->data=%s\nnode->dataleft=%s\n", node->data, node->left->data);
    }
    else if (node->right != NULL) {
        printf("right:node->data=%s\nnode->dataright=%s\n", node->data, node->right->data);
    }
    else {
        fclose(skobki);
        printf("error in tree in print\n");
    }
    
    
    return 0;
}

int PrintDot(Node *root)
{
    assert(root != NULL);
    FILE *graph = fopen("graph.txt", "w");

    int global_counter = 0;

    fprintf(graph, "digraph G{\n");

    PrintStruct(graph, root, &global_counter);
    
    fprintf(graph, "}");

    fclose(graph);
    return 0;
}

int PrintStruct(FILE *graph, Node *node, int *global_counter)
{
    
    if (node == NULL)
        return 0;
    
    int tmp_counter = *global_counter;

    
    fprintf(graph, "\tstruct%d [shape=record,label=\"{<f0>%s | {<f1> right | <f2> left} }\" ];\n", 
    *global_counter, node->data);

    if (node->left == NULL && node->right == NULL) 
        return 0;
    
    fprintf(graph, "\tstruct%d->struct%d[label=\"yes\"];\n", tmp_counter, tmp_counter + 1);

    (*global_counter)++;
    
    PrintStruct(graph, node->right, global_counter);
    
    (*global_counter)++;

    fprintf(graph, "\tstruct%d->struct%d[label=\"no\"];\n", tmp_counter, *global_counter );
    
    PrintStruct(graph, node->left, global_counter);
    
    return 0;
}

int MakeTreeFromFile(Node* root) 
{
    FILE *skobki = fopen("skobkiinput.txt", "r");

    char tmp_symb = 'A';

    while (tmp_symb != '{') 
        fscanf(skobki, "%c", &tmp_symb);

    MakeOneScan(root, skobki);

    fclose(skobki);
    return 0;
}

int MakeOneScan(Node* node, FILE *skobki)
{
    char *tmp_str = new char [20];
    char tmp_symb = 'A';

    node->data = new char [20];

    fscanf(skobki, "%s", node->data);

    while (tmp_symb != '{' && tmp_symb != '}') {
        fscanf(skobki, "%c", &tmp_symb);
    }

    if (tmp_symb == '{') {
        node->left = new Node;
        MakeOneScan(node->left, skobki);

        tmp_symb = 'A';

        while (tmp_symb != '{')
            fscanf(skobki, "%c", &tmp_symb);

        node->right = new Node;
        
        tmp_symb = 'A';
        
        //while (tmp_symb != '{')
        //    fscanf(skobki, "%c", &tmp_symb);

        MakeOneScan(node->right, skobki);
        
    }
    else if (tmp_symb == '}') {
        return 0;
    }

    return 0;
}
