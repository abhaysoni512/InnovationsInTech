# user_prompt = "Enter a todo: "
# text1 = input(user_prompt)
# text2 = input(user_prompt)
# text3 = input(user_prompt)
# todos = [text1,text2,text3,"Hello"]


#as we are typing multiple time input function so we will use a way to minimize it
user_prompt = "Enter a todo: "
#suppose we want to store multiple inputs we will use todos list
todos = []
while True:
    todo = input(user_prompt)
    todos.append(todo)          #methods are functions that are attached to other objects here is list object c++ m bhi yhi example h
    print(todos)                


