#include<stdio.h>
#include<gmp.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[n];
    int b[n];
    
    mpz_t mod_num, product, base, exponent, result;

    mpz_set_si(product, 1);  

    mpz_set_si(mod_num, 1000000007);  
    

   for (int i=0; i < n; ++i){

       scanf("%d",&a[i]);

   }
   
     for (int i=0; i < n; ++i){

       scanf("%d",&b[i]);

   }
   
   
    for (int i=0; i < n; ++i){
    
        mpz_set_si(base, a[i]);   // Replace with your base integer
        mpz_set_ui(exponent, b[i]);  // Replace with your exponent integer

        mpz_pow_ui(result, base, mpz_get_ui(exponent));
        
        mpz_mul(product, product, result);


   }
   
    mpz_mod(product, product, mod_num);

   
   mpz_out_str(stdout, 10, product);
   
   
    printf("\n");

    // Don't forget to free the allocated memory
    mpz_clears(base, exponent, result, product, NULL);
    return 0;
}