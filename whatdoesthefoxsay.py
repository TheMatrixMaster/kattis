t = int(input())

for _ in range(t):
    
    known_sounds = set()
    
    words = list(input().split(' '))
    
    newline = str(input().strip())
    
    while newline != 'what does the fox say?':
        
        _, __, sound = newline.split(' ')
        
        known_sounds.add(sound)

        newline = str(input().strip())
        
    words = [w for w in words if w not in known_sounds]
    
    print(' '.join(words))
    