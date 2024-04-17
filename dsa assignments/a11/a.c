//not correct prolly gotta set initial thing to identtity
#include <stdio.h>

void multiply(int n, int a[][n], int b[][n]){
    int result[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            result[i][j] = 0;
            for(int k=0; k<n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // Copy the elements of the result matrix back to array a
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = result[i][j];
        }
    }
}



int main(){

    int n,p;
    scanf("%d",&n);
    scanf("%d",&p);

    int a_initial[n][n];
    int a[n][n];
    int ans[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
            a_initial[i][j] = a[i][j];
            ans[i][j] = a[i][j];
    }}

    int t=0;

    while(t<=p-1){
        if(t==p-1){
            break;
        }
        int temp = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j] = a_initial[i][j];
            }}
        while(temp<p-t){
            multiply(n,a,a);
            temp*=2;
        }
        t+=temp;
        multiply(n,ans,a);

    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}



