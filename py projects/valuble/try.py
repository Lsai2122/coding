s = {"a":2,"b":3,"c":1}
sorted(s.values(),key=lambda x:x[1])
print(s)