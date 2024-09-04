const express = require("express");
const mongoose = require("mongoose");
const app = express();
const {Schema}=mongoose;
//To connect the mongoDB to VS
mongoose.connect("mongodb://localhost:27017/server-todo")
.then(()=>
{
    console.log("haan ji hogya connect mongoDB");
})
.catch(err=>
{
    console.log("nahi hua connect mongoDB");
})
  
//TO create the schema 
// const todoSchema = new mongoose.Schema({ (or)
const todoSchema = new Schema({
    task : String,
    id : Number,
    isCompleted :{
        type:Boolean,
        default:false
    }
});
 
//To create the model
const todo = mongoose.model("todo",todoSchema);
console.log(todo);


//To create the task
//<<<<<--------new method-------->>>>>>
// const task=todo.create({
//     task:'this is the task 1',
//     id:1,
//     isCompleted:true
// })
// .then(task => {
//     console.log("Task created successfully:", task);
// })
// .catch(err => {
//     console.log("Error creating task:", err);
// })

app.listen(3000,()=>
{
    console.log("server started at 3000 port");
})