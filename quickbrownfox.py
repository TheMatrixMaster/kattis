n = int(input())

for _ in range(n):
    
    letters = [1] * 26
    line = input()
    
    for char in line:
        
        if char.isalpha():
            asc = ord(char.lower())
            letters[asc-97] = 0
            
    if letters.count(1) == 0:
        print('pangram')
    else:
        out = ''
        
        for i, l in enumerate(letters):
            if l == 1:
                out += chr(i+97)
                
        print(f"missing {out}")
        
    
    