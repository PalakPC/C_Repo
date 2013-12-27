var http = require('http');
var mysql = require('mysql');
var fs =  require('fs');
// Create a connection to MySql Server and Database
var connection = mysql.createConnection({
	host : 'localhost',
	database: 'myfiles',
	user : 'root',
	password : 'fire'
});
//var connection;
// Create a simple Web Server to respond to requests
http.createServer(function(req, res){
	// RECEIVED A REQUEST!
	// for this example respond with a HTTP 200 OK
	res.writeHeader(200);
	res.write('Connect to mySql\n');
	// Connect to mySql (if there is an erro, report it and terminate de request)
	//connection=mysql.createConnection(dbconfig);
	//connection.connect(function(err){
	//if(err != null) {
		//res.end('Error connecting to mysql:' + err+'\n');
	//}
//});
	// Query the database to some data 
	connection.query("SELECT * from my_filenames", function(err, rows){
		// There was a error or not?
		if(err != null) {
			res.end("Query error:" + err);
		} 
		else {
			// Shows the result on console window
			res.writeHead(200, {'Content-Type':'text/html'});
			for (var i=0; i<rows.length; ++i)
			{
				console.log(rows[i]);
				//res.write(JSON.stringify(rows[i]));
			}
			//res.end();
			//res.write("<html><body><b>yo people</b></body></html>");
			//console.log(JSON.stringify(html));
			fs.readFile('index.html', function(err, html){
				//if(err){	
					//throw err;
				//}
				res.write(html);
			//});			
			//}
			// Close connection
			//connection.end();
			});
		}	
		// The server will be listen on port 8080 
	});
}).listen(3000);
