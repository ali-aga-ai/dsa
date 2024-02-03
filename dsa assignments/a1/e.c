#include <stdio.h>
#include <stdbool.h>
#include <gmp.h>

int main() {
    mpz_t n, b, kb, modul, p;
    int k = 1;
    char inputStr1[1024], inputStr2[1024];

    // Get input values for n and b
    printf("Enter N: ");
    scanf("%1023s", inputStr1);

    printf("Enter B: ");
    scanf("%1023s", inputStr2);

    // Initialize and set values for n and b
    mpz_init_set_str(n, inputStr1, 10);
    mpz_init_set_str(b, inputStr2, 10);

    mpz_init(kb);
    mpz_init(modul);
    mpz_init(p);

    while (1) {
        // Calculate kb = k * b + 1
        mpz_mul_ui(kb, b, k);
        mpz_add_ui(kb, kb, 1);

        // Calculate modul = kb % n
        mpz_mod(modul, kb, n);

        // Check if modul is zero
        if (mpz_cmp_ui(modul, 0) == 0) {
            // Calculate p = kb / n
            mpz_divexact(p, kb, n);

            // Print the result
            gmp_printf("Passcode: %Zd\n", p);
            break;
        }

        k++;
    }

    // Cleanup and free memory
    mpz_clear(n);
    mpz_clear(b);
    mpz_clear(kb);
    mpz_clear(modul);
    mpz_clear(p);

    printf("Hello World\n");

    return 0;
}
