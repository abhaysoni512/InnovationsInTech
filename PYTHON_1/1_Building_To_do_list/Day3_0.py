todos = []

while True:
    user_action = input("Type add or show or break : ")
    
    #learning : user can enter add followed by space 
    user_action = user_action.strip()      #strip ka use space ko hatane ke liye
    match user_action:                     #switch case
        case 'add':
            user_action = input("Enter todo : ")
            todos.append(user_action)
        case 'show':
            for item in todos:
                item = item.title()
                print(item)
        case 'break':
            break
        #learning
        case _:     #don't use default instead python has - _ (underscore)
            print("Entered a wrong prompt , please retry...")


print("Bye...")