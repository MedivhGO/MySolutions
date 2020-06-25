//https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int i;
    long lg;
    long long llg;
    char c;
    float fl;
    double dl;
    scanf("%d %ld %lld %c %f %lf",&i,&lg,&llg,&c,&fl,&dl);
    printf("%d\n%ld\n%lld\n%c\n%f\n%lf\n",i,lg,llg,c,fl,dl);
    return 0;
}
