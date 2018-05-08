var die = {
	size: 6,
	totalRolls: 0,
	roll: function() {
		var result = Math.ceil(this.size * Math.random());
		this.totalRolls++;
		return result;	
	} 
};

exports.die = die;
exports.name = "my dice exports";