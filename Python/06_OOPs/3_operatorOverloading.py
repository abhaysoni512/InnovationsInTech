class point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    
    def sum(self,p):
        return point((self.x+p.x),(self.y+p.y))
    def print(self):
        print(f"X = {self.x} & Y= {self.y}")

    #operator overloading
    def __add__(self,p):
        return point((self.x+p.x),(self.y+p.y))

        

p1 = point(3,3)
p2 = point(11,2)

p = p1.sum(p2)
p.print()

p3 = p1+p2     #operator overloaded
p3.print()
