student = {
	"name": "Mark",
	"student_id": 15163,
	"feedback": None
}

student["last_name"] = "Kowalski"

try:
	last_name = student["last_name"] # Try to find last name of student
	numbered_last_name = 3 + last_name
except KeyError:
	print("Error finding last_name") # Except when there is Key Error
								   	 # If there is a Key Error, print statement
except TypeError as error:
	print("I can't add these two together")	# Can't add int and string together 
	print(error)

print("This code executes.")


#Testing out tuple and looping through 
tuple_stuff = (3, 5, 1, "Mark")

for index in tuple_stuff:
	print("{0}".format(index))