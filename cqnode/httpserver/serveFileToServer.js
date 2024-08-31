const http = require('http');
const fs = require('fs');
const path = require('path');

// Create an HTTP server
const server = http.createServer((req, res) => {
    // Define the file path based on the request URL
    let filePath = '.' + req.url;
    if (filePath === './') filePath = './index.html';
    if(filePath==='./about')filePath = './promise.js';

    // Get the file extension
    const extname = path.extname(filePath);
    
    // Set default content type based on file extension
    let contentType = 'text/html';
    switch (extname) {
        case '.js':
            contentType = 'text/javascript';
            break;
        case '.css':
            contentType = 'text/css';
            break;
        case '.png':
            contentType = 'image/png';
            break;
        case '.jpg':
            contentType = 'image/jpeg';
            break;
        case '.json':
            contentType = 'application/json';
            break;
        case '.pdf':
            contentType = 'application/pdf';
            break;
        default:
            contentType = 'text/html';
            break;
    }

    // Read the file and respond
    fs.readFile(filePath, (err, content) => {
        if (err) {
            res.writeHead(500);
            res.end('Server Error');
        } else {
            res.writeHead(200, { 'Content-Type': contentType });
            res.write(content);
            res.end("bye");
        }
    });
});

// Define the port and start the server
server.listen(3000, '127.0.0.1', () => {
    console.log('Server started at http://127.0.0.1:3000');
});
