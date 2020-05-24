''' this is count sort it is used only in number albhabets can also expressed as number worst case is O(n+k) n len of arr k is length of count '''

def sort(arr):
	a=max(arr)
	count=[0]*(a+1)
	output=[0]*len(arr)
	for i in arr:
		count[i]=count[i]+1
	print(count,output)
	for i in range(1,a+1):
		count[i]=count[i-1]+count[i]
	print(count,output)
	i=len(arr)-1
	while(i>=0):
		output[count[arr[i]]-1]=arr[i]
		count[arr[i]]-=1
		i=i-1
		print(count,output)
	return output

arr=list(map(int,input().split()))
arr=sort(arr)
print(arr)