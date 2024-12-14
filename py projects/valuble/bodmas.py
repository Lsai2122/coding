# cook your dish here
but = []
flow = []
j = int(input())
for i in range(j):
    k = input().split(" ")
    for t in range(len(k)):
        k[i]=int(k[i])
    if k[0]<=k[1]+k[2] and k[1]<=k[2]+k[0] and k[2]<=k[1]+k[0]:
        print("yes")
    else:
        print("NO")