// NOT IMPLEMENTING INT -> STRING BUT IT IS RATHER SIMPLE. YOU JUST STORE KEY, PTR TO STRING, POINTER TO NEXT ELEMENT IN THE CHAIN. 
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


void add(int x, int val)
{
    int p = hash(x);
    if (table[p] == NULL)
    {
        int* q = malloc(3 * sizeof(int));  // Allocate space for 2 integers
        table[p] = q;

        /* why we did table[p] = q and not table[p] = q[0] ?
        q is the pointer to the start of the allocated memory (the address).
        q[0] dereferences that pointer and gives the value stored at the address q.
        we could've done table[p] = &q[0]
        */

        q[0] = x;  // Store key at index 0
        q[1] = val;  // Store value at index 1
        q[2] = NULL;  // End of chain (NULL)
    }
    else
    {
        int* y = table[p];
        while (y)
        {
            if (y[0] == x)
            {
                y[1] = val;  // Update value
                return;  // Value already exists
            }
            else
            {
                y = (int*)y[2];  // Move to next item in the chain
            }
        }
        if (y == NULL)
        {
            int* q = malloc(3 * sizeof(int));  // Allocate space for a new entry
            y = q;
            q[0] = x;
            q[1] = val;
            q[2] = NULL; 
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
            add(y[0],y[1]);  // Reinsert old value
            y = (int*)y[2];  // Move to next element in the chain
        }
    }
    free(old_table);
}


int fetch(int x)
{
    int p = hash(x);
    int* y = table[p];
    while (y)
    {
        if (y[0] == x)
        {
            return y[1];  // Value found
        }
        else
        {
            y = (int*)y[2];  // Move to next item in the chain
        }
    }
    return 0;  // Value not found
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
                table[p] = (int*)y[2];  // Update head of chain
            }
            else
            {
                prev[2] = y[2];  // Update previous node
            }
            free(y);  // Free memory
            return;
        }
        else
        {
            prev = y;
            y = (int*)y[2];  // Move to next item in the chain
        }
    }
}


int main() {
    // Initialize the table
    table = malloc(table_size * sizeof(int*));
    for (int i = 0; i < table_size; i++) {
        table[i] = NULL;
    }
    
    
    add(1,2);
    add(2,3);
    add(2,4);
    delete(1);
    
    printf("%d\n",fetch(2));
    
    return 0;
} 