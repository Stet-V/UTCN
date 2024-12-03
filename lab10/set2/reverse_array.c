#include <stdio.h>

void reverse_array(int *a, int n) {
    if (n < 2)
        return;
    int temp = a[0];
    a[0] = a[n - 1];
    a[n - 1] = temp;
    reverse_array(a + 1, n - 2); 
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    reverse_array(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}