import random as ran
def display(cards):

    for i in cards:
        t=9
        if i == "10":
            t=8
        print(i+("*"*t),end=" ")
    print()
    for i in range(8):
        for i in range(13):
            print("*"*10,end=" ")
        print()
    for i in cards:
        t=9
        if i == "10":
            t=8
        print(("*"*t)+i,end=" ")

def freq_sort(cards):
    freq={}
    for i in cards:
        if i in freq.keys():
            freq[i]+=1
        else:
            freq[i]=1
    k = sorted(freq.items(),key = lambda x:(x[1],x[0]),reverse=True)
    freq = {}
    for i in k:
        a,b = i
        freq[a] = b
    sorted_cards = []
    for i,j in freq.items():
        for k in range(j):
            sorted_cards.append(i)
    return sorted_cards

def show_or_no(cards):
    freq={}
    for i in cards:
        if i in freq.keys():
            freq[i]+=1
        else:
            freq[i]=1
    freq = sorted(freq.items(),key= lambda x:x[1],reverse=True)
    m = dict(freq)
    temp = list(m.values())
    if temp[0]==4 and temp[1]==temp[2]==temp[3]==3:
        return True
    return False

def give_cards():
    for i in range(13):
        ran.shuffle(cards)
        players_cards["player"].append(cards[0])
    for i in range(13):
        ran.shuffle(cards)
        players_cards["comp"].append(cards[0])

cards = ["A","2","3","4","5","6","7","8","9","10","K","J","Q"]
global players_cards
players_cards = {"player":[],"comp":[]}
give_cards()
players_cards["player"] = freq_sort(players_cards["player"])
display(players_cards["player"])
print("\n\t\t\t\t\t\t\t\033[1m\033[4m Available card\033[0m\033[0m")