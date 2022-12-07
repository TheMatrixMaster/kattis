word = str(input())

best = ""

for i in range(1, len(word)-1):

    for j in range(i+1, len(word)):

        first = "".join(reversed(word[0:i]))
        second = "".join(reversed(word[i:j]))
        third = "".join(reversed(word[j:]))

        final = first + second + third

        if not best: best = final
        elif final < best: best = final

print(best)
