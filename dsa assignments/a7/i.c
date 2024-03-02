#include <stdio.h>
// Bubble Sort function
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    
    int n,k;
    
    int alph_freq[26];
    
    for(int i=0; i<26; i++){
       alph_freq[i] =0;
    } 
    
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    char a[n];
    
    for(int i=0; i<n; i++){
        
        scanf(" %c",&a[i]);// needs to caprue newline and space elements
        
        alph_freq[a[i] - 'a']++;
        
    }
    
    
    sort(alph_freq,26);
    
    int ans=0;
    
    for(int i=0; i<26 ; i++){
        if(alph_freq[i]!=0 && k>0 && k>=alph_freq[i]){
            ans+=alph_freq[i]*alph_freq[i];
            k-=alph_freq[i];
        }
        
        else if(alph_freq[i]!=0 && k>0 && k<alph_freq[i]){
            ans+=k*k;
            k-=k;
        }
    }
    
    printf("%d ",ans);
    
    return 0;
}