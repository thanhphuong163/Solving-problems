import numpy as np

# O(n log(log(n)))
def countPrime(n):
    isPrime = np.ones((n+1), dtype=int)
    isPrime[0] = 0
    isPrime[1] = 0
    i = 2
    while i*i <= n:
        if isPrime[i] == 1:
            for j in range(i*i, n+1, i):
                isPrime[j] = 0
        i += 1
    return isPrime.sum()

# O(n)
def countPrimeV2(n):
    isPrime = np.ones((n+1), dtype=int)
    prime = []
    spf = [None] * (n+1)
    isPrime[0] = 0
    isPrime[1] = 0
    for i in range(2, n):
        if isPrime[i] == 1:
            prime.append(i)
            spf[i] = i
        j = 0
        while j < len(prime) and i * prime[j] < n and prime[j] <= spf[i]:
            isPrime[i * prime[j]] = 0
            spf[i * prime[j]] = prime[j]
            j += 1
    return len(prime)

n = 30
print(countPrime(n) == countPrimeV2(n))
