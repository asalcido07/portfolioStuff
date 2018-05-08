var gradeBook = {
	_grades: [],
	
	addGrade: function(newGrade) {
		this._grades.push(newGrade);
	},

	getCountOfGrades: function() {
		return this._grades.length;	
	},

	getAverage: function() {
		var total = 0; 

		for (var i = 0; i < this._grades.length; i++) {
			total += this._grades[i];
		}

		return total / this._grades.length;
	},

	reset: function() {
		this._grades = [];
	},

	printAverage: function() {
		var total = 0;

		for (var i = 0; i < this._grades.length; i++) {
			total += this._grades[i];
		}

		console.log(total / this._grades.length);
	},

	getLetterGrade: function() {
		var letterGrade = this.getAverage(); // Use this when calling another function inside a function

		if (letterGrade >= 90 && letterGrade <= 100) {
			return 'A';
		}

		else if (letterGrade >= 80 && letterGrade < 90) {
			return 'B';
		}

		else if (letterGrade >= 70 && letterGrade < 80) {
			return 'C';
		}

		else if (letterGrade >= 60 && letterGrade < 70) {
			return 'D';
		}

		else {
			return 'F';
		}
	}
};

// store gradeBook object into exports.book
// Export book property
exports.book = gradeBook; 