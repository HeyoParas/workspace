const fs=require('fs');
const filedata=fs.readFileSync('file.txt','utf-8');
console.log(filedata);