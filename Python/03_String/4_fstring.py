#string formatting
template = "Dear {},You are awesome. Take this {}$ bag."

a = "John"
a1 = 10000
b = "Jack"
b1 = 1000
c = "Marry"
c1 = 300

s1 = template.format(a,a1)
print(s1)

#now let's fstring works to variable inside string f"{}""
print(f"Dear {a},You are awesome. Take this {a1}$ bag.")