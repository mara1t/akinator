#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define $$$ printf("on line=%d\n", __LINE__);

typedef char* elem_t;

enum {
    STRMODE,
    INTMODE
};

const int TreeMode = INTMODE;

struct Node {
    char *data;
    Node *right;
    Node *left;
};

int MakeAkinator(Node *);
int Insert(Node *);
int PrintSkobki(Node*, FILE*);
int PrintDot(Node*);
int PrintStruct(FILE*, Node*, int*);
int MakeTreeFromFile(Node*);
int MakeOneScan(Node*, FILE*);
int Chararcteristic(Node *root, char *def_str);
int FindElem(Node *root, char *value);
int MenuToPlay(Node *root);