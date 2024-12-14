screens ={ 

1 : "Transformers" , 
2 : "Aliens" , 
3 : "Agent" 

}

snacks = { 
1 : 
[ "1)  Normal Pop corn" ,"2)  Spicy Popcorn" ],

2 :
["1)  Coco Cola" , "2)  Sprite" , "3)  Thumbs Up" , "4)  7 Up"],

3 :
["1)  Egg Puff" , "2)  Sandwich" , "3)  Samosa" , "4)  Burgur" ]

}

program_start = True

    
print("             __________________________________\n            |           JLE Movies             |\n             ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n")
while program_start:
    print("Msg: Greetings! Sir, Kindly select the fecility you want to check.")
    option = input("1 For a Ticket, 2 For some Snack, 3 For Movies lists. \n")
    option = int(option)
    print("\n")
    if option == 1:
        
        start = True
        while start:
          
              print("Insert the screen number Sir.")
              screen_no=input(':')
              screen_no = int(screen_no)
              print("\n")
              if screen_no >3 :
                  
                  print("screen no is Less than 3 sir.\n")
                  
              else:
          
                  print(f"  {screens[screen_no]} is playing Sir. Would like to confirm the ticket. (state Yes or No)")
                  forward = input(':')
                  forward = forward.title()
                  
                  if forward == "Yes":
                        
                        flag = True
                        while flag :
                            
                            print("\n  How many are you sir?")
                            members = input(':')
                            members = int(members)
                            print("\n")
                            if members > 10 :
                                
                                print("  Sorry to Inform you that this mechanism only allows a 10 seats booking at once.\n So lets try this again")
                                
                            elif members <=0:
                                
                                print("  Sorry sir the input must be greater that 0")
                                
                            elif members > 0:
                                
                                print(f"\n   Booking {members} Tickets. Thank you, For using our services Have a Great movie.\n \n \n")
                                flag = False
                                start = False
                                
                  elif forward == "No" :
                     
                     print("Okay sir, Redirecting you to the starting page\n")
                     break
                  else :
                    
                    print("insert a valid keyword Sir. Let's try this again\n")
                    
    elif option ==2:
        
        start_2 = True
        while start_2:
            
            
            print("Select any of the following with its respective number to get it's sublist.\n 1) Popcorn \n 2) Drink\n 3)Other snacks ")
            option_snacks = input(":")
            option_snacks = int(option_snacks)
            print("\n")
            
            
            if option_snacks >=4:
                print("Option is less than 4")
                
                
            elif option_snacks >= 1:
                
                #creating a loop to display the sub topicof snack
                
                for snack_sub in snacks[option_snacks]:
                    
                    print(f"{snack_sub}")
                order = input("What's your Order? :")
                order = int(order)
                
                #getting the order sorted with small code           
                option_snacks_sub = snacks[option_snacks]
                got_order = option_snacks_sub[order - 1]
                got_order = got_order.replace(")" , "")
                got_order = got_order.replace(f"{order}" , "")
                got_order = got_order.replace("  ", "")
                got_order = got_order.title()
                
                
                print(f"\n                'Getting {got_order} ready.'\n \n \n")
                break
    elif option==3:
        for screen_no in screens:
                movie_name = screens[screen_no]
                print(f"Screen no {screen_no}-> {movie_name} ")
        print("\n\n")