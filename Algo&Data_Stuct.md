[TOC]

## Time complexity

![image-20200915132328058](/Users/yuxinmiao/Library/Application Support/typora-user-images/image-20200915132328058.png)

### Solve Recurrence

**Master method:** $T(n) \leq aT(\frac{n}{b}) + O(n^d)$

- base case: for sufficiently small $n$, $T(n) < constant$
- a = number of recursive calls (positive integer)
- b = input size shrinking factor (positive integer)
- $O(n^d)$: the runtime of merging solutions. d is a real value $\geq $ 0
- a, b, d : independent of n
- ![image-20200917083956683](/Users/yuxinmiao/Library/Application Support/typora-user-images/image-20200917083956683.png)
   	1. In merge sort, a=2, b=2, d=1
   	2. in binary search, a=1, b=2, d=0

## Divide-and-conquer Approach

- merge sort 
- Quick sort 

## Sorting

A sorting algorithm that is based on pairwise comparisons mush use $\Omega (NlogN)$ operations to sort in the worst case

Reorder array A of size N with consistent comparison function

- in place: requires $\mathcal{O}(1)$ additional memory；不占用额外内存，只利用原来存储待排数据的存储空间进行比较和交换。

  ​	“ Space usage affects the constant factor, because the memory access takes time. Modern computers are based on memory hierarchy. The top is small cache, but extremely fast. If O(1) additional space, it can be fit inside the cache and then, the program is fast; otherwise, it cannot be fit inside the cache, which needs to read the secondary memory, which takes time. ”

- Stability: whether the algorithm maintains the relative order of records with equal keys

|             | Best Case Time               | Worst  Case Time    | Average Case Time | In Place | Stable |
| ----------- | ---------------------------- | ------------------- | ----------------- | -------- | ------ |
| Insertion   | O(N) sorted array            | O($N^2$)  逆序array | O($N^2$)          | Yes      | Yes    |
| Selection   | О(n2) comparisons, O(1) Swap | O($N^2$)            | O($N^2$)          | Yes      | No     |
| Bubble      |                              | O($N^2$)            | O($N^2$)          | Yes      | Yes    |
| Merge Sort  |                              | O($N log⁡N$)         | O($N log⁡N$)       | No       | Yes    |
| Quick  Sort |                              | O($N^2$)            | O($N log⁡N$)       | Weakly   | No     |

### Comparison Sort

Each item is compared against others to determine its order

![img](https://cdn.jsdelivr.net/gh/zhyjc6/My-Pictures/2020/03/20200330143209.png)

![img](https://www.runoob.com/wp-content/uploads/2019/03/0B319B38-B70E-4118-B897-74EFA7E368F9.png)



​	

### Non-comparison Sort / distribution-based sort

- each item is put into predifined “bins”, independent of other items; no comparison with other items needed
- Counting sort / bucket sort / radix sort



In-place and not in-place both merge sort each subarray recursively, the difference is in the `merge`  function. For the marge sort discussed in the class, $$\leq $$ is used to compare so that it is stable. 

In-place merge sort need to shift all the element because no additional memory (like the additional array in slides), so time complexity $$O(n^2)$$ not $$O(nlogn)$$ any more. 





## Dynamic Programming

https://www.zhihu.com/question/23995189

### intro

用尽量少的1，5，11凑出15；贪心策略$15 = 1 * 11 + 4 *1$, 五张。

正确的为$15 = 3 * 5$， 三张。 贪心策略为尽量使之后面对的w更少，只考虑眼前情况

用$f(n)$ 表示凑出n所需要的最少数量。与1，5，11各用了多少无关。

Cost = f(4) + 11 / f(10) + 5 / f(14) + 1 -> $f(n) = min\{ f(n-1),f(n-5),f(n-11)\} + 1 $

以$\mathcal{O}(n)$ 复杂度解决

- 将一个问题拆成几个子问题，分别求解这些子问题，即可推断出大问题的解

- Definitions: (DP 需要满足的前提)
  - 无后效性：确定f(n)后，如何凑出f(n)即无关
  - 最优子结构: f(n)即为小问题的**最优解**， 因此可以得出大问题的**最优解**

DP: 枚举有可能成为答案的解，自带剪枝 - 尽量缩小可能解空间

### knapsack problem



## union-find 

A *[disjoint-set data structure](http://en.wikipedia.org/wiki/Disjoint-set_data_structure)* is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A [*union-find algorithm*](http://en.wikipedia.org/wiki/Disjoint-set_data_structure) is an algorithm that performs two useful operations on such a data structure:

并查集是一种树型的数据结构，用于处理一些不交集的合并及查询问题; 不能将在同一组的元素拆开

 two operations  

- `Find(v)`: find the root of the tree for vertex $v$
- `Union(v, w)`: link the root of the tree containg vertex $v$ to the root of tree containing vertex $w$ 

两处优化

- When `Find`, update all the nodes along the path (all link them to the root directly)
- When `Union`, set the root with higher depth as the parent of another root (minimize the depth of the tree) 

## MST (Minimum Spnning Tree)

1. Definitions

- **tree**: acyclic, connected undirected graph; $|E| = |V| - 1$ 
- any connected graph with $N$ nodes and $N-1$ edges is a tree
- graph $G=(V,E)$, **subgraph** $G’ = (V’,E’)$ iff $V’\subseteq V \& U’\subseteq U$ 
- **spanning tree** of a connected undirected graph $G$ is a subgraph of $G$ that contains all the nodes and is a tree.
- weighted, connected and undirected graph -> **MST**, which is a spanning tree with the minimum sum of weights.
- $T$ is a tree: if it contained a cycle, at least one edge could be removed, allowing a lower weight while preserving the connected property of $T$

2. Algorithms 

   **a. Prim’s Algorithm** 

   - $V = T \cup T’$ , $T:$ nodes added to MST; $T’:$ nodes not in MST

   - For each node $v \in T’$, keep a measure $D(v)$ storing **current smallest weight** over all edges that connect $v$ to a node in $T$
   - Keep $P(v)$ for each node $v$: $(P(v),  v)$ is the edge chosen in MST

   Full version:

   1) Pick one node $s$, set $D(s) = 0$, for any other node $v$, set $D(v)=\infty$ and $P(v)$ unknown

   2) Set $T’ = V$

   3) While $T’ \neq \emptyset $

   - For all nodes in $T’$, choose a node $v$ that has the smallest $D(v)$.
   - Remove $v$ from set $T'$
   - For $v’s$ neighbors $u$ that still in $T’$, if exist $D(u)>w(v,u)$, then update $D(u)$ as $w(v,u)$  and $P(u)$ as $v$

   **b. Krustal’s Algorithm** 

   Greedy Algorithm, union-find data structure 

   - sort all the edges $G.E$ by weight 
   - for edges in $G.E$ in non-decreasing order, adding them into $T$ if no cycle would be created 

   To check whether a cycle will be created, union find: whether two edges have the same root `Find` ; add them: `Union`



## Binary Search Tree

### 定义

* 空树是一棵BST
* 对于任意节点，它的key比左树的**所有**子节点大，比右树的**所有**子节点小
* 所有操作的平均复杂度: $O(\log n)$

For balanced tree: $h = logn$ ; so need to rebalance the tree if it is unbalanced       

### 操作

#### Search

* node *search(node *root, Key k)

* 递归搜索：若与当前node相同则返回，小于则搜索left，大于则搜索right

#### Insertion

* void insert(node *&root, Item item)：使用reference-to-pointer，因为是直接针对节点的修改，而不是修改值（修改pointer本身而非修改pointer指向）
* 假装搜索，插到最后搜索为NULL的地方
* 若key重复会直接无视（判断key的时候不要写else，写else if）

#### Remove

* void remove(node *&root, Key k)
* 若为leaf：直接删除（先delete后置为NULL）
* 若为单节点：删掉后把下面的接上
* 若为双节点：把该节点赋值为左树最大值（此时不要直接改pointer），把左树最大值节点接为其左子树（可能为leaf也可能为单节点），最后delete最大值节点

### 额外操作

#### Output in Sorted Order 排序输出

* 直接中序遍历输出 (In-order DFS): $O(n)$

#### Get Min/Max

* 一直往左/右遍历直到尽头
* $O(height)$ 平均: $O(\log n)$

#### Get Predecssor

* 用helper function递归，或者迭代实现
* $O(height)$ 平均: $O(\log n)$
* search目标key，途中记录first left ancestor(如果往右search了就记录root)
* 搜索到key后，如果左树非空，则返回左树Max，否则返回first left ancestor

#### Rank Search

* 最小项rank为0
* node增加额外的变量`int leftSize`，记录左树节点个数
* remove和insert方法都需要修改：途中更新leftSize
* leftSize代表每个节点在以该节点为根的子树中的rank
* else return rankSearch(root->right, rank – 1 - root->leftSize);
* $O(height)$ 平均: $O(\log n)$

#### Range Search

* void **rangeSearch**(node **root**, Key **searchRange**[], Key **treeRange**[], List **results**)
* $O(n) $
* In-order搜索，所以结果也是排序的
* 左树重叠则继续搜索；root在范围内则加入结果；右树重叠则继续搜索
* 搜搜过程中更新range
* 本操作修改后可用于检验BST

## K-d Tree

### 定义

* 每一层有不同的discriminator
* $O(\log⁡ n)$ insert and search 时间
* 左节点在**当前维度**上key小于根节点，右节点同理
* 不同维度循环使用

### 操作

#### Insertion

* 维度循环，直到NULL插入

#### Search

* 纬度循环，直到key完全相同

#### Remove

* 找到右树中**当前维度**最小的值（如果没有就找左树最大值），用其替换需要删除的node
* 递归删除用于替换的最大值/最小值节点，递归删除那个节点
* 直到删除一个leaf为止

#### FindMin

* 先找左树最小值
* 如果当前维度和要找的维度不同，则再找一下右树最小值
* 返回左树最小值，root，右树最小值中最小的

#### RangeSearch

* Key **searchRange**[], Key **treeRange**[] 两个数组，存放2*dim个元素，描述每个维度的range
* 若和左树在当前维度有重合，则search左树，更新range
* 若root在range中，则加入
* 若和右树在当前维度有重合，则search右树，更新range

## AVL Tree

### 定义

* search, insertion, removal平均复杂度$O(\log n)$，且不会退化
* AVL Balanced: 
  * 空树是AVL Balanced的
  * 一棵非空树，若其左/右子树均AVL Balanced，且左右子树高度差至多为1
* Balance Factor:  $B_T=h_l-h_r \leq 1$

### 操作

#### 平衡修复

* fix **the first unbalanced** **node** in the access path **from the leaf**.

* 根据元素插入的路径来选择修复手段：
  * 左->左: LL Rotation，向右转一次，高度和插入前相等
  * 右->右: RR Rotation，向左转一次，高度和插入前相等
  * 左->右：父节点向左，祖父向右
  * 右->左：父节点向右，祖父向左
* 只需修复一次











