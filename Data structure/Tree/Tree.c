#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;                 //Data element
     struct node * left;          //Pointer to left node
     struct node * right;         //Pointer to right node
};

struct node * MakeNode(int value)
{
    struct node * temp=(node * )malloc(sizeof(node));
    temp->data = value;
    temp->left = temp->right=NULL;
    return temp;
}

int main() {
	struct node root;
	MakeNode(5);
}