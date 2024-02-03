#include <gmp.h>
#include <assert.h>
#include <stdio.h>

int square() {
    mpz_t n1;
    mpz_t n2;
    mpz_t n;

    int flag;
    char inputStr1[1024];
    char inputStr2[1024];

    // Get input from the user
    printf("Enter first number: ");
    scanf("%1023s", inputStr1);

    printf("Enter second number: ");
    scanf("%1023s", inputStr2);

    // Initialize and set values for n1 and n2
    // Initialize and set values for n1 and n2
    mpz_init_set_str(n1, inputStr1, 10);
    mpz_init_set_str(n2, inputStr2, 10);

    // Multiply n1 and n2, store the result in n
    mpz_init(n);
    mpz_mul(n, n1, n2);

    // Output the result
    printf("ans = ");
    mpz_out_str(stdout, 10, n);
    
    // Clear resources
    mpz_clear(n1);
    mpz_clear(n2);
    mpz_clear(n);

    return 0;
}
