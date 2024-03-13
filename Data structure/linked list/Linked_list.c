#include <stdio.h>
#include <stdlib.h>

struct Data_TypeDef {
    int i_data;
    float f_data;
    char c_data;
} Data_TypeDef;

struct Node_TypeDef {
    struct Data_TypeDef data;
    struct Node_TypeDef *ptr;  
} Node_TypeDef;

struct Node_TypeDef *CreateNewNode(int data) {
    struct Node_TypeDef *new_node = (struct Node_TypeDef *) calloc (1, sizeof(struct Node_TypeDef));
    new_node->data.i_data = data;
    new_node->ptr = NULL;
    return new_node;
}

void Init(struct Node_TypeDef *head, int data) {
    struct Node_TypeDef *new_node = CreateNewNode(data);

    head->ptr = new_node;
}

void AddHead(struct Node_TypeDef *head, int data) {
    struct Node_TypeDef *new_node = CreateNewNode(data);

    new_node->ptr = head->ptr;
    head->ptr = new_node;
}
void AddTail(struct Node_TypeDef *head, int data) {
    struct Node_TypeDef *new_node = CreateNewNode(data);
    struct Node_TypeDef *head_tmp = head;
    while(head_tmp->ptr != NULL) {
        head_tmp = head_tmp->ptr;
    }
    if(head_tmp->ptr == NULL){
        new_node->ptr = NULL;
        head_tmp->ptr = new_node;
    }
}
void AddMidle(struct Node_TypeDef *head, int data, int locate) {
    struct Node_TypeDef *new_node = CreateNewNode(data);
    struct Node_TypeDef *head_tmp = head;
    int count  = 0;
    while(head_tmp->ptr != NULL) {
        head_tmp = head_tmp->ptr;
        count ++;
        if(count == locate){
            new_node->ptr = head_tmp->ptr;
            head_tmp->ptr = new_node;
        }
    }
    
}
void DeleteHead(struct Node_TypeDef *head) {
    struct Node_TypeDef *head_tmp = head->ptr;
    head->ptr = head->ptr->ptr;
    free(head_tmp);
    // new_node->ptr = head->ptr;
    // head->ptr = new_node;
}
void DeleteMidle(struct Node_TypeDef *head, int locate) {
    struct Node_TypeDef *head_tmp = head;
    int count  = 0;
    while(head_tmp->ptr != NULL) {
        head_tmp = head_tmp->ptr;
        count ++;
        if(count == locate){
           struct Node_TypeDef *delete = head_tmp->ptr;
           head_tmp->ptr = head_tmp->ptr->ptr;
           free(delete);
        }
    }
    
}

void DeleteTail(struct Node_TypeDef *head) {
    struct Node_TypeDef *head_tmp = head;
    while(head_tmp->ptr != NULL) {
        head_tmp = head_tmp->ptr;
        if(head_tmp->ptr->ptr == NULL){
            // struct Node_TypeDef *delete = head_tmp->ptr;
            free(head_tmp->ptr);
            head_tmp->ptr  = NULL;
        }
    }

}

void change_data(struct Node_TypeDef *head, int data1, int locate) {
    struct Node_TypeDef *head_tmp = head;
    int count  = 0;
    if (locate == 0)
    {
         head->ptr->data.i_data = data1;
    }
    else{
    while(head_tmp->ptr != NULL) {
        head_tmp = head_tmp->ptr;
        count ++;
        if(count == locate){
            head_tmp->ptr->data.i_data = data1;
        }
    }
    }
    
}

void print(struct Node_TypeDef *head) {
    struct Node_TypeDef *head_tmp = head;

    while(head_tmp->ptr != NULL) {
        printf("%d ", head_tmp->ptr->data.i_data);
        head_tmp = head_tmp->ptr;
    }
}

int main() {
    struct Node_TypeDef *head = CreateNewNode(0);

    //Init(head, 1);
    
    AddHead(head, 2);
    AddHead(head, 3);
    AddHead(head, 99);
    AddHead(head, 50);
    AddTail(head, 8);
    AddTail(head, 9);
    AddMidle(head, 7, 3);
    print(head);
    printf("\n");
  //  DeleteHead(head);
    DeleteMidle(head, 3);
    //DeleteTail(head);
    change_data(head, 60, 0);
    print(head);
	printf("\n");
    free(head);

    return 0;
}