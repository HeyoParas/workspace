const express = require("express");
const app = express();

const middleWare = (req, res, next) => {
  if (!req.query.age) {
    res.send("please enter age first");
  } else if (req.query.age < 18) {
    res.send("not adult");
  } else if (req.query.age >= 18) {
    next(); //iska control sidha >>>>>>>>>>>>>>
  }
};
// app.use(middleWare);

//<<<<<<<<<<<idhr ajega agar age 18 se upar hui toh routes use krne dega
app.get("/", (req, res) => {
  res.send("home page");
});
app.get("/user", middleWare, (req, res) => {
  res.send("User page");
});

app.get("/about", (req, res) => {
  res.send("about page");
});

app.get("/contact", middleWare, (req, res) => {
  res.send("contact page");
});

app.listen(3000, () => {
  console.log("server start at 3000");
});
