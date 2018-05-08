students = []

# Create a list, store values in list, return list
def get_students_titlecase():
	students_titlecase = [] 
	for student in students:
		students_titlecase = student["name"].title()
	return students_titlecase

# Create a list, store values from function call, print values
def print_students_titlecase():
	students_titlecase = get_students_titlecase()
	print(students_titlecase)

# Add new student to list
def add_student(name, student_id=332):	# 332 default value if not value is passed
	student = {"name": name, "student_id": student_id}	
	students.append(student)

def choose_to_add():
	choice = input("Would you like to add a student? ")
	if (choice == "yes"):
		student_name = input("Enter student name: ")
		student_id = input("Enter student ID: ")
		add_student(student_name, student_id)
		choose_to_add()

	else:
		print("Will now print out students...")
		print_students_titlecase()

student_list = get_students_titlecase()

choose_to_add()



print(students)

#print_students_titlecase function doesn't work