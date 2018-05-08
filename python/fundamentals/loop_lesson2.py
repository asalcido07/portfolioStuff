student_names = ["Adam", "Ralph", "Ticun", "Adrian", "Edgar"]

for name in student_names:
	if name == "Ticun":
		print("Found him! " + name)
		break
	print("Currently testing " + name)

print("\n\n")

for name in student_names:
	if name == "Ticun":
		continue				# Everytihng below continue in block will not execute
		print("Found him! " + name)
	print("Currently testing " + name)

# Result
# Currently testing Adam
# Currently testing Ralph
# Currently testing Adrian
# Currently testing Edgar