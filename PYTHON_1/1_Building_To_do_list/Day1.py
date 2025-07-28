'''
#1st
# s1 output something
print("Enter to do : ") 
user_text = input()
'''

'''
#2nd : argument
user_prompt = "Enter to do : "
user_text = input(user_prompt)     #argument
print(user_text)
print(type(user_text))
'''

#3rd : multiple inputs storage  : list
user_prompt = "Enter a todo: "
text1 = input(user_prompt)
text2 = input(user_prompt)
text3 = input(user_prompt)
todos = [text1,text2,text3,"Hello"]
print(todos)

print(type(todos))

