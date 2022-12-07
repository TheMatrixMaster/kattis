

inp = str(input())

counter = 1

while inp != "END":
    
    isEven = True
    
    intervals = set()
    last = -1
    curr = 0
    
    for i, c in enumerate(inp[1:]):
        i = i+1
        if c == '*':
            last = curr
            curr = i
            
            intervals.add(curr-last)
            
            if len(intervals) > 1:
                isEven = False
                
    if isEven: print(counter, "EVEN")
    else: print(counter, "NOT EVEN")
                
    inp = str(input())
    counter += 1