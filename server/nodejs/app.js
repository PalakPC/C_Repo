var mysql = require("mysql");
var fs = require("fs");
var url = require("url");
var util = require("util");
var express = require("express");
var config = require("./config/config.js");
//var MysqlController = require("./controllers/mysql.js");
var _ = require("underscore");
var queryString = require("querystring");

var app = express();

var connection = mysql.createConnection({
		host: 'localhost',
		user: 'root',
		password: 'palak',
		database: 'files'
	});
connection.connect();

require("./config/express.js")(app, config);

app.get('/', function(req, res){
		res.redirect("home");
	});

app.get("/home", function(req, res, next){
		res.sendfile("home.html", {root: "./views/"});
	});
app.get("/inputQuery", function(req, res){
	var results;
	connection.query('select * from file', function(err, rows, fs){
		if (err) {
			console.log('Something is broken');
			console.log(err);
			console.log(fs);
		}
		results = JSON.stringify(rows);
		res.json(results);
	});
});

app.listen(config.SERVER_PORT);
console.log("Mysql server up and running at --> " + config.SERVER_PORT);
