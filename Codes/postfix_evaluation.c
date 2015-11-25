/* Objective: To evaluate a given postfix expression
 * Author: Khalibartan (Utkarsh) 
 * Reg.no :20142027
 */
#include<stdio.h>
#include<string.h>
//Algorithm
/*
 * Scan input postifx expression string from left to right
 * If an operand is encountered put it onto stack
 * If an operator is encountered then pop two elements from stack preform opertation and push result back into stack
 *
 */
int main(){
	char postfix[100];			//Declaring space for postfix string
	
	printf("Enter postfix string you want to evaluate ");		//Prompting user to enter a postfix expression
	
	scanf("%[^\n]",postfix);  		//Scaning till newline character is entered
	
	int stack[100],top=-1,i,operand1,operand2,len;		// Declaring stack,top,i(for traversal),operand1,operand2,result (for storing result )
	
	len=strlen(postfix);			//Storing length of postfix expression
	
	for(i=0;i<len;i++){
		if(postfix[i]>='0' && postfix[i]<='9'){
			stack[++top]=(int)postfix[i]-(int)'0';
		}
		else{
			operand1=stack[top--];
			operand2=stack[top--];
			if(postfix[i]=='*'){
				stack[++top]=operand1*operand2;
			}
			else if(postfix[i]=='+'){
				stack[++top]=operand1+operand2;
			}
			else if(postfix[i]=='-'){
				stack[++top]=operand1-operand2;
			}
				
			else if(postfix[i]=='/'){
				stack[++top]=operand1/operand2;
			}
			else if(postfix[i]=='%'){
				stack[++top]=operand1%operand2;
			}
		}
	}
	printf("Result of expression is: %d",stack[top]);
return 0;
}
