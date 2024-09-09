const express = require("express");
const ejsmodule = require("ejs");
const path = require("path");
const { v4: uuidv4 } = require("uuid");

const app = express();
const cookieParser = require("cookie-parser");

const signupUser = [];

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

app.get("/", (req, res) => {
  res.render("signUp");
});

app.get("/login", (req, res) => {
  res.render("login");
});
app.get("/SignUp", (req, res) => {
  res.render("SignUp");
});

app.post("/login", (req, res) => {
  const { username, email, password } = req.body;
  const uniqueId = uuidv4();
  
  const userobj = {
    username: username,
    email: email,
    password: password,
    sessionId:uniqueId,
  };
  signupUser.push(userobj);
  
  
  console.log("Sign up user array :", signupUser);
  
  if (signupUser.length === 0) {
    return res.redirect("signUp", { message: "SignUp First" });
  }
  if (signupUser.length > 0) {
    res.render("login");
  }
});

app.post("/welcome", (req, res) => {
  
  console.log("request.body :", req.body);
  const { username, password } = req.body;
  console.log("name,pass :", username, password);

  if (signupUser.length === 0) {
    return res.render("signUp", { message: "SignUp First" });
  }
  let sessionId
  for(let i=0;i<signupUser.length;i++)
  {
    if(signupUser[i].username==username)
    {
      sessionId=signupUser[i].sessionId;
      break;
    }
  }

  if (signupUser.length > 0) {
    for (let i = 0; i < signupUser.length; i++) {
      if (
        signupUser[i].username == username &&
        signupUser[i].password == password
      ) {
        console.log("login successfully");
        res.cookie("sessionId",sessionId,{ maxAge: 900000, httpOnly: true });
        return res.render("welcome", { name: username });
      }
    }

    for (let i = 0; i < signupUser.length; i++) {
      if (
        signupUser[i].username == username &&
        signupUser[i].password != password
      ) {
        return res.render("login", { message2: "Invalid password" });
      }
    }

    for (let i = 0; i < signupUser.length; i++) {
      if (
        (signupUser[i].username != username &&
          signupUser[i].password == password) ||
        (signupUser[i].username != username &&
          signupUser[i].password != password)
      ) {
        console.log("hiiiiiiiii");
        return res.render("login", {
          message1: "Invalid Username",
          message2: "Invalid Password",
        });
      }
    }
  }
});

app.get("/welcome",(req,res)=>{

   let id = req.cookies.sessionId;
   console.log("this is the cookie come with the welcome get request : ",id);
   let username;
   for(let i=0;i<signupUser.length;i++)
   {
      if(signupUser[i].sessionId == id)
      {
          username=signupUser[i].username;
          console.log("this: ",signupUser[i].username);
          break;
      }
   }
   console.log("username :",username);
  
  res.render("welcome",{name:username});
})

app.listen(3000, () => console.log("server start running at port 3000"));
