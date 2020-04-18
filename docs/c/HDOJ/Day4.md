# 杭电 OJ 刷题记录——Day4

| 题号     | 1004 | 2031 | 2033 | 2057 | 2070 | 2071 | 2072 | 2081 | 2091 | 2093 |
| -------- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| **结果** |  AC  |  AC  |  AC  |  AC  |  AC  |  AC  |  AC  |  AC  |  PE  |  WA  |

**1004**——找出出现最多的颜色（还是不会用指针，特别是数组指针）

```c
#include <stdio.h>
#include <string.h>

#define N 1000

// 颜色-数量结构
typedef struct {
    char color[N];
    int count;
} Color_Count;

int ExistsInStruct(char color[], Color_Count cc[], int structLen);
void AddCountOfColor(char color[], Color_Count cc[], int structLen);

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    if(n == 0) return 0;
    while(n != 0) {
        // 读取输入的所有颜色
        char color[N][20];
        for(int i = 0; i < n; i++) {
            scanf("%s", color[i]);
            getchar();
        }
        Color_Count colorCount[N];
        int length = 0; // colorCount 数组长度
        // 处理每个颜色输入
        for(int i = 0; i < n; i++) {
            if(!ExistsInStruct(color[i], colorCount, length)){
                strcpy(colorCount[length].color, color[i]);
                colorCount[length].count = 1;
                length++;
            } else {
                AddCountOfColor(color[i], colorCount, length);
            }
        }
        // 找出数量最多的颜色——假设该颜色唯一
        int maxPosition = 0;
        for(int i = 1; i < length; i++) {
            if(colorCount[i].count > colorCount[maxPosition].count)
                maxPosition = i;
        }
        printf("%s\n", colorCount[maxPosition].color);
        scanf("%d", &n);
        getchar();
    }

    return 0;
}

int ExistsInStruct(char color[], Color_Count cc[], int structLen) {
    for(int i = 0; i < structLen; i++) {
        if(strcmp(color, cc[i].color) == 0) return 1;
    }
    return 0;
}

void AddCountOfColor(char color[], Color_Count cc[], int structLen) {
    for(int i = 0; i < structLen; i++) {
        if(strcmp(color, cc[i].color) == 0) {
            cc[i].count++;
            break;
        }
    }
}
```

**2031**——十进制转换为任意进制

有时候分出几个函数可能会让逻辑看起来更清晰些，但是代码却因为传值变得复杂了很多，所以别觉得把逻辑都写在主函数里面就不好。（因为分出了三个函数，代码多了一半，而且出错也不好调试）

```c
#include <stdio.h>
#define N 100

int main() {
    int n, base;
    while(scanf("%d %d", &n, &base) != EOF) {
        // 考虑负数情况
        int negativeFlag = 0;
        if(n < 0) {
            n = -n;
            negativeFlag = 1;
        }
        // 除 base 取余
        int quotient = n / base;
        int reminder[N];
        reminder[0] = n % base;
        int i = 1;
        while(quotient > 0) {
            reminder[i++] = quotient % base;
            quotient = quotient / base;
        }
        // 逆序输出余数
        if(negativeFlag) printf("-");
        for(int j = i-1; j >= 0; j--) {
            if(reminder[j] < 10)
                printf("%d", reminder[j]);
            else
                printf("%c", reminder[j] - 10 + 'A');
        }
        printf("\n");
    }
    return 0;
}
```

**2033**——时分秒加法：注意秒和分的进位即可。

```c
#include <stdio.h>

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    getchar();
    while(caseCount--) {
        int aHour, aMinute, aSecond,
            bHour, bMinute, bSecond,
            sumHour, sumMinute, sumSecond;
        scanf("%d %d %d %d %d %d", &aHour, &aMinute, &aSecond,
                                   &bHour, &bMinute, &bSecond);
        sumSecond = aSecond + bSecond;
        // 进位标志
        int secondCarry = 0,
            minuteCarry = 0;
        // 秒进位
        if(sumSecond >= 60) {
            secondCarry = 1;
            sumSecond -= 60;
            sumMinute = aMinute + bMinute + 1;
            if(sumMinute >= 60) { // 分进位
                minuteCarry = 1;
                sumMinute -= 60;
            }
        } else { // 秒不进位
            sumMinute = aMinute + bMinute;
            if(sumMinute >= 60) { // 分进位
                minuteCarry = 1;
                sumMinute -= 60;
            }
        }
        sumHour = aHour + bHour;
        if(minuteCarry) sumHour += 1;

        printf("%d %d %d\n", sumHour, sumMinute, sumSecond);
    }
    return 0;
}
```

**2057**——十六进制加法：(1) 用 `__int64` 类型表示大整数；(2)用 `%I64X, %I64x` 控制十六进制输入输出，x 的大小写表示十六进制表示法的大小写。

```c
#include <stdio.h>

int main() {
    // 大整数
    __int64 hexNum1, hexNum2;
    while(scanf("%I64X %I64X", &hexNum1, &hexNum2) != EOF) {
            __int64 sum = hexNum1 + hexNum2;
        if(sum >= 0) printf("%I64X\n", sum);
        else printf("-%I64X\n", -sum);
    }
    return 0;
}
```

**2070**——斐波那契数列：不能用递归，速度太慢，重复计算太多，而直接把每个元素算出来放到数组中。

```c
#include <stdio.h>
#define N 51

int main() {
    // 初始化存储斐波那契数列的数组
    __int64 fibbonacci[N];
    fibbonacci[0] = 0;
    fibbonacci[1] = 1;
    for(int i = 2; i < N; i++) {
        fibbonacci[i] = fibbonacci[i-1] + fibbonacci[i-2];
    }
    // 输出对应位置的元素
    int n;
    scanf("%d", &n);
    while(n != -1) {
        printf("%I64d\n", fibbonacci[n]);
        scanf("%d", &n);
    }
    return 0;
}
```

**2071**——找最大值

```c
#include <stdio.h>
#define N 100

float FindMax(float height[N], int length);

int main() {
    int caseCount;
    scanf("%d", &caseCount);
    while(caseCount--) {
        int n;
        scanf("%d", &n);
        float height[N];

        for(int i = 0; i < n; i++) {
            scanf("%f", &height[i]);
        }
        printf("%.2f\n", FindMax(height, n));
    }
    return 0;
}

float FindMax(float height[N], int length) {
    int maxPosition = 0;
    for(int i = 1; i < length; i++)
        if(height[i] > height[maxPosition])
            maxPosition = i;
    return height[maxPosition];
}
```

**2072**——统计不同单词的数量：注意数量为 0 的情况。

```c
#include <stdio.h>
#include <string.h>

#define N 10000
#define WORD_LENGTH 100

int main() {
    char sentence[N];
    char allWords[N][WORD_LENGTH];
    gets(sentence);
    while(strcmp(sentence, "#") != 0) {
        if(strcmp(sentence, "#") == 0)
            break;
        int wordCount = 0;
        int length = strlen(sentence);
        char word[WORD_LENGTH];
        memset(word, '\0', sizeof(word));
        int position = 0;
        // 逐个字符处理
        for(int i = 0; i <= length; i++) {
            if(sentence[i] == ' ' || sentence[i] == '\0') {
                word[position] = '\0';
                // 检查该单词是否已经出现过，没出现则记录
                int existFlag = 0;
                if(strlen(word) > 0) { // 只输入回车，则统计结果为 0
                    for(int j = 0; j < wordCount; j++) {
                        if(strcmp(word, allWords[j]) == 0)
                            existFlag = 1;
                    }
                }
                if(!existFlag && strlen(word) > 0){
                    strcpy(allWords[wordCount++], word);
                }
                // 初始化 word 数组
                position = 0;
                // 处理结束时输出单词数
                if(sentence[i] == '\0') {
                    printf("%d\n", wordCount);
                    break;
                }
            // 遇见字母，则放入 word 数组
            } else if(sentence[i] >= 'a' && sentence[i] <= 'z'){
                word[position++] = sentence[i];
            }
        }
        gets(sentence);
    }
    return 0;
}
```

**2081**——手机短号：截取字符串+拼接字符串。

```c
#include <stdio.h>
#include <string.h>

int main() {
    int lineCount;
    scanf("%d", &lineCount);
    getchar(); // 读出回车符
    while(lineCount--) {
        char shortNumber[7];
        char longNumber[12];
        memset(shortNumber, '\0', sizeof(shortNumber));
        memset(longNumber, '\0', sizeof(longNumber));
        gets(longNumber);
        shortNumber[0] = '6';
        // 找到后五位
        char *p = (longNumber+6);
        strcat(shortNumber, p);
        printf("%s\n", shortNumber);
    }
    return 0;
}
```

**2091**——空心三角形

操，题目给的真他妈脑残，根本没说他妈的清楚输出格式到底他妈的怎么要求，所以下面的代码只能 PE，但是不能 AC，妈的浪费老子时间。

```c
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char c;
    int level;
    int times = 0;
    while(scanf("%c", &c) != EOF) {
        if(c == '@')
            break;
        scanf("%d", &level);
        getchar(); // !!! 读出回车符
        if(times)
        	printf("\n");
        if(level == 1)
            printf("%c\n", c);
        else if(level == 2) {
            printf(" %c \n", c);
            printf("%c%c%c\n", c, c, c);
        } else {
            // 初始化存储矩阵
            char triangle[N][N];
            for(int i = 0; i < N; i++)
                memset(triangle[i], ' ', sizeof(triangle[i]));
            int width = 2 * level - 1;
            // 填充第一行
            int midPosition = level - 1;
            triangle[0][midPosition] = c;
            // 填充中间行
            int leftPosition = midPosition - 1,
                rightPosition = midPosition + 1;
            for(int i = 1; i < level - 1; i++) {
                triangle[i][leftPosition] = c;
                triangle[i][rightPosition] = c;
                leftPosition--;
                rightPosition++;
            }
            // 填充最后一行
            for(int j = 0; j < width; j++)
                triangle[level - 1][j] = c;
            // 逐行输出结果
            for(int i = 0; i < level; i++) {
                int lineWidth = level + i;
                for(int j = 0; j < lineWidth; j++)
                    printf("%c", triangle[i][j]);
                printf("\n");
            }
        }
        times++;
    }
    return 0;
}
```

**2093**——在本地运行正确，但是显示 WA，垃圾如我调了半天，喊了一万句草泥马，还是不行，放弃。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 11
#define QUESTION_COUNT 13
#define STUDENT_COUNT 10000

typedef struct {
    char name[NAME_LENGTH];
    int accepted;
    int time;
} Student;
Student students[STUDENT_COUNT];

int MyCompare(const void *q,const void *w);
void PrintStudentRank(Student students[], int length);

int main() {
    int questionCount, penalty;
    scanf("%d %d", &questionCount, &penalty);
    getchar(); // 读出回车符
    int studentIdx = 0;
    // 读取每个学生的信息
    while(scanf("%s", students[studentIdx].name) != EOF) {
        students[studentIdx].accepted = 0;
        students[studentIdx].time = 0;
        // 统计该学生这 questionCount 道题的解答情况
        for(int i = 0; i < questionCount; i++) {
            int timeCost;
            scanf("%d", &timeCost);
            if(timeCost > 0) {
                students[studentIdx].accepted++;
                students[studentIdx].time += timeCost;
                if(getchar() == '(') { // 有括号的情况，加上惩罚时间
                    int faultTimes;
                    scanf("%d", &faultTimes);
                    students[studentIdx].time += penalty * faultTimes;
                    getchar(); // 读出右括号
                }
            }
        }
        qsort(students, studentIdx + 1, sizeof(Student), MyCompare);
        PrintStudentRank(students, studentIdx + 1);
        studentIdx++;
        getchar(); // 读出回车符
    }
    return 0;
}

int MyCompare(const void *q,const void *w) {
    Student *s1=(Student*)q,*s2=(Student*)w;
    if(s1->accepted != s2->accepted)
        return s2->accepted - s1->accepted;
    if(s1->time != s2->time)
        return s1->time - s2->time;
    return strcmp(s1->name, s2->name);
}

void PrintStudentRank(Student students[], int length) {
    for(int i = 0; i < length; i++)
        printf("%-10s %2d %4d\n", students[i].name,
               students[i].accepted, students[i].time);
}
```

