''' it is greedy algorithm there should not be a negetive cycle
worst case O(e+vlgv) e=edge v=vertices  '''
nodes = ('A', 'B', 'C', 'D', 'E', 'F', 'G')
distances = {
    'B': {'A': 5, 'D': 1, 'G': 2},
    'A': {'B': 5, 'D': 3, 'E': 12, 'F' :5},
    'D': {'B': 1, 'G': 1, 'E': 1, 'A': 3},
    'G': {'B': 2, 'D': 1, 'C': 2},
    'C': {'G': 2, 'E': 1, 'F': 16},
    'E': {'A': 12, 'D': 1, 'C': 1, 'F': 2},
    'F': {'A': 5, 'E': 2, 'C': 16}}
visited={}
unvisited={node:None for node in nodes}
curnode='B'
curdist=0
unvisited[curnode]=curdist
count=0#to see how many times loop is running
while True:
	for neighbour,dist in distances[curnode].items():
		if neighbour not in unvisited:
			continue
		newdist=curdist+dist 
		if unvisited[neighbour]==None or unvisited[neighbour]>newdist:
			unvisited[neighbour]=newdist
	visited[curnode]=curdist
	print(count)
	print( "visit",visited)
	
	del unvisited[curnode]
	print("unvisit",unvisited)
	if not unvisited:
		break
	real=[node for node in unvisited.items() if node[1]]#to find nearest neighbour
	curnode,curdist=sorted(real,key=lambda x:x[1])[0]
	print(real)
	print(curnode,curdist)
	count=count+1

print(visited)
