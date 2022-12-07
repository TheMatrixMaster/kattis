drm = list(str(input()))

f = drm[:len(drm)//2]
s = drm[len(drm)//2:]

rotf = sum([ord(x)-65 for x in f])
rots = sum([ord(x)-65 for x in s])

f = [(((ord(x)-65)+rotf)%26) for x in f]
s = [(((ord(x)-65)+rots)%26) for x in s]

z = [chr((f[i]+s[i])%26+65) for i in range(len(f))]

print("".join(z))