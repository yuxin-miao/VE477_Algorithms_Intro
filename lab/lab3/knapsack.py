# Dynamic Programming for subset problem
# sample input: sum // array
# 4
# 1 2 5
# output the subset in ascending order:  possible solutions


def subset_sum(arr, target):
    subset = [[False for i in range(target + 1)] for i in range(len(arr) + 1)]
    for i in range(len(arr) + 1):
        subset[i][0] = True

    for i in range(1, len(arr) + 1):
        for j in range(1, target + 1):
            if j < arr[i - 1]:
                subset[i][j] = subset[i - 1][j]
            else:
                subset[i][j] = subset[i - 1][j] or subset[i - 1][j - arr[i - 1]]

    return subset


def print_set(arr, target, num, result, dp):
    if num == 0 and target != 0 and dp[1][target]:
        result.append(arr[num])
        print(sorted(result))
        return

    if target == 0:
        print(sorted(result))
        return

    if dp[num][target]:
        new_result = result.copy()
        print_set(arr, target, num - 1, new_result, dp)

    if target >= arr[num]:
        if dp[num][target - arr[num]]:
            result.append(arr[num])
            print_set(arr, target - arr[num], num - 1, result, dp)


target_sum = int(input())
input_arr = [int(item) for item in input().split()]

if __name__ == '__main__':
    import timeit
    print(timeit.timeit("subset_sum(input_arr, target_sum)",
                        setup="from __main__ import subset_sum, input_arr, target_sum", number=100))

# if target_sum == 0:
#    print([])
#    exit()
# dp_ = subset_sum(input_arr, target_sum)
# print_set(input_arr, target_sum, len(input_arr) - 1, [], dp_)
