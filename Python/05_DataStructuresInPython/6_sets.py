#sets are unordered, unique collections(no duplicates these are mutuable

s = {"apple","banana","cherry"}

print(s,type(s))

s.add("lemon")
print(s)
# s.remove("mango") Will throw an error
s.discard("manago")