kk=[[0,1,1,0],[0,0,0,1],[0,0,0,1],[0,0,1,0]]
indegree=[0]*len(kk)
def dag(kk):
	stack=[]
	for i in range(0,len(kk)):
		for j in range(0,len(kk[i])):
			indegree[j]=indegree[j]+kk[i][j]
	for i in range(len(indegree)):
		if indegree[i]==0:
			stack.append(i)
	while len(stack):
		j=stack.pop(0)
		for k in range(j,len(kk)):
			indegree[k]=indegree[k]-1
			if indegree[k]==0:
				stack.append(k)
				print(stack)

dag(kk)