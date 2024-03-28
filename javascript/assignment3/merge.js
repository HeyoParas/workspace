const fs=require("fs");
const path=require('path');
fs.readdir("./javascript/assignment3",(err,files)=>
{
    if(err)
    {
        console.log("error");
    }
    else
    {
       console.log("ok");
        
for(let i=0;i<files.length;i++)
{
    let fileName = files[i];
    let filePath = path.join('./javascript/assignment3', fileName);
    fs.readFile(filePath, 'utf8', (err, data) => {
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

