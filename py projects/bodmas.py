inputs=[]
while True:
	no=0
	op=0
	no=int(input("Type the number: "))
	op=input("Give the operator or type 'Q' for exit: ")
	if op.lower()=='q':
		inputs.append(no)
		break
	else:
		inputs.append(no)
		inputs.append(op)
k=[]
n=-1
for u in inputs:
	n+=1
	if u=="/":
		k.append(n)
z=0
for p in k:
	p=p-z
	a=inputs[p-1]
	b=inputs[p+1]
	inputs[p]=a/b
	inputs.pop(p+1)
	inputs.pop(p-1)
	z+=2
n=-1
k=[]
for u in inputs:
	n+=1
	if u=="*":
		k.append(n)
z=0
for p in k:
	p=p-z
	a=inputs[p-1]
	b=inputs[p+1]
	inputs[p]=a*b
	inputs.pop(p+1)
	inputs.pop(p-1)
	z+=2
n=-1
k=[]
for u in inputs:
	n+=1
	if u == "+":
		k.append(n)
z=0
for p in k:
	p=p-z
	a=inputs[p-1]
	b=inputs[p+1]
	inputs[p]=a+b
	inputs.pop(p+1)
	inputs.pop(p-1)
	z+=2
n=-1
k=[]
for u in inputs:
	n+=1
	if u == "-":
		k.append(n)
z=0
for p in k:
	p=p-z
	a=inputs[p-1]
	b=inputs[p+1]
	inputs[p]=a-b
	inputs.pop(p+1)
	inputs.pop(p-1)
	z+=2
print(inputs[0])