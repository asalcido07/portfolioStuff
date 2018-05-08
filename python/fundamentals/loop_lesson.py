student_names = ["Adam", "Ralph", "Ticun", "Adrian", "Edgar"]

# Different way of iterating and printing out names in list
for name in student_names:
	print(f"Student's name is {name}.")

print("\n\n")

# Typical way of looping and printing?
for name in student_names:
	print("Student's name is {0}".format(name))

print("\n\n")

x = 0
for index in range(10):
	x += 10
	print("The value of X is {0}".format(x))

print("\n\n")

x = 0
for index in range(11):
	x += 10
	print("The value of X is {0}".format(x))

print("\n\n")

x = 0
for index in range(5,10):
	x += 10
	print("The value of X is {0}".format(x))

print("\n\n")

# Iterates at least once, but 5 is incremented (+6) 5 + 6 = 10
# If 10 < 11, continue loop
x = 0
for index in range(5,11,5):
	x += 10
	print("The value of X is {0}".format(x))

print("\n\n")

# Iterates at least once, but 5 is incremented (+6) 5 + 6 = 11
# If 11 < 11, stop the loop
x = 0
for index in range(5,11,6):
	x += 10
	print("The value of X is {0}".format(x))