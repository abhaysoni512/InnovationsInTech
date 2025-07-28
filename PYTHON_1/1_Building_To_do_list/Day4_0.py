todos = []

while True:
    user_action = input("Type add or show or edit or break : ")
    user_action = user_action.strip()
    match user_action:
        case 'add':
            todo = input("Enter todo : ")
            todos.append(todo)
        case 'show':
            index = 0
            for item in todos: 
                #learning remove space 0 . swim : ---> use of variable on sting
                print(f"{index}.{item}")
                index+=1
        case 'break':
            break
        case "edit":
            number = input("Enter no whom you want to edit: ")
            todos[int(number)] = input("Enter new edit todo :")        
        case _ :
            print("Entered a wrong prompt , please retry...")


