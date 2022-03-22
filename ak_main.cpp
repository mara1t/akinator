#include "ak.h"

int main() 
{
    //HeadTree MyHeadTree(2);

    Node *root = new Node;

    MakeTreeFromFile(root);

    MakeAkinator(root);
    
    FILE *skobkifile = fopen("skobkiinput.txt", "w");
    
    PrintSkobki(root, skobkifile);
    fclose(skobkifile);
    PrintDot(root);
    
    return 0;
}