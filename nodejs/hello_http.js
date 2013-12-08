var http = require('http');

var server = http.createServer(function(req, res) {
	res.writeHead(200);
	res.write('Hello Http');
	res.end('done');
});
server.listen(8080);
