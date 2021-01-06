
 /*
 @Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT, Bangalore
 Purpose: This program does the following:
 a) Creates Binary Tree through 'Double Recursion' call to 'createTree' function
 b) Displays the tree in three types of traversal
 --- Inorder, Preorder and Postorder methods
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct myBintree
{
    int marks;
    struct myBintree *left;
    struct myBintree *right;
} myBintree;

myBintree *root = NULL;

myBintree *createBinTree()
{
    myBintree *ptr;
    int m;
    printf("Enter data(-1 for no data):");
    scanf("%d",&m);
    
    if(m==-1)
        return NULL;
    
    ptr=(myBintree*)malloc(sizeof(myBintree));
    ptr->marks=m;
    
    printf("Enter left child of %d:\n",m);
    ptr->left=createBinTree();
    
    printf("Enter right child of %d:\n",m);
    ptr->right=createBinTree();
    
    return ptr;
}

void BinTreePreorder(myBintree *temp)//address of root node is passed in temp
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->marks);        //visit the root
        BinTreePreorder(temp->left);        //preorder traversal on left subtree
        BinTreePreorder(temp->right);        //preorder traversal om right subtree
    }
}//end preorder

void BinTreeInorder(myBintree *temp)
{
    
    if(temp!=NULL)
    {
        BinTreeInorder(temp->left);
        printf("%d\t",temp->marks);
        BinTreeInorder(temp->right);
        
    }
    
}//end inorder

void BinTreePostorder(myBintree *temp)
{
    
    if(temp!=NULL)
    {
        BinTreePostorder(temp->left);
        BinTreePostorder(temp->right);
        printf("%d\t",temp->marks);
        
    }
    
}//end postorder

int main()
{
    
    root=createBinTree();
    printf("\nThe tree is:\n");
    
    printf("\nThe preorder traversal of tree is:\n");
    BinTreePreorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    BinTreePostorder(root);
    printf("\nThe inorder traversal of tree is:\n");
    BinTreeInorder(root);
    printf("\n");
    return 0;
}



