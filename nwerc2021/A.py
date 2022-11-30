import sys
out = ""

def getTime():
    i = input()
    if i == "ACCESS GRANTED": return 10**9
    return int(i[15:-4])

time = 0
for i in range(20):
    out += "a"
    print(out)
    sys.stdout.flush()
    time = getTime()
    if time != 5: break

def inc(c):
    if c == 'z': return 'A'
    if c == 'Z': return '0'
    return chr(ord(c) + 1)

while (time-5)//9 <= len(out):
    correct = (time-5)//9
    idx = correct-1
    out = out[:idx] + inc(out[idx]) + out[idx+1:]
    print(out)
    time = getTime()