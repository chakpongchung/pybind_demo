#!/usr/bin/env python3

import resource, sys
import numba

resource.setrlimit(resource.RLIMIT_STACK, (resource.RLIM_INFINITY, resource.RLIM_INFINITY))
sys.setrecursionlimit(10**8)

@numba.jit(nopython=True, cache=True, nogil=True)
def ack(M: int, N: int):
    if M == 0:
        return N + 1
    elif N == 0:
        return ack(M - 1, 1)
    else:
        return ack(M - 1, ack(M, N - 1))

# 4,1 does 2862984010 calculations
print(ack(4, 1))
