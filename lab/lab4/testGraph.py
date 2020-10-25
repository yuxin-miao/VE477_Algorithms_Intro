import os
import time
from tqdm import tqdm
from random import randint

for edge_num in range(3000, 3001, 10):
    with open("5in.txt", "w+") as f:
        f.write(str(edge_num) + '\n')
        start = randint(0, 50)
        for count in range(int(edge_num/5)):
            if count < 10:
                v = start * (count + 1)
            else:
                v = start * (randint(10, 20))
            for v_time in range(5):
                x = str(randint(0, 50))
                f.write(str(v) + ' ' + x + ' ' + str(randint(10000, 100000)) + '\n')

        f.write(str(start) + '\n')
        f.write(x + '\n')

    # yxm = os.popen("python3 Dijkstra.py < 5in.txt").read()
    # print(yxm)
