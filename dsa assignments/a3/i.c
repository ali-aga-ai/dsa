#include<stdio.h>
#include<gmp.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[n];

    mpz_t mod_num, product,base, result;

    mpz_set_si(product, 1);  

    mpz_set_si(mod_num, 1000000007);  
    

   for (int i=0; i < n; ++i){

        scanf("%d",&a[i]);
   }
   

   
   int count =0;
    for (int i=0; i < n; ++i){
        
        int c=0;
        
        for(int j=2; j*j<a[i]; j++){
            if(a[i]%j==0){
                c=1;
                count++;
                break;
            }
        }
       
        if(a[i]==4){ // cuz rt 4 =2 
            c=1;
        }
        if(c){//if not prime
           
            mpz_set_si(base, a[i]);
   
            mpz_mul(product, product, base);    
        }
        

   }
   if(count==0){
       printf("%d",-1);
       return 0;
   }
    mpz_mod(product, product, mod_num);

   
   mpz_out_str(stdout, 10, product);
   
   
    printf("\n");

    // Don't forget to free the allocated memory
    mpz_clears(base, product, NULL);
    return 0;
}


//mpz_set_si for setting string to integer value
//mpz_ t is the string/ 