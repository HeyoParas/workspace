var input = document.querySelector("#input-text-box");
var btn = document.querySelector("#btn");
var todos = document.querySelector(".list-container");
var Delete = document.querySelector("#span");
var newtask = document.createElement("div");


btn.addEventListener("click", () => {
  if (input.value === "") {
    alert("enter the task!!!");
  } else {
    console.log("button press");
    newtask.innerHTML =
      '<input type="checkbox" id="checkbox"></input>' +
      " " +
      input.value +
      '<span id="span">❌</span>';
    console.log(newtask);
    todos.appendChild(newtask);

    let deleteTask = document.querySelector("span");
    deleteTask.addEventListener("click", () => {
      todos.removeChild(newtask);
    });

    var check = document.querySelector("#checkbox");
    check.addEventListener("change", function () {
      if (check.checked) {
        console.log("press checked");
        newtask.style.textDecoration = "line-through";
        Delete.style.textDecoration="none";
      } else {
        newtask.style.textDecoration = "none";
      }
    });
  }
  input.value = "";
});
