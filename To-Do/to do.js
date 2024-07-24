
let inputbox =document.querySelector("#input-text-box")
let list = document.querySelector(".list-container")
let btn = document.querySelector("#btn");


btn.addEventListener('click',function()
{
    //agar user sirf blank chordke add krega task toh alert dega
    if(inputbox.value==="")
    {
        alert("Write a task!!!");
    }
    else //agar blank ni chodega toh new task add kr dega
    {
        let newelement = document.createElement('p');
        newelement.innerHTML = '<input type="checkbox" id  ="checkbox"></input>' + '   ' +inputbox.value;
        list.appendChild(newelement);
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
                let newelement = document.createElement('p');
                newelement.innerHTML = '<input type="checkbox" id  ="checkbox"></input>' + '   ' +inputbox.value;
                list.appendChild(newelement);

                //new element create krega jo delete ke kaam ayega

                let deleteIcon = document.createElement('span');
                deleteIcon.innerHTML = '❌'; 
                deleteIcon.className = 'delete-icon';
                newelement.appendChild(deleteIcon);

                //delete element ke upar click hote hi list mein se task remove kr dega

                deleteIcon.addEventListener('click', function() {
                    list.removeChild(newelement);
                });
                

                //agar checkbox check krte hai toh task linethrough kr dega
                let checkbox = newelement.querySelector('#checkbox');
                checkbox.addEventListener('change', function() {
                    if (checkbox.checked) {
                        newelement.style.textDecoration = "line-through";
                    } else {
                        newelement.style.textDecoration = "none";
                    }
                });
            }
            inputbox.value="";
    }
})



