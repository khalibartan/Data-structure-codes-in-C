//Objective: Addition of two polynomials using linked list
//Author: Utkarsh
//Registration number: 20142027

#include<stdio.h>
#include<stdlib.h>
/*
 *	creating a structure for a node.
 *	This node has three parts, an exponent of the term, coefficient of term,a link to the next term 
 */

struct node{
	int exp;
	float cof;
	struct node *next;
}*start=NULL,*start2=NULL,*start3=NULL;

//Declaration of functions

struct node *create(struct node *s);
struct node *insert(struct node *s,int exp,float coef);
void poly_add(struct node *p1,struct node *p2);
void display(struct node *p);

/*
 *	Iterates over the list and prints the term
*/

void display(struct node *p){
	struct node *ptr=p;
	while(ptr!=NULL){
		printf("%.2fx^%d ",ptr->cof,ptr->exp);
		ptr=ptr->next;
		if(ptr){
			printf("+ ");
		}
		else{
			printf("\n");
		}
	}
}

/*
 *	Create function takes an argument which is the starting pointer of the linked list.
 *	It do following things:
 *		Create a linked list whose starting pointer is given argument to the function
 *		For each term scans the coefficient and exponent of the term
 *		Passes the scanned arguments to insert function to insert at right place
 */
struct node *create(struct node *s){
	int i,ex,n;
	float cof;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter the coefficient and exponent of %d term: ",i);
		scanf("%f %d",&cof,&ex);
		s=insert(s,ex,cof);
	}
	return s;
}

/*
 *	Insert function takes three arguments the starting pointer, the coefficient of term , the exponent of the term
 *	It do following things:
 *		If the linked list is empty it add the given parameters to the starting node
 *		If linked list is not empty it iterates over the linked list till required position is reached
 *			Required position is determined by decreasing order of exponents
 */

struct node *insert(struct node *s,int exp,float coef){
	struct node *temp=malloc(sizeof(struct node));
	temp->exp=exp;
	temp->cof=coef;
	if(s==NULL || temp->exp > s->exp){
		temp->next=s;
		s=temp;
	}
	else{
		struct node *ptr=s;
		while(ptr->next!=NULL && ptr->exp > exp)
			ptr=ptr->next;		//Iterating over until end of node is reached or exponent of node to be inserted becomes larger than current node
		temp->next=ptr->next;
		ptr->next=temp;
	}
	return s;
}

/*
 *	The poly_add fucntion takes following arguments: The two starting pointers of linked list
 *	It do following things:
 *		It iterates over the two linked list until end of any one of them is reached
 *			Insert elements in the linked list in sequence ( larger comes first)
 *			Whenever two exponents are equal we sum the coefficients and then add it to linked list
 *		Then it appends the remaining terms in anyone of the list to the main list
 */

void poly_add(struct node *p,struct node *ptr){
	struct node *p1=p;
	struct node *p2=ptr;
	while(p1!=NULL && p2!=NULL){
		if(p1->exp > p2->exp){
			start3=insert(start3,p1->exp,p1->cof);
			p1=p1->next;
		}
		else if (p2->exp > p1->exp){
			start3=insert(start3,p2->exp,p2->cof);
			p2=p2->next;
		}
		else if(p1->exp == p2->exp){
			start3=insert(start3,p1->exp,p1->cof+p2->cof);
			p1=p1->next;
			p2=p2->next;
		}
	}
	while(p1!=NULL){
		start3=insert(start3,p1->exp,p1->cof);
		p1=p1->next;
	}
	while(p2!=NULL){
		start3=insert(start3,p2->exp,p2->cof);
		p2=p2->next;
	}
}

int main(){
	printf("Enter the polynomial 1\n");
	start=create(start);
	printf("Enter the polynomial 2\n");
	start2=create(start2);
	printf("Frist polynomial is: "); 
	display(start);
	printf("Second polynomial is: ");
	display(start2);
	poly_add(start,start2);
	printf("Addition of ploynomials are: ");
	display(start3);
return 0;
}
 
