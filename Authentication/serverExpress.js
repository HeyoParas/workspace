const express = require("express");
const ejsmodule = require("ejs");
const path = require("path");
const mongoose = require("mongoose");
const session = require("express-session");

mongoose
  .connect("mongodb://localhost:27017/ExpressSession")
  .then(() => {
    console.log("mongoose connected successfully ");
  })
  .catch((err) => {
    console.log("cannot connect");
  });

const userSchema = new mongoose.Schema({
  username: {
    type: String,
    required: true,
    unique: true,
  },
  email: {
    type: String,
    required: true,
    unique: true,
  },
  password: {
    type: String,
    required: true,
  },
});

const users = mongoose.model("users", userSchema);
console.log(users);

const app = express();
const cookieParser = require("cookie-parser");

// Set ejs files
app.set("view engine", "ejs");

// Set path for serving static files at client side
const filepath = path.join(__dirname, "public");
console.log("filepath :", filepath);

// Use static files at client side
app.use(express.static(filepath));

// Middlewares
app.use(cookieParser());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Configure express-session
app.use(
  session({
    secret: "mysecretkey", // This should be a secret key to sign the session ID cookie
    resave: false,
    saveUninitialized: false,
    cookie: { maxAge: 100000*30, httpOnly: true }, // Adjust maxAge as needed
  })
);

app.use((req, res, next) => {
  console.log("request.method :", req.method);
  console.log("request.url :", req.url);
  next();
});

app.get("/", async (req, res) => {
  res.render("signUp");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.get("/SignUp", (req, res) => {
  res.render("SignUp");
});

app.post("/login", async (req, res) => {
  const { username, email, password } = req.body;

  let user = await users.findOne({ username: username, email: email });

  if (!user) {
    let newUser = await users.create({
      username: username,
      email: email,
      password: password,
    });
    console.log("new user:", newUser);

    await newUser.save();
  } else {
    return res.render("signUp", { message: "Account Already Exists" });
  }

  return res.render("login");
});

app.post("/welcome", async (req, res) => {
  const { username, password } = req.body;
  console.log("name,pass :", username, password);

  let user = await users.findOne({ username: username, password: password });

  if (user) {
    console.log("login successfully");

    req.session.username = user.username;

    return res.render("welcome", { name: username });
  } else {
    let userByUsername = await users.findOne({ username: username });
    if (userByUsername) {
      return res.render("login", { message2: "Invalid password" });
    } else {
      return res.render("login", {
        message1: "Invalid Username",
        message2: "Invalid Password",
      });
    }
  }
});

app.get("/welcome", async (req, res) => {
  // Check if username exists in session
  if (!req.session.username) {
    return res.render("signUp", { message: "Please Sign Up or Login" });
  }

  // Retrieve the last logged-in user from the session
  let username = req.session.username;
  console.log("Last logged-in user:", username);

  return res.render("welcome", { name: username });
});

app.listen(3000, () => console.log("server start running at port 3000"));
