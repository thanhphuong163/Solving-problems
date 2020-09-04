def selectionSort(nums):
    count = 0
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[j] < nums[i]:
                count += 1
                nums[j], nums[i] = nums[i], nums[j]
    return count

def bubleSort(nums):
    count = 0
    for i in range(len(nums)-1,-1,-1):
        for j in range(i):
            if nums[j] > nums[j+1]:
                count += 1
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return count

if __name__ == "__main__":
    with open('input.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            nums = [int(num) for num in line.strip().split(' ')]
            print(len(nums))
            print("Selection sort:", selectionSort(nums.copy()))
            print("Buble sort:", bubleSort(nums.copy()))
