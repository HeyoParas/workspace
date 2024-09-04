const express = require("express");
const ejsFile = require("ejs");
const path = require("path");
const mongoose=require("mongoose");
const app = express();
const {Schema}=mongoose;

const filepath = path.join(__dirname, "public");

mongoose.connect("mongodb://localhost:27017/server-todo")
.then(()=>
{
  console.log("mongoose connected to localhost:27017/server-todo successfully ");
})
.catch(err=>
{
  console.log("cannot connected");
})

const TodoSchema = new Schema(
  {
    task: String,
    id:Number,
    isCompleted:{ type: Boolean, default:false},
  })

  const todos = mongoose.model("todos",TodoSchema);
  console.log(todos);

app.use((req, res, next) => {
  console.log(req.method, req.url);
  next();
});

app.use(express.json());
console.log(filepath);
app.use(express.static(filepath));

app.set("view engine", "ejs");

app.get("/", async (req, res) => {
 try{
    let data = await todos.find({}).sort({ _id: -1 });;
    console.log(data);
    res.render("todohtml", { tasks: data });
 }
 catch(err){
  console.log("error occured",err);
 }
});

app.post("/addtask", async (req, res) => {
  let newTask = req.body;
  console.log("new task :",newTask);
  let task=newTask.task;
  let id=newTask.id;
  let isCompleted=newTask.isCompleted;
  console.log(task,id,isCompleted);

  try {
    let x = await todos.insertMany({task:task,id:id,isCompleted:isCompleted});
    if (x) {
      res.json({ success: true, message: "Task added successfully" });
    } else {
      res.json({ success: false, message: "Task not added" });
    }
  } catch (error) {
    console.error("Error in adding task:", error);
    res.status(500).json({ success: false, message: "Error adding task" });
  }
});

app.post("/deletetask", async (req, res) => {
  const deleteID = req.body.id;
  console.log(deleteID);

  
  try {
      let x = await todos.deleteOne({id:deleteID});
    if (x) {
      res.json({ success: true, message: "Task delete successfully" });
    } else {
      res.json({ success: false, message: "Task not delete" });
    }
  } catch (error) {
    console.error("Error in delete task:", error);
    res.status(500).json({ success: false, message: "Error delete task" });
  }

});

app.post("/editTask", async (req, res) => {
  let id = req.body.id;
  console.log("edited task id :", id);
  let editedTask = req.body.task;

  try {
    let x = await todos.updateOne({id:id},{$set:{task:editedTask}})
    if (x) {
      res.json({ success: true, message: "Task edit successfully" });
    } else {
      res.json({ success: false, message: "Task not edit" });
    }
  } catch (error) {
    console.error("Error in edit task:", error);
    res.status(500).json({ success: false, message: "Error edit task" });
  }
});

app.post("/isComplete", async (req, res) => {
  console.log(req.body);
  const status = req.body.status;
  console.log("status is :", status);
  const id = req.body.id;

  try {
    let x = await todos.updateOne({id:id},{$set:{isCompleted:status}})
    if (x) {
      res.json({ success: true, message: "Task checked successfully" });
    } else {
      res.json({ success: false, message: "Task not checked" });
    }
  } catch (error) {
    console.error("Error in checked task:", error);
    res.status(500).json({ success: false, message: "Error checked task" });
  }
});

app.listen(3000, () => {
  console.log("start running server at 3000");
});
