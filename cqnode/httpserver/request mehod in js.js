const http = require('http');


const server = http.createServer((req, res) => {
    // 1. Get HTTP method
    console.log('HTTP Method:', req.method);

    // 2. Get URL
    console.log('URL:', req.url);

    // // 3. Get headers
    // console.log('Headers:', req.headers);

    // // 4. Get a specific header
    // const userAgent = req.headers['user-agent'];
    // console.log('User-Agent:', userAgent);

    // // 5. Set encoding for request data
    // req.setEncoding('utf8');

    // // 6. Handle data event
    // req.on('data', (chunk) => {
    //     console.log('Data received:', chunk);
    // });

    // // 7. Handle end event
    // req.on('end', () => {
    //     console.log('Request has been fully received.');

    //     // Sending a simple response
    //     res.statusCode = 200;
    //     res.setHeader('Content-Type', 'text/plain');
    //     res.end('Request processed\n');
    // });

    // 8. Pipe request to a writable stream (optional)
    // req.pipe(destinationStream);
});

server.listen(3000, '127.0.0.1', () => {
    console.log('Server running at http://127.0.0.1:3000/');
});
