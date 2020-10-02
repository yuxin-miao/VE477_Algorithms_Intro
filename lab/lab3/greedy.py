# greedy algorithm for Subset Sum problem


def small_first(arr, target):  # fit the knapsack with the smallest items first
    arr.sort()
    result = []
    for i in range(len(arr)):
        if target - sum(result) < arr[i]:
            return []
        else:
            result.append(arr[i])
        if sum(result) == target:
            return result


def large_first(arr, target):
    arr.sort(reverse=True)
    result = []
    for i in range(len(arr)):
        if target - sum(result) < arr[i]:
            continue
        else:
            result.append(arr[i])
        if sum(result) == target_sum:
            return result
    return []


target_sum = int(input())
input_arr = [int(item) for item in input().split()]

if __name__ == '__main__':
    import timeit
    # small_result = small_first(input_arr, target_sum)
    print(timeit.timeit("small_first(input_arr, target_sum)",
                        setup="from __main__ import small_first, input_arr, target_sum", number=100))
    print(timeit.timeit("large_first(input_arr, target_sum)",
                        setup="from __main__ import large_first, input_arr, target_sum", number=100))

    #  print("small first greedy algorithm: {}".format(sorted(small_result)))
