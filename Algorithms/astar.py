class Astar(object):
    def __init__(self,n,a,b):
        self.steps=0
        self.N=n
        self.A=a
        self.B=b

    def distace(x,y):
        return abs(x-self.A[0])+abs(y-self.A[1])
    def find():



print("Enter size of maze");
n=input();
arr=[]

for i in range(n):
    for j in range(n):
        arr[i][j]=input();
print("Enter coordinates of A")
a=list(map(int,input().split()))
print("Enter coordinates of B")
b=list(map(int,input().split()))
