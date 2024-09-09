const express = require("express");
const ejsmodule = require("ejs");
const path = require("path");
const mongoose = require("mongoose");
const { v4: uuidv4 } = require("uuid");
const { Schema } = mongoose;

mongoose
  .connect("mongodb://localhost:27017/signupUser")
  .then(() => {
    console.log("mongoose connected  successfully ");
  })
  .catch((err) => {
    console.log("cannot connected");
  });
const userSchema = new Schema({
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
  sessionId: {
    type: String,
    required: true,
  },
});
const users = mongoose.model("users", userSchema);
console.log(users);

const app = express();
const cookieParser = require("cookie-parser");

// const signupUser = [];

//set ejs files
app.set("view engine", "ejs");

//set path for serving static files at client side
const filepath = path.join(__dirname, "public");
console.log("filepath :", filepath);

//using static files at client side
app.use(express.static(filepath));

//middleWares
app.use(cookieParser());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
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
  const uniqueId = uuidv4();

  // const userobj = {
  //   username: username,
  //   email: email,
  //   password: password,
  //   sessionId:uniqueId,
  // };
  // signupUser.push(userobj);

  let usersArray = await users.find() || [];

  let user = usersArray.find(user => (user.username == username && user.email == email));

  if(!user){
    let newUser = await users.create({
      username: username,
      email: email,
      password: password,
      sessionId:uniqueId
    });
    console.log("new user:",newUser);

    await newUser.save();
  }
  else return res.render("signUp", { message: "Account Already Exists" });
  
  return res.render("login");

});

app.post("/welcome", async (req, res) => {
  console.log("request.body :", req.body);
  const { username, password } = req.body;
  console.log("name,pass :", username, password);
  //agar kisi ne bina sign up kie starting m login kr lia but DB mein data hi nhi tha toh 
  let test = await users.find();
  console.log("test array :",test)
  if (test.length==0) {
    console.log("hii");
    return res.render("signUp", { message: "SignUp First" });
  }

  let sessionId;
  let x = await users.findOne({username:username,password:password});
  console.log("x: ",x);
  if(x)
  {
  sessionId = x.sessionId;
  console.log("session id :", sessionId);
  }

  if (test.length>0) {

    let x = await users.findOne({ username: username, password: password });
    if (x) {
      console.log("login successfully");
      res.cookie("sessionId", sessionId,{ maxAge: 30000, httpOnly: true });
      return res.render("welcome", { name: username });
    }

    let y = await users.findOne({
      username: username,
      password: { $ne: password },
    });
    if (y) {
      return res.render("login", { message2: "Invalid password" });
    }

    let z = await users.find({
      $or: [
        { $and: [{ username: { $ne: username } }, { password: password }] },
        {
          $and: [
            { username: { $ne: username } },
            { password: { $ne: password } },
          ],
        },
      ],
    });
    if (z) {
      console.log("hiiiiiiiii");
      return res.render("login", {
        message1: "Invalid Username",
        message2: "Invalid Password",
      });
    }
  }
});

app.get("/welcome", async (req, res) => {
  let id = req.cookies.sessionId;
  if(!id)
  {
    res.render("signUp",{message:null})
  }
  console.log("this is the cookie come with the welcome get request : ", id);
  let username;
  let x = await users.findOne({ sessionId: id });
  if (x) {
    username = x.username;
    console.log("this: ", x.username);
  }

  console.log("username :", username);

  res.render("welcome", { name: username });
});

app.listen(3000, () => console.log("server start running at port 3000"));
