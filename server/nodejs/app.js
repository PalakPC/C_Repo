//Node.js server to print the rows of a MySQL table to an HTML page on button click.

var mysql = require ("mysql");
var express = require ("express");
var path = require ("path");
var config = require ("./config/config.js");

var app = express ();

app.use(express.static(config.ROOT_PATH + "/views")); 

var connection = mysql.createConnection ( {
	host: 'localhost',
	user: 'root',
	password: 'palak',
	database: 'files'
} );
connection.connect ();

app.get ('/', function (req, res) {
	res.redirect("home");
} );

app.get ("/home", function (req, res, next) {
	res.sendfile ("home.html", {root: "./views/"} );
} );

app.get ("/inputQuery", function (req, res) {
	connection.query ('select * from file', function (err, rows, fs) {
		if (err) {
			console.log ('Something is broken');
			console.log (err);
			console.log (fs);
		}
		res.json (rows);
	} );
} );

app.listen (config.SERVER_PORT);
console.log ("Mysql server up and running at --> " + config.SERVER_PORT);
