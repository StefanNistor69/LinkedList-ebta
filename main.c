#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	char *string;
	struct node* next;


}*head;

void push(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*) malloc(sizeof(struct node));


    new_node->data  = new_data;


    new_node->next = (*head_ref);


    (*head_ref)    = new_node;
}
void append(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    struct node *last = *head_ref;


    new_node->data  = new_data;


    new_node->next = NULL;


    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }


    while (last->next != NULL)
        last = last->next;


    last->next = new_node;
    return;
}


void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {

        next = current->next;


        current->next = prev;


        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void insert(struct node** head){

    int pos, x;
    printf("New node position: \n");
    printf(" > ");
    scanf("%d", &pos);
    printf("New value: \n");
    printf(" > ");
    scanf("%d", &x);


    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = x;
    temp1->next = NULL;
    if (pos == 1){
        temp1->next = *head;
        *head = temp1;
        return;
    }

    struct node* temp2 = *head;
    for (int i = 0; i < pos-2; i++){
        temp2 = temp2 -> next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}
void del(struct node** head){

    int pos;
    printf("position to remove: ");
    printf(" > ");
    scanf("%d", &pos);


    struct node* temp1 = *head;

    if(pos==1){
        *head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < pos-2; i++)
        temp1 = temp1->next;

    struct node* temp2 = temp1->next;
    temp1->next =temp2->next;
    free(temp2);
}
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;


    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
int searchElement(struct node* head, int item)
{
    struct node* current = head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == item){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void WriteLinkedList(struct node* root) {
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        exit(1);
    }

    for (struct node* curr = root; curr != NULL; curr = curr->next) {
        fprintf(file, "%d, ", curr->data);
    }
    fclose(file);
}


void ReadLinkedList(struct node** root) {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        exit(2);
    }

    int val;
    while(fscanf(file, "%d, ", &val) > 0) {
        append(root, val);
    }
    fclose(file);
}
void display(struct node* head)
{
    if (head == NULL) {
        printf("List has no elements \n");
        return;
    }
    struct node* temp = head;
    printf("\n Linked List : ");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
 struct node* head = NULL;
    int first_choice,second_choice, number_of_elements;

    int exit = 0;


    printf("Create list?\n");
    printf("1.Yes    2.No");


    scanf("%d", &first_choice);

    switch (first_choice)
    {
    case 1:

        printf("Number of list elements: ");
        scanf("%d",&number_of_elements);
        for (int i = 0; i < number_of_elements; i++){
                int data;
                scanf("%d", &data);
                append(&head, data); }
        printf("List: ");
        display(head);
    break;
    case 2:
        printf("you can try something from here or exit bu typing 0");
        break;
    default:
        break;
    }
     while(exit == 0) {

        printf("1.Append; 2.Push; 3.Reverse; 4.insert; 5.Remove; 6.BubbleSort; 7.Search; 8.Write;  9.Read;");


        scanf("%d", &second_choice);

        switch (second_choice)
        {

           case 1: {
                int data;
                scanf("%d", &data);
                append(&head, data);
                display(head);
                break;
           }
           case 2: {
                int data;
                scanf("%d", &data);
                push(&head, data);
                display(head);
                break;
           }

           case 3: {

                reverse(&head);
                display(head);
           break;
           }
           case 4: {

                insert(&head);
                display(head);
           }break;

           case 5:{

                del(&head);
                display(head);
            }break;

           case 6:{

                bubbleSort(head);
                display(head);
            }break;

            case 7:{

                int data;
                scanf("%d", &data);
                if (searchElement(head, data)) {
                    printf("Yes"); }
                else {
                printf("No"); }
                printf("\n");
                display(head);
                break;
            }

            case 8: {
                WriteLinkedList(head);
                display(head);
                 }break;

            case 9:{
                ReadLinkedList(&head);
                display(head);
                }break;


           case 0:{
           printf(" \n Program stopped. ");
           exit=1;
           }break;


           default:
              break;

        }
    }
  return 0;

};






