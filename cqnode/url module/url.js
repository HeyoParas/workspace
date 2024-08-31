const http = require("http");
const url = require("url");
const myServer = http.createServer((req, res) => {

  let dummyUrl=req.url;
  console.log("Trimmed URL :",dummyUrl);



  const link = url.parse(req.url, true);
  console.log(link);
  console.log("formatted:",url.format(link));
  console.log("link search", link.search);
  console.log("link pathname", link.pathname);
  console.log("link path", link.path);
  console.log("link href", link.href);
  console.log("link query", link.query);
  console.log("link query age", link.query.age);
  switch (link.pathname) {
    case "/":
      res.end("Home Page");
      break;

    case "/about":
      const username = link.query.name;
      res.end(`Hi,${username}`);
      break;
    case "/favicon.ico":
      res.end("");
      return;
    default:
      res.end("404 Not Found");
  }
});

myServer.listen(8000, () => console.log("server Started"));
