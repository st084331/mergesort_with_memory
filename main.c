#include <stdio.h>
#include <stdlib.h>

int compar(int *elem1, int *elem2) {
    if (*elem1 < *elem2) {
        return 1;
    } else if (*elem1 > *elem2){
        return 0;
    } else{
        return 2;
    }
}

void merge(int *a, size_t num, size_t size, int (*compar)(int *, int *)) {
    {
        int mid = num / 2;
        if (num % 2 == 1)
            mid++;
        int h = 1;
        int *c = (int *) malloc(num * size);
        int step;
        while (compar(&h, (int *) &num) == 1) {
            step = h;
            int i = 0;
            int* j = malloc(size);
            *j = mid;
            int k = 0;
            while (compar(&step, &mid) != 0) {
                int mid_and_step = mid + step;
                while (compar(&i, &step) == 1 && compar(j, (int *) &num) == 1 && compar(j, &mid_and_step) == 1) {
                    if (compar(a+i, a+(*j)) == 1) {
                        c[k] = *(a+i);
                        i++;
                        k++;
                    } else {
                        c[k] = *(a+(*j));
                        (*j)++;
                        k++;
                    }
                }
                while (compar(&i, &step) == 1) {
                    c[k] = a[i];
                    i++;
                    k++;
                }
                while (compar(j , &mid_and_step) == 1 && compar(j, (int *) &num) == 1) {
                    c[k] = a[*j];
                    (*j)++;
                    k++;
                }
                step = step + h;
            }
            h = h * 2;
            for (i = 0; i < num; i++)
                a[i] = *(c+i);
        }
    }
}

int main() {
    int a[8];
    for (int i = 0; i < 8; i++)
        a[i] = rand() % 20 - 10;
    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");
    merge(a, 8, sizeof(int), (int (*)(int *, int *)) compar);
    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");
    getchar();

    return 0;
}
