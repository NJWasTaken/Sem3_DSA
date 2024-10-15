#include "tbst.h"

NODE *CreateNode(int val){
    NODE *node;
    node = (NODE*)malloc(sizeof(NODE));
    if (node==NULL){
        printf("Memory not available to allocate.\n");
        exit(0);
    }
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    node->left_t=true;
    node->right_t=true;
    return node;
}

bool SearchTree(NODE *root, int val, NODE **par){
    // Searching for a Node with given value 
    NODE *node = root; 
    bool found = false;
    while (node != NULL && !found) 
    { 
        // If key already exists, return 
        if (val == (node->data)) 
        { 
            found=true; 
        } 
  
        *par = node; // Update parent pointer 

        // Moving on left subtree. 
        if (val < node->data) 
        { 
            if (node->left_t == false) 
                node = node->left; 
            else
                break; 
        } 
  
        // Moving on right subtree. 
        else
        { 
            if (node->right_t == false) 
                node = node->right; 
            else
                break; 
        } 
    }
    return found;  
}

NODE* insert(int val, NODE* root){

    // Searching for a Node with given value 
    NODE *node = root; 
    NODE *par = NULL; // Parent of key to be inserted 
    if (SearchTree(root,val,&par)){
        printf("Not inserted.\n");
        return root;
    }
  
    // Create a new node 
    NODE *temp = CreateNode(val);
    temp-> left_t = true; 
    temp-> right_t = true; 
  
    if (par == NULL) 
    { 
        root = temp; 
        temp->left = NULL; 
        temp->right = NULL; 
    } 
    else if (val < (par->data)) 
    { 
        temp->left = par->left; 
        temp->right = par; 
        par->left_t = false; 
        par->left = temp; 
    } 
    else
    { 
        temp->left = par; 
        temp->right = par->right; 
        par->right_t = false; 
        par->right = temp; 
    } 
  
    return root; 
}

NODE* CreateTree(NODE* root){
    int n;
    printf("Enter number of nodes to insert: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        root = insert(a,root);
    }
    
    return root;
}

void PrintTree(NODE* root){
    if (root == NULL) 
        printf("Tree is empty.\n"); 
  
    // Reach leftmost node 
    NODE *ptr = root; 
    while (ptr->left_t == false) 
        ptr = ptr->left; 
  
    // One by one print successors 
    while (ptr!=NULL) 
    { 
        printf("%d ",ptr->data); 
        if (ptr->right_t==true) ptr=ptr->right;
        else{
            ptr=ptr->right;
            while(ptr->left_t==false)ptr=ptr->left;
        }
    }  
}

NODE* Delete(NODE* root){
    int n;
    printf("Enter value to be deleted from the tree: ");
    scanf("%d",&n);

    NODE* node = NULL;
    SearchTree(root,n,&node);
    
    bool l = node->left_t;
    bool r = node->right_t;
    if(l)printf("left\n%d\n",node->left->data);
    if(r)printf("right\n%d\n",node->right->data);
    // //CASE A:
    // if (!l&&!r){
        
    // }
    // //CASE
    // elif(!l&&r){

    // }

}


NODE* Manipulate(NODE* root){
    while(1){
        char c;
        printf("\nInsert node: I | Delete node: D | Search: S | Print: P | Exit: Q - ");
        scanf(" %c",&c);
        c = toupper(c);
        if (c=='Q'){break;}
        else{
            switch(c)
            {
            case 'D':
                Delete(root);
                break;
            
            case 'P':
                PrintTree(root);
                break;

            case 'S':
                int val;
                printf("Enter value to be searched: ");
                scanf("%d",&val);
                NODE *par = NULL;
                if (SearchTree(root,val,&par)){
                    printf("%d is present in the tree.\n",val);
                }
                else{
                    printf("%d is absent in the tree.\n",val);
                }
                break;

            case 'I':
                root = CreateTree(root);
                break;

            default:
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}


