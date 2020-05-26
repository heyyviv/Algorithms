#The Best Time to Party
#Given a list of intervals when celebrities will be at the party
#Output is the time that you want to go the party when the maximum number of
#celebrities are still there.
#Clever algorithm that will work with fractional times

sched = [(6, 8), (6, 12), (6, 7), (7, 8), (7, 10), (8, 9), (8, 10), (9, 12),
            (9, 10), (10, 11), (10, 12), (11, 12)]
sched2 = [(6.0, 8.0), (6.5, 12.0), (6.5, 7.0), (7.0, 8.0), (7.5, 10.0), (8.0, 9.0),
          (8.0, 10.0), (9.0, 12.0), (9.5, 10.0), (10.0, 11.0), (10.0, 12.0), (11.0, 12.0)]
sched3 = [(6, 7), (7,9), (10, 11), (10, 12), (8, 10), (9, 11), (6, 8),
          (9, 10), (11, 12), (11, 13), (11, 14)]

def bestparty(guest):
	time=[]
	for row in guest:
		time.append((row[0],"start"))
		time.append((row[1],"end"))
	sortlist(time)

	maxcount,timearr=calctime(time)
	print("at time ",timearr,"people ",maxcount)


def sortlist(time):
	for i in range(len(time)-1):
		issmall=i
		for j in range(i,len(time)):
			if(time[j][0]<time[issmall][0] or (time[j][0]==time[issmall][0] and time[j][1]<time[issmall][1])):
				issmall=j
		(time[i],time[issmall])=(time[issmall],time[i])

	return

def calctime(time):
	maxcount=0
	exactcount=0
	maxtime=0
	for row in time:
		if row[1]=="start":
			exactcount=exactcount+1
		elif row[1]=="end":
			exactcount=exactcount-1
		if exactcount>maxcount:
			maxcount=exactcount
			maxtime=row[0]

	return maxcount,maxtime





bestparty(sched)