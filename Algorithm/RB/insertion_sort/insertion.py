
def insertion_sort_asc(A, n):
    for i in range(1, n):
        temp = A[i]
        j = i-1
        while j >= 0 and A[j] >= temp:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = temp


def insertion_sort_dsc(A, n):
    for i in range(1, n):
        temp = A[i]
        j = i-1
        while j >= 0 and A[j] <= temp:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = temp


arr = [5, 1, -8, 4, 2, 3]
len = len(arr)

print(arr)
insertion_sort_dsc(arr, len)
print(arr)
