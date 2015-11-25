/*Objective: To create a file and insert numbers in that file
 * Author: Khalibartan (Utkarsh)
 * Reg.no: 20142027
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr;
	int i,n;
	int temp;
	fptr=fopen("numbers.txt","w");//Opening numbers.txt in write mode
	if(fptr==NULL){
		printf("Cannot create the file");//Condition if file is not created
		return 0;
	}
	printf("I'll create sudo random numbers write them in a file and then I'll read them and classify them in odd and even\nEnter the number of elements: ");
	scanf("%d",&n);//Taking input the total number of random numbers
	for(i=0;i<n;i++){
		temp=rand();//Creating random number
		fprintf(fptr,"%d\n",temp);//writing number on file
	}
	fclose(fptr);//closing the file
	fptr=fopen("numbers.txt","r");//opening numbers.txt in read mode
        FILE *fptr_odd,*fptr_even;
        fptr_odd=fopen("odd.txt","w");//opening odd.txt in write mode
        fptr_even=fopen("even.txt","w");//opening even.txt in write mode
        if((fptr_even==NULL)||(fptr_odd==NULL)){
                printf("Couldn't create file");//If file is not created
                return 0;
        }
	i=0;
	while(i<n){
		fscanf(fptr,"%d",&temp);//reading number from numbers.txt
		/*writing number in file according to odd or even*/
		if(temp%2==0){
			fprintf(fptr_even,"%d\n",temp);
		}
		else{
			fprintf(fptr_odd,"%d\n",temp);
		}
		i++;
	}
	//Closing the files        
	fclose(fptr);
	fclose(fptr_odd);
	fclose(fptr_even);

return 0;
}

