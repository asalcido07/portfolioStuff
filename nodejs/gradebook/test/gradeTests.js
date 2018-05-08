var book = require("../lib/grades").book;

exports["setUp"] = function(callback) {
	book.reset();
	callback();
};

// [], different notation to add a property or function to exports object
// Can have spaces in between

exports["Can average grades"] = function(test) {
	book.addGrade(100);
	book.addGrade(50);

	var average = book.getAverage();

	test.equal(average, 75);
	test.done();
};

exports["Can add new grade"] = function(test) {
	book.addGrade(90);
	var count = book.getCountOfGrades();

	test.equal(count, 1);
	test.done();
};

exports["Can print average score"] = function(test) {
	var average = 0;

	book.addGrade(50);
	book.addGrade(50);
	book.addGrade(50);

	average = book.getAverage();
	book.printAverage();

	test.equal(average, 50);
	test.done();
};

exports["Can compute letter grade of A"] = function(test) {
	book.addGrade(100);
	book.addGrade(0);

	var result = book.getLetterGrade();
	test.equal(result, 'F');
	test.done();
}