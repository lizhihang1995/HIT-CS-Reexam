# 集合运算

[TOC]

---
**概念**

- **空集**：空集是任意集合的子集，且空集是唯一的。

- **集族**：以集合为元素的集合称为集族。

- **幂集**： 集合 **S 的所有子集**(包括空集和S本身)形成的集族称为 S 的幂集，记为 $$2^S$$。

**运算**

- 并对交的分配律：$$A \cup (B\cap C) = (A \cup B) \cap (A \cup C)$$（交对并的分配律同样满足）
- 差：A - B 记为 $$A \setminus B$$.
- 对称差：$$A \bigtriangleup B = (A \setminus B)\cup(B \setminus A)$$.

- 余集：$$A \subseteq S, A^c=S \setminus A$$.
  - 德摩根公式：
    - $$(A \cup B)^c = A^c \cap B_c$$.
    - $$(A \cap B)^c = A^c \cup B_c$$.
  - <mark>对偶原理</mark>：若有关 **并、交、余** 的某一关系式成立，如果将式中的 <mark>$$\cup,\cap,\subseteq,\supseteq$$</mark> 分别换成 <mark>$$\cap,\cup,\supseteq,\subseteq$$</mark>，并将式中 <mark>每个集换成它的余集</mark>，那么关系式依然成立。

- 笛卡尔积：$$A\times B = \{(a,b) \mid a \in A and b \in B\}$$.
  - 笛卡尔积对并、交、差分别满足分配律。
    - $$A \times (B \cup C) = (A \times B)\cup(A\times C)$$，交差类似。

**基数**

- 记法：A 的基数记为 |A|.
- 乘积法则：|AxB|=|A|x|B|.
- |A∪B|=|A|+|B|-|A∩B|.
- |A△B|=|A|+|B|-2|A∩B|.