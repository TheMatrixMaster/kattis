S = str(input()).strip()
P = str(input()).strip()

success = False

if len(S) == len(P):
    if (P == S) or P == S.swapcase():
        success = True
elif len(P) == len(S) - 1:
    if S[0].isdigit() and S[1:] == P:
        success = True
    elif S[-1].isdigit() and S[:-1] == P:
        success = True

if success:
    print("Yes")
else:
    print("No")

