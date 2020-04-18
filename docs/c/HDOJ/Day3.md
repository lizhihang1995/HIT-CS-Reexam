# 杭电 OJ 刷题记录——Day3

| 题号     | 1062/1064 | 1170 | 1197 | 1720 | 2012 | 2030/2032 | 2040/2042 | 2054/2055 | 2629 |
| -------- | :-------: | :--: | :--: | :--: | :--: | :-------: | :-------: | :-------: | :--: |
| **结果** |    AC     |  AC  |  AC  |  AC  |  AC  |    AC     |    AC     |    AC     |  AC  |

**1062**——单词逆序输出：先切分句子 → 后逆序输出。（太笨了，卡了大半天 #_#）

```c
#include <stdio.h>
#include <string.h>
#define N 1000

void reverseWord(char *word);

int main() {
    int lineCount;  // 确定行数
    scanf("%d", &lineCount);
    getchar();      // 读出回车符
    // 一行一行处理
    for(int i = 0; i < lineCount; i++) {
        char line[N];
        gets(line);
        int length = strlen(line);
        int pos = 0;
        char copy[N]; // 辅助数组
        // 切分为单词并逆序输出
        for(int j = 0; j <= length; j++) { // 注意 '\0'
            // 遇到空格表示一个单词结束，将该单词逆序输出
            if(line[j] == ' ') {
                copy[pos] = '\0';
                pos = 0; // 重新开始记录下一个单词
                reverseWord(copy);
                printf("%s ", copy);
            }
            // 句子结束
            else if(line[j] == '\0') {
                    copy[pos] = '\0';
                    reverseWord(copy);
                    printf("%s\n", copy);
                    break;
            }
            else {
                copy[pos++] = line[j];
            }
        }
    }
    return 0;
}
// 将单词逆序
void reverseWord(char *word) {
    char reversed[N]; // 辅助数组
    int i, j;
    for(i = 0; word[i] != '\0'; i++);
    i--;
    for(j = 0; i >= 0; i--, j++)
        reversed[j] = word[i];
    reversed[j] = '\0';
    strcpy(word, reversed);
}
```

**1064**——计算账户每月余额的平均数

```c
#include <stdio.h>
#define N 12
int main() {
    double sum;
    for(int i = 0; i < N; i++) {
        double num;
        scanf("%lf", &num);
        sum += num;
    }
    printf("$%.2f\n", sum / N);
    return 0;
}
```

**1170**——计算简单运算的值，只有结果是小数时才显示两位小数。

```c
#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        char aOperator;
        int num1, num2;
        scanf(" %c", &aOperator);
        scanf("%d %d", &num1, &num2);
        if(aOperator == '/') { // 只有除法可能得出小数
            double result = (double)num1 / (double)num2;
            if((int)result != result) // 不为整数
                printf("%.2f\n", result);
            else printf("%d\n", (int)result);
        } else {
            int result = 0;
            if(aOperator == '+')
                result = num1 + num2;
            else if(aOperator == '-')
                result = num1 - num2;
            else if(aOperator == '*')
                result = num1 * num2;
            printf("%d\n", result);
        }
    }
    return 0;
}
```

**1197**——求特殊的四位数，关键是进制转换

```c
#include <stdio.h>

int GetSumOfDigits(int decimal, int base);
int GetDigitsSumOfDecimal(int);

int main() {
    for(int i = 1000; i <= 9999; i++) {
        int duodecimalSum = GetSumOfDigits(i, 12);
        int hexadecimalSum = GetSumOfDigits(i, 16);
        int decimalSum = GetDigitsSumOfDecimal(i);
        if(decimalSum == duodecimalSum && decimalSum == hexadecimalSum)
            printf("%d\n", i);
    }
//    int test = 2992;
//    printf("base 16: %d\n",GetSumOfDigits(test, 16));
//    printf("base 12: %d\n",GetSumOfDigits(test, 12));
//    printf("base 10: %d\n", GetDigitsSumOfDecimal(test));
    return 0;
}
// 计算十二进制、十六进制的各位数字之和
int GetSumOfDigits(int decimal, int base) {
    int reminder[4] = {0, 0, 0, 0};
    reminder[0] = decimal % base;
    int quotient = decimal / base;
    int i = 1;
    while(quotient >= base) {
        reminder[i++] = quotient % base;
        quotient = quotient / base;
    }
    reminder[i] = quotient;
    int sum = 0;
    for(int j = 0; j <= i; j++){
        sum += reminder[j];
    }
    return sum;
}
// 计算十进制数各位数字之和
int GetDigitsSumOfDecimal(int num) {
    int thousands = num / 1000;
    int hundreds = (num - 1000 * thousands) / 100;
    int tens = (num - 1000 * thousands - 100 * hundreds) / 10;
    int singles = num - thousands * 1000 - hundreds * 100 - tens * 10;
    return thousands + hundreds + tens + singles;
}
```

**1720**——十六进制数字的加法，注意用 `%x` 控制符接收十六进制输入。

```c
#include <stdio.h>

int main() {
    int num1, num2;
    while(scanf("%x %x", &num1, &num2) != EOF) {
        printf("%d\n", num1 + num2);
    }
    return 0;
}
```

**2012**——素数判定

```c
#include <stdio.h>

int IsPrime(int);

int main() {
    int num1 = -1, num2 = -1;
    while(!(num1 == 0 && num2 == 0)) {
        scanf("%d %d", &num1, &num2);
        int isPrime = 1;
        // 判断是否有不满足条件的数
        for(int i = num1; i <= num2; i++) {
            int expression = i * i + i + 41;
            if(!IsPrime(expression))
                isPrime = 0;
        }
        // 输出结果
        if(!(num1 == 0 && num2 == 0)) {
            if(isPrime) printf("OK\n");
            else printf("Sorry\n");
        }
    }

    return 0;
}
// 判断是否为素数
int IsPrime(int num) {
    for(int i = 2; i <= num/2; i++)
        if(num % i == 0) return 0;
    return 1;
}
```

**2030**——统计汉字个数：汉字的机内码占两个字节，且每个字节都是负数。

```c
#include <stdio.h>
#include <string.h>

#define N 1000

int main() {
    int lineCount;
    char sentence[N];
    scanf("%d", &lineCount);
    getchar(); // 读出回车符
    while(lineCount--) {
        int count = 0;
        gets(sentence);
        int length = strlen(sentence);
        for(int i = 0; i < length; i++) {
            if(sentence[i] < 0)
                count++; // 汉字的字符为负数
        }
        printf("%d\n", count / 2); // 一个汉字包含两个字符
    }
    return 0;
}
```

**2032**——杨辉三角

```c
#include <stdio.h>
#define N 100

int main() {
    int n;
    int YHTriangle[N][N];
    // 初始化第一列和 \ 对角线为 1
    for(int i = 0; i < N; i++) {
        YHTriangle[i][0] = 1;
        YHTriangle[i][i] = 1;
    }
    // 初始化其他部分
    for(int i = 2; i < N; i++) {
        for(int j = 1; j < i; j++) {
            YHTriangle[i][j] = YHTriangle[i-1][j-1] + YHTriangle[i-1][j];
        }
    }
    while(scanf("%d", &n) != EOF) {
        // i 表示行，j 表示列
        for(int i = 0; i < n; i++) {
            int j;
            for(j = 0; j < i; j++) {
                printf("%d ", YHTriangle[i][j]);
            }
            printf("%d\n", YHTriangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

**2040**——亲和数：两个数中任何一个数都是另一个数的真约数之和。

```c
#include <stdio.h>

int IsAffinityNumbers(int, int);
int GetSumOfFactors(int);

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        if(IsAffinityNumbers(num1, num2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

int IsAffinityNumbers(int num1, int num2) {
    int sum1 = GetSumOfFactors(num1);
    int sum2 = GetSumOfFactors(num2);
    if(sum1 == num2 && sum2 == num1)
        return 1;
    else
        return 0;
}

int GetSumOfFactors(int num) {
    int sum = 1;
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            sum += i;
    }
    return sum;
}
```

**2042**——数羊

```c
#include <stdio.h>

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        int n; // 收费站数量
        scanf("%d", &n);
        int current = 3,
            lastOne;
        for(int i = 0; i < n; i++) {
            lastOne = 2 * (current - 1);
            current = lastOne;
        }
        printf("%d\n",current);
    }
    return 0;
}
```

**2054**——判断两数是否相等，范围可以很大，所以 **用字符数组保存数字**，去掉末尾的 0 之后逐位比较。

```c
#include <stdio.h>
#include <string.h>

#define N 100000

int IsEqual(char num1[], char num2[]);
void RemoveZero(char *point);

int main() {
    char num1[N], num2[N];
    while(scanf("%s %s", num1, num2) != EOF) {
        if(IsEqual(num1, num2)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

int IsEqual(char num1[], char num2[]) {
    // 指向小数点的指针
    char *point1 = NULL, *point2 = NULL;
    point1 = strchr(num1, '.');
    point2 = strchr(num2, '.');
    // 去掉末尾的零
    if(point1 != NULL) RemoveZero(point1);
    if(point2 != NULL) RemoveZero(point2);
    // 逐位比较
    int flag = 1;
    int length1 = strlen(num1);
    for(int i = 0; i <= length1; i++) {
        if(num1[i] != num2[i]) flag = 0;
    }
    return flag;
}

void RemoveZero(char *point) {
    int length = strlen(point);
    for(int i = length-1; i >= 0; i--) {
        if(point[i] == '0' || point[i] == '.')
            point[i] = '\0';
        else break;
    }
}
```

**2055**——计算表达式

```c
#include <stdio.h>

int main() {
    int lineCount;
    scanf("%d", &lineCount);
    while(lineCount--) {
        // compute y+f(x)
        char x;
        int y, fx;
        getchar(); // read Enter
        scanf("%c %d", &x, &y);
        if(x <= 'Z')
            fx = x - 'A' + 1;
        else
            fx = -(x - 'a' + 1);
        printf("%d\n", y+fx);
    }
    return 0;
}
```

**2629**——解析身份证号

```c
#include <stdio.h>
#include <string.h>

#define ID_LENGTH 18
#define PROVINCE_COUNT 8
#define N 50

int main() {
    // 指向二维数组的指针
    const char *PROVINCE[PROVINCE_COUNT][2] = {
        {"11", "Beijing"},
        {"33", "Zhejiang"},
        {"31", "Shanghai"},
        {"21", "Liaoning"},
        {"82", "Macao"},
        {"81", "Hong Kong"},
        {"54", "Tibet"},
        {"71", "Taiwan"}
    };
    int lineCount;
    scanf("%d", &lineCount);
    getchar(); // 读出回车符
    char ID[ID_LENGTH+1];
    memset(ID, 0, sizeof(ID));
    while(lineCount--) {
        gets(ID);
        char province[N],
             year[5], month[3], day[3];
        int i = 0, j = 0, k = 0, m = 0; // 循环计数
        // 省份
        for(i = 0; i < 2; i++)
            province[i] = ID[i];
        province[i] = '\0';
        // 将省份代号匹配到名称
        for(int idx = 0; idx < PROVINCE_COUNT; idx++) {
            if(strcmp(province, PROVINCE[idx][0]) == 0)
                strcpy(province, PROVINCE[idx][1]);
        }
        // 年份
        for(i = 6; i < 10; i++, j++)
            year[j] = ID[i];
        year[j] = '\0';
        // 月份
        for(; i < 12; i++, k++)
            month[k] = ID[i];
        month[k] = '\0';
        // 日
        for(; i < 14; i++, m++)
            day[m] = ID[i];
        day[m] = '\0';

        printf("He/She is from %s,and his/her birthday is on %s,%s,%s based on the table.\n",
               province, month, day, year);
    }
    return 0;
}
```

