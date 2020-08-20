/*
 As with mergesort, quicksort
runs in O(n · h) time, where h is the height of the recursion tree.
“Quicksort runs in Θ(n log n) time, with high probability, if you give
me randomly ordered data to sort.”



*/
def partition(arr,left,right):
    pos=left
    for i in range(left,right):
        if(arr[i]<arr[right]):
            (arr[i],arr[pos])=(arr[pos],arr[i])
            pos+=1
    (arr[pos],arr[right])=(arr[right],arr[pos])
    return pos

def quicksort(arr,left,right):
    if(left<right):
        yellow=partition(arr,left,right)
        quicksort(arr,left,yellow-1)
        quicksort(arr,yellow+1,right)

array=list(map(int,input().split()))
n=len(array)
quicksort(array,0,n-1)
print(array)
