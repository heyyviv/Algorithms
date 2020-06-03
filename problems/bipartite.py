''' Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the
 opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.  
nput
The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and 
the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug 
numbers separated by a single space. Bugs are numbered consecutively starting from one.

Output
The output for every scenario is a line containing “Scenario #i:”, where i is the number of the scenario starting at 1, followed by one line saying either “No
 suspicious bugs found!” if the experiment is consistent with his assumption about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s 
 assumption is definitely wrong.
 Input:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Output:
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found! '''

from collections import defaultdict
class Graph:
	def __init__(self,v):
		self.v=v
		self.graph=[[0 for i in range(0,v)] for j in range(0,v)]
		self.color=[-1]*v
	def insert(self,u,v):
		self.graph[u][v]=1
		self.graph[v][u]=1
	def bipartite(self,src):
		
		self.color[src]=1
		queue=[]
		queue.append(src)
		
		while queue:

			u=queue.pop()
			print(u)
			print(self.graph)
			if self.graph[u][u]==1:
				return False
			for i in range(0,self.v):
				if self.graph[u][i]==1 and self.color[i]==-1:
					queue.append(i)
					self.color[i]=1-self.color[u]#change color for every opposite node in graph
				elif self.graph[u][i]==1 and self.color[i]==self.color[u]:
					return False

		return True


t=int(input())
for pp in range(t):

	n,m=map(int,input().split())
	gg=Graph(n)
	for i in range(0,m):
		u,v=map(int,input().split())
		gg.insert(u-1,v-1)
	flag=0
	for kk in range(0,n):
		if gg.color[kk]==-1:
			test=gg.bipartite(kk)
			if test==False:
				flag=1
				break



	if flag==0:
		print("Scenario #"+str(pp+1)+":")
		print("No suspicious bugs found!")
	else:
		print("Scenario #"+str(pp+1)+":")
		print("Suspicious bugs found!")