#how to remove extra break line

todos = []

while True:
    #get input from user and remove extra space from it
    user_action = input("Type add or show or edit or break or complete: ")
    user_action = user_action.strip()

    # use switch case
    match user_action:
        case 'add':
            # why \n as in file io we want next todo on new line
            todo = input("Enter todo : ") + "\n"

            #to preserve previous data
            file = open("todo.txt",'r')
            todos = file.readlines()
            file.close()

            todos.append(todo)

            file = open("todo.txt",'w')
            file.writelines(todos)
            file.close()
        case 'show':
            file = open("todo.txt",'r')
            todos = file.readlines()
            file.close()
            '''
                #sol1 to solve double new enter one we added on add todo ,one by print function 
                new_todos = []
                for item in todos:
                item = item.strip()
                new_todos.append(item)
            '''

            '''
                #sol2 without for loop or we can say on single line : using list comprehension
                new_todos = [item.strip('\n') for item in todos]
            '''
            #we don't need above methods
            for index,item in enumerate(todos): 
                item.strip('\n')
                print(f"{index}.{item}")
        case 'break':
            break
        case "edit":
            number = int(input("Enter no whom you want to edit: "))
            todos[number] = input("Enter new edit todo :")  
        #compllete means delete that item from list
        case 'complete':
            number = int(input("Enter no whom you want to complete: "))
            todos.pop(number)
        case _ :
            print("Entered a wrong prompt , please retry...")

print("bYE!")