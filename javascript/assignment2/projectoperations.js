tasks={
    length:0
};
function add(taskid,taskdetails)
{
    tasks[taskid]=taskdetails;
    tasks.length++;
}
function update(taskid,updatetaskdetails)
{
    if(tasks[taskid])
    {
        tasks[taskid]=updatetaskdetails;
    }
    else{
        console.log("taskid is not present");
    }
}
function del(taskid)
{
    if(tasks[taskid])
    {
        delete tasks[taskid];
        tasks.length--;
    }
    else{
        console.log("id is not present");
    }
}
function display()
{
 console.log("total number of tasks :",tasks.length,"\n");
 console.log("Tasks are:");
 for(let i=0;i<tasks.length;i++)
 {
    console.log("Task id:",i);
    console.log("Tasks details",tasks[i]);
    console.log("\n");
 }
}
module.exports={
    add,del,update,display
}