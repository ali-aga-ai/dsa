#include <stdio.h>
#include <stdbool.h>

bool isLeafNode(int* arr, int i, int n) {
    if (2 * i > n) {
        return true;
    }
    return arr[2 * i] == -1 && arr[2 * i + 1] == -1;
}

void removeNode(int* arr, int k, int n) {
    if (k > n) {
        return;
    }
    arr[k] = -1;
    removeNode(arr, 2 * k, n);
    removeNode(arr, 2 * k + 1, n);
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int height(int* arr, int i, int n) {
    if (i > n || arr[i] == -1) {
        return 0;
    }
    int leftHeight = height(arr, 2 * i, n);
    int rightHeight = height(arr, 2 * i + 1, n);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    int n, k, j;
    scanf("%d %d", &n, &k);
    
    int a[n + 1];
    a[0] = -1;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == k) {
            j = i;
        }
    }
    
    removeNode(a, j, n);
    
    int treeHeight = height(a, 1, n);
    printf("Height of the modified tree: %d\n", treeHeight);
    
    return 0;
}
