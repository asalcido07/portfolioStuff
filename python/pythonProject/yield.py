students = []

def read_file():
	try:
		f = open("students.txt", "r") # reading file with "r"
		for student in read_students(f):
			students.append(student) # Changed from add_student(student)
		f.close()
	except Exception:
		print("Could not read file")

def read_students(f):
	for line in f:
		yield line

read_file()
print(students)

#lambda function example
double = lambda x: x * 2

print(double(2))