
let btn = document.querySelector("#btn");
let inputbox = document.querySelector("#input-text-box");
let todos = document.querySelector(".list-container");

window.addEventListener('load', loadTasksFromLocalStorage);

btn.addEventListener('click', () => {
    if (inputbox.value === "") {
        alert("Enter the task");
    } else {
        createNewTodo();
    }
    inputbox.value = "";
})

inputbox.addEventListener('keydown', function (e) {
    if (e.key === 'Enter') {
        if (inputbox.value === "") {
            alert("Write a task!!!");
        } else {
            createNewTodo();
        }
        inputbox.value = "";
    }
})

function createNewTodo() {
    let todoText = inputbox.value;
    addTask(todoText);
    saveTaskToLocalStorage(todoText);
}

function addTask(todoText) {
    var Task = document.createElement('div');
    Task.setAttribute("class", "Todo-content");
    Task.innerHTML = '<div><input type="checkbox" class="checkbox"></input>' + '<span>' + todoText + '</span></div>';
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
        removeTaskFromLocalStorage(todoText);
    });

    let editBtn = document.createElement('button');
    editBtn.innerHTML = '✎';
    editBtn.setAttribute("id", "edit-button");
    DEicon.appendChild(editBtn);

    editBtn.addEventListener('click', function () {
        let editedTask = prompt("Edit your task", todoText);
        if (editedTask !== null && editedTask !== '') {
            Task.querySelector('span').textContent = editedTask;
            updateTaskInLocalStorage(todoText, editedTask);
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

function saveTaskToLocalStorage(todoText) {
    let tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.push(todoText);
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

function loadTasksFromLocalStorage() {
    let tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.forEach(todoText => {
        addTask(todoText);
    });
}

function removeTaskFromLocalStorage(todoText) {
    let tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks = tasks.filter(task => task !== todoText);
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

function updateTaskInLocalStorage(oldTask, newTask) {
    let tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    let taskIndex = tasks.indexOf(oldTask);
    if (taskIndex !== -1) {
        tasks[taskIndex] = newTask;
    }
    localStorage.setItem('tasks', JSON.stringify(tasks));
}



