# 映射

[TOC]

---
### 几种映射

- **部分映射**：设 $$f:A \rightarrow Y,A \subseteq X$$，则称 f 是 X 上一个部分映射。

- **单射**：设 $$f:X \rightarrow Y, \forall x,x' \in X, if\, x \ne x', \, then \, f(x) \ne f(x')$$，则称 f 为 X 到 Y 的单射。即 **自变量不同，则函数值不同**。（严格单调）

- **满射**：设 $$f:X \rightarrow Y, \, \forall y \in Y, \, \exists x \in X, \, make f(x)=y$$，则称 f 为从 X 到 Y 上的映射，或称 f 为满射。(对每一个函数值，都能找到自变量与之对应)

- **双射**：若 f **既是单射又是满射**，则称 f 为双射，或 **一一对应**。

- **恒等映射**：设 $$f:X \rightarrow X, \, \forall x \in X, f(x)=x$$，称 f 为 X 上的恒等映射，记为 $$I_X$$.

### 一般性质

- **象** 的概念：f(A)={f(x)|x∈A}，称 f(A) 为 A 在 f 下的象。(集合 A 中所有元素的函数值集合)
- **原象** 的概念：B 为 Y 的子集，则由 f 和 B 确定的 X 的一个子集 {x|f(x)∈B, x∈X}  用 $$f^{-1}(B)$$ 表示，叫做在 f 下 B 的原象。(函数值对应的自变量的集合)
- 定理：设 $$f:X \rightarrow Y, C,D \subseteq Y$$，则
  - 原象公式：$$f^{-1}(C \cup D)=f^{-1}(C) \cup f^{-1}(D)$$ (∩、△运算同样满足，象同样满足)。

### 映射的合成

- **定义**：设 $$f:X \rightarrow Y, g: Y \rightarrow Z$$，一个 **从 X 到 Z 的映射** h 称为 f 与 g 的合成。
- **记法**：$$f(f(x))$$ 记为 $$g\circ f$$ 或者简记为 $$gf$$。
- **结合律**：合成运算满足结合律，设 $$f:X \rightarrow Y, g: Y \rightarrow Z, h:Z \rightarrow W$$, 则有 $$h(gf)=(hg)f$$。
- **定理**：设 $$f: X \rightarrow Y, g: Y \rightarrow Z$$，则：
  - 如果 f,g 都是单射，则 gf 也是单射。(满射、双射同样满足)
  - 如果 gf 是单射，则 f 是单射。
  - 如果 gf 是满射，则 g 是满射。
  - 如果 gf 是双射，则 f 是单射，且 g 是满射。

### 逆映射

- **逆映射**：逆映射是反函数概念的推广。设 $$f:X \rightarrow Y$$，如果存在一个映射 $$g:Y \rightarrow X$$ 使得 $$f \circ g = I_Y and g \circ f = I_X$$，则 g 为 f 的逆映射。（函数和反函数，定义域和值域对应）
- **左可逆**：$$g \circ f = I_X$$，则 g 称为 f 的左逆映射。
- **右可逆**：$$f \circ g=I_Y$$，则 g 为 f 的右逆映射。
- **定理**：
  - f 可逆的充要条件是 **f 为双射**（**一一对应**）。
  - f **左可逆** 的充要条件是 **f 为单射**。
  - f **右可逆** 的充要条件是 **f 为满射**。
- **定理**：如果 f 可逆，那么 **逆映射唯一**，记为 $$f^{-1}$$.
- **定理**：$$f: X \rightarrow Y, g: Y \rightarrow Z$$ 都可逆，则 gf 也可逆，且 $$(gf)^{-1}=f^{-1}g^{-1}$$.


### 置换

- **定义**：有限集合 **S 到自身的一一对应** 称为 S 上的一个置换。如果 S 的基数为 n，则称为 n 次置换。
- **乘积**：两个 n 次置换 α 与 β 的 **合成** βα 称为乘积。计算方法就是进行两次一一对应：
  <img src="./image/swap.png" width="600">

- **逆置换**：$$\sigma^{-1}$$ 是将 σ 的 **上下两行交换** 所得的表达式。 
- **k-循环置换**：设 σ 是 S 上的一个 n 次置换，且 $$i_1\sigma = i_2, i_2\sigma = i_3,\cdots,i_{k-1}\sigma=i_k,i_k\sigma=i_1$$，则 σ 是一个 k-循环置换。k=2 时称为对换。
  - (1,2,3) 就可以表示一个 3-循环置换，表示把 1 变成 2，2 变成 3， 3 变成 1，其他不变。
  - 定理：**没有共同数字** 的循环置换满足交换律，即 αβ = βα。
  - **置换的循环分解定理**：每个置换都能被分解成若干个 **没有共同数字** 的循环置换的乘积，且 **分解唯一**（无视顺序）。
  - 每个置换都能被分解成若干个 **对换** 的乘积，且 **分解不唯一**，但对换的个数的 **奇偶性一致**。
