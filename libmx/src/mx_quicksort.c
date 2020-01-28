#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int pivot = (right - left) / 2 + left;
    int i;
    int j;
    int count = 0;
    int newL = left;
    int newR = right;

    while (newL <= newR) {
        for (i = left; i <= right; i++) {
            if (mx_strlen(arr[i]) > mx_strlen(arr[pivot]) || i == pivot) {
                newL = i;
                break;
            }
        }
        for (j = right; j >= left; j--) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[pivot]) || j == pivot) {
                newR = j;
                break;
            }
        }
        if (i == pivot && newR != pivot) {
            newL = i;
            pivot = newR;
        }
        else if (j == pivot && newL != pivot) {
            newR = j;
            pivot = newL;
        }
        if (newL != newR) {
            mx_swap_str(&arr[newL], &arr[newR]);
            count++;
        }
        newL++;
        newR--;
    }
    newL = pivot + 1;
    newR = pivot - 1;
    if (left < newR)
        count = count + mx_quicksort(arr, left, newR);
    if (newL < right)
        count = count + mx_quicksort(arr, newL, right);
    return count;
}
