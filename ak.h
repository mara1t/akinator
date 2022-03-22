#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define $$$ printf("on line=%d\n", __LINE__);

typedef char* elem_t;

enum {
    STRMODE = 0,
    INTMODE = 1
};

const int TreeMode = INTMODE;

struct Node {
    char *data;
    Node *right;
    Node *left;
};

class HeadTree {
    int size;

    public:
        Node *Find(elem_t);
        //int MyCmp(elem_t value1, elem_t value2);
        
        
        
        HeadTree(int size_);
        ~HeadTree();
};
int MakeAkinator(Node *);
int Insert(Node *);
int PrintSkobki(Node*, FILE*);
int PrintDot(Node*);
int PrintStruct(FILE*, Node*, int*);
int MakeTreeFromFile(Node*);
int MakeOneScan(Node*, FILE*);