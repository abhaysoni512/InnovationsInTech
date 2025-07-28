# oops is way of prgamming that allows us to create objects that can have properties and methods.

# Class is a blueprint or a template
# Object is specific instance from the class blueprint

class Employee:
    company = "HP"  #this is class Attribute

    def get_salary(self):  #self is like this pointer #it is mandatory in python
        return self.salary
    
    #constructor
    def __init__(self,salary = 34000, name ="", bond =1,company = "Lula") :
        self.salary = salary        #it's instance attribute of name salary and assigned it with salary
        self.name = name
        self.bond = bond
        self.company  = company
    
    def printInfo(self):
        print(f"Employee: {self.name}, Salary: {self.salary}, Bond ={self.bond}, Company = {self.company}")
    
    

e1 =Employee(salary= 0.1, name="Abhay", bond=4,company= "Tesla")
e1.printInfo() #always print instance attribute whenever present
print(Employee.company)

'''
#object introspection
CMD:
print(dir(e1))
Output:
['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__firstlineno__', '__format__', '__ge__', '__getattribute__', '__getstate__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__static_attributes__', '__str__', '__subclasshook__', '__weakref__', 'bond', 'company', 'get_salary', 'name', 'printInfo', 'salary']
'''

