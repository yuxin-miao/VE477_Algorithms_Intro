import random
import timeit
import numpy as np


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


def LinearSearch(A, k):
    n = len(A)
    for i in range(n):
        if A[i] == k:
            return i
    return n  # not found, index out of range


def ScrambleSearch(A, k):
    random.shuffle(A)
    return LinearSearch(A, k)


if __name__ == '__main__':
    random.seed()
    arr_len = 1000000
    arr = [random.randint(0, arr_len * 10) for i in range(arr_len)]
    random_time, linear_time, scramble_time = [], [], []
    for i in range(1000):
        key = random.randint(0, arr_len)
        random_time.append(timeit.timeit("RandomSearch(arr, key)",
                                         setup="from __main__ import RandomSearch, arr, key", number=3))
        # print("1000 times random search time: {}".format(random_time))
        linear_time.append(timeit.timeit("LinearSearch(arr, key)",
                                         setup="from __main__ import LinearSearch, arr, key", number=3))
        # print("1000 times linear search time: {}".format(linear_time))
        scramble_time.append(timeit.timeit("ScrambleSearch(arr, key)",
                                           setup="from __main__ import ScrambleSearch, arr, key", number=3))
        # print("1000 times linear search time: {}".format(scramble_time))
    print("1000 times random search time: {}".format(np.mean(random_time)))
    print("1000 times linear search time: {}".format(np.mean(linear_time)))
    print("1000 times linear search time: {}".format(np.mean(scramble_time)))
