/*Objective: To find sum of digits using Queue
 *Author : Khalibartan (Utkarsh)
 *Reg no.:20142027
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Algorithm: I'll scan number using strings
 * Will convert char into integer
 * Use this value and it to queue
 */
int char_to_int(char c){
	int x=(int)c;
	x=x-48;
	return x;
}

int main(){
	int n;
	printf("Enter the number of digits: ");
	scanf("%d",&n);
	char *s=malloc(n*sizeof(char));
	printf("Enter the number: ");
	scanf("%s",s);
	int length=strlen(s);
	int *queue=malloc(2*length*sizeof(int));
	int i=1,pop=-1,push=-1,x,y;
	queue[++push]=char_to_int(s[0]);
	for(i=1;i<length;i++){
		queue[++push]=char_to_int(s[i]);
		x=queue[++pop];
		y=queue[++pop];
		queue[++push]=x+y;
	}
	printf("Sum of digits is: %d",queue[++pop]);
return 0;
}
		



