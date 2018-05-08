student = {
	"name": "Mark",
	"student_id": 15163,
	"feedback": None
}

all_students = [
	{"name": "Mark", "student_id": 15163},
	{"name": "Katarina", "student_id": 63112},
	{"name": "Jessica", "student_id": 30021}
]

print(student["name"])

# Checks if last_name key exists, if not found return "Unknown"
print(student.get("last_name", "Unknown"))

print(student.get("name", "Unknown"))

# Get all keys
print(student.keys())

# Get all values
print(student.values())

student["name"] = "James"

print(student["name"])

del student["name"] 

print("\n\n")

#How to loop through list of dictionaries and look at each key
for dic_item in all_students:
	for key in dic_item:
		print(dic_item[key])

# Check if "Jessica" exists in list (all_students) of dictionaries (dic)
# If found, print out the statement
if any(dic["name"] == "Jessica" for dic in all_students):
	print("Jessica does exist")


if not any(dic["name"] == "bob" for dic in all_students):
	print("Bob doesn't exist")