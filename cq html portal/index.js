var btn = document.getElementById("press");
var input = document.getElementById("ip");
var parent = document.getElementById("parent")

btn.addEventListener("click",function()

{
    var value=input.value;
    var h1 = document.createElement("h1");
    h1.innerText = value;

    parent.appendChild(h1);
}); 