myList = ['a','b','c']

#note this a b c are individually objects

myList.__setitem__(1,'d') #or myList[1]= 'd'

for item in myList:
    print(item)


#list are 
FileNames = ["1.Raw Data.txt","2.Reports.txt","3.Presentaion.txt"]

for mylist1 in FileNames:
   mylist1 = mylist1.replace('.','-',1)    # '.' ko '-' ko first occurance me replace kro
   print(mylist1)