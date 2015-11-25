/* Objective: Implement qucik sort
 * Author : Khalibartan (Utkarsh)
 * Reg.no : 20142027
 */
#include<stdio.h>
#define MAX 30

enum bool {FALSE,TRUE};
/* Algorithm : Biased implementation using first element as pivot always.
 * 1.Chose a pivot
 * 2.Arrange all elements smaller than pivot before and larger after
 * 3.Recursively sort the two parts obtained by repeating 1-2.
 */
display(int arr[],int low,int up)
{
    int i;
    for(i=low;i<=up;i++)
        printf("%d ",arr[i]);
}

quick(int arr[],int low,int up)
{
    int piv,temp,left,right;
    enum bool pivot_placed=FALSE;
    left=low;
    right=up;
    piv=low; /*Take the first element of sublist as piv */

    if(low>=up)
        return;
    printf("Sublist : ");
    display(arr,low,up);

    /*Loop till pivot is placed at proper place in the sublist*/
    while(pivot_placed==FALSE)
    {
        /*Compare from right to left  */
        while( arr[piv]<=arr[right] && piv!=right )
            right=right-1;
        if( piv==right )
            pivot_placed=TRUE;
        if( arr[piv] > arr[right] )
        {
            temp=arr[piv];
            arr[piv]=arr[right];
            arr[right]=temp;
            piv=right;
        }
        /*Compare from left to right */
        while( arr[piv]>=arr[left] && left!=piv )
            left=left+1;
        if(piv==left)
            pivot_placed=TRUE;
        if( arr[piv] < arr[left] )
        {
            temp=arr[piv];
            arr[piv]=arr[left];
            arr[left]=temp;
            piv=left;
        }
    }
    printf("-> Pivot Placed is %d -> ",arr[piv]);
    display(arr,low,up);
    printf("\n");

    quick(arr,low,piv-1);
    quick(arr,piv+1,up);
}




int main()
{
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element: ",i+1);
        scanf("%d",&array[i]);
    }
    quick(arr,0,n-1);

    printf("Sorted list is :\n");
    display(arr,0,n-1);
    printf("\n");
    return 0;
}


