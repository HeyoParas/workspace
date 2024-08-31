const http = require('http');
const url = require('url');

// Create an HTTP server
const server = http.createServer((req, res) => {
    // Parse the URL and extract query parameters
    const parsedUrl = url.parse(req.url, true);
    const query = parsedUrl.query;

    console.log('URL:', req.url);
    console.log('Query Parameters:', query);

    // Handle the request based on the URL path
    if (parsedUrl.pathname === '/search') {
        const searchTerm = query.term || 'not provided';
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end(`You searched for: ${searchTerm}`);
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Page not found');
    }
});

// Define the port and start the server
server.listen(3000, '127.0.0.1', () => {
    console.log('Server started at http://127.0.0.1:3000');
});
