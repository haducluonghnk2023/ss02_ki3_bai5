#include<stdio.h>
int main(){
	int n,k;
 	do {
        printf("Nhap so luong phan tu trong mang (0 < n <= 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("So luong phan tu trong mang phai trong khoang tu 1 den 100.\n");
        }
    } while (n <= 0 || n > 100);

    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for(int i=0;i<n;i++){
    	printf("phan tu [%d]",i);
    	scanf("%d",&arr[i]);
	}
	printf("Nhap phan tu k can xoa: ");
    scanf("%d", &k);
    int i=0;
	for( i=0;i<n;i++){
		if(arr[i]==k){
			for(int j=i;j<n-1;j++){
				arr[j]=arr[j+1];
			}
			n--;
			break;
		}
	}
	if (i < n) { 
        printf("Phan tu %d da duoc xoa. Mang sau khi xoa:\n", k);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", k);
    }
	return 0;
}
