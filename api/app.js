var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var helmet = require('helmet');
var cors = require('cors');

var usersRouter = require('./routes/users_route');
var transfersrouter = require('./routes/transfersrouter');
var accountsRouter = require('./routes/accounts_route');

var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use('/users', usersRouter);
app.use('/transfers', transfersrouter);
app.use('/accounts_model', accountsRouter)

module.exports = app;
