import pandas as pd
import matplotlib.pyplot as plt

def selectionSort(nums):
    count = 0
    for i in range(len(nums)):
        minIndx = i
        for j in range(i+1, len(nums)):
            count += 1
            if nums[j] < nums[i]:
                minIndx = j
        nums[minIndx], nums[i] = nums[i], nums[minIndx]
    return count

def bubbleSort(nums):
    count = 0
    for i in range(len(nums)-1,-1,-1):
        for j in range(i):
            count += 1
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return count

def insertionSort(nums):
    count = 0
    for i in range(1, len(nums)):
        for j in range(i-1, -1, -1):
            count += 1
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return count

def partition(arr, low, high):
    count = 0
    i = (low-1)         # index of smaller element
    pivot = arr[high]     # pivot
    for j in range(low, high):
        count += 1
        if arr[j] <= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1), count


def quickSort(arr, low, high):
    count = 0
    if len(arr) == 1:
        return arr
    if low < high:
        pi, pCount = partition(arr, low, high)
        count += pCount
        count += quickSort(arr, low, pi-1)
        count += quickSort(arr, pi+1, high)
    return count

if __name__ == "__main__":
    result = {
        "n": [],
        "Selection": [],
        "Bubble": [],
        "Insertion": [],
        "Quick": []
    }
    with open('test.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            nums = [int(num) for num in line.strip().split(' ')]
            result["n"].append(len(nums))
            result["Selection"].append(selectionSort(nums.copy()))
            result["Bubble"].append(bubbleSort(nums.copy()))
            result["Insertion"].append(insertionSort(nums.copy()))
            result["Quick"].append(quickSort(nums.copy(), 0, len(nums)-1))
    df = pd.DataFrame(data=result)

    # Plot complexity analysis
    features = df.columns[1:]
    fig, ax = plt.subplots(1, figsize=(10, 7))
    for feature in features:
        ax.scatter(df['n'], df[feature], alpha=0.5, label=feature)
        # x = df['n'].values
        # y = df[feature].values
        # a,b,c = np.polyfit(x,y,2)
        # x_ = np.linspace(0, 200, 200)
        # y_ = a*x_**2 + b*x_ + c
        # ax.plot(x_,y_,alpha=0.7, label=feature)
    ax.set_xlabel('n')
    ax.set_ylabel('T(n)')
    plt.legend()
    plt.show()
