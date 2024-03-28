let addTask = require('./addTask.js');
let displayTask = require('./displayTask.js');
let updateTask = require('./updateTask.js');
let deleteTask = require('./deleteTask.js');

let taskArr = new Array;
addTask(taskArr,"task1");
addTask(taskArr,"task2");
displayTask(taskArr);
deleteTask(taskArr);
displayTask(taskArr);
// console.log(taskArr[0]);
