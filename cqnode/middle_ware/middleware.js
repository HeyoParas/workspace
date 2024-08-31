module.exports = middleWare = (req, res, next) => {
    if (!req.query.age) {
      res.send("please enter age first");
    } else if (req.query.age < 18) {
      res.send("not adult");
    } else if (req.query.age >= 18) {
      next(); 
    }};