a = enumerate("hello")

print(a)
# we will get as <enumerate object at 0x10248d4e0>

#to print a, we have to use :
a = list(a)
print(a)

#[(0, 'h'), (1, 'e'), (2, 'l'), (3, 'l'), (4, 'o')]