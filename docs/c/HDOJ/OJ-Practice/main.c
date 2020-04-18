#include <stdio.h>
#include <math.h>
#define N 20

int main() {
    double x;
    scanf("%lf", &x);
    double term = x, sum = 0;
    int sign = 1, counter = 1;
    while(fabs(term) >= 1e-5) {
        term = sign * pow(x, counter) / factorial[counter];
        sum += term;
        counter += 2;
        sign = -sign;
    }
    printf("%f\n", sum);
    return 0;
}
