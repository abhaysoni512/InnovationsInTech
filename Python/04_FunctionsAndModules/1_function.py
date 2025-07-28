def average(a,b,c):     # a,b,c are positional arguments
    return (a+b+c)/3

a=11
b=11
c=11

print(average(a,b,c))
print(average(1,2,3))
d= average(1,2,3)
print(d)

def add(a, b=0):    #b=0 default argument
    return a+b

print(add(1))
print(add(1,2))

c1 = add(b=5,a=1)
print(c1)