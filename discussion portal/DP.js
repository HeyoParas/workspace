let arr=[];
let queCopy;
window.addEventListener('load', loadQuestionFromLocalStorage);

let newQuestionBtn = document.querySelector("#new-question-form-button");

let questionInputBox = document.querySelector("#search-question");

let subjectInputBox = document.querySelector("#enter-subject");

let questionText = document.querySelector("#question-area");
let submitQuestionBtn = document.querySelector("#question-submit-button");
let questionBank = document.querySelector("#question-bank");
let rightContainer = document.querySelector(".right-container1");

let displayQuestion = document.querySelector("#display-question");

let Page1 = document.querySelector(".right-container1");
let Page2 = document.querySelector(".right-container2");

let responserName = document.querySelector("#responser-name");
let responserComment = document.querySelector("#responser-comment");
let responseBtn = document.querySelector("#response-button");

let responseBank = document.querySelector(".people-response");




newQuestionBtn.addEventListener("click", () => {
  Page1.style.display = "block";
  Page2.style.display = "none";
});

responseBtn.addEventListener("click", () => {
  if (responserName.value == "" || responserComment.value == "") {
    alert("Enter Name and Comment !!");
  } else {
    addResponse(responserName.value, responserComment.value);
    responserName.value = "";
    responserComment.value = "";
  }
});

function addResponse(name, comment) {
  let responseList = document.createElement("div");
  responseList.setAttribute("class", "response-list");
  responseList.innerHTML = `<h3>${name}</h3><p>${comment}</p><hr>`;
  responseBank.prepend(responseList);
}

submitQuestionBtn.addEventListener("click", () => {
  if (subjectInputBox.value == "" || questionText.value =="") {
    alert("Enter subject and Question !!");
  } else {
      
      let obj={
          sub:subjectInputBox.value,
          que:questionText.value,
          id:Date.now()
        }
        
        addQuestions(subjectInputBox.value, questionText.value);
    saveQuestionToLocalStorage(obj,arr)
    subjectInputBox.value = "";
    questionText.value = "";
  }
});

function addQuestions(subject, question) {
  const now = new Date();
  var questionList = document.createElement("div");
  questionList.innerHTML = `<h1 id='mainHeading'>${subject}</h1><div class='classList'><div>${question}</div><div></div>${now}</div>`;
  questionBank.prepend(questionList);
}

questionBank.addEventListener("click", (event) => {
 queCopy = event.target.parentNode;
  displayQuestion.appendChild(queCopy);
  console.log(queCopy);
  Page1.style.display = "none";
  Page2.style.display = "block";
});



function saveQuestionToLocalStorage(obj,arr) {

  console.log(arr)
  console.log(obj)
    arr.push(obj);
    localStorage.setItem('questions', JSON.stringify(arr));
}

function loadQuestionFromLocalStorage() {
    arr = JSON.parse(localStorage.getItem('questions')) || [];
    arr.forEach(function ({sub,que})  {
        addQuestions(sub,que);
    });
}