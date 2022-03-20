#include "ak.h"

int main() 
{
    HeadTree MyHeadTree(2);

    MyHeadTree.root = new Node;

    MakeTreeFromFile(MyHeadTree.root);

    FILE *skobkifile = fopen("skobkiinput.txt", "w");
    
    MyHeadTree.MakeAkinator();
    
    PrintDot(MyHeadTree.root);
    
    PrintSkobki(MyHeadTree.root, skobkifile);

    fclose(skobkifile);
    
    return 0;
}