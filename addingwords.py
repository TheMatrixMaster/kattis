from sys import stdin

vars = {}

def parse_expr(tokens, acc, op):
    tok = tokens.pop(0)
    if tok == '=':
        keys = list(vars.keys())
        vals = list(vars.values())
        return 'unknown' if acc not in vals else keys[vals.index(acc)]
    elif tok == '+': return parse_expr(tokens, acc, '+')
    elif tok == '-': return parse_expr(tokens, acc, '-')
    else:
        if tok not in vars: return 'unknown'
        elif op == '+': return parse_expr(tokens, acc+vars[tok], '+')
        elif op == '-': return parse_expr(tokens, acc-vars[tok], '+')

out = []

for line in stdin:
    
    if line.startswith('def'):
        _, var, val = line.split(' ')
        vars[var] = int(val)
        
    elif line.startswith('calc'):
        toks = line[5:-1].split(' ')
        r = parse_expr(toks, 0, '+')

        out.append(line[5:-1] + f' {r}')

    elif line.startswith('clear'):
        vars = {}

for line in out:
    print(line)