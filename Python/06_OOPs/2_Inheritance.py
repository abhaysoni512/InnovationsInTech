class Animal:
    location = "Austrailia"
    def __init__(self,name):

        print("Constructor called")
        self.name = name
    def speak(self):
        print("Generic Animal Sound")
    #suppose we want to call parent class method from child class object
a = Animal("Dog")
class Dog(Animal):
    def speak(self):
        super().speak()
        print("Woof")


d = Dog("Bruno")
d.speak()
print(d.location)
        