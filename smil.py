
s = str(input())

addresses = []

for i in range(len(s)-1, 0, -1):
    
    if s[i] == ')':
        
        if s[i-1] in [':', ';']:
            addresses.append(i-1)
        elif s[i-1] == '-':
            if i > 1 and s[i-2] in [':', ';']:
                addresses.append(i-2)
            
for i in reversed(addresses):
    print(i)