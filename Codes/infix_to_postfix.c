/*Objective: To convert a given infix expression to postfix
 * Author: Khalibartan (Utkarsh)
 * Reg.no:20142027
*/
#include<stdio.h>
#include<string.h>
/* Algorithm for infix to postifx conversion
 * Push left parenthesis onto stack and right parenthesis at end of infix expression
 * scan infix expression from 0 to end
 * if an operand is encountered put in into output postfix string
 * if a left parenthesis is encountered push it into stack
 * if an opreator(O1) is encountered then do following:
 * 	if there is an opertator O2 at the top of stack and O1 has precedence less than that of O2,
 * 		then pop O2 off the stack onto output expression and put O1 into stack
 *	push O1 onto stack
 * if a right parenthesis is encountered empty stack until a left parenthesis is encountered
*/

int main(){
	int precedence[50];
	precedence['*']=3;	// Defining a precendence hash .
	precedence['%']=3;	// Higher the value higher the precendence
	precedence['/']=3;
	precedence['+']=2;
	precedence['-']=2;

	char infix[1000],postfix[1000],stack[500]={'('}; //Intializing stack with left parenthesis
	
	printf("Enter infix expression: ");
	
	scanf("%[^\n]",infix); //Scaning the infix expression till newline is enter
	
	int len,top=0,postfix_index=0;//Intializing top with 0 //Postifx_index tell till where output string is filled

	len=strlen(infix); //Storing length of infix expression string
	
	int i=0;
	
	infix[len++]=')'; //Putting right parenthesis at the end of infix string

	for(i=0;i<=len;i++){
		if(infix[i]==' '||infix[i]=='\t'){
			continue;
		}
		else if((infix[i]>=48 && infix[i]<=57)||(infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z')){
			postfix[postfix_index++]=infix[i];  // Putting scaned operand onto output string
		}
		else{
			if(infix[i]==')'){
				while(stack[top]!='('){
					postfix[postfix_index++]=stack[top--];	//Putting operators until a left parenthesis is encountered
				}
				top--;
			}
			else if(infix[i]=='('){
				stack[++top]='(';		//Putting left parenthesis onto stack
			}
			else if((infix[i]>='*' && infix[i]<='/') || infix[i]=='%'){	   //Doing what is mentioned in alogrithm for operator encountered

				if(( stack[top]>='*' && stack[top]<='/' ) || stack[top]=='%' ){
					while(precedence[stack[top]]>=precedence[infix[i]])
						postfix[postfix_index++]=stack[top--];	
                    top--;
                }
				stack[++top]=infix[i];
				}
				else{
						stack[++top]=infix[i];
				}				
			}
		}
	}
	postfix[postfix_index]='\0'; 			//Converting postfix expression into string
	printf("Postfix expression is : %s",postfix);		//Printinf postfix expression
return 0;
}
