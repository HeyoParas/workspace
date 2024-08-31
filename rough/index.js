document.querySelector(".btn").addEventListener("click", () => {
  let res = fetch('https://dummyjson.com/carts');
  let div=document.querySelector(".sample");

  res.then((response) => {
      // Check if the response status is not OK (i.e., not 200-299)
      if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
      }
      return response.json();  // Convert response to JSON
  })
  .then((data) => {
      console.log(data);
      let x=document.createElement("p"); 
      x.innerText=data;
      // Handle the JSON data
      div.appendChild(x);
  })
  .catch((error) => {
      console.error("Error occurred:", error);  // Handle any errors
  });
});