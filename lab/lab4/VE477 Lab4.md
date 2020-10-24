<p align="right"> 于欣淼 518021910792 </p>

# VE477 Lab4

### Q1 

The implementation of Fibonacci heap is attached at the end 

### Q2

denote the number of items in the heap as $n$.

| Procedure     | Fibonacci Heap  (amortized) |
| ------------- | --------------------------- |
| `MakeHeap`    | $\Theta(1)$                 |
| `Insert`      | $\Theta(1)$                 |
| `Minimum`     | $\Theta(1)$                 |
| `ExtractMin`  | $\Theta(\rm{log}n)$         |
| `Union`       | $\Theta(1)$                 |
| `DecreaseKey` | $\Theta(1)$                 |
| `Delete`      | $\Theta(\rm{log}n)$         |

### Q3

- List the running time for operations on these two implementations

| Procedure     | Binary Heap (worst-case) | Fibonacci Heap  (amortized) |
| ------------- | ------------------------ | --------------------------- |
| `MakeHeap`    | $\Theta(1)$              | $\Theta(1)$                 |
| `Insert`      | $\Theta(\rm{log}n)$      | $\Theta(1)$                 |
| `Minimum`     | $\Theta(1)$              | $\Theta(1)$                 |
| `ExtractMin`  | $\Theta(\rm{log}n)$      | $\Theta(\rm{log}n)$         |
| `Union`       | $\Theta(n)$              | $\Theta(1)$                 |
| `DecreaseKey` | $\Theta(\rm{log}n)$      | $\Theta(1)$                 |
| `Delete`      | $\Theta(\rm{log}n)$      | $\Theta(\rm{log}n)$         |

Notice that the the running time of binary heap is analyzed based on worst-case while the of fibonacci heap is amortized analysis. So Fibonacci Heap performs better for `Insert`, `Union`, `DecreaseKey`, but might be worse for `ExtractMin` and `Delete`. 

- Advantages of Fibonacci Heap: supports a set of operations to be “mergeable heap” with running in constant amortized time, suitable when not much `ExtractMin` and `Delete` operations are needed. 
- Disadvantages of Fibonacci Heap: hard to implement and constant factors.

### Q4

With a constant amortized running time for `Insert`, `Union` and `DecreaseKey`, the circumstances that we need to perform much of such operations will prefer Fibonacci heap. 

So for **Dijkstra and Prim algorithm**, the reduced time complexity of `DecreaseKey` is really important. As time complexity is $\mathcal{O}(VlogV+ElogE)$ with binary heap and could be reduced to $\mathcal{O}(VlogV+E)$ with Fibonacci Heap. 



```python
import math


class Node:
    def __init__(self, key=0, parent=None, child=None, degree=0, mark=False):
        self.key = key
        self.parent = parent
        self.child = child
        self.degree = degree
        self.mark = mark
        self.right = self
        self.left = self


class FibHeap:
    def __init__(self, h_min=None, n=0):
        self.h_min = h_min
        self.n = n

    # need to perform MakeHeap?

    def __remove_from_list(self, x):
        if x.right is x:
            return None
        else:
            x.left.right = x.right
            x.right.left = x.left

    def __add_in_list(self, y, x):
        # x is an element in a circular doubly-linked list
        # insert y into this list
        if x is None or y is None:
            return
        if y is x:
            return
        # y.left = y.right = y  # to insert, make sure y is a single element
        y.right = x
        x.left.right = y
        y.left = x.left
        x.left = y

    def insert(self, x):
        new_node = Node(key=x)
        if not self.h_min:  # the heap is empty
            self.h_min = new_node
        else:  # insert the new_node into root list
            self.__add_in_list(new_node, self.h_min)
            if new_node.key < self.h_min.key:  # update H.min if needed
                self.h_min = new_node
        self.n = self.n + 1  # increase the root number of H

    def minimum(self):
        return self.h_min

    def link(self, y, x):
        # remove y from root list
        self.__remove_from_list(y)
        printNode(x)
        # make y a child of x
        y.left = y.right = y
        y.parent = x
        if not x.child:
            x.child = y
        self.__add_in_list(y, x.child)
        if y.key < x.child.key:
            x.child = y
        # increment x.degree
        x.degree = x.degree + 1
        y.mark = False  # y newly become a child

    def consolidate(self):
        # utility function for extract_min to consolidate teh root list of H
        # decrease the number of trees in H
        max_degree = math.ceil(math.log(self.n, 2))
        root_degree = [None] * (max_degree + 1)
        root_degree[self.h_min.degree] = self.h_min  # put H.min according to its degree
        w = self.h_min.right  # begin to scan from right of H.min
        min_to_stop = self.h_min
        while w is not min_to_stop:
            d = w.degree
            x = w
            while root_degree[d]:
                y = root_degree[d]  # y is another node that has same degree as x
                if x.key > y.key:
                    temp = x
                    x = y
                    y = temp
                if y.right is min_to_stop:  # otherwise the loop will not end
                    min_to_stop = x
                self.link(y, x)
                if x.right is x:
                    min_to_stop = x
                root_degree[d] = None
                d = d + 1
            root_degree[d] = x  # x newly have one more child (x)
            w = x.right
        self.h_min = None
        # rebuild the root list of H
        for item in root_degree:
            if item:
                # all nodes in root_degree is treated as a root node
                # no left / right
                item.left = item.right = item
                if not self.h_min:
                    self.h_min = item
                else:
                    self.__add_in_list(item, self.h_min)
                    if item.key < self.h_min.key:
                        self.h_min = item

    def extract_min(self):
        z = self.h_min  # the node that will be returned
        if z:
            x = z.child
            if x:
                while True:
                    # add x into z's list (H's root list)
                    temp = x.right
                    self.__add_in_list(x, z)
                    x.parent = None
                    x = temp
                    if x is z.child:
                        break
            # remove z from z's list
            check = (z == z.right)
            self.__remove_from_list(z)
            printList(z.right)
            if check:  # only one element
                self.h_min = None
            else:
                self.h_min = z.right
                self.consolidate()
            self.n = self.n - 1
        return z

    def union(self, h2):
        # will return a new heap that is the union of self and h2
        new_h = FibHeap()
        new_h.h_min = self.h_min
        new_h.h_min.right.left = h2.h_min.left
        h2.h_min.left.right = new_h.h_min.right

        new_h.h_min.right = h2.h_min
        h2.h_min.left = new_h.h_min
        new_h.n = self.n + h2.n
        if not self.h_min:
            new_h.h_min = h2.h_min
        elif h2.h_min:
            if h2.h_min.key < self.h_min.key:
                new_h.h_min = h2.h_min
        return new_h

    def __cut(self, x, y):
        # x.parent = y, _cut x and y
        check = (x == x.right)
        self.__remove_from_list(x)
        if check:  # x is the only element in this list
            y.child = None
        x.parent = None
        # add x to the root list of H
        self.__add_in_list(x, self.h_min)
        x.mark = False
        y.degree = y.degree - 1

    def __cas_cut(self, y):
        z = y.parent
        if not z:
            return
        if not y.mark:
            y.mark = True
        else:
            self.__cut(y, z)
            self.__cas_cut(z)

    def decrease_key(self, x, k):
        # EFFECTS: decrease the key of x to k
        if k > x.key:  # could not decrease
            return
        x.key = k
        y = x.parent
        if y and x.key < y.key:
            # _cut x and y, also cascading _cut the parent of x
            self.__cut(x, y)
            self.__cas_cut(y)
        # update H.min if needed
        if x.key < self.h_min.key:
            self.h_min = x

    def delete(self, x):
        # delete x from heap
        # make x as H.min through decreasing x's key
        self.decrease_key(x, float("-inf"))
        printRootList(self)
        self.extract_min()
```

