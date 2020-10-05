def findBin(nums, k):
    L = 0
    R = len(nums) - 1
    while L < R:
        mid = int(L + (R - L) / 2)
        if nums[mid] < k:
            L = mid + 1
        elif nums[mid] > k:
            R = mid - 1
        else:
            return mid
    return L

arr = [1,2,3,4,5,6,7,8]
print(findBin(arr, 8))