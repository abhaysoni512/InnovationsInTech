todos = []

while True:
    user_action = input("Type add or show or break : ")
    user_action = user_action.strip()
    match user_action:
        case 'add':
            todo = input("Enter todo : ")
            todos.append(todo)
        case 'show':
            for item in todos:
                print(item)
        case 'break':
            break
        case _:
            print("Entered a wrong prompt , please retry...")


