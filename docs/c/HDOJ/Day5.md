# 杭电 OJ 刷题记录——Day5

|   题号   | 2075 | 2089 | 2090 | 2092 | 1995 | 2096-2099 |
| :------: | :--: | :--: | :--: | :--: | :--: | :-------: |
| **结果** |  AC  |  AC  |  AC  |  AC  |  AC  |    AC     |

**2075**——是否整除（极其简单）

```c
#include <stdio.h>

int main() {
    int n;
    int a, b;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        if(a % b == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```

**2089**——统计不包含 4 或 62 的非不吉利数字个数：直接暴力解决会报超时错误，需要提前把每个范围的非不吉利数字个数计算出来(总体范围为 1-1000000)，这样避免重复计算。

```c
// 暴力方法——超时错误
#include <stdio.h>

int Include4Or62(int);

int main() {
    int low, high;
    scanf("%d %d", &low, &high);
    while(!(low == 0 && high == 0)) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            if(!Include4Or62(i))
                count++;
        }
        printf("%d\n", count);
        scanf("%d %d", &low, &high);
    }
    return 0;
}

int Include4Or62(int n) {
    while(n > 0) {
        if(n % 10 == 4 || n % 100 == 62)
            return 1;
        n = n / 10;
    }
    return 0;
}
```

```c
// 预先算出每个范围非不吉利数字个数——AC
#include <stdio.h>
#define N 1000000

int NotInclude4Or62(long);

int count[N]; // 大数组定义在 main 函数外

int main() {
    // 计算数组：存储每个范围非不吉利数字个数
    count[0] = 0;
    for(long i = 1; i < N; i++) {
        count[i] = count[i-1] + NotInclude4Or62(i);
    }
    // 输入输出
    long low, high;
    scanf("%ld %ld", &low, &high);
    while(!(low == 0 && high == 0)) {
        printf("%d\n", count[high]-count[low-1]); // 注意 low-1
        scanf("%ld %ld", &low, &high);
    }
    return 0;
}

int NotInclude4Or62(long n) {
    while(n > 0) {
        // 包含 4 或 62，返回 0
        if(n % 10 == 4 || n % 100 == 62)
            return 0;
        n = n / 10;
    }
    // 不包含 4 或 62，计数加一
    return 1;
}
```

**2090**——算菜价：恶心，没有说明怎么算输入结束。

```c
#include <stdio.h>
#define N 30

int main() {
    char name[N];
    double count, price, sum = 0;
    while(scanf("%s %lf %lf", name, &count, &price) == 3) {
        char c = getchar();
        sum += count * price;
    }
    printf("%.1f\n", sum);
    return 0;
}
```

**2092**——一元二次方程的整数解

```c
#include <stdio.h>
#include <math.h>

int main() {
    /*
     * 判断方程组是否有整数解
     * (1) x + y = n;
     * (2) x * y = m;
     * 转化为一元二次方程 x^2-nx+m=0
     * delta=n^2-4m,
     * delta >= 0 则有解，进一步 delta 为完全平方数，则有整数解
    */
    int n, m;
    scanf("%d %d", &n, &m);
    while(!(n == 0 && m == 0)) {
        int delta = n * n - 4 * m;
        if(delta < 0) printf("No\n");
        else {
            double temp = sqrt(delta);
            if((int) temp == temp)
                printf("Yes\n");
            else
                printf("No\n");
        }
        scanf("%d %d", &n, &m);
    }
    return 0;
}
```

**1995**——汉诺塔，一共 n 个盘子，计算 k 号盘的移动次数。（最上面的为 1 号）

```c
#include <stdio.h>
#include <math.h>

int k;
int main() {
    int caseCount;
    int n;
    scanf("%d", &caseCount);
    while(caseCount--) {
        scanf("%d %d", &n, &k);
        /*
         * 计算在总盘数为 n 时 k 号盘一共要移动多少步
         * 容易知道 x-1 号盘的移动次数是 x 号盘的两倍
         * 而 n 号盘(最底下)只需要移动一次
         * 所以自底向上每个盘的移动次数是等比数列，公比为 2
        */
        printf("%I64d\n", (__int64)pow(2, n-k));
    }

}
```

**2096**——计算 A+B，加数和结果都保留最后两位数字：利用 `n = n % 100` 即可得出最低两位数。

```c
#include <stdio.h>

int main() {
    int caseCount;
    int num1, num2;
    scanf("%d", &caseCount);
    while(caseCount--) {
        scanf("%d %d", &num1, &num2);
        if(num1 >= 100) num1 = num1 % 100;
        if(num2 >= 100) num2 = num2 % 100;
        int sum = num1 + num2;
        sum = sum % 100;
        printf("%d\n", sum);
    }
    return 0;
}
```

**2097**——Sky 数：十进制转换为12、16进制。

```c
#include <stdio.h>

int IsSkyNumber(int);
int GetSumOfDigits(int num, int base);

int main() {
    int num;
    scanf("%d", &num);
    while(num != 0) {
        if(IsSkyNumber(num))
            printf("%d is a Sky Number.\n", num);
        else
            printf("%d is not a Sky Number.\n", num);
        scanf("%d", &num);
    }
    return 0;
}

int IsSkyNumber(int num) {
    int sumHex = GetSumOfDigits(num, 16);
    int sumDuo = GetSumOfDigits(num, 12);
    int sumDec = GetSumOfDigits(num, 10); // 十进制各位之和
    return (sumDec == sumDuo && sumDec == sumHex);
}

int GetSumOfDigits(int num, int base){
    int sum = 0;
    while(num > 0) {
        sum += num % base;
        num /= base;
    }
    return sum;
}
```

**2098**——把一个偶数拆成 **两个** 素数之和，有几种拆分方法。

```c
#include <stdio.h>
#define N 100001

int prime[N] = { 0 };
int IsPrime(int n);

int main() {
    // 初始化素数数组
    for(int i = 0; i < N; i++) {
        if(IsPrime(i)) prime[i] = 1;
    }
    int num;
    scanf("%d", &num);
    while(num != 0) {
        int groupCount = 0;
        for(int i = 3; i < num/2; i++){
            // 关键：检查对称的两个数
            if(prime[i] && prime[num-i])
                groupCount++;
        }
        printf("%d\n", groupCount);
        scanf("%d", &num);
    }
    return 0;
}

int IsPrime(int n) {
    if(n < 2 || n % 2 == 0) return 0;
    for(int i = 3; i <= n/2; i++)
        if(n % i == 0) return 0;
    return 1;
}
```

**2099**——整除：输出时，如果结果数组中某元素只有一位，需要补 0。

```c
#include <stdio.h>
#define N 100

int main() {
    int dividend, divisor;
    scanf("%d %d", &dividend, &divisor);
    while(!(dividend == 0 && divisor == 0)) {
        int low = dividend * 100,
            high = low + 99,
            result[N], j = 0;
        // 找出满足条件的数
        for(int i = low; i <= high; i++) {
            if(i % divisor == 0)
                result[j++] = i % 100;
        }
        // 输出结果数组
        for(int i = 0; i < j; i++) {
            // 如果只有一位，要在前面补 0
            if(result[i] < 10) printf("0");
            printf("%d", result[i]);
            if(i < j-1) printf(" ");
        }
        printf("\n");
        scanf("%d %d", &dividend, &divisor);
    }
    return 0;
}
```

