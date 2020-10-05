def sumList(a):
    if len(a) == 0:
        return
    if len(a) == 1:
        return a[0]
    else:
        return a[-1] + sumList(a[:-1])

def convert2Base(n, base):
    digits = ['a','b','c','d','e','f']
    if n == 0:
        return ""
    else:
        return convert2Base(int(n/base), base) + str(n % base if n % base < 10 else digits[n % base - 10])

def sumRecursion(lst):
    if len(lst) == 0:
        return 0
    else:
        return (lst[-1] if type(lst[-1]) == int else sumRecursion(lst[-1])) + sumRecursion(lst[:-1])

def sumDigits(n):
    if n:
        return (n % 10) + sumDigits(int(n / 10))
    else:
        return 0

def power(n,e):
    if e > 1:
        return n * power(n,e-1)
    elif e == 1:
        return n
    else:
        return 1

def gcd(m,n):
    if m == n:
        return m
    else:
        return gcd(min(m,n), abs(m-n))

if __name__ == "__main__":
    a = [1,2,[3,4],[5,6,[7,8]]]
    n = 16
    e = 32
    print(gcd(n, e))
    
