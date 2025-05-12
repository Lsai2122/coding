def append_elem(a,seq = None):
    if seq == None:
        seq = []
    seq.append(a)
    return seq
print(append_elem(1))
print(append_elem(2))