let userName = document.querySelector("#userName");
let email = document.querySelector("#email");
let password = document.querySelector("#password");
let signUpBtn = document.querySelector("#signUp");
let obj={};
signUpBtn.addEventListener("click",()=>
{
    if(userName.value=="" && email.value=="" && password.value=="")
    {
        alert("Enter all Fields");
    }
    else if(userName.value.trim()=="" && email.value.trim()=="" && password.value.trim()=="")
    {
        alert("Enter all Fields");
    }
    else
    {
        sendCredentials();
    }
});

function sendCredentials()
{
    let userName=userName.value;
    let email=email.value;
    let password=password.value;

    let obj = {
        userName:userName,
        email:email,
        password:password
    }
    console.log("data :",obj)
    console.log("hiiii");

    fetch("/send",{
        method:"POST",
        headers:{"content-Type":"application/json"},
        body:JSON.stringy({obj}),
    })
    .then((response)=>{
        response.json();
    })
    .then((data) => {
        console.log("Data send :", data);
    })
    .catch((err) => {
        console.log("Error:", err);
    });
}


// function functionA() {

//     fetch("/signUp")
//       .then((response) => {
//         response.json();
//         console.log("hi");
//       })
//       .catch((err) => {
//         console.log("Error:", err);
//       });

//   }