#include "ak.h"


int ReadBuf(char *buf)
{
    char c;
    fgets(buf, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }
    return 0;
}

int MenuToPlay(Node *root)
{
    while (1) {
        printf("------------\nTo play write-1\nto show characteristics write-2\nto exit write-0\n------------\n");

        char menu_str[30];

        ReadBuf(menu_str);

        if (strcmp(menu_str, "1") == 0) {
            MakeAkinator(root);
        }
        else if (strcmp(menu_str, "2") == 0) {
            printf("Write the word to know more about it\n");

            char str_to_find[30];
            ReadBuf(str_to_find);

            Chararcteristic(root, str_to_find);
        }
        else if (strcmp(menu_str, "0") == 0) {
            printf("game stopped\n");
            break;
        }
        else {
            printf("error in menu\n");
            return -1;
        }

    }

    return 0;
}


int Chararcteristic(Node *root, char *def_str)
{
    char *tmp_str = new char[20];
    strcpy(tmp_str, def_str);

    
    if (FindElem(root->left, tmp_str) == 0) {
        printf("%s\n", root->data);
    }
    else if (FindElem(root->right, tmp_str) == 0) {
        printf("not %s\n", root->data);
    }
    return 0;
}

int FindElem(Node *root, char *value) 
{
    if (root == NULL) {
        return -1;
    }
    else if (strcmp(value, root->data) == 0) {
        return 0;
    }
    
    if (FindElem(root->left, value) == 0) {
        printf("%s, ", root->data);
        return 0;
    }
    else if (FindElem(root->right, value) == 0) {
        printf("not %s, ", root->data);
        return 0;
    }
    else {
        return -1;
    }

    return -1;
}

int MakeAkinator(Node *root)
{


    assert(root != NULL);
    Node *node = root;
        

    while (node->left != NULL && node->right != NULL) {
<<<<<<< HEAD
        
        char *tmp_ans = new char [30];
        printf("is it %s?\n", node->data);
        
        ReadBuf(tmp_ans);
=======
        
        char *tmp_ans = new char [4];
        printf("is it %s?\n", node->data);
        
        scanf("%s", tmp_ans);
>>>>>>> a52b998e4b4f91b6240539daae2388050ce2bf12

        if (strcmp(tmp_ans, "yes") == 0) {
            
            node = node->left;
        }
        else if (strcmp(tmp_ans, "no") == 0) {
            
            node = node->right;
        }
        else {
            printf("*write yes/no\n");
        }
        delete[] tmp_ans;
    }

    if (node->left == NULL && node->right == NULL) {
    
<<<<<<< HEAD
        char *tmp_ans = new char [20];
        printf("is it %s?\n", node->data);

        ReadBuf(tmp_ans);
=======
        char *tmp_ans = new char [4];
        printf("is it %s?\n", node->data);

        scanf("%s", tmp_ans);
>>>>>>> a52b998e4b4f91b6240539daae2388050ce2bf12
        
        if (strcmp(tmp_ans, "yes") == 0) {
            printf("GOOD GAME!!!\n");
            delete[] tmp_ans;
<<<<<<< HEAD
=======
            //delete[] play;
>>>>>>> a52b998e4b4f91b6240539daae2388050ce2bf12
            return 0;    
        }
        else if (strcmp(tmp_ans, "no") == 0) {
            Insert(node);
        }
        else {
            printf("*write yes/no\n");
        }
        delete[] tmp_ans;
    }
    else {
        printf("error\n");
    }
        
      
    return 0;
}

int Insert(Node *tmp_root)
{
    printf("Who is it?\n");

    tmp_root->left = new Node;
    (tmp_root->left)->data = new char [20];
    tmp_root->right = new Node;
    (tmp_root->right)->data = new char [20];

    ReadBuf((tmp_root->left)->data);

    strcpy((tmp_root->right)->data, tmp_root->data);

    printf("What's the difference from another?\n");
    
    ReadBuf(tmp_root->data);

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

        MakeOneScan(node->right, skobki);
        
    }
    else if (tmp_symb == '}') {
        return 0;
    }

    return 0;
}
