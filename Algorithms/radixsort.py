def countsort(arr,place):
	l=len(arr)
	count=[0]*10
	output=[0]*l
	for i in arr:
		index=i//place
		count[index%10]+=1
	for i in range(1,10):
		count[i]=count[i-1]+count[i]
	i=l-1
	while(i>=0):
		index=arr[i]//place
		output[count[arr[i]%10]-1]=arr[i]
		count[arr[i]]-=1
		i=i-1
	for i in range(0,l):
		arr[i]=output[i]


def radix(arr):
	place=1
	a=max(arr)
	while(a//place>0):
		countsort(arr,place)
		place=place*10
	return arr




arr=list(map(int,input().split()))
arr=radix(arr)
print(arr)