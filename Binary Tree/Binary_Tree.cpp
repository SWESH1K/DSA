#include "bits/stdc++.h"
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root) {
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(int inorder[], int start, int end, int curr) {
    for(int i=start;i<=end;i++) {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int index=0;

    if(start>end)
        return NULL;

    int curr = preorder[index];
    index++;
    node *newnode = new node(curr);

    int pos = search(inorder, start, end, curr);
    newnode->left = buildTree(preorder, inorder, start, pos-1);
    newnode->right = buildTree(preorder, inorder, pos+1, end);

    return newnode;

}

int main()
{
    struct node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);

    /*
              1
            /  \
           2    3
    */


   root->left->left = new node(4);
   root->left->right = new node(5);

    /*
              1
            /  \
           2    3
         /  \
        4    5
    */

   root->right->left = new node(6);
   root->right->right = new node(7);

    /*
               1
            /    \
           2      3
         /  \   /  \
        4    5 6    7
    */

   cout<<"PreOrder:"<<endl;
   preorder(root);
   cout<<endl<<"InOrder:"<<endl;
   inorder(root);
   cout<<endl<<"PostOrder:"<<endl;
   postorder(root);
   cout<<endl;

   // Building the Tree using preorder and inorder:

   cout<<endl<<"Creating a new tree..."<<endl;

   int preorders[] = {1, 2, 4, 3, 5};
   int inorders[] = {4, 2, 1, 5, 3};

   /*
            1
          /  \
         2    3
        /    /
       4    5
   */

   node *newroot = buildTree(preorders, inorders, 0, 4);

   cout<<"Tree created successfully"<<endl<<"The inorder of the Tree is:"<<endl;
   inorder(newroot);
    return 0;
}