# Python 基础

[TOC]

## 基本语法

**注释**：

- 单行注释以 `#` 开头；
- 多行注释以 **三个单/双引号** 开头，并以此结尾。

**type()** 函数返回参数的类型：

- `int`
- `float`
- `str`
- `bool`

**内置函数进行强制类型转换**：

- `int()`
- `float()`
- `str()`

**接受键盘输入 & 格式化输出**：

```python
a = int(input('a=')) # int() 将输入字符串转换成整型
b = int(input('b='))
print('%d + %d = %d' % (a, b, a+b))
```

**逻辑运算符**：`and`、`or`、`not`。

**条件语句**：`if:...elif:...else:`，注意并非`else if` 而是 `elif`，且关键字后面要 **跟上冒号**，并且 **具有相同缩进的语句属于同一个代码块。**

**循环**：

- for...in 循环：`for x in range(101): sum+=x`
- while 循环：`while expression: ...`

**函数**：

- 定义函数：`def func(variable=defaultValue): ... return ...`
- 可变数量参数：`def add(*args): ... for(val in args): ...`
- 用模块管理函数：使用模块可以避免函数重名问题，一个 `.py` 文件就是一个模块。假如在两个模块中都定义了 `foo()` 函数，那么可以以不同别名导入另一个 Python 文件：
  ```python
  import module1 as m1
  import module2 as m2
  m1.foo()
  m2.foo()
  ```
- 变量作用域：函数中可以定义和全局变量同名的局部变量。可以用 `global` 关键字指明某个参数指的是全局变量。
- 常规格式：
  ```python
  def main():
      ...
  if __name__ == '__main__':
        main()
  ```

**字符串**：

- 字符串可用单引号或者双引号括起来，三个单引号/双引号可以包含多行字符串。
- 字符串常用操作：使用 `+` 拼接，`*` 重复，`in` 检查是否包含指定子串，`[index]` 根据下标索引 `[:]` 切片。
  ```python
  s0 = 'hello'
  s1 = s0 * 2            # hello hello
  s2 = 'hello' + 'world' # hello world
  print('he' in s0)      # True
  print(s0[0])           # 'h'
  # 切片操作
  str[start:[end]]      # 如果不指定 end 则直到最后
  str[start:[end]:step] # step 为步长
  str[::-1]             # step 为 -1，则反转字符串
  str[-3:-1]            # 倒数第 3 到倒数第 2 个字符
  ```
- 字符串常用函数：
  - `len(str)` 返回字符串长度
  - `capitalize()` 将字符串首字母转为大写，并返回新字符串；
  - `title()` 将字符串每个单词的首字母都转为大写，并返回新字符串；
  - `upper()` 将每个字母都转为大写，并返回新字符串。
  - `find(sub)` 查找子串所在位置；
  - `index(sub)` 查找子串所在位置，另外如果找不到会引发异常。
  - `startsWith(prefix)`、`endsWith(suffix)`
  - `center(50, '*')`、`rjust(50, '*)` 以指定宽度居中/右对齐，在两侧/左边用指定字符填充。
  - `isdigit()` 检查字符串是否全是数字构成的；
  - `isalpha()` 检查字符串是否全是字母构成的；
  - `isalnum()` 检查字符串是否仅有字母和字符串构成。
  - `strip()` 修剪左右两侧空格，返回新字符串。

- 格式化输出字符串：
  - 传统方式：`print('{0}*{1}={2}'.format(a,b,a*b))`
  - 3.6 版本以后，`print(f'{a}*{b}={a*b}')`

---
## 常用数据结构

**列表 list：**

- 定义 1：`list1 = [1,2,3,4,5]`
- 定义 2：`list2 = ['hello'] * 2` # ['hello', 'hello']
- 打印：`print(list1)` # [1,2,3,4,5]
- `len(list1)` 列表元素个数
- 使用下标访问元素：`print(list1[0])`
- 使用负数索引访问：`list1[-1]` # 5
- 追加元素：`list1.append(new_elem)`
- 插入元素：`list1.insert(index, new_elem)`
- 扩展列表：`list1.extend(list2)`、`list1 += [100, 200]`
- 删除指定元素：`if 3 in list1: list1.remove(3)`
- 删除指定位置元素：`list1.pop(len(list1)-1)`
- 清空列表：`list1.clear()`
- 遍历：
  ```python
  # 方法 1
  for elem in list1: 
    print(elem)
  # 方法 2
  for index, elem in enumerate(list1)
    print(index, elem)
  ```
- 切片操作：和字符串的切片操作类似。
- 排序：
  - `list2 = sorted(list1[,reverse=True])`
  - 通过 `key` 关键字指定根据字符串长度排序 `sorted(list, key=len)`
  - 对原对象直接排序 `list1.sort(reverse=Tue)` 

- 列表的生成式：
  ```python
  # 通过生成式产生列表
  f = [x for x in range(1,5)] # [1,2,3,4,5]
  f = [x+y for x in 'AB' for y in '12] # xy的全排列
  # 返回一个生成器，不断调用以产生各个元素，本身不占用额外空间
  f = (x for x in range(1,5))
  for(val in f):
      print(val) # 1 2 3 4
  ```
  
  另一种产生生成器的方法是使用 `yield` 关键字替代 `return`，将函数变成生成器：
  ```python
  def fib(n):
      a,b = 0,1
      for _ in range(n):
          a,b = b,a+b
          yield a

  def main():
      for val in fib(20):
          print(val)

  if __name__ == '__main__':
      main()
  ```

**元组：**

- 元组和列表很像，但是 **不可修改**，而一个不变对象自动就是 **线程安全** 的。
- 所以如果不需要对元素进行添加、删除、修改操作时，可以考虑使用元组；
- 如果一个方法要返回多个值，也可以返回一个元组。
- 元组在创建时间和占用空间上都优于列表。
- 元组和列表可以相互转换。

```python
t = ('mason', 25) # 定义元组
for member in t:  # 遍历
    print(member)
person = list(t)  # 元组转换为列表
atuple = tuple(person) # 列表转换为元组
```

**集合：**

- 定义集合：
  - 用字面量定义：`set1 = {1,2,2,3}`
  - 用构造器定义：`set2 = set(1,2,2,3)`
  - 用推导式定义：`set3 = {n for n in range(1,4)}`
- 增加元素：`set1.add(4)`
- 删除元素：
  - `discard(elem)` 如果元素存在则删除该元素，否则无效；返回值为 None。
  - `remove(elem)` 如果元素存在则删除元素，否则抛出 KeyError。返回值为 None。
  - `pop()` 随机删除一个元素，并返回该元素。
- 集合运算：
  - 交集：`set1 & set2`
  - 并集：`set1 | set2`
  - 差集：`set1 - set2`
  - 对称差：(`(set1-set2)|(set2-set1)`)：`set1 ^ set2`
  - 判断子集和超集：`set1<=set2`

**字典（键值对）：**

- 定义：
  - 用字面量定义：`scores = {'mason': 90, 'rachael': 90}`
  - 用构造器定义：`scores = dict(mason=90, rachael=90)`
  - 用 `zip` 函数定义：`scores = didct(zip(['mason','rachael'], [90,90]))`
  - 用推导式定义：`square = {num: num ** 2 for num in range(1,5)}`
- 获取键值：
  - `scores['mason']`
  - `scores.get('mason')`
- 修改：
  - `scores['mason'] = 95`
  - `scores.update(rachael=95)`
- 删除：`scores.pop('mason')`
- 清空：`scores.clear()`
- 遍历：(`for ... in ...`, `in`)
  ```python
  for key in scores:
      print(f'{key}: {scores[key]}')
  if 'mason' in scores:
      print(scores['mason'])
  ```

**实例：**

设计一个函数返回给定文件的后缀名：

```python
def get_suffix(filename, has_dot=False):
    """
    获取文件名的后缀名
    :param filename: 文件名
    :param has_dot: 返回的后缀名是否需要带点
    :return: 文件的后缀名
    """
    pos = filename.rfind('.')
    if 0 < pos < len(filename) - 1:
        index = pos if has_dot else pos + 1
        return filename[index:]
    else:
        return ''
```

---
## 类

**定义类：**

```python
class Student(object):
    # __init__ 方法是构造器
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def study(self, course_name):
        print('%s正在学习%s.' % (self.name, course_name))
```

**创建对象**：

```python
def main():
    stu1 = Student('mason', 25)
    stu1.study('Python')
if __name__ == '__main__':
    main()
```

**访问可见性问题**：

- Python 只有私有和公开两种访问权限；
- 如果希望属性 **私有**，可以让 **属性名以两个下划线作为开头**。但是 Python 没有从语法上严格保证私有属性或方法的私密性，它只是给私有属性换了一个名字来妨碍对它们的直接访问，只要知道更换名字的规则，还是可以直接访问到。
- 如果希望属性是 **受保护的**，**让属性名以单下划线开头**，表示其他类访问这样的属性时要慎重。

**@property 装饰器：**

使用 `@property` 装饰器包装 `getter, setter` 操作，使得对属性的访问安全方便。

```python
class Person(object):
    def __init__(self, name, age):
        self._name = name
        self._age = age
    # getter 
    @property
    def name(self):
        return self._name
    @property
    def age(self):
        return self._age
    # setter
    @age.setter
    def age(self, age):
        self.age = age

def main():
    person = Person('Steve',31)
    person.age = 32 # getter、setter 都要有

if __name__ == '__main__':
    main()
```

**__slots__：**

python 允许在运行时动态给对象绑定新的属性或方法，但为了限定只能绑定某些方法，可以使用 `__slots__` 属性：

```python
class Person(object):
    # 限定 Person 对象只能有下面三种属性
    __slots__  ('_name', '_age', '_gender')
    # ...

def main():
    person = Person('mason', 25)
    person.gender = 'male' # 允许动态添加属性
    person.status == 'loser' # 属性错误，不能绑定该属性
```

**静态方法：**

静态方法是未创建对象就能调用的方法，可用来检查创建对象的条件是否满足，从而决定是否创建这个对象。例如创建一个三角形对象，如果给定的三条边不能组成一个三角形，那么就不会创建对象。

```python
from math import sqrt

class Triangle(object):
    def __init__(self, a, b, c):
        self._a = a
        self._b = b
        self._c = c

    @staticmethod
    def is_valid(a, b, c):
        return (a + b > c) and (a + c > b) and (b + c > a)
    
    def perimeter(self):
        return self._a + self._b + self._c

def main():
    a, b, c = 3, 4, 5
    # 调用静态方法
    if Triangle.is_valid(a, b, c):
        t = Triangle(a, b, c)
        print(t.perimeter())
    else:
        print('无法构成三角形')

if __name__ == '__main__':
    main()
```

**继承：**

前面定义的类都是 `ClassName(object)`，实际上就是继承了 `object` 类，即类的继承写法为 `ClassName(ParentClass)`。

```python
class Student(Person):
    def __init__(self, name, age, grade):
        super().__init__(name, age)
        self._grade = grade
    
    @property
    def grade(self):
        return self._grade
    
    @grade.setter
    def grade(self, grade):
        self._grade = grade
```

## 文件操作

**读文件：**

```python
def main():
    f = None
    try:
        f = open('./test.txt', 'r', encoding='utf-8')
        print(f.read())
    except FileNotFountError:
        print('找不到文件')
    finally:
        if f:
            f.close()
```

使用 `for-in` 循环逐行读取或者用 `readlines` 将文件 **按行读取到一个列表中**：

```python
def main():
    with open('./test.txt', 'r', encoding='utf-8') as f:
        print(f.read())
    
    # 通过 for-in 循环逐行读取
    with open('test.txt',mode='r') as f:
        for line in f:
            print(line, end='')
    
    # 逐行读取到列表中
    with open('test.txt') as f:
        lines = f.readlines()
    print(lines)
```

**写文件：**

和读文件差不多，只是将 `open` 函数的模式设置为 `'w'` (或者设置成 `'a'` 表示追加)：

```python
filename = 'test.txt'
try:
    fs = open(filename, 'w', encoding='utf-8')
    fs.write('hello world')
except IOError as ex:
    print(ex)
finally:
    fs.close()
```

