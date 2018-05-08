students = []

# Create a list, store values in list, return list
def get_students_titlecase():
	student_titlecase = [] 
	for student in students:
		students_titlecase = student.title()
	return student_titlecase

# Create a list, store values from function call, print values
def print_students_titlecase():
	students_titlecase = get_students_titlecase()
	print(student_titlecase)

# Add new student to list
def add_student(name, student_id=332):	# 332 default value if not value is passed
	student = {"name": name, "student_id": student_id }	
	students.append(student)


def var_args(name, *args):
	print(name)
	print(args)


def var_kwargs(name, **kwargs):
	print(name)
	print(kwargs["description"], kwargs["feedback"])						

student_list = get_students_titlecase()

add_student(name="Mark", student_id=15)

print("Hello", "World", 3, None, "Something")

var_args("Mark", "Loves Python", None, "Hello", True)

var_kwargs("Mark", description="Loves Python", feedback=None, pluralsight_subscriber=True)