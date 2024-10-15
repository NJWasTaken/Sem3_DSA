#include <stdio.h>
#include "tbst.h"

int main(){
    NODE* root=NULL;
    root=CreateTree(root);
    PrintTree(root);
    root = Manipulate(root);
    return 0;
}