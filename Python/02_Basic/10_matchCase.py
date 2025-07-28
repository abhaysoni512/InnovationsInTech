a = int(input("Enter a value: "))

match a:
    case 1:
        print("Yon won a charger")
    case 2:
        print("You won 1 rs")
    case _:
        print("Better luck next time") # _ for default