/* Objective : Implement bucket sort
 * Author : Khalibartan (Utkarsh)
 * Reg.no : 20142027
 */ 
#include<stdio.h>
#include<stdlib.h>
/* Algorithm : Numbers are classified into buckets. Then buckets are sorted using quick sort.
 */
int getMax(int arr[], int n)
{
    int mx = arr[0];int i;
    for ( i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
/* A comparision function */
int comp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
/* Bucket sort function */
void bucketsort(int a[],int n,int b[][100]){
    int i;
    int m=getMax(a,n);int exp;
    for( exp = 1; m/exp > 0; exp *= 10);
    exp/=10;
    int pp=-1;
    int j;int k[10]={0};
    for(i=0;i<n;i++){
        b[a[i]/exp][k[a[i]/exp]++]=a[i];
    }	
    for(i=0;i<10;i++){
        qsort(b[i],k[i]--,sizeof(int),comp);
    }
    for(i=0;i<10;++i){
        for(j=0;j<=k[i];++j){
            a[++pp]=b[i][j];
        }
    }
}
int main (){
    int n,i,j ;
    clock_t start_x,end_x,total_x;
    printf("enter the number of elements \n");
    scanf("%d",&n);int a[100],b[10][100];
    printf("\nenter the number of elements\n");
    for(i=0;i<n;i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    bucketsort(a,n,b);
    printf("Sorted list is: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
