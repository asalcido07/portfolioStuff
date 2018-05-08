var x = 3, y = 2.5;

var type = typeof "3";
var z = '3';
var result = x > y;
var name = "Barry";

var writeGreeting = function(name) {
	var message = "Hello, " + name;

	console.log(message);
}

writeGreeting(name);

var answer = parseInt(z) + y; // parseInt typecasts string into type number
console.log(answer);
console.log(typeof answer);

x = 5;

console.log(typeof x);
console.log(typeof y);
console.log(typeof z);
console.log(typeof console);
console.log(typeof console.log);

