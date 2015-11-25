/* Objective : Evaluation of an expression tree
 * Author: Khalibartan (Utkarsh)
 * Reg no: 20142027
 */

#include<stdio.h>
#include<stdlib.h>
 /* Note: Each leaf is an operand
  * The root and internal nodes are operator
  *  Subtrees are subexpressions with root being an operator
  *  Inorder traversal gives infix expression
  *  postorder traversal produces postifx expression
  *  preorder traversal produces prefix expression
  */

//This programm will have code for infix expression
struct node{
    char data;
    struct node *left_ptr,*right_ptr;
}*root=NULL;


void create();
int operand(char a);
void infix(struct node *x);


void create(){
    
    do{
        struct node *p=malloc(sizeof(struct node));
        p->left_ptr=NULL;
        p->right_ptr=NULL;
        printf("Enter data: ");
        scanf("%c",&p->data);
        if(root==NULL){
            root->data=p->data;
        }
    }while
}

int operand(char a){
    if((a>='*'&&a<='/')||(a=='%')){
        return 1;
    }
    else{
        return 0;
    }
}

void infix(struct node *x){
    if(x!=NULL){
        if(operand(x->data)){
            printf("%c ",x->data);
        }
        else{
            printf("( ");
            infix(x->left_ptr);
            printf("%c ",x->data);
            infix(x->right_ptr);
            printf(")");
        }
    }
}

int main(){
    void create();
    void infix();
    return 0;
}
