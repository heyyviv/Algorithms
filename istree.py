''' defaultdict is default value id dictionary is anything we want here it is list
first checking whether there is cycle 
second wheather every node is visited
i havw Dynamic programmimg here''' 

from collections import defaultdict
class Graph:
	def __init__(self,v):
		self.v=v
		self.graph=defaultdict(list)
	def insert(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def iscyclic(self,v,visited,parent):
		visited[v]=True
		#visiting every node from that node
		for i in self.graph[v]:
			if visited[i]==False:
				if self.iscyclic(i,visited,v)==True:
					return True
			#child is visited earlier than there is cycle as it is undirected graph
			elif i!=parent:
				return True
		return False


	def istree(self):
		visited=[False]*self.v
		if self.iscyclic(0,visited,-1)==True:
			return False

		for i in range(self.v):
			if visited[i]==False:
				return False
		return True



''' n is number of node and m is edges in graph 
example :
3 2  -> n m
1 2  -> edge1 edge2
2 3  -> edge2 edge3''' 

n,m=map(int,input().split())
graph=Graph(n)
for _ in range(0,m):
	u,v=map(int,input().split())
	graph.insert(u,v)

if graph.istree()==True:
	print("YES")
else:
	print("NO")
