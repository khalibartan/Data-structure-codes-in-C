/*Objective : Implement Radix sort
 * Author: Khalibartan (Utkarsh)
 * Reg. no : 20142027
 */
# include<stdio.h>
# include<stdlib.h>
/* I'll use linked list to save memory.
 * Algorithm: In each pass k, numbers are arranged according to the kth digit least significant digit. After n passes (n=no of digits of maximum number), the list becomes sorted. It is similar to alphabetical order arrangement.
 */
struct  node
{
	int info ;
	struct node *link;
}*start=NULL;

int main()
{
	struct node *tmp,*q;
	int i,n,value;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&value);

		/* Inserting elements in the linked list */
		tmp= malloc(sizeof(struct node));
		tmp->info=value;
		tmp->link=NULL;

		if(start==NULL) /* Inserting first element */
			start=tmp;
		else
		{ /* Inserting values at end */
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}

	printf("Unsorted list is :\n");
	display();
	radix_sort();
	printf("Sorted list is :\n");
	display ();
    return 0;
}
/*utility function for displaying */
void display()
{
	struct node *p=start;
	while( p !=NULL)
	{
		printf("%d ", p->info);
		p= p->link;
	}
	printf("\n");
}
/* radix sort function */
void radix_sort()
{
	int i,k,dig,maxdig,mindig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];

	least_sig=1;
	most_sig=large_dig(start);

	for(k = least_sig; k <= most_sig ; k++)
	{
		for(i = 0 ; i <= 9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL ;
		}
		maxdig=0;
		mindig=9;
		p = start ;
		while( p != NULL)
		{
			/*Find kth digit in the number*/
			dig = digit(p->info, k);
			if(dig>maxdig)
				maxdig=dig;
			if(dig<mindig)
				mindig=dig;

			/*Add the number to queue of dig*/
			if(front[dig] == NULL)
				front[dig] = p ;
			else
				rear[dig]->link = p ;
			rear[dig] = p ;
			p=p->link;
		}
		/* maxdig and mindig are the maximum amd minimum
		   digits of the kth digits of all the numbers*/
		printf("mindig=%d  maxdig=%d\n",mindig,maxdig);
		/*Join all the queues to form the new linked list*/
		start=front[mindig];
		for(i=mindig;i<maxdig;i++)
		{
			if(rear[i+1]!=NULL)
				rear[i]->link=front[i+1];
			else
				rear[i+1]=rear[i];
		}
		rear[maxdig]->link=NULL;
		printf("New list : ");
		display();
	}

}

/* This function finds number of digits in the largest element of the list */
int large_dig()
{
	struct node *p=start ;
	int large = 0,ndig = 0 ;

	while(p != NULL)
	{
		if(p ->info > large)
			large = p->info;
		p = p->link ;
	}
	printf("Largest Element is %d , ",large);
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}

	printf("Number of digits in it are %d\n",ndig);
	return(ndig);
}

/*This function returns kth digit of a number*/
int digit(int number, int k)
{
	int digit, i ;
	for(i = 1 ; i <=k ; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
	return(digit);
}



