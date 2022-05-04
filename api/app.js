var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var helmet = require('helmet');
var cors = require('cors');
const jwt = require('jsonwebtoken');

var verifyrouter = require('./routes/verifyrouter');
var lockrouter = require('./routes/lockrouter');
var loginrouter = require('./routes/loginrouter');
var usersrouter = require('./routes/usersrouter');
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

app.use('/verify', verifyrouter);
app.use('/lock', lockrouter);
app.use('/login', loginrouter);
app.use(authenticateToken);
app.use('/accounts', accountsrouter)
app.use('/transfers', transfersrouter)
app.use('/cards', cardsrouter);
app.use('/users', usersrouter);

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
