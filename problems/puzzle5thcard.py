#Programming for the Puzzled -- Srini Devadas
#You Can Read Minds (With a Little Calibration)
#Five random cards are chosen and one of them is hidden.
#C>D>H>S
#A<2<3<4<5<6<7<8<9<10<J<Q<K
deck = ['A_C', 'A_D', 'A_H', 'A_S', '2_C', '2_D', '2_H', '2_S', '3_C', '3_D', '3_H', '3_S',
        '4_C', '4_D', '4_H', '4_S', '5_C', '5_D', '5_H', '5_S', '6_C', '6_D', '6_H', '6_S',
        '7_C', '7_D', '7_H', '7_S', '8_C', '8_D', '8_H', '8_S', '9_C', '9_D', '9_H', '9_S',
        '10_C', '10_D', '10_H', '10_S', 'J_C', 'J_D', 'J_H', 'J_S',
        'Q_C', 'Q_D', 'Q_H', 'Q_S', 'K_C', 'K_D', 'K_H', 'K_S']

def Assistcards():
	(cards,suit,cardno,cpos)=([],[],[],[])
	numsuit=[0,0,0,0]
	print("Card in deck: ",deck)
	for i in range(0,5):                  
		print("enter "+str(i+1)+"card ")
		cc=input()
		cards.append(cc)
		n=deck.index(cc)
		cpos.append(n)
		suit.append(n%4)
		cardno.append(n//4)
		numsuit[n%4]+=1
		if(numsuit[n%4]>1):
			pairsuit=n%4

	cardh=[]
	for i in range(0,5):
		if suit[i]==pairsuit:
			cardh.append(i)
	hidden,other,encoded=cardarrange(cards,cardh,cardno)
	card3=[]
	for i in range(0,5):
		if i!=hidden and i!=other:
			card3.append(cpos[i])
	sortlist(card3)

	other3card(card3,encoded)
	card5th=input("Enter 5th card")
	if(card5th==cards[hidden]):
		print("correct")
	
	else:
		print("Corect card is ",card[hidden])


def cardarrange(card,cardh,cardno):
	encoded=cardno[cardh[1]]-cardno[cardh[0]]
	if encoded>0 and encoded<=6:
		hidden=cardh[1]
		other=cardh[0]
	else:
		hidden=cardh[0]
		other=cardh[1]
		encoded=cardno[cardh[0]]-cardno[cardh[1]]
	print("1st card",card[other])
	return hidden,other,encoded



def sortlist(card3):
	for i in range(0,len(card3)-1):
		index=i
		for j in range(i,len(card3)):
			if(card3[index]<card3[j]):
				index=j
		(card3[index],card3[i])=(card3[i],card3[index])

	return 

def other3card(card3,encoded):
	if encoded==1:
		first,second,third=card3[0],card3[1],card3[2]
	if encoded==2:
		first,second,third=card3[0],card3[2],card3[1]
	if encoded==3:
		first,second,third=card3[1],card3[0],card3[2]
	if encoded==4:
		first,second,third=card3[1],card3[2],card3[0]
	if encoded==5:
		first,second,third=card3[2],card3[0],card3[1]
	if encoded==6:
		first,second,third=card3[2],card3[1],card3[0]


	print("2nd card ",deck[first])
	print("3rd card",deck[second])
	print("4th card",deck[third])

	return




#Assistcards()


def guessMagicCard():
	(card,cpos,cind)=([],[],[])
	suit=0
	card1st=0

	for i in range(0,4):
		kk=input("enter a card")
		n=deck.index(kk)
		card.append(kk)
		
		cind.append(n)
		if i==0:
			suit=n%4
			cardp1st=n//4
	if(cind[1]<cind[2] and cind[1]<cind[3]):
		if(cind[2]<cind[3]):
			encode=6
		else:
			encode=5
	elif(cind[2]<cind[3] and cind[2]<cind[1]):
		if(cind[1]<cind[3]):
			encode=4
		else:
			encode=3
	elif(cind[3]<cind[2] and cind[3]<cind[1]):
		if(cind[1]<cind[2]):
			encode=2
		else:
			encode=1
	xpos=(card1st+encode)%13
	index=xpos*4+suit
	print(deck[index])

	
guessMagicCard()


