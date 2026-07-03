#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
 scanf("%d",&n);
int *a;
 a = (int*)malloc(sizeof(int)*n);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int sum = 0;
 for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
 for(int i=0;i<n;i++){
    sum+=a[i];
}
double avg = (double)sum/n;
printf("\nAverage = %.2lf",avg);
return 0;
      }