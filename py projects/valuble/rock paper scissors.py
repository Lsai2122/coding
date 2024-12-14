import random as ran
import time

# starting to create a random set for rps
rps = ["rock" , "paper" , "scissors","rock" , "paper" , "scissors","rock" , "paper" , "scissors","rock" , "paper" , "scissors","rock" , "paper" , "scissors","rock" , "paper" , "scissors","rock" , "paper" , "scissors"]
ran.shuffle(rps)

#decider for who wins
def who_wins(player,system,p_points,s_points):
	#sorting the options in a order
	
	if system.lower() =="rock":
		
		
		if player.lower() =="rock":
			status= "draw"
			
		elif player.lower()=="paper":
			status="win"
			
		elif player.lower()=="scissors":
			status="lose"
			
		
	elif system.lower() =="paper":
			
			
		if player.lower() =="rock":
			status= "lose"
			
		elif player.lower()=="paper":
			status="draw"
			
		elif player.lower()=="scissors":
			status="win"
			
		
	elif system.lower()=="scissors":
		
		
		if player.lower() =="rock":
			status= "win"
			
		elif player.lower()=="paper":
			status="lose"
			
		elif player.lower()=="scissors":
			status="draw"
	
	
	#adding points
	if status == "win":
		text="You won"
		width=55
		print(text.center(width))
		p_points += 2
	
	elif status =="lose":
		text="You lost against Computer"
		width=60
		print(text.center(width))
		s_points +=2
	
	elif status=="draw":
		text = "It's a Draw"
		width=55
		print(text.center(width))
		p_points+=1
		s_points+=1
		
	return p_points , s_points



#storage
p_points=0
s_points=0
status="na"




#display
text = "\033[1mWelcome to Rock, Paper and scissors\033[0m"
width=70
print(text.center(width))
# while loop for looping if player wants rematch
while True:
	ran.shuffle(rps)
	#while loop for wrong entry
	while True:
		time.sleep(1)
		print("->Choose Rock, paper, or Scissors")
		time.sleep(0.5)
		p_opt=input("->You can choose with 1st letter or the word : ")
		
		#if sorting to make it clear
		if p_opt.lower()=="r" or p_opt.lower()=="rock":
			player="rock"
			break
				
		elif p_opt.lower()=="p" or p_opt.lower()=="paper":
			player="paper"
			break
				
		elif p_opt.lower()=="s" or p_opt.lower()=="scissors":
			player='scissors'
			break
			
		else:
			time.sleep(1)
			print("\nInput should be Rock , Paper , Scissors or R, P, S\n")
	time.sleep(0.5)
	print(f"\nComputer chose {rps[0]}\n\n")
	time.sleep(0.5)
	
	#calling decider
	p_points , s_points =who_wins(player,rps[0],p_points,s_points)
	print("\n")
	time.sleep(0.3)
	
	#displaying points
	print(f"\033[2mPlayer : {p_points} ,Computer : {s_points}")
	time.sleep(0.5)
	print("\n")
	
	#while loop for wrong response
	while True:
		rematch = input("Do you want to continue?(Yes/no)")
		print("\n")
		if rematch=="y" or rematch=="yea" or rematch=="yes" or rematch =="sure" or rematch == "ok":
			time.sleep(0.5)
			print("Restarting..\n")
			break
			
		elif rematch =="no":
			
			if p_points>s_points:
				print("You won".center(55))
				break
				
			elif p_points==s_points:
				print("It's a Draw".center(55))
				break
				
				
			else:
				print("You lost".center(55))
				break
				
				
		else:
				print("input should be yes or no")
	if rematch =="no":
		break