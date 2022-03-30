var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');



var transfersrouter = require('./routes/transfersrouter');
var accountsrouter = require('./routes/accountsrouter');

var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use('/transfers', transfersrouter)
app.use('/accounts', accountsrouter)

module.exports = app;
