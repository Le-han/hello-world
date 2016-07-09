#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int n){
    int i;
    for (i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
}

void output(int *arr, int n){
    int i;
    for (i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n){
    int i, j, tmp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        //output(arr, n);
    }
}

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

void selection_sort(int *arr, int n){
    int i, j, min_id;
    for (i = 0; i < n - 1; i++){
        min_id = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_id]){
                min_id = j;
            }
        }
        if (min_id != i){
            int tmp = arr[min_id];
            arr[min_id] = arr[i];
            arr[i] = tmp;
        }
    }
}
/*
void quick_sort(int *arr, int first, int last){
    int i = first, j = last;
    int x = arr[(first + last) / 2];
    do{
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (arr[i] > arr[j]){
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
            j--;
        }

    } while (i <= j);
}
*/
void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];

    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;

        if(i <= j) {
            if (s_arr[i] > s_arr[j]) {
             //swap(&s_arr[i], &s_arr[j]);
             int tmp = s_arr[j];
             s_arr[j] = s_arr[i];
             s_arr[i] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}
int main()
{
    int *arr;
    int n;
    scanf("%d", &n);
    arr = (int*) malloc(sizeof(int) * n);
    input(arr, n);

    printf("BUBBLE SORT RESULT: \n");
    bubble_sort(arr, n);
    output(arr, n);

    printf("qsort RESULT: \n");
    qsort(arr, n, sizeof(int), cmp);
    output(arr, n);

    printf("SELECTION SORT RESULT: \n");
    selection_sort(arr, n);
    output(arr, n);

    printf("QUICK SORT RESULT: \n");
    qs(arr, 0, n-1);
    output(arr, n);

    free(arr);
    return 0;
}

