name = "harry world"

# TypeError: 'str' object does not support item assignment
print(len(name))
print(name.upper())
print(name.lower())
print(name.capitalize())
print(name.title())
print("--------------------------------------------------------")
text = " hello world "
print(text.strip())
print(text.lstrip())
print(text.rstrip())

print("--------------------------------------------------------")

text = "Pyhton is fun and fun and fun"
print(text.find("is"))
print(text.replace("fun","cool"))

print("--------------------------------------------------------")

text = "Apples,Bananas,Pineapples" 
print(text.split(","))             #convert into list
print(text)