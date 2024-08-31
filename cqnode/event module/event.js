const Event = require('events');

// class MyEmitter extends EventEmitter {}

// const myEmitter = new MyEmitter();
const myEmitter = new Event();

myEmitter.on('hello', () => {
  console.log('An event occurred!');
});

myEmitter.emit('hello');
