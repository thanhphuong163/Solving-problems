# Problem statement:
# Given denominations of coins and the target amount N.
# What is the number of ways to make up amount N?

# dp[i][last] : the number of ways that sum is $i$ and the last used coin is $last$
# nums = {1, 2, 5}
# dp[i][j] = dp[i-nums[j]][j] + dp[i][j-1]
def solve(N, nums):
    k = len(nums)
    dp = [[0 for j in range(k)] for i in range(N+1)]
    for i in range(k):
        dp[0][i] = 1
    for i in range(1, N+1):
        for j in range(k):
            x = dp[i-nums[j]][j] if i - nums[j] >= 0 else 0
            y = dp[i][j-1] if j >= 1 else 0
            dp[i][j] = x + y
    return dp[N][k-1]

if __name__ == "__main__":
    N = 170
    nums = [1, 2, 5]
    print(solve(N, nums))

