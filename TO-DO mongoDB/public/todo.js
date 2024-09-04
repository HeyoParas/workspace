let btn = document.querySelector("#btn");
let inputbox = document.querySelector("#input-text-box");
let todos = document.querySelector(".list-container");
let taskobj = {};
let arr = [];

btn.addEventListener("click", () => {
  if (inputbox.value.trim() === "" || inputbox.value === null) {
    alert("Enter the task");
  } else {
    createNewTodo();
  }
  inputbox.value = "";
});

inputbox.addEventListener("keydown", function (e) {
  if (e.key === "Enter") {
    if (inputbox.value.trim() === "" || inputbox.value === null) {
      alert("Enter the task");
    } else {
      createNewTodo();
    }
    inputbox.value = "";
  }
});

function createNewTodo() {
  let timestamp = Date.now();
  console.log(timestamp);
  let todoText = inputbox.value;
  var Task = document.createElement("div");
  Task.setAttribute("class", "Todo-content");
  Task.setAttribute("id", String(timestamp));
  Task.innerHTML =
    '<div><input type="checkbox" class="checkbox" onclick="checkmark(this)"></input>' +
    "<span id=" +timestamp +" >" +todoText +"</span></div>";
  todos.prepend(Task);

  let DEicon = document.createElement("div");
  DEicon.setAttribute("class", "DE-icon");
  Task.appendChild(DEicon);

  let deleteIcon = document.createElement("button");
  deleteIcon.innerHTML = "🗑";
  deleteIcon.setAttribute("class", "cross-button");
  deleteIcon.setAttribute("onclick", "deleteTodo(this)");
  DEicon.appendChild(deleteIcon);
  console.log(deleteIcon);

  let editBtn = document.createElement("button");
  editBtn.innerHTML = "✎";
  editBtn.setAttribute("class", "edit-button");
  editBtn.setAttribute("onclick", "editTodo(this)");
  DEicon.appendChild(editBtn);

  taskobj = {
    task: todoText,
    id: timestamp,
    isCompleted: false,
  };

  fetch("/addtask", {
    method: "POST",
    headers: { "content-Type": "application/json" },
    body: JSON.stringify(taskobj),
  })
  .then((response) => {
      response.json();
    })
    .then((data) => {
      console.log("record added:", data);
    })
    .catch((err) => {
      console.log("Error:", err);
    });
}

function deleteTodo(event) {
  let id = event.parentNode.parentNode.id;
  let deleteElement = document.getElementById(id);
  let parentElement = document.querySelector(".list-container");
  parentElement.removeChild(deleteElement);

  fetch("/deletetask", {
    method: "POST",
    headers: { "content-Type": "application/json" },
    body: JSON.stringify({ id: id }),
  })
    .then((response) => response.json())
    .then((data) => {
      console.log("Record deleted:", data);
    })
    .catch((error) => {
      console.log("Error:", error);
    });
}

function editTodo(event) {
  let id = event.parentNode.parentNode.id;
  console.log(id);
  let div = document.getElementById(id);
  console.log(div.firstElementChild.lastElementChild);
  let oldtask = div.firstElementChild.lastElementChild.textContent;
  console.log("here is old taks", oldtask);
  let textBox = div.firstElementChild.lastElementChild;

  let editedTask = prompt("Edit your task");
  console.log("edited task is :", editedTask);
  if (editedTask === null || editedTask.trim() === "") {
    alert("write a task!!");
    textBox.textContent = oldtask;
    taskobj = {
      task: oldtask,
      id: id,
    };
  } else {
    textBox.textContent = editedTask;
    taskobj = {
      task: editedTask,
      id: id,
    };
  }
  // document.querySelector('span').textContent = editedTask;

  fetch("/editTask", {
    method: "POST",
    headers: { "content-Type": "application/json" },
    body: JSON.stringify(taskobj),
  })
    .then((response) => {
      response.json();
    })
    .then((data) => {
      console.log("record edited:", data);
    })
    .catch((err) => {
      console.log("Error:", err);
    });
}

function checkmark(event) {
  console.log("event", event);
  let id = event.parentNode.parentNode.id;
  let span = event.nextElementSibling;
  console.log("span box of the text:", span);
  let status = false;

  if (event.checked) {
    span.style.textDecoration = "line-through";
    console.log("hello");
    status = true;
  }
  if (!event.checked) {
    console.log("world");
    span.style.textDecoration = "none";
    status = false;
  }

  fetch("/isComplete", {
    method: "POST",
    headers: { "content-Type": "application/json" },
    body: JSON.stringify({ id: id, status: status }),
  })
    .then((response) => response.json())
    .then((data) => {
      console.log("Record checked:", data);
    })
    .catch((error) => {
      console.log("Error:", error);
    });
}
