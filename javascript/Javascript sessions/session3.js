const fs=require('fs');
const filedata=fs.readFileSync('./javascript/javascript sessions/hello.txt','utf-8');
console.log(filedata);