def binary_search(arr, left, right, val):
    if right >= left:
        mid = (left + right) // 2
        if arr[mid] == val:
            return mid
        elif arr[mid] > val:
            return binary_search(arr, left, mid-1, val)

        elif arr[mid] < val:
            return binary_search(arr, mid + 1, right, val)

    return -1


# arr = [100, 50, 40, 10, 60, 70, 80, 400, 30]
brr = [10, 20, 30, 40, 50]
l = len(brr)

ind = binary_search(brr, 0, l-1, 100)
print(l)
