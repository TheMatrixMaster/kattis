s = input()

upper = 0
lower = 0
symbols = 0
whitespaces = 0

for c in s:
    asc = ord(c)
    if asc == 95:
        whitespaces += 1
    elif 65 <= ord(c) <= 90:
        upper += 1
    elif 97 <= ord(c) <= 122:
        lower += 1
    else:
        symbols += 1


total = upper + lower + symbols + whitespaces

print(whitespaces / total)
print(lower / total)
print(upper / total)
print(symbols / total)