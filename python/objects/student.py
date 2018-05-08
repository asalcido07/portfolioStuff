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
