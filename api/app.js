var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var helmet = require('helmet');
var cors = require('cors');
const jwt = require('jsonwebtoken');

var loginRouter = require('./routes/loginrouter');
var usersRouter = require('./routes/users_route');
var transfersrouter = require('./routes/transfersrouter');
var accountsrouter = require('./routes/accountsrouter');
var cardsrouter = require('./routes/cardsrouter');


var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', loginRouter);
app.use(authenticateToken);
app.use('/accounts', accountsrouter)
app.use('/transfers', transfersrouter)
app.use('/cards', cardsrouter);
app.use('/users_model', usersRouter);


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.AUT_TOKEN, (err, card_number) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = card_number
  
      next()
    })
  }

  
module.exports = app;
