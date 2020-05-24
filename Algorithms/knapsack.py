'''Dynamic programming example used for calculating in which order whould we arrange a certain thing examle bag'''
def knapsack(val,wt,W,n):
	if n==0 or W==0:
		return 0
	if wt[n-1]>W:
		return knapsack(val,wt,W,n-1)
	else:
		return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1))#return largest value

#start
val=[20,50,100,90,40]#importance of item
wt=[10,20,30,35,40]#weight of items
W=60#total weight
n=len(val)
print(knapsack(val,wt,W,n))