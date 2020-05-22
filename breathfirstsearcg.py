''' Time complexity is O(v+e) v=vertices e=edge  it is used in  it is use in google search and in a experiment to find how many 
move is required to solve a 3x3 rubix cube(20 move) time complexity(nxn/lg n)'''
from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph_data=defaultdict(list)
    def add(self,u,v):
        self.graph_data[u].append(v)

    def bfs(self,i):
        print(self.graph_data)
        l=len(self.graph_data)
        parent=[-1]*l
        visited=[-1]*l
        q=[]
        visited[i]=1
        q.append(i)
        while len(q)>0:
            kk=q.pop(0)
            print(kk)
            for cur in self.graph_data[kk]:
                print("cur" +str(cur))
                if visited[cur]==-1:
                    parent[cur]=kk
                    visited[cur]=1
                    q.append(cur)
        return parent

g=Graph()
g.add(0,1)
g.add(0,4)
g.add(1,2)
g.add(2,3)
g.add(3,4)
g.add(4,4)
print(g.bfs(0))
