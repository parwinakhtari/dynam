full question link: https://www.hackerrank.com/challenges/fibonacci-modified/problem
# Python program to solve

def fibonacciModified(t1, t2, n):
    i = 2
    while i < n:
        t1, t2 = t2, t1 + t2*t2
        i += 1
    return t2
