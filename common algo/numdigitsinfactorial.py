# Python3 program to find the
# number of digits in a factorial
import math
from sys import stdin
 
# This function receives an integer
# n, and returns the number of
# digits present in n!
 
 
def findDigits(n):
     
    # factorial of -ve number
    # doesn't exists
    if (n < 0):
        return 0
 
    # base case
    if (n <= 1):
        return 1
 
    # Use Kamenetsky formula to
    # calculate the number of digits
    x = ((n * math.log10(n / math.e) +
              math.log10(2 * math.pi * n) /2.0))
 
    return math.floor(x) + 1
 
 
# Driver code
if __name__ == "__main__":
    lines = stdin.read().splitlines()
    for line in lines:
        print(findDigits(int(line)))
  
  