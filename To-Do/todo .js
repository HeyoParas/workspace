var inputbox = document.querySelector("#input-text-box");
var list = document.querySelector(".list-container");
var btn = document.querySelector("#btn");
var arr = [];

var counter = 0;

btn.addEventListener("click", function () {
  if (inputbox.value === "") {
    alert("Write a task!!!");
  } else {
    fun();
  }
  inputbox.value = "";
});
inputbox.addEventListener("keydown", function (e) {
  if (e.key === "Enter") {
    if (inputbox.value === "") {
      alert("Write a task!!!");
    } else {
      fun();
    }
    inputbox.value = "";
  }
});

function createTodo(x, y) {
  let task = {
    todos: x,
    id: y,
  };
  return task;
}

function fun() {
  var newelement = document.createElement("div");
  newelement.setAttribute("class", "Todo-content");
  newelement.innerHTML =
    '<div><input type="checkbox" id  ="checkbox"></input>' +
    "<span>" +
    inputbox.value +
    "</span></div>";
  let x = inputbox.value;
  let y = counter;
  counter++;
  let task = createTodo(x, y);
  arr.push(task);
  let str = JSON.stringify(arr);
  localStorage.setItem("todos", str);
  list.prepend(newelement);

  DEicon = document.createElement("div");
  DEicon.setAttribute("id", "DE-icon");
  newelement.appendChild(DEicon);

  deleteIcon = document.createElement("button");
  deleteIcon.innerHTML = "🗑";
  deleteIcon.setAttribute("id", "cross-button");
  DEicon.appendChild(deleteIcon);

  deleteIcon.addEventListener("click", function () {
    list.removeChild(newelement);
  });

  editBtn = document.createElement("button");
  editBtn.innerHTML = "✎";
  editBtn.setAttribute("id", "edit-button");
  DEicon.appendChild(editBtn);

  editBtn.addEventListener("click", function () {});

  let checkbox = newelement.querySelector("#checkbox");
  let span = newelement.querySelector("span");
  checkbox.addEventListener("change", function () {
    if (checkbox.checked) {
      span.style.textDecoration = "line-through";
    } else {
      span.style.textDecoration = "none";
    }
  });
}
