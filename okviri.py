w = input()

pp = []

rows = ['']*5

for i, c in enumerate(w):

    wendy = i != 0 and (i+1) % 3 == 0
    
    if wendy:
        rows[0] += '..*..'
        rows[1] += '.*.*.'
        rows[2] += f'*.{c}.*'
        rows[3] += '.*.*.'
        rows[4] += '..*..'
    
    elif i != 0 and (i+1) % 3 == 1:
        rows[0] += '.#.'
        rows[1] += '#.#'
        rows[2] += f'.{c}.'
        rows[3] += '#.#'
        rows[4] += '.#.'

    else:
        rows[0] += '..#.'
        rows[1] += '.#.#'
        rows[2] += f'#.{c}.'
        rows[3] += '.#.#'
        rows[4] += '..#.'

    if i == len(w) - 1 and not wendy:
        rows[0] += '.'
        rows[1] += '.'
        rows[2] += '#'
        rows[3] += '.'
        rows[4] += '.'

for row in rows:
    print(row)