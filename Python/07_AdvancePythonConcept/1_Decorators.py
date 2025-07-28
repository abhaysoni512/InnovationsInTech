'''
    Decorator is a function that takes a function as argument, it creates a new function inside its body (wrapper). Then it return that new function
'''

def decorator(say_hello):
    def wrapper():
        print("Before hello greet ")
        say_hello()
        print("After hello greet")
    return wrapper   #return the wrapper function from decorator (not from inside wrapper)

'''
    def say_hello():
        print("hello!")
    f = decorator(say_hello)
    f()

'''

# we can use alternatively using decorator

@decorator  #change functionality using wrapper
def say_hello():
    print("hello")

say_hello()


