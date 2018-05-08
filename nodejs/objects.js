var die = {
	size: 6,
	totalRolls: 0,
	roll: function() {
		var result = Math.ceil(this.size * Math.random());
		this.totalRolls++;
		return result;	
	} 
};

die.size = 10;

console.log(die.roll());
console.log(die.roll());
console.log(die.roll());
console.log("Total rolls " + die.totalRolls);

console.log(die);