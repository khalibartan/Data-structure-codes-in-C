/*Objective : To find sum two numbers unbounded using circular queue
 *Author : Khalibartan (Utkarsh)
 *Reg.no : 20142027
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int char_to_string(char c);

void strrev(char* str){
	int length = strlen(str);
	int i,j;
	char temp;
	for(i = 0, j = length-1;i < (length)/2; i++, j--){
		temp = str[i];
		str[i]=str[j];
		str[j] = temp;
	}
	return;
}

int char_to_string(char c){ // Converts a charachter to its integer data type
	int x=(int)c;
	x=x-48;
	return x;
}

int main(){
	int n1,n2;
	printf("Enter the number of digits for first number: ");
	scanf("%d",&n1);
	char *num1=malloc(n1*sizeof(char));
	printf("Enter the number:\n");
	scanf("%s",num1);
	printf("Enter the number of digits for second number: ");
	scanf("%d",&n2);
	char *num2=malloc(n2*sizeof(char));
	printf("Enter the second number:\n");
	scanf("%s",num2);
	n1=strlen(num1);
	n2=strlen(num2);
	strrev(num1);
	strrev(num2);
	int l=(n1>n2?n1:n2);
	int *queue=malloc(l*sizeof(int));
	int enque=-1,deque=-1,i=0,carry=0,x=0,y=0;
	while(i<l){
		x=0;y=0;
		if(i<n1){
			x=char_to_string(num1[i]);
		}
		if(i<n2){
			y=char_to_string(num2[i]);
		}
		queue[++enque]=(x+y+carry)%10;
		carry=(x+y+carry)/10;
		++deque;
		i++;
	}
	i=0;
	if(carry!=0){
		queue[++enque]=carry;
		++deque;
		i=-1;
	}
	printf("Sum of given numbers is: ");
	while(i<l){
		printf("%d",queue[deque--]);
		i++;
	}
return 0;
}

	
	
