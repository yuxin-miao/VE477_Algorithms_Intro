from random import randint, choice
from FibonacciHeap import FibHeap, verbose
import copy


def receiveTxt():
    aa = FibHeap()
    ll = input().split(', ')
    nums = []
    for item in ll:
        aa.insert(int(item))
        nums.append(int(item))
    return aa, nums


def randomTest():
    a = FibHeap()
    nums = []

    for i in range(randint(1, 100)):
        num = randint(-100, 100)
        a.insert(num)
        nums.append(num)

    return a, nums


if __name__ == '__main__':
    '''random or input txt'''
    fib, answer = receiveTxt()
    while True:
        fib, answer = randomTest()
        input_txt = copy.deepcopy(answer)
        # print(answer)
        result = []
        answer.sort()
        # print(answer)
        while fib.minimum():
            result.append(fib.minimum().key)
            fib.extract_min()
        # print(result)
        if result != answer:
            print(input_txt)
            print(answer)
            print(result)
            break



    '''pre insert test'''

    # fib_copy = copy.deepcopy(fib)
    # answer.sort()
    # print(answer)
    # pre_result = []
    # count = 0
    # while fib_copy.minimum():
    #     pre_result.append(fib_copy.minimum().key)
    #     fib_copy.extract_min()
    #     if verbose:
    #         count = count + 1
    #         print("**** EM time {} finish****".format(count))
    #
    # print(pre_result)
    #
    # fib.shell()
