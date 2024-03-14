//source: https://nguyenvanhieu.vn/cay-nhi-phan-binary-tree/

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
    struct node * temp=(struct node * )malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right=NULL;
    return temp;
}

int MaxDepth(struct node* node) 
{
    if (node==NULL) 
        return 0;
    else
    {
         /* compute the depth of each subtree */
          int lDepth = MaxDepth(node->left);
          int rDepth = MaxDepth(node->right);

          /* use the larger one */
          if (lDepth > rDepth) 
                return(lDepth+1);
          else 
               return(rDepth+1);
   }
}

int main() {
	struct node * root;
	root = MakeNode(1);
	root->left = MakeNode(5);
	root->left->right = MakeNode(6);
	root->left->right->left = MakeNode(7);
	// Test by printing the value of the root node
	printf("Size of struct node: %lu bytes\n", sizeof(struct node));

    printf("Value of the root node: %d\n", root->data);
	printf("Value of the node: %d\n", root->left->right->left->data);

	int d = MaxDepth(root);
	printf("depth: %d\n", d);
	
    // Remember to free allocated memory when you're done using it
	free(root->left->right->left);
	free(root->left->right); // Free nút con phải của nút 5
    free(root->left);         // Free nút con trái (nút 5)
    free(root);
    return 0;
}