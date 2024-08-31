const fn = require("./operation.js");
console.log(fn);

console.log(fn.sub(50,30));
console.log(fn.add(50,30));
console.log(fn.mul(50,30));
console.log(fn.div(50,30));

//we can do destructing also;

const {add,sub,mul,div}=fn;
console.log(add);
console.log(sub);
console.log(mul);
console.log(div);

console.log(sub(50,30));
console.log(add(50,30));
console.log(mul(50,30));
console.log(div(50,30));

