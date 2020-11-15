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

2. a) **no index `i`**

   Then the number of indices is the number needed to pick all the indices, denote as $X$. The probability of picking any inedx remains $1/n$,  

   

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





### Q3

1. `ScrambleSearch`

