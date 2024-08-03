let btn=document.querySelector("#btn");
let inputbox=document.querySelector("#input-text-box");
let todos=document.querySelector(".list-container");
var arr= [];

var counter=0;

btn.addEventListener('click',()=>{

    if(inputbox.value==="")
    {
        alert("enter the task");
    }
    else
    {
        createNewTodo();
        TaskDone();
    }
    inputbox.value="";
})

inputbox.addEventListener('keydown', function(e) {
    if (e.key === 'Enter') {
        if(inputbox.value==="" )
            {
                alert("Write a task!!!");
            }
            else{
                createNewTodo();
                TaskDone();
            }
            inputbox.value="";
    }
})

function createTodo(x,y){
    let task={
        todos:x,
        id:y
    }
    return task;
}

function createNewTodo()
{
    var Task = document.createElement('div');
    Task.setAttribute("class","Todo-content");
    Task.innerHTML = '<div><input type="checkbox" id  ="checkbox"></input>'+'<span>'+ inputbox.value +'</span></div>';
    todos.prepend(Task);
    deleteTodo(Task);
    TaskDone();
}

function renameTodo(editedTask)
{

    let UpdatedTask=editedTask;
    var Task = document.createElement('div');
    Task.setAttribute("class","Todo-content");
    Task.innerHTML = '<div><input type="checkbox" id  ="checkbox"></input>'+'<span>'+ UpdatedTask+'</span></div>';
    todos.prepend(Task);
    deleteTodo(Task);
    return Task;
}

function deleteTodo(Task)
{
    let DEicon=document.createElement('div');
    DEicon.setAttribute("id","DE-icon");
    Task.appendChild(DEicon);

    let deleteIcon = document.createElement('button');
    deleteIcon.innerHTML = '🗑'; 
    deleteIcon.setAttribute("id","cross-button");
    DEicon.appendChild(deleteIcon);

    deleteIcon.addEventListener('click', function() {
        todos.removeChild(Task);
    });

    EditTask(DEicon,Task)
}

function EditTask(DEicon,oldtask)
{
    editBtn = document.createElement('button');
    editBtn.innerHTML = '✎'; 
    editBtn.setAttribute("id","edit-button");
    DEicon.appendChild(editBtn);

    editBtn.addEventListener('click',function()
    {
        todos.removeChild(oldtask);
        let editedTask = prompt("edit your task");
        if(editedTask!==null && editedTask!=='')
        {
        let Task=renameTodo(editedTask);
        todos.prepend(Task);
        }
    })

}

function TaskDone()
{
     let checkbox = todos.querySelector('#checkbox');
     let span = todos.querySelector('span');
    checkbox.addEventListener('change', function() {
        if (checkbox.checked) {
            span.style.textDecoration = "line-through";
            
        } else {
            span.style.textDecoration = "none";
        }
    });
}