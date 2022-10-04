# Bubble_Sort in C
~~~
#include<stdio.h>
int main(){
    int i,j,arr[10],n,swap;
    printf("Enter the number of elements:- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element number %d :- ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    printf("\nThe new array is:- \n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    
}
~~~
