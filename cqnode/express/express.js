const express=require("express");
const file = require("./MOCK_DATA.json");

// console.log(express);
const app=express();
app.get('/',(req,res)=>
{
    res.send("homepage");
});
app.get('/about',(req,res)=>
{
    res.send("aboutpage");
});
app.get('/help',(req,res)=>
{
    res.send("helppage");
});
app.get('/search/:id',(req,res)=>
{
    let id=Number(req.params.id);
    let Data = file.find((index)=>index.id===id);
    console.log(Data);
    res.send(Data);
});

app.post('/help',(req,res)=>
{
    res.send("submit");
});
app.listen(3000,()=>console.log("server start at 3000"));
