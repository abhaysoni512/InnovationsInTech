'''
 0 1 1 2 3 5 8 13
 fib(0) = 0
 fib(1) = 1
 fib(2) = fib(0)+fib(1)
'''


def fibbonacci(n):
    if(n<=1): return n
    return fibbonacci(n-2)+fibbonacci(n-1)

print(fibbonacci(4))