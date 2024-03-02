// learn insertion sort properly
//temp is there just to transfer all info in the end into the main array
// in this, instead of my idea of grouping up k sized elements what it does is the merge sort technique. start big, go smaller.
// now if the lemgth of the smaller shit is lesser than or equal to k do insertion sort
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int temp[], int left, int right, int k) {
    if (left < right) {
        if (right - left + 1 <= k) {//MAIN CONDITION
            insertionSort(arr + left, right - left + 1);
        } else {
            int mid = left + (right - left) / 2;
            mergeSort(arr, temp, left, mid, k);
            mergeSort(arr, temp, mid + 1, right, k);
            merge(arr, temp, left, mid, right);
        }
    }
}

void hybridSort(int arr[], int n, int k) {
    int* temp = (int*)malloc(n * sizeof(int));
    mergeSort(arr, temp, 0, n - 1, k);
    free(temp);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    hybridSort(arr, n, k);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
