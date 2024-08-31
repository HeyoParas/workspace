const os = require("os");
console.log("architecture : ",os.arch());
console.log(`free memory : ${os.freemem()/1024/1024/1024}`);
console.log(`total memory : ${os.totalmem()/1024/1024/1024}`);
console.log(`os platform : ${os.platform}`);
console.log(`os hostname : ${os.hostname}`);
console.log(`os type : ${os.type}`);
