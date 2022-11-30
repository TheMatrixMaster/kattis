n = int(input())

table = {
    '000': '0',
    '001': '1',
    '010': '2',
    '011': '3',
    '100': '4',
    '101': '5',
    '110': '6',
    '111': '7'
}

result = ''

while n > 0:
    
    rem = str(n % 1000)
    
    loss = 3 - len(rem)
    
    if loss > 0:
        rem = '0'*loss + rem
        
    result = table[rem] + result
        
    n = n // 1000
    
    
print(result)