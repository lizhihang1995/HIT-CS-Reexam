# C 语言编程题

计算 $$a+aa+...+aa...a$$(n个a)，n 和 a 的值由键盘输入。

```c
int main() {
    long term = 0, sum = 0;
    int n, a;
    scanf("%d %d", &n, &a);
    for(int i = 0; i < n; i++) {
        term = term * 10 + a;
        sum += term;
    }
    printf("%ld", sum);
    return 0;
}
```

计算 $$1-1/2+1/3-1/4+...$$ 直到最后一项的绝对值小于 $$10^{-4}$$。

```c
int main() {
    int sign = 1; // 符号
    int counter = 1; // 分母
    double term = 1, sum = 0;
    while(fabs(term)>=pow(10, -4)) {
        term = (double)sign / counter;
        sum += term;
        sign = -sign;
        counter++;
    }
    printf("%f\n", sum);
    return 0;
}
```

