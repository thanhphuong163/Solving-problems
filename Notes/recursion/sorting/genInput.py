import numpy as np
def genInput(n):
    nums = np.random.randint(1,n,size=n)
    return [str(num) for num in nums]

with open('input.txt', 'w') as f:
    for i in range(200):
        n = np.random.randint(10,300,size=1)
        nums = genInput(n)
        f.write(' '.join(nums)+'\n')