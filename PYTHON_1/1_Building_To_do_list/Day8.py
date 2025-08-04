# we are using with context manager

todos = []

while True:
    #get input from user and remove extra space from it
    user_action = input("Type add or show or edit or break or complete: ")
    user_action = user_action.strip()

    # use switch case
    match user_action:
        case 'add':
            todo = input("Enter todo : ") + "\n"
            with open("todo.txt",'r') as file:
                todos = file.readlines()
            todos.append(todo)
            with open("todo.txt",'w') as file:
                file.writelines(todos)
        case 'show':
            with open("todo.txt",'r') as file:
                todos = file.readlines()
            todos = [item.strip('\n') for item in todos]
            for index,item in enumerate(todos): 
                print(f"{index}.{item}")
        case 'break':
            break
        case "edit":
            number = int(input("Enter no whom you want to edit: "))
            todos[number] = input("Enter new edit todo :")  
        case 'complete':
            number = int(input("Enter no whom you want to complete: "))
            todos.pop(number)
        case _ :
            print("Entered a wrong prompt , please retry...")

print("bYE!")