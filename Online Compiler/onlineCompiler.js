let compileBtn = document.querySelector("#runButton");
compileBtn.addEventListener("click", () => {
  let output = document.getElementById("output");
  output.innerText="";
  let codingLanguage = document.getElementById("language");
  console.log(codingLanguage);
  let lang = codingLanguage.value;
  console.log(lang);
  let langId;
  if (lang == "c") {
    langId = 7;
    console.log("current language id: ", langId);
  }
  if (lang == "cpp") {
    langId = 77;
    console.log("current language id: ", langId);
  }
  if (lang == "java") {
    langId = 8;
    console.log("current language id: ", langId);
  }
  if (lang == "javascript") {
    langId = 4;
    console.log("current language id: ", langId);
  }
  if (lang == "python") {
    langId = 0;
    console.log("current language id: ", langId);
  }
  let code = document.getElementById("codeArea");
  console.log("code is :", code.value);

  let obj = {
    code: code.value,
    langId: langId,
  };

  let xhr = new XMLHttpRequest();
  xhr.open("POST", "https://course.codequotient.com/api/executeCode", true);
  xhr.setRequestHeader("Content-type", "application/json");
  xhr.send(JSON.stringify(obj));

  xhr.onreadystatechange = function () {
    if (xhr.readyState == 4) {
      let response = JSON.parse(xhr.responseText);
      console.log("response is :", response);
      if (response.error) {
        console.log("error: ", response.error);
        output.innerText = "error: " + response.error;
      } else {
        let codeId = response.codeId;
        console.log(codeId);
        let intervalId = setInterval(() => {
          let newxhr = new XMLHttpRequest();
          console.log(newxhr);
          newxhr.open(
            "GET",
            `https://course.codequotient.com/api/codeResult/${codeId}`,
            true
          );
          newxhr.send();
          newxhr.addEventListener("load", () => {
            let newresponse = JSON.parse(newxhr.responseText);
            console.log("new response :", newresponse);
            if (newresponse.data) {
              clearInterval(intervalId);
              let resultCode = JSON.parse(newresponse.data).output;
              console.log(resultCode);
              if(resultCode=="")
              {
                output.innerText = "ERROR IN CODE";
              }
              else{
              output.innerText = resultCode;
              output.style.color="yellow";
              }
            }
          });
        }, 2000);
      }
    }
  };
});
