#include<Stdio.h>
#include<gmp.h>

int main(){
    char inputStr1[1024];
    mpz_t n1;
    int count;


        printf("Enter first number: ");
    scanf("%1023s", inputStr1);

    mpz_init_set_str(n1, inputStr1, 10);



   for (i=0; i < 3000; ++i){

       if (n1 %2 == 0)
          printf ("0");
       else{
          printf("1");
          count++;
       }
       n1/=2; // Shift right by 1

   }
    printf("%d", count);
    return 0;
}