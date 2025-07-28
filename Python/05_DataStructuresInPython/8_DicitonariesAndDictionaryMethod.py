Student = {"name":"Abhay","age":26,"prof":"Software developer"}

#note : key should be hasable(mutable)
print(Student,type(Student))

print(Student["name"])

Student["age"] = 23

print(Student["age"])

#print all the keys
print(Student.keys())

#print all values
print(Student.values())

Student.pop("prof")
print(Student)