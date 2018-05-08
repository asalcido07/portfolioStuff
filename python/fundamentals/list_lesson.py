student_names = ["Adam", "Ralph", "Ticun", "Adrian", "Edgar"]

print(student_names[0])
print(student_names[1])
print(student_names[4])

student_names[4] = "Josh"

print(student_names[4])

student_names.append("Edgar")

print(student_names)

#Checking if Edgar is in the list
if "Edgar" in student_names:
	print("Edgar is in the list")

print(len(student_names))

#How to delete an item in the list
del student_names[2]

print(student_names)

print(student_names[1:-1])

