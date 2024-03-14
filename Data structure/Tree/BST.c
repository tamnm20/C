//source: https://nguyenvanhieu.vn/cay-tim-kiem-nhi-phan-binary-search-tree/#ftoc-heading-1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
} node_t;

void Free( node_t* root )
{
    if ( root == NULL )
        return;
    Free( root->left );//Gọi đệ quy xóa cây con bên trái
    Free( root->right );//Gọi đệ quy xóa cây con bên phải
    free( root );//Giải phóng vùng nhớ cho con trỏ hiện tại
}

//Hàm điều hướng của cây
int LeftOf( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
//    return value <= root->data;
}

int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}

//Thêm phần tử vào BST

node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL ) //Nếu Node hiện tại = NULL, đó là vị trí cần thêm. Thêm vào BST và kết thúc
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) ) //Nếu giá trị cần thêm < giá trị root hiện tại, gọi đệ quy Insert vào cây con bên trái
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) ) //Nếu giá trị cần thêm > giá trị root hiện tại, gọi đệ quy Insert vào cây con bên phải.
        root->right = Insert( root->right, value );
    return root;
}

bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}

void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data); //Ghé thăm Node root
        PreOrder(root->left);	//Gọi đệ quy duyệt qua cây con bên trái
        PreOrder(root->right);	//Gọi đệ quy duyệt qua cây con bên phải
    }
}

void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);	//Gọi đệ quy duyệt qua cây con bên trái
        printf("%d ", root->data);//Ghé thăm Node root
        InOrder(root->right);	//Gọi đệ quy duyệt qua cây con bên phải
    }
}

void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
	node_t* root = NULL; //Node gốc
	root = Insert( root, 25 );
    root = Insert( root, 15 );
    root = Insert( root, 50 );
    root = Insert( root, 10 );
    root = Insert( root, 22 );
    root = Insert( root, 35 );
    root = Insert( root, 70 );
    root = Insert( root, 4 );
    root = Insert( root, 12 );
    root = Insert( root, 18 );
    root = Insert( root, 24 );
    root = Insert( root, 31 );
    root = Insert( root, 44 );
    root = Insert( root, 66 );
    root = Insert( root, 90 );
	
	printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder: ");
    PostOrder(root);
	
	printf("\n==Thu them phan tu 9, 2 vao BTS==\n");
    Insert(root, 9);
	Insert(root, 2);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder: ");
    PostOrder(root);
	
	printf("\nTim kiem phan tu 31: ");
	if(Search(root, 31)) printf("yes\n");
	else printf("no\n");
	
	printf("\nTim kiem phan tu 100: ");
	if(Search(root, 31)) printf("yes\n");
	else printf("no\n");
	
	Free( root );
    root = NULL;
    return 0;
}