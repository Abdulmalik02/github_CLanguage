#include <stdio.h>
#include <conio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node tree;

tree *root = NULL;

tree* newnode(int data) {

  tree *new = NULL;
  new = (tree *)malloc(sizeof(tree));

  new->data = data;
  new->left = NULL;
  new->right = NULL;

  return(new);
}

void preorder(tree *root) {

  if(root == NULL) {return;}

  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(tree *root) {

  if(root == NULL) {return;}

  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}

void postorder(tree *root) {

  if(root == NULL) {return;}

  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}

int main() {
  root = newnode(10);
  root->left = newnode(20);
  root->right = newnode(30);
  root->left->left = newnode(40);
  root->left->right = newnode(50);
  printf("Preorder traversal of binary tree is : ");
  preorder(root);
  printf("\n");
  printf("Inorder traversal of binary tree is : ");
  inorder(root);
  printf("\n");
  printf("Postorder traversal of binary tree is : ");
  postorder(root);

  getchar();
  return 0;
}
