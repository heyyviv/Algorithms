'''Dynamic programming example used for calculating in which order whould we arrange a certain thing example bag'''
def knapsack(val,wt,W,n):
	if n==0 or W==0:
		return 0
	if wt[n-1]>W:
		return knapsack(val,wt,W,n-1)
	else:
		return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1))#return largest value


#dynamic programing with memoization
def knapsack_dp(capacity,values,weights):
	l=len(values)
	dp=[[0 for col in range(capacity+1)] for row in range(l+1)]

	for i in range(1,l+1):
		w=weights[i-1]
		v=values[i-1]
		for j in range(1,capacity+1):
			dp[i][j]=dp[i-1][j]
			if j>=w and dp[i-1][j-w]+v>dp[i][j]:
				dp[i][j]=dp[i-1][j-w]+v

	sz=capacity
	for i in range(l,0,-1):
		if dp[i][sz]!=dp[i-1][sz]:
			print("item of value "+str(values[i-1])+" and weigth "+str(weights[i-1])+" taken")
			sz=sz-weights[i-1]



	return dp[l][capacity]







#start
val=[20,50,100,90,40]#importance of item
wt=[10,20,30,35,40]#weight of items
W=60#total weight
n=len(val)
print(knapsack(val,wt,W,n))
print(knapsack_dp(W,val,wt))
