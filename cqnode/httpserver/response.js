const http = require('http');

// Create an HTTP server
const server = http.createServer((req, res) => {
    console.log('HTTP Method:', req.method);
    console.log('URL:', req.url);

    // Handle different request URLs
    if (req.url === '/') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end("Welcome to the home page");
    } else if (req.url === '/about') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end("Welcome to the about page");
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end("Not found");
    }
});

// Define the port and start the server
server.listen(3000, '127.0.0.1', () => {
    console.log('Server started at http://127.0.0.1:3000');
});
