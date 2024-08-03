var sum=0
let productInput=document.querySelector('#product-name');
let priceInput=document.querySelector('#product-price');
let btn=document.querySelector('#btn');
let productList=document.querySelector('.products')
let span=document.querySelector('.sum')

priceInput.addEventListener('keypress',function(e)
{

  if(e.key==="Enter")
  {
  if(productInput.value === "" || priceInput.value === "")
  {
    alert("write whole details");
  }
  else
  {
    let product = productInput.value
    let price = priceInput.value

      createList(product,price);
  }
  productInput.value="";
  priceInput.value="";
}
})


function createList(product,price)
{
  var list = document.createElement("div");
  list.setAttribute("class","lists")
  list.innerHTML="<div id=productName>"+product+"</div>"+"<div id=productPrice>"+price+"</div>";
  productList.appendChild(list);
  
  let deleteBtn=document.createElement("button");
  deleteBtn.setAttribute("class","delete");
  deleteBtn.innerText="delete";
  list.appendChild(deleteBtn);
  console.log(productList);

  total(price);

  deleteBtn.addEventListener('click',function(){
    console.log("delete call")
    productList.removeChild(list);
    updateTotal(price)
    
  })
}



function total(price)
{
  sum=parseInt(price)+parseInt(sum);
  span.textContent="total :"+sum;
}
function updateTotal(price)
{
  sum=parseInt(sum)-parseInt(price)
  span.textContent="total :"+sum
}



