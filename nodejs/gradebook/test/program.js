var book = require("../lib/grades").book;

exports["setUp"] = function(callback) {
	book.reset();
	callback();
};

exports["Can print average score"] = function(test) {
	var average = 0;

	book.addGrade(90);
	book.addGrade(90);
	book.addGrade(90);

	average = book.getAverage();
	book.printAverage();

	test.equal(average, 90);
	test.done();
};