var User = require("../models/user.js");
var mysql = require("mysql");
var childProcess =  require("child_process");
var url = require("url");
var queryString = require("querystring");

var MysqlController = {

	configure: function(){
	},

	home: function(req, res, next){
		res.sendfile("home.html", {root: "./views/"});
	},

	inputQuery: function(req, res){
		var results;
		connection.query('select * from files', function(err, rows, fs){
			if (err) {
				console.log('Something is broken');
				console.log(err);
				console.log(fs);
			}
			results = JSON.stringify(rows);
			res.json(results);
		});
	},
};

module.exports = MysqlController;

	
