#include<stdio.h>
#include<stdlib.h>
void print_ll();
int insert(int i );
void delete(int i );

struct node{
	int value;
	struct node *next;
	struct node *previous;
}*start=NULL;

void print_ll(){
	struct node *ptr=start;
	for(;ptr->next!=NULL;ptr=ptr->next){
		printf("%d ",ptr->value);
	}
}

int insert(int i){
	int last=i;
	struct node *temp = malloc(sizeof(struct node));
	printf("Enter the value ");
	scanf("%d",&temp->value);
	if(start==NULL){
		start=temp;
		temp->next=NULL;
		temp->previous=NULL;
		return 0;
	}
	else{
		struct node *ptr=start;
		while(i-- && ptr->next!=NULL){
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		temp->previous=ptr;
		ptr->next=temp;
		ptr=temp;
		if(temp->next!=NULL){
			temp->next->previous=temp;
		}
		return last+1;
	}
}

void create(){
	int x=0,option=1;
	while(option!=0){
		printf("Enter 0 to end creation or non zero value to add another node: ");
		scanf("%d",&option);
		if(option){
			x=insert(x);
		}
		else{
			break;
		}
	}
	print_ll();
}
void delete(int i){
	int last=0;
	if(start==NULL){
		printf("Linked list is empty or geeky term stack underflow -_- ");
	}
	else{
		struct node *ptr=malloc(sizeof(struct node));
		struct node *del_ptr=malloc(sizeof(struct node));
		ptr=start;
		while(i-- -1!=0 && ptr->next->next!=NULL){
			ptr=ptr->next;
		}
		del_ptr=ptr->next;
		del_ptr->next->previous=ptr;
		ptr->next=del_ptr->next;
		free(del_ptr);
		printf("Linked list after deletion is:\n");
		print_ll();	
	}
}
main(){
	int op,i=0,a;
	struct node *ptr=start;
	do{
		printf("Select the option by hitting corresponding number to the option\n1. Create a linked list (Warning: If a previous linked list is created than it will be lost)\n2. Insert an element at start\n3. Insert an element at end\n4. Insert an element at specified index\n5. Delete an element at start\n6. Delete an element at end\n7.Delete an element at specified index\n: ");
		scanf("%d",&op);
		switch(op){
			case 1:start=NULL;create();break;
			case 2:insert(0);print_ll();break;
			case 4:printf("Enter the index :");scanf("%d",&i);insert(i);print_ll();break;
			case 3:while(ptr->next!=NULL){
				i++;ptr=ptr->next;
				}
				insert(i-1);print_ll();break;
			case 5:delete(0);break;
			case 6:while(ptr->next!=NULL){
				i++;ptr=ptr->next;
				}delete(i-1);break;
			case 7:printf("Enter the index :");scanf("%d",&i);delete(i);break;
			default:printf("Given value is not a valid option ");
		}
		printf("Do you want to menu again ( hit non zero value for yes 0 to stop )");
		scanf("%d",&a);
		i=0;
	}while(a!=0);
}	 

				
		
	 
			
