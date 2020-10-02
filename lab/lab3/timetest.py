import os
from tqdm import tqdm
import random
import matplotlib.pyplot as plt
import pandas as pd

numbers = [i for i in range(300)]
# input size: from 2 to xmax
smalltime, largetime, kptime = [], [], []
xmax = 150
for a in tqdm(range(2, xmax)):
    _sum = random.randint(10, 20) * a  # target number
    array_input = random.sample(numbers, a)
    with open("subset.in", "w+") as f:
        print(_sum, file=f)
        print(*array_input, sep=' ', file=f)
    # write the file used for input

    timetwo = os.popen("python3 greedy.py < subset.in").read()
    # time_one = os.popen("python3 knapsack.py < subset.in").read()
    timelist = list(map(float, timetwo.split()))
    smalltime.append(timelist[0])
    largetime.append(timelist[1])
    # kptime.append(float(time_one))

xlist = [i for i in range(2, xmax)]
df = pd.DataFrame(data=smalltime, index=xlist, columns=["small_first"])
df["large_first"] = largetime
# df["correct_algo"] = kptime
# print(df)
plt.scatter(xlist, smalltime, marker='o', color='blue', label="small first", alpha=0.6)
plt.scatter(xlist, largetime, marker='x', color='red', label="large first", alpha=0.6)
# plt.scatter(xlist, kptime, marker='*', color='green', label="correct algo", alpha=0.6)
plt.legend(loc='best')
plt.show()
