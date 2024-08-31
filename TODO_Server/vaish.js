function handleCheckBox(target){
    const task = target.parentElement;
    let taskId = task.id;
    let status = task.getAttribute("status");
    // const isCompleted = target.checked;  //  or use this true if checkbox is checked, false otherwise  

    let div = task.querySelector('.task');
    if(target.checked){
      // console.log("checked");
      div.classList.add("strike-through");
      // toDoList.append(task);
      status = true;
    }
    else{
      // console.log("unchecked");
      div.classList.remove("strike-through");
      status = false;
    }
    task.setAttribute("status", status);

    fetch("/checkBox/"+ taskId,{
      method:"PATCH",
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({isCompleted:status})
    })
    .then((response)=>{
      return response.json();
    })  
    .then(data => {
      if (data.success) {
        console.log("success");
      }
    })
    .catch(error => {
      console.error("Error: ",error);
    })
}







//route to handle the checkBox
app.patch("/checkBox/:id", (req, res) => {
    let tasks = [];
    let taskId = req.params.id;
    taskId = Number(taskId);
    let status = req.body;
    fs.readFile("tasksData.json", "utf8", (err, data) => {
      if (err) {
        console.err(err);
        return;
      } else {
        if (data) {
          tasks = JSON.parse(data);
        } else {
          tasks = [];
        }
      }
      for (let i = 0; i < tasks.length; i++) {
        if (tasks[i].id === taskId) {
          tasks[i].isCompleted = status.isCompleted;
          break;
        }
      }
      fs.writeFile("tasksData.json", JSON.stringify(tasks), (err) => {
        if (err) {
          console.err(err);
          return;
        }
        res.json({ success: true });
      });
    });
  });