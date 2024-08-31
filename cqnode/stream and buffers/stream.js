const fs = require('fs');

const readableStream = fs.createReadStream('temp.txt', 'utf8');

readableStream.on('data', (chunk) => {
  console.log('New chunk received:', chunk);
});

readableStream.on('end', () => {
  console.log('No more data in stream.');
});
