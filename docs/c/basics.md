# 基础

## 数据类型

### 有符号整数 & 无符号整数

两者的区别在于 __怎样解释整数的最高位__：
- 无符号整数：最高位被解释为数据位；
- 有符号整数：最高位被解释为符号位——0 表示正数，1 表示负数。

负数使用 __补码__ 表示：
- 这样可以将减法运算转化为加法运算；
- +0 和 -0 的表示形式一样。

### 实数存储

__定点数__：
- __纯小数__：小数点位于符号位和第一个数值位之间；
- __整型__：小数点位于数值位之后。

__浮点数__：小数点的位置是可以浮动的，例如 123.45 可以写成 1.2345 x 10<sup>2</sup>，或者 0.12345 x 10<sup>3</sup>。即：__随着 10 的指数的变化，小数点位置也要变化。__

存储时，指数部分称为 __阶码__，决定表数范围，小数部分叫做 __尾数__，决定精度。

---

## 算术运算

### 自动类型转换

当表达式中操作数类型不同时，在运算之前，C 编译器先将所有操作数转换为同一类型，具体由什么转换为什么的规则称为 __类型提升__：
- 将所有 `char` 和 `short` 提升为 `int`。
- 所有 `float` 提升为 `double`。

赋值时的类型转换，会将等号右边的转换为左边的类型。

### 标准数学函数

- `sqrt(x)` 计算 x 的平方根
- `fabs(x)` 计算 x 的绝对值
- `exp(x)` 计算 e 的 x 次方指数
- `pow(x,y)` 计算 x 的 y 次方
- `sin(x), cos(x)`

__判断实数是否等于 0：__不能直接和 0 比较，而要验证是否和 0 的差距在一个很小的范围内：

```c
#define EPS 1e-6
fabs(x) < EPS
```

---

## 输入输出

__转义字符__ (如 `\n`)按一个字符计数。

__`getchar()`__ 函数从键盘读入一个字符，不接受参数；
__`putchar(char)`__ 向屏幕输出一个字符。

```c
char c = getchar();
putchar(c);
```

__指定输出小数位数__：`printf("%7.2f")` 表示输出占7个字符，精度为小数点后两位。

__scanf__ 函数的返回值就是 __正确读入的数据项数__。

__scanf 函数的格式修饰符：__
- `%ld` 输入长整型；
- `%hd` 输入短整型；
- `%lf` 输入 `double` 型；
- `%f` 输入 `float` 型。

> #### Note::
> 
> 为什么单精度和双精度的输入控制不一样，而输出控制一样（都为 `%f`）？
> - `scanf()` 输入时需要知道读入的数据需要四个还是八个字节来存储；
> - `printf()` 会将单精度自动转换为双精度来输出。

还有一个特殊的修饰符 `*`，表示忽略相应位置的输入。例如 `scanf("%2d%*2d%2d", &a, &b)`，用户输入为 123456，那么结果是把 12 赋给 a，56 赋给 b。

__getchar__ 输入字符时，回车键会将输入数据放入 __行缓冲区__ 中，然后 `getchar` 再从中依次读取字符。

> #### Hint::忽略缓冲区中空白字符的方法
> 
> 1. 在 `%c` 前加一个空格：`scanf(" %c", &a)`
> 2. 添加 `getchar()` 读出空白字符，然后读取非空白字符。

要注意控制字符串的定义和响应变量类型的对应。
> #### Danger::
> 
> 如果控制格式和对应的变量类型不同，那么会输出 __乱码或者 0__.