name = "Abhay12345678"
print(len(name))
k = 0
for i in name:
    print("name [",k,"] =",i)
    k=+1

print("-----------------------------")
#name = " A     b   h  a   y"
#         0     1   2  3   4
#         -5    -4  -3 -2  -1
print(name[-1]) #5-1 = 4

#slicing
print(name[0:2]) #goes from 0 to 1 i.e Ab
print(name[2:-1]) #same as [2:4] ha

#print(name[0:10:n]) #skip n-1 characters
print(name[0::1])  #skip 0 character
print(name[0::2])  #skip 1 character
