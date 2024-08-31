const http = require('http');
const url = require('url');

// Ek HTTP server create karein
const server = http.createServer((req, res) => {
    // URL ko parse karein aur query parameters ko nikalein
    const parsedUrl = url.parse(req.url, true);
    const pathname = parsedUrl.pathname;
    const query = parsedUrl.query;

    console.log('HTTP Method:', req.method);
    console.log(req.url);
    console.log('URL Pathname:', pathname);
    console.log('Query Parameters:', query);

    // Different request URLs handle karein
    if (pathname === '/') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end("Welcome to the home page");
    } else if (pathname === '/about') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end("Welcome to the about page");
    } else if (pathname === '/contact') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end("Welcome to the contact page");
    } else if (pathname === '/search') {
        const searchTerm = query.term || 'not provided';
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end(`Search results for: ${searchTerm}`);
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end("Not found");
    }
});

// Port define karein aur server start karein
server.listen(3000, '127.0.0.1', () => {
    console.log('Server started at http://127.0.0.1:3000');
});
