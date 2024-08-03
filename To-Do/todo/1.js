var inputBox=document.getElementById("input-box");
var listContainer=document.getElementById("list-container");
var btn=document.getElementById("btn");
btn.addEventListener('click',addTask());

window.addEventListener('todo', showTask);

function addTask(){
    if(inputBox.value==='')
    {
        alert("write something");
        console.log("alert call");
    }
    else{
        let li=document.createElement("li");
        li.innerHTML=inputBox.value;
        listContainer.prepend(li);
        let span =document.createElement("span");
        span.innerHTML="X";
        li.appendChild(span);
    }
    inputBox.value="";
    saveData();
}

listContainer.addEventListener('click',function(e)
{
    if(e.target.tagName==='LI')
    {
        e.target.classList.toggle("checked");
        saveData();
    }
    else if(e.target.tagName==='SPAN')
    {
        e.target.parentElement.remove();
        saveData();
    }
},false);

function saveData()
{
    localStorage.setItem("todo",listContainer.innerHTML);
}
function showTask()
{
    listContainer.innerHTML = localStorage.getItem("todo");
}
showTask();