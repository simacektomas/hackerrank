#!/bin/python3

import math
import os
import random
import re
import sys
from heapq import heapify, heappush, heappop

#
# Complete the 'cookies' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY A
#

def cookies(k, A):
    # Construct Min Heap (by default) from given array
    heapify(A)
    lowest_sweetnes = A[0]
    moves = 0
        
    while lowest_sweetnes < k and len(A) >= 2:     
        cookie = heappop(A) + 2*heappop(A)
        heappush(A, cookie)             
        lowest_sweetnes = A[0]
        moves += 1
    
    return -1 if lowest_sweetnes < k else moves
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    A = list(map(int, input().rstrip().split()))

    result = cookies(k, A)

    fptr.write(str(result) + '\n')

    fptr.close()

