# fib(0) = 0
# fib(1) = 1
# fib(n) = fib(n-1) + fib(n-2), if n > 1
def fib(n):
    if n <= 1:
        return n
    else:
        return fib(n-1) + fib(n-2)


def fib_dp(n, ans):
    if ans[n] == -1:
        if n <= 1:
            ans[n] = n
        else:
            ans[n] = fib_dp(n-1, ans) + fib_dp(n-2, ans)
    return ans[n]


def fib_dp_(n):
    ans = list([0, 1])
    for i in range(2, n+1):
        ans.append(ans[i-1] + ans[i-2])
    return ans[n]


if __name__ == "__main__":
    t = input()  # number of tests
    for i in range(int(t)):
        n = input()
        ans = [-1 for i in range(int(n)+1)]
        print(n)
        print("Result using dp top-down: ", fib_dp(int(n), ans))
        print("Result using dp bottom-up: ", fib_dp_(int(n)))
        print("Result using recursion: ", fib(int(n)))
