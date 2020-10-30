import math

verbose = False


class Node:
    def __init__(self, key=0, value=None, parent=None, child=None, degree=0, mark=False):
        self.key = key
        self.value = value  # used for dijkstra
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
        if verbose:
            print("(1.) remove x [{}] from x's list, result: ".format(x.key))
        if x.right is x:
            return None
        else:
            x.left.right = x.right
            x.right.left = x.left
        if verbose:
            printList(x.right)

    def __add_in_list(self, y, x):
        # x is an element in a circular doubly-linked list
        # insert y into this list at x's left

        if x is None or y is None:
            return
        if y is x:
            return
        if verbose:
            print("(2.) add y [{}] into x[{}]'s list at x left, result: ".format(y.key, x.key), end='')
        # y.left = y.right = y  # to insert, make sure y is a single element
        y.right = x
        x.left.right = y
        y.left = x.left
        x.left = y
        if verbose:
            printList(x)

    def insert(self, x, vertex=None):
        new_node = Node(key=x, value=vertex)
        if not self.h_min:  # the heap is empty
            self.h_min = new_node
        else:  # insert the new_node into root list
            self.__add_in_list(new_node, self.h_min)
            if new_node.key < self.h_min.key:  # update H.min if needed
                self.h_min = new_node
        self.n = self.n + 1  # increase the root number of H
        # print(self.h_min.key)
        return new_node

    def minimum(self):
        return self.h_min

    def link(self, y, x):
        # remove y from root list
        if verbose:
            print("3. link y [{}] -> x [{}]".format(y.key, x.key))
            print("before link y->x: ", end='')
            printList(y)
        self.__remove_from_list(y)

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
        if verbose:
            print("after link y->x: ", end='')
            printList(x)

    def consolidate(self):
        # utility function for extract_min to consolidate teh root list of H
        # decrease the number of trees in H
        max_degree = math.ceil(math.log(self.n, 2))
        root_degree = [None] * (max_degree + 1)
        root_degree[self.h_min.degree] = self.h_min  # put H.min according to its degree
        w = self.h_min.right  # begin to scan from right of H.min
        min_to_stop = self.h_min
        root_list = [min_to_stop]
        while w is not min_to_stop:
            root_list.append(w)
            w = w.right

        for w in root_list:
            d = w.degree
            x = w

            while root_degree[d]:
                if root_degree[d] is w:
                    break
                y = root_degree[d]  # y is another node that has same degree as x
                if x.key > y.key:
                    temp = x
                    x = y
                    y = temp
                # if y.right is min_to_stop:  # otherwise the loop will not end
                #     min_to_stop = x
                self.link(y, x)
                # if y is min_to_stop:  # the original stop point links to x
                #     min_to_stop = x
                # if x.right is x:
                #     min_to_stop = x
                root_degree[d] = None
                d = d + 1
            root_degree[d] = x  # x newly have one more child (x)

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
                    # add x into z's list (H's root list) (at z's left)
                    temp = x.right
                    self.__add_in_list(x, z)
                    x.parent = None
                    x = temp
                    if x is z.child:
                        break
            # remove z from z's list
            check = (z == z.right)
            self.__remove_from_list(z)
            if verbose:
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
        if verbose:
            print("cut x[{}] (as child) from y[{}]".format(x.key, y.key))
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
        if verbose:
            print("cas_cut y[{}]".format(y.key))
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
        if verbose:
            print("decrease key [{}] to [{}]".format(x.key, k))
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
        # printRootList(self)
        self.extract_min()


def printRootList(h: 'FibHeap'):
    print("root list: " + str(h.h_min.key), end=' ')
    rh = h.h_min.right
    while rh is not h.h_min:
        print(rh.key, end=' ')
        # printNode(rh)
        rh = rh.right
    print('\n')


def printNode(node: 'Node'):
    if not node:
        return None
    print('node: ' + str(node.key) + ', degree: ' + str(node.degree))
    chfir = node.child
    print('child is: ', end='')
    for num in range(node.degree):
        print(chfir.key, end=' ')
        chfir = chfir.right
    print('\n')


def printList(node: 'Node'):
    # print the list the node is in
    if node is None:
        print("Empty")
        return
    x = node.right
    print(node.key, end=' ')
    while x is not node:
        print(x.key, end=' ')
        x = x.right
    print('\n')

# fib = FibHeap()
# fib2 = FibHeap()
# for i in range(5, 7):
#     fib.insert(i)
#     fib2.insert(i + 10)
#
# for i in range(3):
#     fib.insert(i)
#     fib2.insert(i - 3)

# printRootList(fib)
# fib.extract_min()
# printRootList(fib)
# fib.delete(fib.h_min.child.left)
# printRootList(fib)
