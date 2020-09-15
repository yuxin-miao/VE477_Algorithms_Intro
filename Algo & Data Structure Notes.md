

![image-20200915132328058](/Users/yuxinmiao/Library/Application Support/typora-user-images/image-20200915132328058.png)

## Sorting

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



