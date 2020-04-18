# 杭电 OJ 刷题记录——Day 6

|   题号   | 1108 | 1713 |  1717  | 1722 | 2064 | 2077 | 2136 | 2138 | 2504 |
| :------: | :--: | :--: | :----: | :--: | :--: | :--: | :--: | :--: | :--: |
| **结果** |  AC  |  AC  | **WA** |  AC  |  AC  |  AC  |  AC  |  AC  |  AC  |

**1108**——最小公倍数：以较大数为基准，每次加一倍检验能否被较小数整除。

```c
#include <stdio.h>
#define N 1000

int main() {
    int num1, num2;
    while(scanf("%d %d", &num1, &num2) != EOF) {
        int big, small;
        if(num1 >= num2) {
            big = num1;
            small = num2;
        } else {
            big = num2;
            small = num1;
        }
        for(int i = 1; i < N; i++) {
            if((big * i) % small == 0) {
                printf("%d\n", big * i);
                break;
            }
        }
    }
    return 0;
}
```

**1713**——求两卫星的相遇周期，实际上是求两卫星公转周期的最小公倍数，而因为公转周期是分数，所以就是求两个分数的最小公倍数。🚥 要用大整数类型。

```c
#include <stdio.h>

__int64 Gcd(__int64, __int64);

/*
 * 计算两个分数的最小公倍数：
 * 1.化简两个分数为最简形式——分子分母同除以其最大公约数
 * 2.分子为两个分子的最小公倍数
 * 3.分母为两个分母的最大公约数
 * 公式：a*b = 最大公约数*最小公倍数
*/
int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        __int64 numerator1, denominator1,
            numerator2, denominator2;
        scanf("%I64d/%I64d %I64d/%I64d", &numerator1, &denominator1,
                &numerator2, &denominator2);
        // 将两个分数化为最简形式
        __int64 gcd1 = Gcd(numerator1, denominator1);
        __int64 gcd2 = Gcd(numerator2, denominator2);
        numerator1 /= gcd1;
        denominator1 /= gcd1;
        numerator2 /= gcd2;
        denominator2 /= gcd2;
        // 求两个分子的最小公倍数
        __int64 resultNumerator = numerator1 * numerator2 / Gcd(numerator1, numerator2);
        // 求两个分母的最大公约数
        __int64 resultDenominator = Gcd(denominator1, denominator2);
        // 输出(经过上述计算，结果已经最简)
        if(resultNumerator % resultDenominator == 0)
            printf("%I64d\n", resultNumerator/resultDenominator);
        else
            printf("%I64d/%I64d\n", resultNumerator, resultDenominator);
    }
    return 0;
}

// 最大公约数——辗转相除
__int64 Gcd(__int64 num1, __int64 num2) {
    if(num2 == 0) return num1;
    return Gcd(num2, num1 % num2);
}
```

**1717**——小数转分数，艹，在本地可以，提交就出错系列。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int Gcd(int num1, int num2);
int MyPower(int x, int n);

/*
 * 将纯小数转化为最简分数
 * 分成三种情况：
 * (1)普通小数：0.123——分子=小数点后面的数(共n位)，分母是10^n。123/10^3
 * (2)纯循环小数：0.(12)——分子=循环数(共n位)，分母是999...(n位)。12/99
 * (3)部分循环小数：0.12(34)——分子=整个小数部分的数-不循环部分的数，
 *    如果循环部分位数为 m，非循环部分位数为 n，则分母为 999...(m位)000...(n位)。
 *    0.12(345)就变为 (12345-12)/99900.
 */
int main() {
    int caseCount;
    char inputStr[N];
    scanf("%d", &caseCount);
    getchar();
    while(caseCount--) {
        gets(inputStr);
        int numerator, denominator;
        int inputLength = strlen(inputStr);
        if(!strchr(inputStr, '(')) { // 普通不循环小数
            // 计算分子分母
            int decimalCount = inputLength-2;
            char *p = inputStr+2;
            int inputNum = atoi(p);
            numerator = inputNum;
            denominator = MyPower(10, decimalCount);
        } else if(inputStr[2] == '(') { // 纯循环小数
            // 将右括号从数组中删除
            inputStr[inputLength-1] = '\0';
            // 计算分子分母
            char *p = inputStr+3;
            int inputNum = atoi(p);
            numerator = inputNum;
            denominator = MyPower(10, inputLength-4)-1;
        } else { // 部分循环小数
            // 区分出非循环部分和循环部分
            char noneCycleStr[N], cycleStr[N];
            int i, j = 0, k = 0;
            for(i = 2; i <= inputLength; i++) {
                if(inputStr[i] != '(')
                    noneCycleStr[j++] = inputStr[i];
                else {
                    noneCycleStr[j] = '\0';
                    break;
                }
            }
            for(i = i+1; i < inputLength-1; i++) {
                cycleStr[k++] = inputStr[i];
            }
            cycleStr[k] = '\0';
            // 计算分子分母
            int noneCycleNum = atoi(noneCycleStr),
                cycleNum = atoi(cycleStr);
            int noneCycleLength = strlen(noneCycleStr),
                cycleLength = strlen(cycleStr);
            numerator = noneCycleNum * MyPower(10, cycleLength) + cycleNum - noneCycleNum;
            denominator = (MyPower(10, cycleLength) - 1) * MyPower(10, noneCycleLength);
        }
        // 化简分子分母
        int gcd = Gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        // 输出
        printf("%d/%d\n", numerator, denominator);
    }
    return 0;
}

// 最大公约数——用于分数约分
int Gcd(int num1, int num2) {
    if(num2 == 0) return num1;
    return Gcd(num2, num1 % num2);
}

// 计算 x^n
int MyPower(int x, int n) {
    int pow = 1;
    for(int i = 0;i < n; i++)
        pow *= x;
    return pow;
}
```

**1722**——切蛋糕：数学问题

```c
#include <stdio.h>

int Gcd(int, int);
int main() {
    /*
     * 将蛋糕分为 p 份，和将蛋糕分为 q 份，
     * 切到相同位置的刀数即是 p 和 q 的最大公约数 gcd(p, q)，是重复的，
     * 因此，所求即为 p+q-gcd(p, q)。
     */
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        int gcd = Gcd(m, n);
        printf("%d\n", m + n - gcd);
    }
    return 0;
}

int Gcd(int m, int n) {
    if(n == 0) return m;
    return Gcd(n, m % n);
}
```

**2064**——汉诺塔III：每次只能移到中间杆或从中间杆移出，求出把 N 个盘从最左移到最右的最少移动次数。这是一个 **动态规划问题**，把 N 个盘从1移到3，需要以下步骤：

1. 上面 N-1 个盘从 1 **间接** 移到 3，需要 f(n-1) 步；
2. 把 N 号盘从 1 移到 2，需要 1 步；
3. 把上面 N-1 个盘从 3 **间接** 移到 1，需要 f(n-1) 步；
4. 把 N 号盘从 2 移到 3，需要 1 步；
5. 把上面 N-1 个盘从 1 **间接** 移到 3，需要 f(n-1) 步。

所以，一共需要移动步数为 **f(n) = 3 * f(n-1) + 2，f(1) = 2**。

```c
#include <stdio.h>
#define N 36

__int64 H[N];
int main() {
    H[0] = 0; H[1] = 2;
    for(int i = 2; i < N; i++) {
        H[i] = 3 * H[i-1] + 2;
    }
    int n;
    while(~scanf("%d", &n))
        printf("%I64d\n", H[n]);
    return 0;
}
```

**2077**——汉诺塔IV，在 2064 基础上，允许 **最大的那个盘在其他盘上面**，求最小移动次数。

不能像普通汉诺塔那样关注 **整体的结束位置**，而要关注 **一根杆移到相邻杆**。所以原问题可以转为两步，即整体移到相邻杆两次。实现移动到相邻杆的步骤为：

1. n-1 从最左移到中间；f(n-1)
2. n-1 从中间再到最右；f(n-1)
3. n 从最左移到中间；1
4. n-1 再从最右回到中间。f(n-1)

至此移动到相邻杆完成，**f(n) = 3 * f(n-1) + 1, f(1) = 1**.

而 **原始问题** 需要：

1. 将 n-1 移动到中间；f(n-1)
2. 将 n 移动到中间，再移到最右；2
3. 将 n-1 移动到最右。f(n-1)

由此得出：**F(n) = 2 * f(n-1) + 2, f(1) = 2**.

```c
#include <stdio.h>
#define N 30

__int64 midH[N] = { 0 }, H[N] = { 0 };
int main() {
    midH[1] = 1;
    H[1] = 2;
    for(int i = 2; i < N; i++) {
        midH[i] = 3 * midH[i-1] + 1;
        H[i] = 2 * midH[i-1] + 2;
    }
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        int n;
        scanf("%d", &n);
        printf("%I64d\n", H[n]);
    }
    return 0;
}
```

**2136**——高效生成素数表——素数筛选法

素数筛选法是一种空间换时间的方法，时间复杂度为线性，原理是 **标记以避免重复判断**——从 2 开始，将 2 的所有倍数都标记上，往后就无需判断这些被标记的数；然后标记 3 的倍数，以此类推。

这道题是要求出 **X 的最大素因数是第几个素数**，把素数筛选法稍微变化一点就可以求解。创建数组 `int a[MAX]`，在标记非素数位置的同时，用 `count` 保存已经出现的素数的个数，并用 `count` 逐个为每一个元素赋值：如果 `a[i] == 0` 表示 `i` 为素数，令 `count++`，对于所有 `i` 的倍数 `j`，`a[j]=count`。(**最后那个能被 j 整除的 i 就是 j 的最大素因数**)

```c
#include <stdio.h>
#define N 1000001

int prime[N] = { 0 }; // 保存每个数的最大素因数在所有素数中的位置
int main() {
    // 设置 prime 数组
    int count = 0;
    for(int i = 2; i < N; i++) {
        if(prime[i] == 0) {
            count++;
            for(int j = i; j < N; j += i)
            	prime[j] = count;
        }
    }
    int x;
    while(scanf("%d", &x) != EOF) {
        printf("%d\n", prime[n]);
    }
    return 0;
}
```



**2138**——素数判定：注意有多组(而非仅一组)测试数据。

```c
#include <stdio.h>
#include <math.h>

int IsPrime(int num);
int main() {
    int numCount;
    while(scanf("%d", &numCount) != EOF) {
        int primeCount = 0;
        for(int i = 0; i < numCount; i++) {
            int num;
            scanf("%d", &num);
            if(IsPrime(num)) primeCount++;
        }
        printf("%d\n", primeCount);
    }
    return 0;
}

int IsPrime(int num) {
    if(num < 2) return 0;
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0)
            return 0;
    return 1;
}
```

**2504**——最大公约数：已知两个数的最大公约数和其中一个数，求另一个数的最小值。

从最大公约数 `gcd` 的二倍开始，依次检查 `gcd` 的倍数 `i` 是否满足条件——`Gcd(a, i) == gcd`

```c
#include <stdio.h>
#define N 1000001

int Gcd(int, int);
int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        int a, gcd, c;
        scanf("%d %d", &a, &gcd);
        // 注意条件是 c != b
        for(int i = gcd + gcd; i < N; i += gcd) {
            if(Gcd(a, i) == gcd) {
                c = i;
                break;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}

int Gcd(int num1, int num2) {
    if(num2 == 0) return num1;
    return Gcd(num2, num1 % num2);
}
```

