const express = require("express");
const ejsFile = require("ejs");
const fs = require("fs");
const path = require("path");
const app = express();

const filepath = path.join(__dirname, "public");

app.use((req, res, next) => {
  console.log(req.method, req.url);
  next();
});

app.use(express.json());
console.log(filepath);
app.use(express.static(filepath));

app.set("view engine", "ejs");

app.get("/", (req, res) => {
  fs.readFile("task.json", "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return;
    }
    if (data) {
      data = JSON.parse(data);
      
    } else {
      data = [];
    }
    res.render("todohtml", { tasks: data });
  });
});

app.post("/addtask", (req, res) => {
  let newTask = req.body;
  console.log(newTask);
  fs.readFile("task.json", "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return;
    } else {
      if (!data) {
        data = "[]";
      }
      data = JSON.parse(data);
      data.unshift(newTask);
    }

    fs.writeFile("task.json", JSON.stringify(data), (err, data) => {
      if (err) {
        console.error(err);
        return;
      }
    });
});
res.json({success: true});
});

app.post("/deletetask", (req, res) => {
  const deleteID = req.body.id;
  console.log(deleteID);
  fs.readFile("task.json", "utf8", (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    let records = JSON.parse(data);
    console.log(records);
    records = records.filter((record) => record.id != deleteID);
    console.log(records);
    fs.writeFile("task.json", JSON.stringify(records), (err) => {
      if (err) {
        return console.log(err);
      }
    });
  });
  res.json({success: true});
});

app.post("/editTask", (req, res) => {
  let id = req.body.id;
  console.log("edited task id :", id);
  let editedTask = req.body.task;

  fs.readFile("task.json", "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return;
    } else {
      data = JSON.parse(data);
      data = data.filter((record) => {
        if (record.id == id) {
          record.task = editedTask;
        }
        return record;
      });
      console.log(data);
      fs.writeFile("task.json", JSON.stringify(data), (err, data) => {
        if (err) {
          console.error(err);
          return;
        }
      });
    }
  });
  res.json({ success: true });
});

app.post("/isComplete", (req, res) => {
  console.log(req.body);
  const status = req.body.status;
  console.log("status is :", status);
  const id = req.body.id;
  fs.readFile("task.json", "utf8", (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    let records = JSON.parse(data);
    console.log(records);
    records = records.map((record) => {
      if (record.id != id) {
        return record;
      } else {
        record.isCompleted = status;
        return record;
      }
    });
    console.log(records);
    fs.writeFile("task.json", JSON.stringify(records), (err) => {
      if (err) {
        return console.log(err);
      }
    });
  });
    res.json({ success: true });
});

app.listen(3000, () => {
  console.log("start running server at 3000");
});
