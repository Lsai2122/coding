import random as ran
import time
#storing cards and randomizing
cards = ['A','J','K','Q','2','3','4','5','6','8','7','9','10']
money = {'dealer':10000}
bids = {}
players_stat = {}
def give_cards(deck,role):
    global cards
    #defining both adding cards to dealer and player in one function
    if role =='player':
        ran.shuffle(cards)
        deck.append(cards[0])
        deck.append(cards[1])
    else:
        ran.shuffle(cards)
        deck[cards[0]] = "open"
        deck[cards[1]] = "close"
def h_or_s(deck,player):
    #defining function to give a crd untill standed
    global cards
    global bids
    while True:
        time.sleep(0.5)
        while True:
            try:
                bid = int(input(f"{player} enter the bid amount"))
                break
            except:
                print("bid must be number")
        bids[player] = bid
        if bid==0:
            time.sleep(0.5)
            print(f"{player} withdrawn")
            break
        elif bid>money[player]:
            time.sleep(0.5)
            print(f"you only have {money[player]}")
        elif bid<100:
            time.sleep(0.5)
            print("The least accecpted bid is 100.")
        else:
            money[player] -= bid
            while True:
                time.sleep(0.5)
                status = input(f"\nbidding : {bid} For Hit: 'h'\nfor Stand: 's' \nfor Adding Bid: 'b' ")
                ran.shuffle(cards)
                if status.lower() == "h":
                    deck.append(cards[0])
                    time.sleep(0.5)
                    print(f"         {player}")
                    for card in deck:
                        time.sleep(0.5)
                        print(f"            {card}")
                    role = "player"
                    time.sleep(0.5)
                    print(f"       {counter(deck,role)}") 
                    time.sleep(0.5)
                    print(f"       Money : {money[player]}")
                    if counter(deck,role)>21:
                        time.sleep(0.5)
                        print(f"{player} bust")
                        break
                elif status.lower() == "s":
                    break
                elif status.lower() == "b":
                    try:
                        time.sleep(0.5)
                        add = int(input("Enter the amount "))
                        bids[player] += add
                        time.sleep(0.5)
                        print(f"added {add}\nNew bid {bids[player]}")
                    except:
                        time.sleep(0.5)
                        print("input should be integet")
                else:
                    time.sleep(0.5)
                    print("Input should be 'h','s','b'")
            break
def counter(deck,role):
    #counts using deck of player and dealer they are list and dict resp
    if role == "player":
        count=0
        aces = 0
        for card in deck:
            try:
                count += int(card)
            except:
                if card == "J" or card == 'K' or card == 'Q':
                    count += 10
                elif card == 'A':
                    aces += 1
            if count+(aces*11)<=21:
                count = count+(aces*11)
            else:
                count = count+aces
    else:
        count = 0
        aces = 0
        for card,stat in deck.items():
            try:
                if stat=="open":
                   count += int(card)
            except:
                if stat=="open":
                    if card == "J" or card == 'K' or card == 'Q':
                        count += 10
                    elif card == 'A':
                        aces += 1
                if count+(aces*11)<=21:
                    count = count+(aces*11)
                else:
                    count = count+aces
    return count
def decider(dealer_scr,player_scrs,player_stats):
    #decide who won an who lost by taking dealer score in int and player scrs in dist
    global money
    i = 0
    for player,score in player_scrs.items():
        if dealer_scr<=21:
            if score>21:
                stat = "loss"
            elif score<21 and score<=dealer_scr:
                stat = "loss"
            else:
                stat = "win"
        else:
            if score>21:
                stat="loss"
            else:
                stat = "win"
        player_stats[i] = stat 
        if stat == "win":
            money[player] += 2*bids[player]
            money["dealer"] -= bids[player]
        i += 1
        time.sleep(0.5)
        return print(f"{player} {stat}")
    
def distributor(amounts,player_stat):
    # distribute money from dealer to winners
    global money
    i = 0
    for bid,stat in amounts.values(),player_stat.values():
        if stat == 'win':
            money[f"player {i}"] += bid
        else:
            money[f'player {i}'] -= bid

flag = True
while flag:
    while True:
        no_of_players = input("how many players ")
        dealer_deck = {}
        players = {}
        decks = {}
        try:
            time.sleep(0.5)
            no_of_players = int(no_of_players)
            break
        except:
            time.sleep(0.5)
            print("Number of players should be a int")
    if no_of_players>0:
        for i in range(no_of_players):
            players[f'player {i+1}'] = "player"
            decks[f'player {i+1}'] = []
            money[f'player {i+1}'] = 1000
    give_cards(dealer_deck,"dealer")
    time.sleep(0.5)
    print("         Dealer")
    for card,stat in dealer_deck.items():
        time.sleep(0.5)
        if stat=="open":
            time.sleep(0.5)
            print(f"            {card}")
        else:
            time.sleep(0.5)
            print(f"         Closed")
    role = "dealer"
    time.sleep(0.5)
    print(f"       Count : {counter(dealer_deck,role)}")
    for (player,role),deck in zip(players.items(),decks.values()):
        give_cards(deck,role)
        time.sleep(0.5)
        print("\n\n\n")
        print(f"         {player}")
        for card in deck:
           time.sleep(0.5)
           print(f"            {card}")
           role = "player"
        time.sleep(0.5)
        print(f"       Count : {counter(deck,role)}")
        time.sleep(0.25)
        print(f"       Money : {money[player]}")
        h_or_s(deck,player)
    dealer_deck[1] = 'open'
    print("      Dealer")
    for card in dealer_deck.keys():
        print(f"      {card}")
    i = 1
    while counter(dealer_deck,"dealer") <17:
        ran.shuffle(cards)
        dealer_deck[cards[1]] = "open"
        time.sleep(0.5)
        print(f"Dealer had drawn {i} cards")
        time.sleep(0.5)
        print("      Dealer")
        for card in dealer_deck.keys():
            time.sleep(0.2)
            print(f"      {card}")
        time.sleep(0.5)
        print(f'     Count : {counter(dealer_deck, "dealer")}')
        i+=1
    role = "dealer"
    player_scrs = {}
    for player,cards in zip(players,decks.values()):
        role = 'player'
        player_scrs[player] = counter(cards,role)
    role = 'dealer'
    decider(counter(dealer_deck,role),player_scrs,players_stat)
    for player,cash in money.items():
        time.sleep(0.5)
        print(f"{player} have {cash}")
    opt = input("play one more time? ")
    yes = ["yes","y","sure","s","ok"]
    if opt in yes:
        continue
    else:
        break
    break