import numpy as np
def genInput(n):
    nums = np.random.randint(1,n,size=n)
    return [str(num) for num in nums]

with open('test.txt', 'w') as f:
    for i in range(100):
        n = np.random.randint(2,200,size=1)
        nums = genInput(n)
        f.write(' '.join(nums)+'\n')