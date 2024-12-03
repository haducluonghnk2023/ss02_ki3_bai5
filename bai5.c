#include <stdio.h>
#include <stdlib.h>

void deleteElementArray(int **arr, int *n, int position) {
    for (int i = position; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = (int *)realloc(*arr, (*n - 1) * sizeof(int));
    (*n)--;
}

int findPosition(int *arr, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int n, value, position;
    int *pArray = NULL;

    do {
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("So luong phan tu cua mang nam tu 1 den 100.\n");
        }
    } while (n <= 0 || n > 100);

    pArray = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &pArray[i]);
    }

    printf("Nhap gia tri can xoa: ");
    scanf("%d", &value);

    position = findPosition(pArray, n, value);
    if (position == -1) {
        printf("Gia tri %d khong ton tai trong mang.\n", value);
    } else {

        while ((position = findPosition(pArray, n, value)) != -1) {
            deleteElementArray(&pArray, &n, position);
        }
        printf("\nMang sau khi xoa gia tri:\n");
        if (n == 0) {
            printf("Mang rong.\n");
        } else {
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, pArray[i]);
            }
        }
    }

    free(pArray); 
    return 0;
}
