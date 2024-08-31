const fs=require('fs');
// console.log(fs);

//all asynchronous methods always takes the callback function as the third ARGUEMENT;

//synchronously write in a file
fs.writeFileSync("./temp.txt","hello there this is a file created synchronously");

//asynchronously write in a file
fs.writeFile("./temp1.txt","hello there this is a file created asynchronously",(err)=>{});

//synchronously read from a file
//when we use synchronously read file method it will give you the result in the variable
const result=fs.readFileSync("./promise.js","utf-8");
console.log(result);

//asynchronously read from a file
fs.readFile("./promise.js","utf-8",(error,result)=>
{
    if(error)
    {
        console.log("error",error);
    }
    else
    {
        console.log(result);
    }
})

//synchronously append in a file
fs.appendFileSync("./temp.txt","\nnew line appended");


//asynchronously append in a file
fs.appendFile("./temp1.txt","\nnew line appended",(err)=>{});

//synchronsously copy a file
fs.cpSync("./temp.txt","./copy.txt");

//asynchronsously copy a file
fs.cp("./temp1.txt","./copy1.txt",(err)=>{
    if(err)
    {
        console.log("error",err);
    }
});

//synchronously delete a file
fs.unlinkSync("copy.txt");

//synchronously create a folder
fs.mkdirSync("./new-temp");
