n = int(input())

def rec_print(words):
    if len(words) == 1:
        print(words.pop())
    elif len(words) > 1:
        first_word = words.pop()
        second_word = words.pop()
        print(first_word)
        rec_print(words)
        print(second_word)

if __name__ == "__main__":
    counter = 1
    while n != 0:
        words = list(reversed([input() for _ in range(n)]))
        print(f"SET {counter}")
        rec_print(words)
        n = int(input())
        counter += 1