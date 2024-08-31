const http = require("http");
const fs = require("fs");
const express = require('express');
const app = express();

app.use((req, res, next) => {
    const currentTime = new Date();
    const ipAddress = req.ip; 
    const requestMethod = req.method; 
    const requestPath = req.url; 

    console.log(currentTime);
    console.log(ipAddress);
    console.log(requestMethod);
    console.log(requestPath);

    const data = `Time: ${currentTime}, IP Address: ${ipAddress}, Method: ${requestMethod}, Path: ${requestPath}\n`;

    console.log(data);

    fs.appendFile("temp.txt", data, (err) => {
        if (err) {
            console.error('Failed to write to log file:', err);
        }
    });

    next();
});
app.get('/', (req, res) => {
    res.send('Hello');
});

app.listen(3000, () => {
    console.log('Server is running 3000');
});
