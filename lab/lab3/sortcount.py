# Given an array, count the inversions in it and output the sorted array


def merge_count(l1, l2):
    count, i, j = 0, 0, 0
    list_all = []
    while i < len(l1) and j < len(l2):
        if l1[i] <= l2[j]:
            list_all.append(l1[i])
            i += 1
        else:
            list_all.append(l2[j])
            count += len(l1) - i
            j += 1

    if i >= len(l1):
        list_all[len(list_all):] = l2[j:]
    else:
        list_all[len(list_all):] = l1[i:]
    return count, list_all


def sort_count(input_list):
    if len(input_list) == 1:
        return 0, input_list
    else:
        left = input_list[0:int(len(input_list) / 2)]
        right = input_list[int(len(input_list) / 2):]
        count1, list1 = sort_count(left)
        count2, list2 = sort_count(right)
        count3, list3 = merge_count(list1, list2)

    count = count1 + count2 + count3
    return count, list3


# sample input: a list of integer in one line. eg. 3 4 2 1

list0 = [int(item) for item in input().split()]
count_all, result_list = sort_count(list0)
print(count_all)
print(result_list)
