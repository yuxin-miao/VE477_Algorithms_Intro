# Stable marriage problem, Gale-Shapley algorithm
# sample input: 4 (number of woman / man)
# 0 1 2 3 (man's preference)
# 0 3 2 1
# 0 2 3 1
# 0 2 1 3
#
# 2 1 0 3 (woman's preference)
# 3 0 1 2
# 2 3 0 1
# 0 1 2 3


def gale_shaply(man_pre, woman_pre):
    w_engage = [-1 for i in range(len(woman_pre))]  # engaged woman's pair
    m_free = [1 for i in range(len(man_pre))]  # all man free
    m_propose = [[0] * len(woman_pre) for i in range(len(man_pre))]  # whether a man propose to a woman
    while 1 in m_free:
        m_index = m_free.index(1)
        m_pre = man_pre[m_index]
        favorite = 0
        while m_propose[m_index][favorite] != 0:  # find the favorite woman not proposed
            favorite += 1

        m_propose[m_index][favorite] = 1           # man propose to woman
        wo_index = m_pre[favorite]

        if w_engage[wo_index] == -1:
            m_free[m_index] = 0
            w_engage[wo_index] = m_index
        else:
            m_dot = w_engage[wo_index]
            wo_pre = woman_pre[wo_index]
            if wo_pre.index(m_dot) < wo_pre.index(m_index):
                m_free[m_index] = 1
            else:
                w_engage[wo_index] = m_index
                m_free[m_index] = 0
                m_free[m_dot] = 1

    return w_engage


man_num = int(input())
man_count, woman_count = 0, 0
man_list = []
while man_count < man_num:
    man_list.append([int(item) for item in input().split()])
    man_count += 1

woman_num = man_num
woman_list = []
empty_line = input()  # discard the empty line
while woman_count < woman_num:
    woman_list.append([int(item) for item in input().split()])
    woman_count += 1

w_en = gale_shaply(man_list, woman_list)
result = []
for i in range(len(w_en)):
    result.extend([[i, w_en.index(i)]])

print(result)
