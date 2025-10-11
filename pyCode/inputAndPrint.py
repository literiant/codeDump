user_name = input("Please enter your name: ")
print("Hello, " + user_name + "!")

print("Hello,", user_name,"!")

print(f"Hello, {user_name}!")

print("Hello",end=" ")
print(user_name,end=" ")
print("!")

print("Hello,{}!".format(user_name))

print("Hello,%s!" % user_name)

user_age1 = int(input("Please enter your age:"))
print("Next year,your age will be",str(user_age1+1))
user_age2 = input("Please enter your age:")
print("Next year,your age will be",user_age2+1)#Error,because user_age2 is str type

