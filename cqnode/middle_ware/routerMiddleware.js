const express = require("express");
const app = express();
const middleWare = require("./middleware");
const route = express.Router();

route.use(middleWare);

app.get("/", (req, res) => {
  res.send("home page");
});
app.get("/user", (req, res) => {
  res.send("User page");
});

route.get("/about", (req, res) => {
  res.send("about page");
});

route.get("/contact", (req, res) => {
  res.send("contact page");
});


app.use('/',route);

app.listen(3000, () => {
  console.log("server start at 3000");
});
