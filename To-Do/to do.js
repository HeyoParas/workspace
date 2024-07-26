var inputbox =document.querySelector("#input-text-box")
var list = document.querySelector(".list-container")
var btn = document.querySelector("#btn");


btn.addEventListener('click',function()
{
    //agar user sirf blank chordke add krega task toh alert dega
    if(inputbox.value==="")
    {
        alert("Write a task!!!");
    }
    else //agar blank ni chodega toh new task add kr dega
    {
        fun();

    }
    inputbox.value="";
});
inputbox.addEventListener('keydown', function(e) {
    //agar user enter key press krega toh add hojega task
    if (e.key === 'Enter') {
        if(inputbox.value==="" )
            {
                alert("Write a task!!!");
            }
            else{
                //new task add krega 
                fun();
            }
            inputbox.value="";
    }
})

function fun()
{
    var newelement = document.createElement('div');
    newelement.setAttribute("class","Todo-content");
    newelement.innerHTML = '<div><input type="checkbox" id  ="checkbox"></input>'+'<span>'+ inputbox.value +'</span></div>';
    list.prepend(newelement);
    //new element create krega jo delete ke kaam ayega

    deleteIcon = document.createElement('button');
    deleteIcon.innerHTML = '✖'; 
    deleteIcon.setAttribute("id","cross-button");
    newelement.appendChild(deleteIcon);

    

    //delete element ke upar click hote hi list mein se task remove kr dega

    deleteIcon.addEventListener('click', function() {
        list.removeChild(newelement);
    });
    

    //agar checkbox check krte hai toh task linethrough kr dega
    let checkbox = newelement.querySelector('#checkbox');
    let span = newelement.querySelector('span');
    checkbox.addEventListener('change', function() {
        if (checkbox.checked) {
            span.style.textDecoration = "line-through";
            
        } else {
            span.style.textDecoration = "none";
        }
    });
}

