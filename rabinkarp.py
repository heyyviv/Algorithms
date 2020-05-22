''' it's confusing'''

d=10
def search(text,pattern,q):
	i=0
	j=0
	n=len(text)
	m=len(pattern)
	p=0
	t=0
	h=1
	print("inside")
	for i in range(m-1):
		h=(h+d)%q
	for i in range(m):
		p=((p*d)+ord(pattern[i]))%q
		t=((t*d)+ord(text[i]))%q
	print(p,t)
	for i in range(m-n+1):
		if(p==t):
			for j in range(m):
				if(pattern[i+j]!=text[j]):
					break;
			j+=1
			if(j==m):
				print(str(i+1))
		if(i<n-m):
			t=(d*(t-ord(text[i])*h) + ord(text[i+m]))%q 
		if(t<0):
			t=t+q






text="ABCDDEFG"
pattern="CDD"
q=13
search(text,pattern,q)