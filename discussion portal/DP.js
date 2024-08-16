let arr = [];
let obj = {};
let responseobj = {};
let currentQuestionId = 0;
winLoad();
function winLoad() {
  window.addEventListener("load", loadQuestionFromLocalStorage);
}

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

let resolveBtn = document.querySelector("#resolve-button");

newQuestionBtn.addEventListener("click", () => {
  Page1.style.display = "block";
  Page2.style.display = "none";
});

submitQuestionBtn.addEventListener("click", () => {
  if (subjectInputBox.value == "" || questionText.value == "") {
    alert("Enter subject and Question !!");
  } else {
    obj = {
      sub: subjectInputBox.value,
      que: questionText.value,
      id: Date.now(),
      response: [],
    };

    addQuestions(subjectInputBox.value, questionText.value, obj.id);
    arr.push(obj);
    saveQuestionToLocalStorage();
    subjectInputBox.value = "";
    questionText.value = "";
  }
});

responseBtn.addEventListener("click", () => {
  if (responserName.value == "" || responserComment.value == "") {
    alert("Enter Name and Comment !!");
  } else {
    addResponse(responserName.value, responserComment.value);
  }
});

function addResponse(name, comment) {
  let responseList = document.createElement("div");
  responseList.setAttribute("class", "response-list");
  responseList.innerHTML = `<h3>${name}</h3><p>${comment}</p><hr>`;
  responseBank.prepend(responseList);
  responserName.value = "";
  responserComment.value = "";
  responseobj = {
    name: name,
    comment: comment,
  };
  for (let i = 0; i < arr.length; i++) {
    if (arr[i].id == currentQuestionId) {
      arr[i].response.push(responseobj);
      break;
    }
  }
  console.log(arr);
  saveQuestionToLocalStorage();
}

function addQuestions(subject, question, id, response) {
  const now = new Date();
  var questionList = document.createElement("div");
  questionList.setAttribute("class", "ques-list");
  questionList.setAttribute("id", id.toString());
  questionList.innerHTML = `<h1 class='mainHeading'>${subject}</h1>
  <div class='classList'>
  <div id='q'>${question}</div>
  <div>${now}</div>
  </div>`;
  questionBank.prepend(questionList);
}

questionBank.addEventListener("click", (event) => {
  responseBank.innerHTML = "";
  displayQuestion.innerHTML = "";
  let queCopy = event.target.closest(".ques-list");
  console.log(queCopy);
  currentQuestionId = queCopy.id;

  console.log(currentQuestionId);
  for (let i = 0; i < arr.length; i++) {
    if (currentQuestionId == arr[i].id) {
      console.log(arr[i].response);
      let response = arr[i].response;
      loadResponseFromLocalStorage(response);
      break;
    }
  }
  if (queCopy.id) {
    currentQuestionId = queCopy.id;
    let temp = queCopy.cloneNode(true);
    displayQuestion.appendChild(temp);
    Page1.style.display = "none";
    Page2.style.display = "block";
  }
});

function saveQuestionToLocalStorage() {
  localStorage.setItem("questions", JSON.stringify(arr));
}

function loadQuestionFromLocalStorage() {
  arr = JSON.parse(localStorage.getItem("questions")) || [];
  arr.forEach(function ({ sub, que, id }) {
    addQuestions(sub, que, id);
  });
}

function loadResponseFromLocalStorage(response) {
  console.log("here", response);
  for (let i = 0; i < response.length; i++) {
    let name = response[i].name;
    console.log(name);
    let comment = response[i].comment;
    console.log(comment);
    loadResponse(name, comment);
  }

  console.log("check ", response);
}

function loadResponse(name, comment) {
  let responseList = document.createElement("div");
  responseList.setAttribute("class", "response-list");
  responseList.innerHTML = `<h3>${name}</h3><p>${comment}</p><hr>`;
  responseBank.prepend(responseList);
}

resolveBtn.addEventListener("click", () => {
  if (currentQuestionId) {
    document.getElementById(currentQuestionId).remove();
    displayQuestion.innerHTML = "";

    arr = arr.filter(
      (question) => question.id.toString() !== currentQuestionId
    );
    localStorage.setItem("questions", JSON.stringify(arr));

    Page1.style.display = "block";
    Page2.style.display = "none";
    currentQuestionId = 0;
  }
});
