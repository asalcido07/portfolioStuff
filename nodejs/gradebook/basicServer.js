var book = require("./lib/grades").book;
var express = require("express");
var app = express();

app.get("/", function(req, res) {
	res.send("Yo what's, good homies?!");
});

app.get("/grade", function(req, res) {

	// "100,90,80,95".split(",") => [100,90,80,95]
	var grades = req.query.grades.split(",");

	for(var i = 0; i < grades.length; i++) {
		book.addGrade(parseInt(grades[i]));
	}

	var average = book.getAverage();
	var letter = book.getLetterGrade();

	res.send("Your average is " + average + " grade " + letter);

});

app.listen(3000);
console.log("Server ready...");
