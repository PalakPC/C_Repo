var http = require("http"),
    url = require("url"),
    express = require("express");
    path = require("path"),
    mysql = require("mysql"),
    fs = require("fs")
    port = process.argv[2] || 8888;

var connection = mysql.createConnection({
    host : 'localhost',
    database : 'myfiles',
    user : 'root',
    password: 'fire'
});

//var app = express();

http.createServer(function(request, response) {				     
	var uri = url.parse(request.url).pathname, 
      	    filename = path.join(process.cwd(), uri);
	path.exists(filename, function(exists) {
		if(!exists) {
			response.writeHead("Content-Type", "text/plain");
			response.write("404 Not Found\n");
			response.end();
			return;
		}
		if (fs.statSync(filename).isDirectory()) 
			filename += '/index.html';
		connection.query("select * from my_filenames", function(err, rows){
			if(err!=null){
				response.end("Query error: "+err);
			}
			else{
				var object = rows[1];
				console.log(object);
				//response.writeHead(200, {'content-type': 'application/json'});
				fs.readFile(filename, "binary", function(error, file) {
					if(error) {        
						response.writeHead(500, {"Content-Type": "text/html"});
						response.write(err + "\n");
						response.end();
						return;
					}	
					response.writeHead(200);
					//response.send(JSON.stringify(obj));
					response.write(file, "binary");
					response.end();
				});
			}
		});
	});
}).listen(parseInt(port, 10));
console.log("Static file server running at\n  => http://localhost:" + port + "/\nCTRL + C to shutdown");
