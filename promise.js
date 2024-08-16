// setTimeout(() => {
//   console.log("hey");
//   setTimeout(() => {
//     console.log("sucess");
//     setTimeout(() => {
//         console.log("chetan");
//         setTimeout(() => {
//             console.log("");
//           }, 5000);
//       }, 5000);
//   }, 5000);
// }, 5000);

let promise = new Promise((resolve,reject)=>{
    setTimeout(()=>{
        resolve("food");
        console.log("paras");
    },5000);
});
promise.then((value)=>{
    setTimeout(()=>{
        console.log("success",value);
    },5000);
}).then(()=>{
    setTimeout(()=>{
        console.log("chetan");
    },5000);
}).then(()=>{
    setTimeout(()=>{
        console.log("success");
    },5000);
})
console.log("sync code");