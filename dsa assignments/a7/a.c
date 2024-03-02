//Radix Sort(figure 'd' part and add it)
//one method, add zeros before
//INCOMPLETE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



void countSort(int* a, int d, int n){
    
    for(int i=0;i<n;i++){
        
    }
       
}

void radixSort(int* a, int n, int d){
    
    
    for(int i=0; i<d ; i++){
        countSort(a,d,n);//countSort for every element in array a ka d digit
    }
    
}


void appendZeros(char str[], int numberOfZeros) {
    int length = strlen(str);

    // Shift existing characters to make space for zeros
    for (int i = length; i > 0; i--) {
        str[i + numberOfZeros - 1] = str[i - 1];
    }

    // Add zeros at the beginning
    for (int i = 0; i < numberOfZeros; i++) {
        str[i] = '0';
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    
    char strings[n][11];//a pointer which points to n strings
    
    for(int i=0;i<n;i++){
        scanf("%10s",&strings[i]);// copy at most 10 strings
        appendZeros(strings[i], 10-strlen(strings[i]));
    }
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }
    
    //radixSort(a,n);
    
    
    return 0;
}