#include <stdio.h>
#include <stdlib.h>

int f(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return abs(a);
}

int f_rec(int a, int b){
    if (b == 0) return a;
    return f_rec(b, a % b);
}

int main(){
    int a, b;
    scanf ("%d %d", &a, &b);
    printf("Evklid algorithm result %d \n", f(a, b));
    printf("Evklid recursive  algorithm result %d \n", f_rec(a, b));
    return 0;
}
