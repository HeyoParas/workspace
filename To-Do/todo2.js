var btn = document.getElementById("changeButton");
var input = document.getElementById("ip");
var parent = document.getElementById("parent");

var todos = readTodosFromStroage();
todos.forEach(function (todo) {
  displayTodoOnUI(todo);
});
btn.addEventListener("click", function () {
  var value = input.value;
  createTodo(value);
  input.value = "";
});
input.addEventListener("keyup", function (event) {
  if (event.key === "Enter") {
    var value = input.value;
    createTodo(value);
    event.target.value = "";
  }
});
function createTodo(value) {
  displayTodoOnUI(value);
  storeDataInStorage(value);
}
function displayTodoOnUI(value) {
  var p = document.createElement("h2");
  p.innerText = value;
  parent.appendChild(p);
}
function storeDataInStorage(value) {
  value = replaceDot(value);
  var oldData = localStorage.getItem("todo");
  if (oldData) {
    oldData = oldData + "." + value;
  } else {
    oldData = value;
  }

  localStorage.setItem("todo", oldData);
}

function replaceDot(value) {
  return value.replaceAll(".", "@#");
}
function readTodosFromStroage() {
  var todosString = localStorage.getItem("todo") || "";
  var todos = todosString.split(".");
  return todos.map(function (todo) {
    return todo.replaceAll("@#", ".");
  });
}
