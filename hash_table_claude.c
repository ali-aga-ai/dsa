#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#define _POSIX_C_SOURCE 199309L
#include <unistd.h>
#endif

int table_size = 2;
int count = 0;
int** table;

// Hash table functions remain the same
void rehash();
int hash(int x) {
    return x % table_size;
}

void add(int x) {
    int p = hash(x);
    if (table[p] == NULL) {
        int* q = malloc(2 * sizeof(int));
        table[p] = q;
        q[0] = x;
        q[1] = 0;
        count++;
    } else {
        int* current = table[p];
        int* prev = NULL;
        while (current != NULL) {
            if (current[0] == x) {
                return;
            }
            prev = current;
            current = (int*)current[1];
        }
        int* q = malloc(2 * sizeof(int));
        q[0] = x;
        q[1] = 0;
        prev[1] = (int)q;
        count++;
    }
    
    if (count > 2 * table_size) {
        rehash();
    }
}

void rehash() {
    int** old_table = table;
    int old_size = table_size;
    table_size *= 2;
    
    table = malloc(table_size * sizeof(int*));
    for (int i = 0; i < table_size; i++) {
        table[i] = NULL;
    }
    
    count = 0;
    
    for (int i = 0; i < old_size; i++) {
        int* current = old_table[i];
        while (current != NULL) {
            add(current[0]);
            int* next = (int*)current[1];
            free(current);
            current = next;
        }
    }
    
    free(old_table);
}

int fetch(int x) {
    int p = hash(x);
    int* current = table[p];
    
    while (current != NULL) {
        if (current[0] == x) {
            return 1;
        }
        current = (int*)current[1];
    }
    return 0;
}

// Cross-platform timing function
long long get_time_ns() {
#ifdef _WIN32
    LARGE_INTEGER frequency;
    LARGE_INTEGER time;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return (1000000000 * time.QuadPart) / frequency.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec;
#endif
}

int main() {
    // Initialize the table
    table = malloc(table_size * sizeof(int*));
    for (int i = 0; i < table_size; i++) {
        table[i] = NULL;
    }
    
    // Start timing
    long long start_time = get_time_ns();
    
    // Operations to time
    add(1);
    add(2);
    
    
    // End timing
    long long end_time = get_time_ns();
    
    // Calculate elapsed time
    long long elapsed_ns = end_time - start_time;
    
    // Print results in different time units
    printf("Time elapsed: %lld nanoseconds\n", elapsed_ns);
    printf("Time elapsed: %.3f microseconds\n", elapsed_ns / 1000.0);
    printf("Time elapsed: %.3f milliseconds\n", elapsed_ns / 1000000.0);
    
    return 0;
}