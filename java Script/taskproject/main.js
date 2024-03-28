const test=require('./projectoperations.js')
test.add(0,"complete");
test.add(1,"complete");
console.log("after adding:");
test.display();
test.del(2);
console.log("after delete:");
test.display();
test.update(1,"revised");
console.log("after update:");
test.display();