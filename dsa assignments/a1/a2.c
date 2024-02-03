#include<stdio.h>


char str1[1000];
char str2[1000];
int sum, len1= 0,len2= 0;
int carry_next =0;
int p,q;
int p_temp,q_temp;


int mult(char a, char b){

    int answer = (a -'0')*(b-'0');

    return answer;
}
int main(){

    scanf("%s",str1); //NO NEED FOR &str1
    scanf("%s",str2);
    
    for(int i = 0 ; i< 999 ; i++){
        if(str1[i]!='\0'){len1++;} // DO NOT USE " " FOR CHARS RATHER USE ' '
        else{break;}
    }
    
    for(int i = 0 ; i< 999 ; i++){
        if(str2[i]!='\0'){len2++;}
        else{break;}
    }
    
    int len = len1*len2;
    char ans[len];
    char carry[len];
    


    for(int i =1; i<=len ; i++ ){
        sum = 0;
        p = 1000-i;
        q =1000;
        
        if(len1>len2){
            
            while(q_temp>=1000 - len1 && p_temp<=1000){
                
                if(i>len2){
                    
                    int diff = i -len2;
                    p = 1000 - i+diff;
                    q = 1000 - diff;
                }
                p_temp = p;
                q_temp =q;
                sum+= mult(str2[p_temp++], str1[q_temp--]);
                }
            sum += carry[len - i];
            
            carry[len - i-1] = sum/10;
            ans[len - i] = sum%10;
            
            }
        printf("%d", ans[len-i]);    
            
        }
        
        return 0;
    }
    
    
   