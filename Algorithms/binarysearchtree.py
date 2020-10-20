'''Binary tree search take lg n time Omega
worst case is O(n) in case of list

sorting take nlog n time in worst case (balanced tree)



test ---
'''

class Node:
	def __init__(self,data=None):
		self.left=None
		self.right=None
		self.val=data
def insert(root,data):
	if(root.val==None):
		root.val=data
		return
	if(data<root.val):
		if(root.left==None):
			root.left=Node(data)
		else:
			insert(root.left,data)
	else:
		if(root.right==None):
			root.right=Node(data)
		else:
			insert(root.right,data)
def search(root,data):

	if(root.val==data):
		return "Yes"
	if(root.val>data):
		if(root.left==None):
			return "No"
		else:
			return search(root.left,data)
	else:
		if(root.right==None):
			return "No"
		else:
			return search(root.right,data)
def inorder(root):
	inorder(root.left)
	printf(root.val)
	inorder(root.right)

arr=list(map(int,input().split()))
root=Node()
for i in range(0,len(arr)):
	insert(root,arr[i])
s=int(input("search"))
print(search(root,s))
