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
Node *HeadTree::Find(elem_t cur_val)
{
    Node *node = root;

    while (node != NULL) {
        if (MyCmp(node->data, cur_val) == 0) 
            return node;
        
        if (MyCmp(node->data, cur_val) == -1) 
            node = node->right;
        
        if (MyCmp(node->data, cur_val) == 1) 
            node = node->left;
    }

    return NULL;
}

int HeadTree::MyCmp(elem_t value1, elem_t value2)
{
    if (TreeMode == INTMODE) {
        if (value1 > value2)    return 1;
        if (value1 < value2)    return -1;
        if (value1 == value2)   return 0;
    }
    else if (TreeMode == STRMODE) {
        
    }
    return 0;
}
*/

/*
/
/
/
*/
int HeadTree::MakeAkinator()
{

    while (1) {
        char *tmp_ans = new char [4];
        char *play = new char[4];
        
        printf("do you want to play?\n");
        scanf("%s", play);

        if (strcmp(play, "no") == 0) {
            printf("game stopped\n");
            return 0;
        }
        else if (strcmp(play, "yes") != 0) {
            printf("error in playing\n");
            return 0;
        }

        assert(root != NULL);
        Node *node = root;
        

        while (node->left != NULL && node->right != NULL) {
            
            printf("is it %s?\n", node->data);
            
            scanf("%s", tmp_ans);

            if (strcmp(tmp_ans, "yes") == 0) {
                
                node = node->left;
            }
            else if (strcmp(tmp_ans, "no") == 0) {
                
                node = node->right;
            }
        }

        if (node->left == NULL && node->right == NULL) {
        
            printf("is it %s?\n", node->data);

            scanf("%s", tmp_ans);
            
            if (strcmp(tmp_ans, "yes") == 0) {
                printf("GOOD GAME!!!\n");
                return 0;    
            }
            else if (strcmp(tmp_ans, "no") == 0) {
                Insert(node);
            }
        }
        else {
            printf("error\n");
        }
        delete[] tmp_ans;
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
    tmp_root->left->data = new char [20];
    tmp_root->right = new Node;
    tmp_root->right->data = new char [20];
    scanf("%s", tmp_root->left->data);

    strcpy(tmp_root->right->data, tmp_root->data);

    printf("What's the difference?\n");
    scanf("%s", tmp_root->data);

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
    else {
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

        while (tmp_symb != '{' && tmp_symb != '}')
            fscanf(skobki, "%c", &tmp_symb);

        node->right = new Node;
        MakeOneScan(node->right, skobki);
    }
    else if (tmp_symb == '}') {
        return 0;
    }

    return 0;
}