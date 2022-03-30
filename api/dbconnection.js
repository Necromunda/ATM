const dotenv = require("dotenv");

const mysql = require('mysql');
dotenv.config();

const dbconnection = mysql.createPool({
    host:'localhost',
    user: 'root',
    password: 'Dreamwalker',
    database: 'banksimul'
})
//gines vituttaa tasaisesti kaikkia, ainakin melkeen

module.exports = dbconnection