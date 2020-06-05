'''question link https://www.spoj.com/problems/HORRIBLE/
i have used segment tree and lazy approach'''
class Graph:
	def __init__(self):
		self.n=100005
		self.seg=[0]*(4*self.n)
		self.lazy=[0]*(4*self.n)
	def build(self,ss,se,si):
		if ss>se:
			return 
		if ss==se:
			self.seg[si]=0
			return
		mid=(ss+se)//2
		self.build(ss,mid,2*si+1)
		self.build(mid+1,se,2*si+1)
		self.seg[si]=self.seg[2*si+1]+self.seg[2*si+2]


	def update(self,ss,se,si,qs,qe,diff):
		if self.lazy[si]!=0:
			self.seg[si]+=(se-ss+1)*(self.lazy[si])
			if ss==ss:
				self.lazy[2*si+1]=self.lazy[si]
				self.lazy[2*si+2]+=self.lazy[si]
			self.lazy[si]=0
		if ss>qe or se<qs:
			return
		if qs<=ss and se<=qe:
			self.seg[si]+=(se-ss+1)*diff
			if ss!=se:
				self.lazy[2*si+1]+=diff
				self.lazy[2*si+2]+=diff
			return
		mid=(ss+se)//2
		self.update(ss,mid,2*si+1,qs,qe,diff)
		self.update(mid+1,se,2*si+2,qs,qe,diff)
		self.seg[si]=self.seg[2*si+1]+self.seg[2*si+2]


	def getsum(self,ss,se,si,qs,qe):
		if self.lazy[si]!=0:
			self.seg[si]+=(se-ss+1)*(self.lazy[si])
			if ss!=si:
				self.lazy[(2*si)+1]+=self.lazy[si]
				self.lazy[(2*si)+2]+=self.lazy[si]
			self.lazy[si]=0
		if ss>qe or se<qs:
			return 0
		if qs<=ss and se<=qe:
			return self.seg[si]
		mid=(ss+se)//2
		return self.getsum(ss,mid,(2*si)+1,qs,qe)+self.getsum(mid+1,se,(2*si)+2,qs,qe)






	


t=int(input())
while t>0:
	n,q=map(int,input().split())
	gg=Graph()
	gg.build(0,n-1,0)
	for _ in range(0,q):
		arr=list(map(int,input().split()))
		if arr[0]==0:
			gg.update(0,n-1,0,arr[1]-1,arr[2]-1,arr[3])
		else:
			kk=gg.getsum(0,n-1,0,arr[1]-1,arr[2]-1)
			print(kk)
	



	t-=1