#include "ak.h"

int main() 
{
    Node *root = new Node;

    MakeTreeFromFile(root);

    //char tmp_str[] = "him";

    //Chararcteristic(root, tmp_str);



    MenuToPlay(root);
    
    FILE *skobkifile = fopen("skobkiinput.txt", "w");
    
    PrintSkobki(root, skobkifile);
    fclose(skobkifile);
    PrintDot(root);
    
    return 0;
}