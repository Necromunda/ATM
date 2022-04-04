const dotenv = require("dotenv");

const mysql = require('mysql2');
dotenv.config();

const dbconnection = mysql.createPool({
    host:'127.0.0.1',
    user: 'root',
    password: 'testi',
    database: 'banksimul'
})
//gines vituttaa tasaisesti kaikkia, ainakin melkeen

module.exports = dbconnection