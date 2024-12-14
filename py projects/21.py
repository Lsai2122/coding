import random
#creating random cards set


cards = ["a","a","a","a",2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,"q",'q',"q","q","j","j","j","j","k","k","k","k","a","a","a","a",2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,"q",'q',"q","q","j","j","j","j","k","k","k","k","a","a","a","a",2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,"q",'q',"q","q","j","j","j","j","k","k","k","k"]
exit = ['bye','exit','q','break','b','e']
random.shuffle(cards)
random.shuffle(cards)
k=0
i=0
#defining

#to give 2 open cards
def give_2_opn_crds(player_cards,cards):
	global i
	player_cards.append(cards[i])
	i += 1
	player_cards.append(cards[i])

#to give hit card
def hit(player_cards,cards):
	global i
	player_cards.append(cards[i])
	i += 1

#to dealer
def dealer_first(dealer_cards,cards):
	global i
	dealer_cards[cards[i]] = True
	i +=1
	dealer_cards[cards[i]] = False
def hit_d(dealer_cards,cards):
	global i
	dealer_cards[cards[i]]=True
	
#print players cards
"""we have to give dict"""
def display_p_cards(players_cards):
	for player , p_cards in players_cards.items():
		print(f"			\033[3m{player}\033[0m")
		for card in p_cards:
			if isinstance(card, str):
				print(f"	  	  	{card.title()}	")
			else:
				print(f"	   	   	{card}")
			time.sleep(0.5)
		print("\n\n\n")
		
def display_1_cards(player,p_cards):
	print(f"\033[3m			{player.title()}\033[0m")
	for p_card in p_cards:
		if isinstance(p_card,str):
			print(f"			{p_card.title()}")
		else:
			print(f"			{p_card}")
			
def display_d(dealer):
	print(f"\033			[3mDealer\033[0m")
	for card,d_status in dealer.items():
		if d_status:
			if isinstance(card,str):
				print(f"			{card.title()}")
			else:
				print(f"			{card}")
		else:
			print("			Closed card")
		time.sleep(0.5)
		
#counter
def counter(cards):
    score = 0
    no_of_a = 0
    for card in cards:
        if isinstance(card, int):
            score += card
        elif isinstance(card, str):
            if card.title() == "K" or card.title() == "Q" or card.title() == "J":
                score += 10
            elif card.title() == "A":
                no_of_a += 1
    if score + (no_of_a * 11) <= 21:
        a_value = 11
    else:
        a_value = 1
    return score + (no_of_a * a_value)
    

#winner decideor
# dict is given
def who_wins(players_cards,dealer_cards):
	values = {}
	def counter(cards):
		score=0
		no_of_a =0
		for card in cards:
			if isinstance(card , int):
				score+=card
			elif isinstance(card, str):
				if card.title() =="K" or card.title()=="Q" or card.title() =="J":
					score+=10
				elif card.title()=="A":
					no_of_a +=1
		if score + (no_of_a*11)<=21:
			a_value=11
		else:
			a_value=1
		return score+(no_of_a*a_value)
	def decide(dealer,players):
		winner_table={}
		for player ,value in players.items():
			if value<=21:
				if dealer<=21:
					if dealer<value:
						winner_table[player]="win"
					elif dealer==value:
						winner_table[player]="draw"
					else:
						winner_table[player]="lose"
				else:
					winner_table[player]="win"
			else:
				winner_table[player]="lose"
		for player , status in winner_table.items():
			time.sleep(1)
			if status=="win":
				print(f"\033[1m{player.title()} Wins\033[0m")
			elif status=="draw":
				print(f"\033[1m{player.title()} got Draw\033[0m")
			else:
				print(f"\033[1m{player.title()} Lost\033[0m")
	for player , cards in players_cards.items():
		values[player]=counter(cards)
	dealer_hand= counter(dealer_cards)
	decide(dealer_hand,values)
	
	
#display starts
flag=True
import time
print("\033[1m                Welcome to Sai's Blackjack\033[0m")
time.sleep(0.5)

while flag:
	no_of_players=input("How many player do you want:")
	if (no_of_players.lower() not in exit):
		try:
			no_of_players = int(no_of_players)
			dealer={}
			players_cards={}
			for n in range(no_of_players):
				players_cards[f"Player {n+1}"]=[]
			for p, p_cards in players_cards.items():
				give_2_opn_crds(p_cards,cards)
			display_p_cards(players_cards)
			dealer_first(dealer,cards)
			display_d(dealer)
			print("____________________________________________________________")
			time.sleep(0.5)
			print("\n\n\n")
			for p , p_cards in players_cards.items():
				is_hit= True
				while is_hit:
					if counter(p_cards)<=21:
						display_1_cards(p,p_cards)
						time.sleep(0.5)
						print(f"\n\033[3m			Count = {counter(p_cards)}\033[0m")
						time.sleep(1)
						print("\n\n")
						h_or_s = input(f"\033[3m{p}\033[0m: Type 'h' for hit and 's' for stand:\n")
						if h_or_s.lower()=="h":
							hit(p_cards,cards)
						elif h_or_s.lower()=="s":
							is_hit=False
						else:
							print("Only 'h' or 's' are allowed")
					else:
						display_1_cards(p,p_cards)
						time.sleep(0.75)
						print(f"\033[3m			{counter(p_cards)}\033[0m")
						print("\n")
						print(f"\033[3m			{p} got bust\033[0m")
						print("\n\n")
						time.sleep(1)
						break
				print("____________________________________________________________\n")

			d_cards=[]
			for d_card in dealer.keys():
				d_cards.append(d_card)
			display_1_cards("dealer",d_cards)
			time.sleep(1)
			print("\n")
			while counter(d_cards)<17:
				hit(d_cards,cards)
				print("Dealer draw one card")
				time.sleep(0.2)
				display_1_cards("dealer",d_cards)
				time.sleep(0.5)
				print(f"\033[3m			count = {counter(d_cards)}\033[0m")
			print(f"\033[1mLoading the results\033[0m",end = "")
			for i in range(3):
				time.sleep(1)
				print(".",end="")
			print("\n")
			who_wins(players_cards,d_cards)
		except:
			print('input should be Numbers or "exit"')
	else:
		break