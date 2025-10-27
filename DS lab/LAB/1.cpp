     //       EXPERIMENT: 1 
     // ARRAY INSERTION , DELETION, TRAVERSAL
#include <stdio.h>
void traverseArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void deleteArray(int A[], int *n, int pos) {
    for (int i = pos - 1; i < *n - 1; i++) {
        A[i] = A[i + 1];
    }
    (*n)--;  // reduce size by 1
}

void insertArray(int A[], int *n, int pos, int x) {
    for (int i = *n; i >= pos; i--) {
        A[i] = A[i - 1];
    }
    A[pos - 1] = x;
    (*n)++;  // increase size by 1
}

int main() {
    int n, x, pos, delPos;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int A[100]; // static array

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("\nEnter the element to be inserted in the array: ");
    scanf("%d", &x);

    printf("Enter the position of element: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    insertArray(A, &n, pos, x);
    printf("After insertion: ");
    traverseArray(A, n);

    printf("\nEnter the position to delete: ");
    scanf("%d", &delPos);

    if (delPos < 1 || delPos > n) {
        printf("Invalid position!\n");
        return 0;
    }

    deleteArray(A, &n, delPos);
    printf("After deletion: ");
    traverseArray(A, n);

    return 0;
}
