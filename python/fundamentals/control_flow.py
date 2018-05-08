number = 5

if number == 5:
	print("number is 5")

else:
	print("number is NOT 5")

text = "python"

if text:
	print("text is defined and truthy")

python_course = True

if python_course:
	print("This will execute")

aliens_found = None

if aliens_found:
	print("This will NOT execute")


num = 3

if number == 3 and python_course:
	print("This will execute")

if number == 3 or python_course:
	print("This will also execute")

#ternary if statements
a = 1
b = 2

print("bigger") if a > b else print("smaller")