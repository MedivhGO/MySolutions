//https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
#include <stdio.h>
void update(int *a,int *b) {
    // Complete this function
    int tmpa = *a;
    int tmpb = *b;
    int resb;
    *a = tmpa+tmpb;
    if(tmpa-tmpb >= 0)
          resb = tmpa-tmpb;
    else
          resb = -(tmpa-tmpb);
    *b = resb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
