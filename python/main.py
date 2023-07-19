import time
def a():
    x = 0
    init = time.time()
    for i in range(int(1e9)):
        # print(i)
        x = (x + 1)/2
    print(time.time()-init)
a()