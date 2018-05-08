students = []

# Create a list, store values in list, return list
def get_students_titlecase():
	students_titlecase = [] 
	for student in students:
		students_titlecase.append(student["name"].title()) # .title capitalizes first word of each string i.e. mark == Mark
	return students_titlecase

# Create a list, store values from function call, print values
def print_students_titlecase():
	students_titlecase = get_students_titlecase()
	print(students_titlecase)

# Add new student to list
def add_student(name, student_id=332):	# 332 default value if not value is passed
	student = {"name": name, "student_id": student_id}	
	students.append(student)

def save_file(student):
	try:
		f = open("students.txt", "a")
		f.write(student + "\n")
		f.close()
	except Exception:
		print("Could not save file")

def read_file():
	try:
		f = open("students.txt", "r") # reading file with "r"
		for student in f.readlines(): # .readlines() will read every line and return 
			add_student(student)
		f.close()
	except Exception:
		print("Could not read file")

read_file()

print_students_titlecase()

student_name = input("Enter student name: ")
student_id = input("Enter student ID: ")

add_student(student_name, student_id)
save_file(student_name)

#print_students_titlecase function doesn't work