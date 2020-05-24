''' so avl tree try to make it balance intersion lg n
deletion lg n search lg n   '''

class Node:
	def __init__(self,data):
		self.left=None
		self.right=None
		self.val=data
		self.height=1
class Avl:
	def insert(self,root,data):
		if(root==None):
			return Node(data)
		if(root.val>data):
			root.left=self.insert(root.left,data)
		if(root.val<data):
			root.right=self.insert(root.right,data)

		root.height=1+max(self.getheight(root.left),self.getheight(root.right))
		bal=self.isbalance(root)
		if(bal>1 and root.left.val>data):
			return self.rightrotate(root)
		if(bal>1 and root.left.val<data):
			root.left=self.leftrotate(root.left)
			return self.rightrotate(root)
		if(bal<-1 and root.right<data):
			return self.leftrotate(root)
		if(bal<-1 and root.right>data):
			root.right=self.rightrotate(root.right)
			return self.leftrotate(root)
		return root


	def getheight(self,root):
		if(root==None):
			return 0
		return root.height
	def isbalance(self,root):
		return self.getheight(root.left)-self.getheight(root.right)
	def rightrotate(self,x):
		y=x.left
		t=y.right

		y.right=x
		x.left=t

		x.height=1+max(self.getheight(x.left),self.getheight(x.right))
		y.height=1+max(self.getheight(y.left),self.getheight(y.right))
		return y
	def leftrotate(self,x):
		y=x.right 
		t=y.left 

		y.left=x
		x.right=t 
		x.height=1+max(self.getheight(x.left),self.getheight(x.right))
		y.height=1+max(self.getheight(y.left),self.getheight(y.right))
		return y
def inorder(root):
	if(root==None):
		return 
	inorder(root.left)
	print(root.val)
	inorder(root.right)







arr=list(map(int,input().split()))
tree=Avl()
root=None
for i in arr:
	root=tree.insert(root,i)
inorder(root)

