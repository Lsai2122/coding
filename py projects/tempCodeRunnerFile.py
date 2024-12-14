num = int(input())
seq = input()
i = 0
greatest_time = 0
letter_pair = {}
while i<num-1:
    pair = seq[i:i+2]
    if pair in letter_pair:
        letter_pair[pair]+=1
    else:
        letter_pair[pair]=1
    i+=1

for temp_pair,temp in letter_pair.items():
    if greatest_time<temp:
        greatest_time=temp
        greatest_pair = temp_pair
    if greatest_time==temp:
        if greatest_pair>temp_pair:
            greatest_pair=temp_pair
print(greatest_pair)