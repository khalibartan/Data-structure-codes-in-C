#include<stdio.h>
#include<stdlib.h>
void print_ll();
void create();
void insert_start();
void insert_end();
void insert_btw();
void del_start();
void del_end();
void del_btw();
struct node{
	int value;
	struct node *next;
}*start=NULL;
void print_ll(){
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node*));
	ptr=start;
	printf("current state of linked list is: ");
	while(ptr!=NULL){
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	printf("\n");

}
void create(){
	int i,n;
	printf("Enter the number of nodes you want to create: ");
	scanf("%d",&i);
    while(i--){
		struct node *current_node,*new_node;
		new_node=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the value : ");
		scanf("%d",&n);
		new_node->value=n;
		new_node->next=NULL;
		if(start==NULL){
			start=new_node;
			current_node=new_node;
		}
		else{
			current_node->next=new_node;
			current_node=new_node;
		}
	}
	print_ll();
}
void insert_start(){
	if(start==NULL){

		printf("List is empty");
	}
	else{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		int n;
		printf("Enter the value you want to insert: ");
		scanf("%d",&n);
		temp->value=n;
		temp->next=start;
		start=temp;
		print_ll();

	}
}	
void insert_end(){
	if(start==NULL){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the value");
		int n;
		scanf("%d",&n);
		temp->value=n;
		temp->next=NULL;
		start=temp;
		print_ll();
	
	}
	else{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the value");
		int n;
		scanf("%d",&n);
		temp->value=n;
		temp->next=NULL;
		struct node *ptr;
		ptr=(struct node*)malloc(sizeof(struct node*));
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
		print_ll();

	}
}

void insert_btw(){
	if(start==NULL){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the value");
		int n;
		scanf("%d ",&n);
		temp->value=n;
		temp->next=NULL;
		start=temp;
		print_ll();
	}
	else{
		int option;
		printf("Enter 1 to give index after which you want to insert( starting from 0) \n enter 2 if you want to give value after which you want to insert");
		scanf("%d",&option);
		if(option==1){
			int i,n;
			printf("Enter the index and value (space in between)");
			scanf("%d %d",&i,&n);
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node*));
			temp->value=n;
			struct node *ptr;
			ptr=(struct node*)malloc(sizeof(struct node*));
			ptr=start;
			while(i--!=0){
				ptr=ptr->next;
			}
			temp->next=ptr->next;
			ptr->next=temp;
		}
		else if(option==2){
			int val,n;
			printf("Enter the value after which you want to insert and value (space in between)");
			scanf("%d %d",&val,&n);
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node*));
			temp->value=n;
			struct node *ptr;
			ptr=(struct node*)malloc(sizeof(struct node*));
			ptr=start;
			while(ptr->value!=val){
				ptr=ptr->next;
			}
			temp->next=ptr->next;
			ptr->next=temp;

		}
		print_ll();
	}
	
}

void del_start(){
	if(start==NULL){
		printf("Linked list is emty");
	}
	else{
		struct node *del_ptr;
		del_ptr=(struct node*)malloc(sizeof(struct node*));
		del_ptr=start;
		start=start->next;
		free(del_ptr);
		print_ll();
	}
}

void del_end(){
	if(start==NULL){
		printf("Linked list is empty");
	}
	else{
		struct node *del_ptr;
		del_ptr=(struct node*)malloc(sizeof(struct node*));
		del_ptr=start;
		while(del_ptr->next->next!=NULL){
			del_ptr=del_ptr->next;
		}
		struct node *ptr;
		ptr=(struct node*)malloc(sizeof(struct node*));
		ptr=del_ptr->next;
		del_ptr->next=NULL;
		free(ptr);
		print_ll();
	}
}

void del_btw(){
	if(start==NULL){
		printf("Linked list is empty");
	}
	else{
		int option;
		printf("Enter 1 to give index after which you want to delete( starting from 0) \n enter 2 if you want to give value which you want to delete");
		scanf("%d",&option);
		if(option==1){
			int i,n;
			printf("Enter the index : ");
			scanf("%d",&i);
			struct node *del_ptr;
			del_ptr=(struct node*)malloc(sizeof(struct node*));
			struct node *ptr;
			ptr=(struct node*)malloc(sizeof(struct node*));
			ptr=start;
			while(i--!=1){
				ptr=ptr->next;
			}

			del_ptr=ptr->next;
			ptr->next=del_ptr->next;
			free(del_ptr);
		}
		else if(option==2){
			int val;
			printf("Enter the value which you want to delete : ");
			scanf("%d",&val);
			struct node *del_ptr;
			del_ptr=(struct node*)malloc(sizeof(struct node*));
			struct node *ptr;
			ptr=(struct node*)malloc(sizeof(struct node*));
			ptr=start;
			while(ptr->next->value!=val){
				ptr=ptr->next;
			}
			del_ptr=ptr->next;
			ptr->next=del_ptr->next;
			free(del_ptr);

		}
		print_ll();
	}


}

int main(){
create();
int option,x=1;
while(1){
printf("What you want to do ( enter the corresponding index to the option to select it):\n1.Insert an element at the starting of linked list\n2.Insert an element at the end of linked list\n3.Insert an element in between the linked list\n4.Delete an element at starting\n5.Delete an element at the end\n6.Delete an element in between\n");
scanf("%d",&option);
switch(option){
case 1:insert_start();break;
case 2:insert_end();break;
case 3:insert_btw();break;
case 4:del_start();break;
case 5:del_end();break;
case 6:del_btw();break;
default:printf("The given value is not a valid option");

}
printf("Do you want menu again (0 for NO, 1 for yes) :");
scanf("%d",&x);
if(x==0)
return 0;
}
return 0;
}	 
			

