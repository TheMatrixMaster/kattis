def add_subtract(tokens, acc):
    if not tokens: return [], acc
    elif tokens[0] not in ['+', '-']:
        new_tokens, new_acc = multiply_divide(tokens, acc)
        return add_subtract(new_tokens, new_acc)
    else:
        op = tokens.pop(0)
        if op == '+': 
            new_tokens, new_acc  = multiply_divide(tokens, 4)
            return add_subtract(new_tokens, acc+new_acc)
        else:
            new_tokens, new_acc  = multiply_divide(tokens, 4)
            return add_subtract(new_tokens, acc-new_acc)
        

def multiply_divide(tokens, acc):
    if not tokens: return [], acc
    elif tokens[0] not in ['*', '/']: return tokens, acc
    else:
        op = tokens.pop(0)
        if op == '*': return multiply_divide(tokens, acc*4)
        else: return multiply_divide(tokens, acc//4)
        

if __name__ == '__main__':

    m = int(input())
    operators = ['*', '+', '-', '/']
    map = {}

    for a in operators:
        for b in operators:
            for c in operators:
                perm = [a, b, c]
                toks, res = add_subtract(perm.copy(), 4)
                map[res] = f"4 {perm[0]} 4 {perm[1]} 4 {perm[2]} 4 = {res}"
            

    for _ in range(m):    
        n = int(input())
        
        if n not in map: print('no solution')
        else: print(map[n])
    