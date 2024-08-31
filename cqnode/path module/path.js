const path = require("path");

// console.log(path);


console.log("directory name : ",__dirname);
console.log("filename name : ",__filename);
console.log("base name : ",path.basename(__dirname));
console.log("extension name : ",path.extname(__filename));
console.log("path parsing : ",path.parse(__filename));
console.log("join : ",path.join(__dirname,"nodejs","path.js"));

