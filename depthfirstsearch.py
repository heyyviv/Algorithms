'''Time complexity o(v+e) v=vertices e=edge '''
from collections import defaultdict

class Graph:

	def __init__(self):
		self.graph=defaultdict(list)
	def add(self,u,v):
		self.graph[u].append(v)

	def dfs(self,i,visited):
		visited[i]=1
		print(i)
		for k in self.graph[i]:
			if visited[k]==-1:
				self.dfs(k,visited)





g=Graph()
g.add(0,1)
g.add(0,2)
g.add(1,2)
g.add(2,3)
g.add(3,3)
g.add(3,6)
g.add(4,2)
g.add(4,5)
g.add(5,6)
g.add(6,6)
g.add(0,4)
print(g.graph)
visited=[-1]*7
g.dfs(0,visited)
