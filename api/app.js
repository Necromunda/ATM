var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
<<<<<<< HEAD
var helmet = require('helmet');
var cors = require('cors');

var usersRouter = require('./routes/users_route');
var transfersrouter = require('./routes/transfersrouter');
var accountsRouter = require('./routes/accountsrouter');
=======
const helmet = require('helmet');
const cors = require('cors');


var transfersrouter = require('./routes/transfersrouter');
>>>>>>> uusihaara

var accountsrouter = require('./routes/accountsrouter');
var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
<<<<<<< HEAD
app.use('/users', usersRouter);
app.use('/transfers', transfersrouter);
=======
app.use('/transfers', transfersrouter)



>>>>>>> uusihaara
app.use('/accounts', accountsrouter)

module.exports = app;
