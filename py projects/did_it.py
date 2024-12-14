import ls
nums=[]
flag=""
exit=["e","bye","exit","break","b"]
while flag.lower() not in exit:
    num = input("give a number to add to list: ")
    try:
        num = int(num)
        nums.append(num)
    except:
        break
print(f"list before sorting : {nums}")
ls.sort(nums)
print(f"after sorting : {nums}")