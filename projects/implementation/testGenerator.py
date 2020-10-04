def f(limit):
    for i in range(limit):
        if(i / 7.0) % 1 == 0:
            yield i

def f1(limit):
    l = []
    for i in range(limit):
        if(i / 7.0) % 1 == 0:
            l.append(i)
    return l

import timeit

t = timeit.Timer(stmt="list(f(50))", setup="from __main__ import f")
print(t.timeit())

t1 = timeit.Timer(stmt="f1(50)", setup="from __main__ import f1")
print(t1.timeit())