const express = require("express");
const ejsmodule = require("ejs");
const path = require("path");
const { v4: uuidv4 } = require("uuid");

const app = express();
const cookieParser = require("cookie-parser");

const users = [];

//middleWares
app.use(cookieParser());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use((req, res, next) => {
  console.log("request.method :", req.method);
  console.log("request.url :", req.url);
  next();
});
const mid = (req, res, next) => {
  console.log("login form data:", req.body);
  console.log("Cookies: ", req.cookies);
  next();
};
// const signUpMiddleWare = (req, res, next) => {
//   if (!req.body) {
//     next();
//   }
//   if (users[0]) {
//       for (let i = 0; i < users.length; i++) {
//         res.render("login", { message: "Already Sign Up, Please login in!!" });
//         res.end();
//       }
//   } else next();
// };

//set ejs files
app.set("view engine", "ejs");

//set path for serving static files at client side
const filepath = path.join(__dirname, "public");
console.log("filepath :", filepath);

//using static files at client side
app.use(express.static(filepath));  

app.get("/", (req, res) => {
  res.render("signUp");
});
app.post("/login", (req, res) => {
  console.log(req.body);
  console.log(users);

  const { username, email, password } = req.body;
  console.log("heres the data come from  form:", req.body);

  // if (users[0]) {
  //   for (let i = 0; i < users.length; i++) {
  //     if (users[i].password != password && users[i].username != username) {
  //       return res.render("login", {
  //         message: "Wrong Username or Password, Retry!",
  //       });
  //     }
  //   }
  // }

  // if user exists then create the session id
  const sessionId = uuidv4();

  res.cookie("sessionId", sessionId);
  res.render("welcome", { name: username });
});

app.get("/signUp", (req, res) => {
  console.log("hiiii");
  res.render("signUp");
});
app.post("/signUp", (req, res) => {
  console.log("sign up data" + req.body);
  const { username, email, password } = req.body;
  console.log(username);
  const newUser = {
    username: username,
    email: email,
    password: password,
  };

  users.push(newUser);
  res.render("login");
});

app.get("/login", (req, res) => {
  console.log("hui");
  res.clearCookie("sessionId");
  res.render("login");
});

app.listen(3000, () => console.log("server start running at port 3000"));
