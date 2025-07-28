#storing data in text file

todos = []

while True:
    user_action = input("Type add or show or edit or break or complete: ")
    user_action = user_action.strip()
    match user_action:
        case 'add':
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
            #enumerate use it takes list as argument
            for index,item in enumerate(todos): 
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