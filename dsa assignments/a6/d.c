// NOT WORKING, FOR TROUBLESHOOTING CHECK WHICH PART ISNT WORKING FIRST
#include <stdio.h>
#include<stdlib.h>
int k;
void merge(int* a, int n, int* b, int m, int* result) {
    int i = 0, j = 0, p = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            result[p++] = a[i++];
        } else {
            result[p++] = b[j++];
        }
    }

    while (i < n) {
        result[p++] = a[i++];
    }

    while (j < m) {
        result[p++] = b[j++];
    }
}




void insertionSort(int* beg, int* end){
    
    for(int i=1;i<k;i++){
        int j=i;
        while(j>0 && beg[j-1]>beg[j]){
            int temp = beg[j];
            beg[j] = beg[j-1];
            beg[j-1] = temp;
            j--;
        }
    }
}


int main() {
    int n;
    
    scanf("%d %d",&n,&k);
    
    int* a  = malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int* temp  = malloc(n*sizeof(int));
    
    int p =n;
    
    for(int i=0;i<(n/k);i++){
        insertionSort(a[k*i],a[k*(i+1)]);
    }
    
    printf("done ");
    
    int i=1;
    while(i<n){
        int c=k*i;
        p =n;
        while(p>0){
            merge(temp,k,temp+c,k,temp);
            a+=2*c;
            p/=2*i;
        }
        temp =a;
        i*=2;
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}