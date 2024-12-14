import random
print("             WELCOME TO ROCK,PAPER AND SCISSOR GAME\n")
player=["rock","paper","scissor","r","s","p"]
name=input("Enter your name\n")
print("Player can choose first letter of the word\n")
comp=["rock","paper","scissor"]
p=0;c=0
while(1):
    choise=input("pick: ")
    if choise in player:
        computer=random.choice(comp)
        if choise.lower()=="r":
            choise="rock"
        elif choise.lower()=="p":
            choise="paper"
        elif choise.lower()=="s":
            choise="scissor"
        if choise.lower()=="rock" and computer=="scissor":
            p+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print(name,"won")
            print("player:",p,"computer:",c) 
        elif choise.lower()=="rock" and computer=="paper":
            c+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print("computer won")
            print("player:",p,"computer:",c)
        elif choise.lower()=="paper" and computer=="rock":
            p+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print(name,"won")
            print("player:",p,"computer:",c)
        elif choise.lower()=="paper" and computer=="scissor" :
            c+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print("computer won")
            print("player:",p,"computer:",c)
        elif choise.lower()=="scissor" and computer=="paper":
            p+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print(name,"won")
            print("player:",p,"computer:",c)
        elif choise.lower()=="scissor" and computer=="rock":
            p+=1
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print(name,"won")
            print("player:",p,"computer:",c)
        else:
            print(name,"choose: ",choise)
            print("computer choose: ",computer)
            print("tie")
            print("player:",p,"computer:",c)
        opt=input("Do you want to contiune this game(if continue press y or end press any button): \n")
        if(opt!="y"):
            if p>c:
                print(name,"won:",p)
                print("computer lose:",c)
            elif p<c:
                print(name,"lose:",p)
                print("computer win:",c)
            else:
                print("both tie")
            break
    else:
        print("INVALID\nEnter correct Word\n")
        