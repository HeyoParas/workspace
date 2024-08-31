const express = require("express");
const path = require("path");

const app = express();

const folderPath = path.join(__dirname,"public");
console.log("folder path :",path.join(__dirname,"public"));


app.use(express.static(folderPath));

app.get('/',(req,res)=>
{
    res.send("welcome page");
})
app.get('/about',(req,res)=>
    {
    res.send("you are on about page");
})
app.get('/help',(req,res)=>
{
    res.send("you are on help page");
})

app.listen(3000,()=>
{
    console.log("server start at port 3000");
})