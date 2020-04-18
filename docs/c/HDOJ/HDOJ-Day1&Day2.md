# 杭电 ACM 刷题记录——Day1 & Day2

## 值得(我)注意的

1. 输入用例个数不确定时，用 `while(scanf("%d", &n) != EOF)`。

2. 读入字符型数据时，一定记得 **读出回车符 `getchar()`**。

3. `gets(line)` 表示把一行输入读入 `line` 字符数组中，遇到回车结束，并自动补 `'\0'`。 

4. 小数和整数混合运算时，一定注意自动类型转换。

5. **表示结构体成员时**，结构体用 `.`，结构体指针用 `->`。

6. **数组长度 vs 数组最后一个元素下标** 时刻注意区分。

7. **大整数** 用 `__int64` 类型，输入输出控制符用 `%I64d` 表示整数，用 `%I64X` 表示十六进制，大写 X 表示用大写的 ABCDEF 表示。

8. 有时候把逻辑分出几个函数反而复杂。

9. `stdlib.h` 中的快排函数：`qsort(数组名, 数组元素个数, 每个元素字节数, 比较函数)`，**从小到大排序**。其中自定义比较函数的方法为：

   ```c
   int MyCompare(void *a, void *b) {
       MyType *a1 = (MyType *)a, 
       	   *a2 = (MyType *)b;
       // 返回正数表示 a > b, 负数表示 a < b
   }
   ```

10. **大数组要定义在 main函数外**，因为定义在 main 函数外就成了全局变量，在堆上分配空间；而在 main 函数内会成为局部变量，在栈上分配空间，容易造成栈溢出。

11. **C 字符串与数字的转换**：

    - **字符串→数字**：包含 `stdlib.h`：
      - 转为 `int`：`atoi`，首先丢弃尽可能多的空白字符，直到找到第一个非空白字符。
      - 转为 `long`：`atol`。
      - 转为 `long long`：`atoll`。
      - 转为 `double`：`atof`。
    - **数字→字符串**：包含 `<cssdio>`：
      - 转为十进制数：`sprintf(str, "%d", value)`
      - 转为十六进制：`sprintf(str, "%x", value)`

12. 判断素数：

    ```c
    int IsPrime(int n) {
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0) return 0;
        return 1;
    }
    ```

13. 最大公约数：

    ```c
    int gcd(int num1, int num2) {
        if(num2 == 0) return num1;
        return gcd(num2, num1 % num2);
    }
    ```

    

## Day 1——1001、1089-1096

**1001**

```c
#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int sum = 0;
        for(int i = 1; i < n + 1; i++)
            sum += i;
        printf("%d\n\n", sum);
    }
    return 0;
}
```

**1089**

```c
#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    while(scanf("%d %d", &num1, &num2) != EOF) {
        printf("%d\n", num1 + num2);
    }
    return 0;
}
```

**1090**

```c
#include <stdio.h>

int main() {
    int lineCount = 0;
    scanf("%d", &lineCount);
    for(int i = 0; i < lineCount; i++) {
        int num1 = 0, num2 = 0;
        scanf("%d %d", &num1, &num2);
        printf("%d\n", num1 + num2);
    }
    return 0;
}
```

**1091**

```c
#include <stdio.h>

int main() {
    int stopFlag = 0;
    while(!stopFlag) {
        int num1 = 0, num2 = 0;
        scanf("%d %d", &num1, &num2);
        stopFlag = (num1 == 0 && num2 == 0);
        if(!stopFlag)
            printf("%d\n", num1 + num2);
    }
    return 0;
}
```

**1092**

```c
#include <stdio.h>
#define N 100

int main() {
    int n = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &n);
        if(n == 0)
            break;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            int num = 0;
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
```

**1093**

```c
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d",&n); // n lines
    for(int i = 0; i < n; i++) {
        int sum = 0, m; // m integers
        scanf("%d",&m);
        for(int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
```

**1094**

```c
#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != -1) {
        int sum = 0, num;
        for(int i = 0; i < n; i++) {
            scanf(" %d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}
```

**1095**

```c
#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    while(scanf("%d %d", &num1, &num2) != EOF) {
        printf("%d\n\n", num1 + num2);
    }
    return 0;
}
```

**1096**

```c
#include <stdio.h>
#include <string.h>
#define N 100

int main() {
    int n = 0, result[N];
    memset(result, 0, sizeof(int));
    scanf("%d",&n); // n lines
    int i;
    // compute line by line
    for(i = 0; i < n; i++) {
        int sum = 0, m; // m integers
        scanf("%d",&m);
        for(int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            sum += num;
        }
        result[i] = sum;
    }
    int k;
    for(k = 0; k < i-1; k++)
        printf("%d\n\n", result[k]);
    // there is no blank line after the last number
    printf("%d\n", result[k]);
    return 0;
}
```

## Day 2——2000-2011

注意：改变数组的函数，需要用指针作为形参：

```c
void sortArray(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++)
            if(arr[i]>arr[j]) {
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
    }
}
// 调用
int arr[] = {1,5,4,2,3};
sortArray(arr,5);
```

2000——字母排序

注意输出格式——两个字母之间有一个空格，最后一个字母后面没有空格。

```c
#include <stdio.h>

void sortCharArray(char *arr, int length);
void printArray(char c[], int length);
void swap(char *c1, char *c2);

int main() {
    char c[3];
    while(scanf("%c%c%c", &c[0], &c[1], &c[2]) != EOF) {
        sortCharArray(c, 3);
        printArray(c, 3);
        getchar();
    }
}
void sortCharArray(char *arr, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void swap(char *c1, char *c2) {
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void printArray(char c[], int length) {
    int i;
    for(i = 0; i < length - 1; i++)
        printf("%-2c", c[i]);
    printf("%c", c[i]);
    printf("\n");
}
```

2001——两点距离

```c
#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2, y1, y2;
    while(scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF) {
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        printf("%.2f\n", distance);
    }
    return 0;
}

```

2002——求球的体积

```c
#include <stdio.h>
#include <math.h>
#define PI 3.1415927

int main() {
    double radius;
    while(scanf("%lf", &radius) != EOF) {
        double volume = PI * pow(radius, 3) * 4 / 3;
        printf("%.3f\n", volume);
    }
    return 0;
}
```

2003——求绝对值

```c
#include <stdio.h>

int main() {
    double num;
    while(scanf("%lf", &num) != EOF) {
        double result;
        if(num >= 0)
            result = num;
        else
            result = -num;
        printf("%.2f\n", result);
    }
    return 0;
}
```

2004——成绩转换

```c
#include <stdio.h>

char GetGradeLevel(int);
int main() {
    int grade;
    while(scanf("%d", &grade) != EOF) {
        if(!(grade >= 0 && grade <= 100))
            printf("Score is error!\n");
        else printf("%c\n", GetGradeLevel(grade));
    }
    return 0;
}

char GetGradeLevel(int grade) {
    char result;
    if(grade >= 90 && grade <= 100) result = 'A';
    else if(grade >= 80 && grade <= 89) result = 'B';
    else if(grade >= 70 && grade <= 79) result = 'C';
    else if(grade >= 60 && grade <= 69) result = 'D';
    else result = 'E';
    return result;
}
```

2005——输入的日期是这一年的第几天

```c
#include <stdio.h>

int IsLeapYear(int year);

int main() {
    int January = 31,
        February = January + 28,
        March = February + 31,
        April = March + 30,
        May = April + 31,
        June = May + 30,
        July = June + 31,
        August = July + 31,
        September = August + 30,
        October = September + 31,
        November = October + 30;

    int year, month, day;
    while(scanf("%d/%d/%d", &year, &month, &day) != EOF) {
        int isLeapYear = IsLeapYear(year);
        int result;
        if(month == 1) result = day;
        else if(month == 2) result = January + day;
        else if(month == 3) {
            if(isLeapYear) result = February + 1 + day;
            else result = February + day;
        } else if(month == 4) {
            if(isLeapYear) result = March + 1 + day;
            else result = March + day;
        } else if(month == 5) {
            if(isLeapYear) result = April + 1 + day;
            else result = April + day;
        } else if(month == 6) {
            if(isLeapYear) result = May + 1 + day;
            else result = May + day;
        } else if(month == 7) {
            if(isLeapYear) result = June + 1 + day;
            else result = June + day;
        } else if(month == 8) {
            if(isLeapYear) result = July + 1 + day;
            else result = July + day;
        } else if(month == 9) {
            if(isLeapYear) result = August + 1 + day;
            else result = August + day;
        } else if(month == 10) {
            if(isLeapYear) result = September + 1 + day;
            else result = September + day;
        } else if(month == 11) {
            if(isLeapYear) result = October + 1 + day;
            else result = October + day;
        } else {
            if(isLeapYear) result = November + 1 + day;
            else result = November + day;
        }
        printf("%d\n", result);
    }
    return 0;
}

int IsLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
```

2006——求奇数乘积

```c
#include <stdio.h>
#define SIZE 100

int MultiplyOddNums(int num[], int length);

int main() {
    int n, num[SIZE];
    while(scanf("%d", &n) != EOF) {
        int i;
        for(i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        printf("%d\n", MultiplyOddNums(num, i));
    }
    return 0;
}
int MultiplyOddNums(int num[], int length) {
    int result = 1;
    for(int i = 0; i < length; i++) {
        if(num[i] % 2 != 0)
            result *= num[i];
    }
    return result;
}
```

2007——求连续数字中奇数的立方和、偶数的平方和。

注意：输入的两个端点不一定先小后大。

```c
#include <stdio.h>

void swap(int *num1, int *num2);

int main() {
    int low, high;
    while(scanf("%d %d", &low, &high) != EOF) {
        if(low > high) swap(&low, &high);
        int oddSum = 0, evenSum = 0;
        for(int i = low; i <= high; i++) {
            if(i % 2 == 0) evenSum += (i * i);
            else oddSum += (i * i * i);
        }
        printf("%d %d\n", evenSum, oddSum);
    }
    return 0;
}
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
```

2008——统计正数、0、负数的个数

注意：输入的数据是 double 类型。

```c
#include <stdio.h>

int main() {
    int n = -1;
    while(scanf("%d", &n) != EOF && n != 0) {
        int negativeCount=0, positiveCount=0, zeroCount=0;
        for(int i = 0; i < n; i++) {
            double num;
            scanf("%lf", &num);
            if(num < 0) negativeCount++;
            else if(num == 0) zeroCount++;
            else positiveCount++;
        }
        if(n != 0)
            printf("%d %d %d\n", negativeCount, zeroCount, positiveCount);
    }
    return 0;
}
```

2009——求数列和

```c
#include <stdio.h>
#include <math.h>

int main() {
    int n,m;
    while(scanf("%d %d", &n, &m) != EOF) {
        double sum = n, current = sqrt(n);
        for(int i = 1; i < m; i++) {
            sum += current;
            current = sqrt(current);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}
```

2010——求水仙花数

```c
#include <stdio.h>
#include <math.h>
#define N 100

int IsDaffodil(int);
int GetHundreds(int);
int GetTens(int);
int GetSingles(int);

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        int daffodils[N], j = 0;
        for(int i = m; i <= n; i++) {
            if(IsDaffodil(i))
                daffodils[j++] = i;
        }
        if(j > 0) {
            int i;
            for(i = 0; i < j-1; i++) {
                printf("%d ", daffodils[i]);
            }
            printf("%d\n", daffodils[i]);
        } else {
            printf("no\n");
        }
    }

    return 0;
}

int IsDaffodil(int num) {
    int result = 0;
    int hundres = GetHundreds(num),
        tens = GetTens(num),
        singles = GetSingles(num);
    if(num == pow(hundres, 3) + pow(tens, 3) + pow(singles, 3))
        result = 1;
    return result;
}

int GetHundreds(int num) {
    return num / 100;
}

int GetTens(int num) {
    int temp = num - 100 * GetHundreds(num);
    return temp / 10;
}

int GetSingles(int num) {
    int singles = num - (100 * GetHundreds(num)) - (10 * GetTens(num));
    return singles;
}
```

2011——求数列前 n 项和，注意 `sign` 和 `current` 都要为 `double` 类型。

```c
#include <stdio.h>
#define N 100

double GetSum(int);

int main() {
    double result[N];
    int m, i;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        double sum;
        int n;
        scanf("%d", &n);
        sum = GetSum(n);
        result[i] = sum;
    }
    for(int j = 0; j < i; j++) {
        printf("%.2f\n", result[j]);
    }
    return 0;
}
// sum of the first n elements
double GetSum(int n) {
    double sum = 0;
    double current = 1, sign = 1;
    for(int j = 0; j < n; j++) {
        sum += sign / current;
        current++;
        sign = -sign;
    }
    return sum;
}
```

