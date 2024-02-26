#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If the next smallest element is from the right half,
            // increment inversion count by the remaining elements in the left half.
            inversionCount += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inversionCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inversionCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursive calls for left and right halves
        inversionCount += mergeSortAndCount(arr, temp, left, mid);
        inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Merge the two halves and count inversions
        inversionCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return inversionCount;
}

int countInversions(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int inversionCount = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return inversionCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversionCount = countInversions(arr, n);

    printf("%d\n", inversionCount);

    return 0;
}
