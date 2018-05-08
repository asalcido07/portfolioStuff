students = []

class Student:

	school_name = "Springfield Elementary"

	# Constructor function
	def __init__(self, name, student_id=332):	# 332 default value if not value is passed
		self.name = name
		self.student_id = student_id
		students.append(self)

	# Returns "Student" when object is printed	
	def __str__(self):
		return "Student " + self.name

	def get_name_capitalize(self):
		return self.name.capitalize()

	def get_school_name(self):
		return self.school_name

mark = Student("Mark")

print(mark)

print(mark.get_name_capitalize())

print(Student.school_name)

class HighSchoolStudent(Student):

	school_name = "Springfield High School"

	def get_school_name(self):
		return "This is a High School student"

	def get_name_capitalize(self):
		original_value = super().get_name_capitalize()
		return original_value + "-HS"


james = HighSchoolStudent("james")
print(james.get_school_name())
print(james.get_name_capitalize())