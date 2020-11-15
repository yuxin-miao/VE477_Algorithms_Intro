# VE477 Lab7

### Q1

1. `RandomSearch`

   ```python
   # random search array A for a given key k
   def RandomSearch(A, k):
       index_set = set()
       n = len(A)
       while len(index_set) < n:
           index = random.randint(0, n - 1)
           if A[index] == k:
               return index
           index_set.add(index)
       return n  # not found, index out of range
   ```

2. a) **no index**: average number of picked index is approximately $n\text{ln}n$

   Define each time we found a new index as a *hit*, so we want to know the expected number $x$ to obtain $n$ *hits*. Partition $x$ into stages, such that the $i$th stage contains the choosing between $i-1$th $hit$ and $i$th $hit$. 

   For each chosen during the $i$th stage, $(i-1)$ index have been chosen, $(n-i+1)$ index have not been chosen. So the probability of getting a $hit$ is $(n-i+1)/n$. 

   Use $x_i$ to denote the number of chosen during stage $i$. The total number of chosen is $x=\sum_{i=1}^nx_i$. $E[x_i]=n/(n-i+1)$. Then we get 
   $$
   E[x]=E[\sum_{i=1}^nx_i]=\sum_{i=1}^nE[x_i]=\sum_{i=1}^n\frac{n}{n-i+1}=n\sum_{i=1}^n\frac{1}{i}=n(\text{ln}n+O(1))
   $$
   b) **one index**: average number is $n$.

   Then each pick is a bernoulli trial with parameter $p=1/n$, to get a total number of success as $1$, from the expectation of binomial distribution, we should pick $n$ indices. 

   c) **more than one index (assume m)**: average number is $n/m$. 

   Same as b), parameter $p=m/n$, so from expectation should be $n/m$. 

### Q2

1. `LinearSearch`

   ```python
   def LinearSearch(A, k):
       n = len(A)
       for i in range(n):
           if A[i] == k:
               return i
       return n  # not found, index out of range
   ```

2. a) **no index**: average and worse case should both be $n$

   b) **one index**: average $\displaystyle \frac{n(n+1)}{2}$, worse $n$

   c) **more than one index (assume m)**: average $\displaystyle \frac{n+1}{m+1}$, worse $n-m+1$ 

   $X_i$ denotes the $i-th$  element is the match, then $Pr[X_i]=\frac{1}{m}$





### Q3

1. `ScrambleSearch`

   ```python
   def ScrambleSearch(A, k):
       random.shuffle(A)
       return LinearSearch(A, k)
   ```

2. same as Linear Search 