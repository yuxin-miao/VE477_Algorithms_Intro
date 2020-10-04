import timeit
import matplotlib.pyplot as plt
import pandas as pd
from tqdm import tqdm


def accel_asc(n):
    a = [0 for i in range(n + 1)]
    k = 1
    y = n - 1
    while k != 0:
        x = a[k - 1] + 1
        k -= 1
        while 2 * x <= y:
            a[k] = x
            y -= x
            k += 1
        l = k + 1
        while x <= y:
            a[k] = x
            a[l] = y
            yield a[:k + 2]
            x += 1
            y -= 1
        a[k] = x + y
        y = x + y - 1
        yield a[:k + 1]


def rule_asc(n):
    a = [0 for i in range(n + 1)]
    k = 1
    a[1] = n
    while k != 0:
        x = a[k - 1] + 1
        y = a[k] - 1
        k -= 1
        while x <= y:
            a[k] = x
            y -= x
            k += 1
        a[k] = x + y
        yield a[:k + 1]


def printArray(p, n):
    for i in range(0, n):
        print(p[i], end=" ")
    print()


def printAllUniqueParts(n):
    p = [0] * n  # An array to store a partition
    k = 0  # Index of last element in a partition
    p[k] = n  # Initialize first partition

    while True:

        # print current partition
        # printArray(p, k + 1)
        rem_val = 0
        while k >= 0 and p[k] == 1:
            rem_val += p[k]
            k -= 1
        if k < 0:
            # print()
            return

        p[k] -= 1
        rem_val += 1

        while rem_val > p[k]:
            p[k + 1] = p[k]
            rem_val = rem_val - p[k]
            k += 1

        p[k + 1] = rem_val
        k += 1


# Driver Code
# g = rule_asc(6)
# f = accel_asc(6)
# while True:
#   try:
#        print(next(g))
#    except StopIteration:
#        break


algo1 = []
algo2 = []
algo3 = []
nmax = 15
for i in tqdm(range(3, nmax)):
    t = timeit.Timer(stmt="list(accel_asc(i))", setup="from __main__ import accel_asc, i")
    algo3.append(t.timeit())
    t1 = timeit.Timer(stmt="list(rule_asc(i))", setup="from __main__ import rule_asc, i")
    algo2.append(t1.timeit())
    algo1.append(timeit.timeit("printAllUniqueParts(i)", setup="from __main__ import printAllUniqueParts, i"))


xlist = [i for i in range(3, nmax)]
df = pd.DataFrame(data=algo1, index=xlist, columns=["Descending"])
df["Ascending1"] = algo2
df["Ascending2"] = algo3
print(df)
plt.scatter(xlist, algo1, marker='o', color='blue', label="descending", alpha=0.6)
plt.scatter(xlist, algo2, marker='x', color='red', label="ascending1", alpha=0.6)
plt.scatter(xlist, algo3, marker='*', color='green', label="ascending2", alpha=0.6)
plt.legend(loc='best')
plt.show()

