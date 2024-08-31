let btn = document.querySelector("#btn");
let inputbox = document.querySelector("#input-text-box");
let todos = document.querySelector(".list-container");

btn.addEventListener('click', () => {
    if (inputbox.value === "") {
        alert("Enter the task");
    } else {
        createNewTodo();
    }
    inputbox.value = "";
});

inputbox.addEventListener('keydown', function (e) {
    if (e.key === 'Enter') {
        if (inputbox.value === "") {
            alert("Write a task!!!");
        } else {
            createNewTodo();
        }
        inputbox.value = "";
    }
});

function createNewTodo() {
    let todoText = inputbox.value;
    addTask(todoText);
    saveTaskToServer(todoText);
}

function addTask(todoText) {
    let Task = document.createElement('div');
    Task.setAttribute("class", "Todo-content");
    Task.innerHTML = `<div><input type="checkbox" class="checkbox"></input><span>${todoText}</span></div>`;
    todos.prepend(Task);
    addIcons(Task, todoText);
}

function addIcons(Task, todoText) {
    let DEicon = document.createElement('div');
    DEicon.setAttribute("id", "DE-icon");
    Task.appendChild(DEicon);

    let deleteIcon = document.createElement('button');
    deleteIcon.innerHTML = '🗑';
    deleteIcon.setAttribute("id", "cross-button");
    DEicon.appendChild(deleteIcon);

    deleteIcon.addEventListener('click', function () {
        todos.removeChild(Task);
        deleteTaskFromServer(todoText);
    });

    let editBtn = document.createElement('button');
    editBtn.innerHTML = '✎';
    editBtn.setAttribute("id", "edit-button");
    DEicon.appendChild(editBtn);

    editBtn.addEventListener('click', function () {
        let editedTask = prompt("Edit your task", todoText);
        if (editedTask !== '') {
            Task.querySelector('span').textContent = editedTask;
            updateTaskOnServer(todoText, editedTask);
        }
    });

    let checkbox = Task.querySelector('.checkbox');
    let span = Task.querySelector('span');
    checkbox.addEventListener('change', function () {
        if (checkbox.checked) {
            span.style.textDecoration = "line-through";
        } else {
            span.style.textDecoration = "none";
        }
    });
}

function saveTaskToServer(todoText) {
    fetch('/tasks', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ task: todoText }),
    })
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error('Error:', error));
}

function deleteTaskFromServer(todoText) {
    fetch('/tasks', {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ task: todoText }),
    })
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error('Error:', error));
}

function updateTaskOnServer(oldTask, newTask) {
    fetch('/tasks', {
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ oldTask, newTask }),
    })
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error('Error:', error));
}
