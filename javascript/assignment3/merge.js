const fs=require("fs");
const path=require('path');
fs.readdir("./javascript/assignment3",function(err,file)
{
    if(err)
    {
        console.log("error");
    }
    else
    {
       console.log("ok \n total number of files in the directory:",file.length,"\n");
        
for(let i=0;i<file.length;i++)
{
    let fileName = file[i];
    let filePath = path.join('./javascript/assignment3', fileName);
    fs.readFile(filePath,(err, data) =>
    {
        if (err) 
        {
            console.log('error');
            return;
        }
    fs.appendFile("./javascript/assignment3/mergecontent.txt", data, (err) => {
            if (err) 
            {
                console.log('Error');
            }
             else 
            {
                console.log(fileName);
            }
    });
    });
}
    }
});

