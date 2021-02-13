#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
}; //node
struct stack{
    struct node * top;
    int size;
}; //stack
void push(int element, struct stack * list);
void display(struct stack list);
int pop(struct stack * list);


struct stack stackgenerate(){ //Generate a stack
    struct stack * st=NULL;
    st=(struct stack*)malloc(sizeof(struct stack));

    if (st!=NULL)
    {
       struct node * temp;
       temp = (struct node *)malloc(sizeof(struct node));
       temp->data = -1;
       temp->next = NULL;
       st->top = temp;
       st->size = 0;
    }
    return *st;
};

void push(int element, struct stack * list){ //Push
struct node * temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->data=element;
temp->next = list->top->next;
list->top->next=temp;
list->size++;
}

void display(struct stack list){ //Print
struct node *temp =list.top;
temp=temp->next;
while(temp!=NULL){
    printf("%d---->",temp->data);
    temp = temp->next;
}
printf("NULL");
}

int pop(struct stack * list){ //pop
struct node *temp;
temp=list->top->next;
list->top->next = list->top->next->next;
list->size--;
return temp->data;
}

int main(){

struct stack list;
list=stackgenerate();
int ch,data;
do{
printf("\n1- Push\n2-Pop\n3-Size\n4-Display\n5-Exit\n");
printf("Choice: ");
scanf("%d", &ch);

    switch (ch){
    case 1:
        printf("Enter: ");
        scanf("%d", &data);
        push(data, &list);
        break;
    case 2:
        printf("%d popped", pop(&list));
        break;
    case 3:
        printf("List size: %d", list.size);
        break;
    case 4:
        display(list);
        break;
    case 5:
        break;


    default:
        printf("please choose option!\n");
        break;
 }

}while (ch != 5);


return 0;
}

