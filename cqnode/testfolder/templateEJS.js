const express = require("express");
const ejsFIle = require("ejs");
const url = require("url");
const app = express();

app.set("view engine", "ejs");

//middleware

app.use((req, res, next) => {
  const myUrl = url.parse(req.url, true);
  const path = myUrl.pathname;
  console.log(path);
  if (req.url === "/") {
    res.send("Please enter name in parameter");
  } else if (path === "/about" && req.query.name) {
    next();
  }
});

app.get("/about", (req, res) => {
  const name = req.query.name;
  console.log(name);
  res.render("temp", { name: name });
});

app.listen(3000, () => {
  console.log("my server running on port 3000");
});
