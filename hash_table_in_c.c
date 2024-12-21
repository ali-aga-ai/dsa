
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int table_size = 2;
int count = 0;
int** table;  // Changed to a pointer to a pointer array

void rehash();

int hash(int x)
{
    return x % table_size;
}


void add(int x)
{
    int p = hash(x);
    if (table[p] == NULL)
    {
        int* q = malloc(2 * sizeof(int));  // Allocate space for 2 integers
        table[p] = q;

        /* why we did table[p] = q and not table[p] = q[0] ?
        q is the pointer to the start of the allocated memory (the address).
        q[0] dereferences that pointer and gives the value stored at the address q.
        we could've done table[p] = &q[0]
        */

        q[0] = x;  // Store value at index 0
        q[1] = NULL;  // End of chain (NULL)
    }
    else
    {
        int* y = table[p];
        while (y)
        {
            if (y[0] == x)
            {
                return;  // Value already exists
            }
            else
            {
                y = (int*)y[1];  // Move to next item in the chain
            }
        }
        if (y == NULL)
        {
            int* q = malloc(2 * sizeof(int));  // Allocate space for a new entry
            y = q;
            q[0] = x;
            q[1] = NULL;
            count++;
            
        }
    }
    if (count > 2 * table_size)
            {
                rehash();  // Rehash if table size exceeds twice the number of elements
            }
}

void rehash(){
    int** old_table = table;
    table = malloc(2 * table_size * sizeof(int*));  ///since table is a pointer to an array of pointers, we need to allocate 2*table_size*sizeof(int *) bytes of memory
    int old_size = table_size;
    table_size = 2 * table_size;

    // Initialize new table entries to NULL
    for (int i = 0; i < 2 * table_size; i++) {
        table[i] = NULL;  // Initialize to NULL (zero for pointers)
    }

    for (int i = 0; i < old_size; i++) {
        int* y = old_table[i];
        while (y) {
            add(y[0]);  // Reinsert old value
            y = (int*)y[1];  // Move to next element in the chain
        }
    }
    free(old_table);
}

void delete(int x){
    int p = hash(x);
    int* y = table[p];
    int* prev = NULL;
    while (y)
    {
        if (y[0] == x)
        {
            if (prev == NULL)
            {
                table[p] = (int*)y[1];  // Update head of chain
            }
            else
            {
                prev[1] = y[1];  // Update previous node
            }
            free(y);  // Free memory
            return;
        }
        else
        {
            prev = y;
            y = (int*)y[1];  // Move to next item in the chain
        }
    }
}
int fetch(int x)
{
    int p = hash(x);
    int* y = table[p];
    while (y)
    {
        if (y[0] == x)
        {
            return 1;  // Value found
        }
        else
        {
            y = (int*)y[1];  // Move to next item in the chain
        }
    }
    return 0;  // Value not found
}

int main() {
    // Initialize the table
    table = malloc(table_size * sizeof(int*));
    for (int i = 0; i < table_size; i++) {
        table[i] = NULL;
    }
    
    clock_t start = clock();
    
    add(1);
    add(2);
    
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    
    return 0;
}