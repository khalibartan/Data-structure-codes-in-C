/* Objective: To do following things with circular doubly linked list
 * 	1.Insert and delete elements
 * 	2.Reverse list
 * 	3.Search an element
 * 	4.Update a node
 */
// Author Khalibartan (utkarsh)
// Reg no: 20142027

#include<stdio.h>
#include<stdlib.h>

/*
 * 	Declaration of structure node data type
 * 	It has three parts:
 * 		1.A value
 * 		2.A pointer to previous node
 * 		3.A pointer to next node
 */

struct node{
	int value;
	struct node *prev;
	struct node *next;
}*start=NULL,*rev;

//Declaration of functions to be used

void create();
int insert(int i);
int delete(int i);
struct node *reverse();
int search();
void display(struct node *s);

// It iterates over the list and prints the values

void display(struct node *s){
	struct node *ptr=s;
	while(ptr->next!=s){
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	printf("%d ",ptr->value);
	printf("\n");
}

/*
 *	Insert function takes only index argument , where new node has to be inserted
 *	It do following things:
 *		If the list is empty it assigns the start the value of new node
 *		If list is non empty it iterates till specified index is reached or end of list is reached and insert the node
 *	It returns the index of last element.
 */
int insert(int i){
	int last=i;
	struct node *temp=malloc(sizeof(struct node));
	printf("Enter the value: ");
	scanf("%d",&temp->value);
	if(start==NULL){
		start=temp;
		temp->next=start;
		temp->prev=start;
	}
	else{
		struct node *ptr=start;
		while(((i--)-1)!=0 && ptr->next!=start){
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		temp->prev=ptr;
		ptr->next=temp;
		temp->next->prev=temp;
	}
	return last+1;
}

/*
 *	Create function takes no arguments
 *	It do following things:
 *		It creates a circular doubly linked list using insert function
 *
 */

void create(){
	int x=0,i;
	printf("Enter the number of nodes you want to create: ");
	scanf("%d",&i);
	while(i--){
		x=insert(x);
	}
	display(start);
}

/*	Delete function takes an argument the index where we have to delete the node
 *	It do following things:
 *		It iterates over the linked list till the desired point is reached or the end
 *		Marks the node
 *		make chages so that node remain contigous
 *		Delets the marked node
 *	Returns the value of deleted node if required
 */

int delete(int i){
    if(start==NULL){
        printf("Stack underflow list is empty ");
    }
    else{
        int val;
        struct node *ptr=malloc(sizeof(struct node));
		struct node *del_ptr=malloc(sizeof(struct node));
		ptr=start;
		while((i-- -1!=0) && (ptr->next->next!=start)){
			ptr=ptr->next;
		}
		del_ptr=ptr->next;
		del_ptr->next->prev=ptr;
		ptr->next=del_ptr->next;
		val=del_ptr->value;
		free(del_ptr);
		printf("Linked list after deletion is:\n");
		display(start);
	    return val;
    }
}

/*
 *	Reverse function takes no argument 
 *	It do following things:
 *		It reverses the given linked list by iterating over elements
 *	Returns a structure node type of the new reveresed list
 */

struct node *reverse(){
	struct node *ptr=start,*ptr2=start->next;
	ptr->next=start;
	ptr->prev=ptr2;
	while(ptr2!=start){
	    ptr2->prev=ptr2->next;
	    ptr2->next=ptr;
	    ptr=ptr2;
	    ptr2=ptr2->prev;
	}
	start=ptr;
	printf("Reversed linked list is:\n");
	display(start);
	return start;
}

/*
 *	Search function takes no arguments.
 *	It do following things :
 *		Prompt user to select an option regarding how he wants to search 
 *			1.Using index (if index is larger than length of list then continues from start)
 *			2.Using value (If value is not found returns -1)
 *		Iterates over the linked list and returns the index if option value was 2 or return value if option was 1
 */

int search(){
	int option,i,counter=0;
	struct node *ptr=start;
	printf(" How you want to search the item (enter corresponding number to the option to select):\n1.Using index\n2.Using value\n: ");
	scanf("%d",&option);
	switch(option){
		case 1: printf("Enter the index: ");scanf("%d",&i);
			while(i--){
				ptr=ptr->next;
			}
			printf("Found value is %d",ptr->value);
			break;
		case 2:printf("Enter the value: ");scanf("%d",&i);
		       while(ptr->value!=i){
				ptr=ptr->next;
				counter++;
				if(ptr==start){
					printf("Given value not found");
                    break;
				}
			}
		    printf("Given value is at index %d",counter);
		    break;
		default:printf("Enter value is not a valid option\n");
	}
}
/*
 * Update function updates a node.It doesn't take any arguments.It does following things
 *  Prompts user to select option , updating a node at given index or updating a node of given value
 *  then asks for new updated value
 *  changes the value of node
 *  and then prints the new list
 */
void update(){
    int op,val,i,flag=0;
    struct node *ptr=start;
    printf("Enter how you want to update:\n1.Update a node at a given index\n2.Update a node by specifying the old value\n:");
    scanf("%d",&op);
    printf("Enter the new value: ");
    scanf("%d",&val);
    switch(op){
        case 1:printf("Enter the index: ");
               scanf("%d",&i);
               while(i--!=0){
                   ptr=ptr->next;
               }
               ptr->value=val;
               break;
        case 2:printf("Enter the value by which you want to search: ");
               scanf("%d",&i);
               while(ptr->value!=i && ptr->next!=start){
                   ptr=ptr->next;
                   if(ptr->next==start){
                        flag=1;
                        break;
                   }
               }
               if(flag==1){
                   printf("Given value not found in list\n");
               }
               else{
                   ptr->value=val;
               }
               break;
        default:printf("Given value is not a valid option\n");
    }
    display(start);
}
int main(){
    int op,i;
    create();
    printf("What you want to do (Enter corresponding index to select the option):\n1.Insert an element at a given position\n2.Delete an element at given position\n3.Reverse circular linked list\n4.Search an element\n5.Update a node\n:");
    scanf("%d",&op);
    switch(op){
        case 1:printf("Enter index where you want to insert: ");
               scanf("%d",&i);
               insert(i);
               display(start);
               break;
        case 2:printf("Enter index where you want to delete: ");
               scanf("%d",&i);
               delete(i);
               break;
        case 3:start=reverse();
               break;
        case 4:search();
               break;
        case 5:update();
               break;
        default:printf("Given value is not a valid option");
    }
return 0;
}
