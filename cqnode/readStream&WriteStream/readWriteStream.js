const fs = require('fs');

// Create a ReadStream for a file
const readStream = fs.createReadStream('example.txt', 'utf8');

// Event listener for when data is available
readStream.on('data', (chunk) => {
    console.log('Chunk received:', chunk);
});

// Event listener for when the file is completely read
readStream.on('end', () => {
    console.log('File read complete.');
});

// Event listener for errors
readStream.on('error', (err) => {
    console.log('Error:', err);
});
