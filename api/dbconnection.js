const dotenv = require("dotenv");

const mysql = require('mysql2');
dotenv.config();

const dbconnection = mysql.createPool({
    host: process.env.HOST,   /*'127.0.0.1',*/
    user: process.env.USER,  /*'root',*/
    password: process.env.PASSWORD,  /*'Dreamwalker',*/
    database: process.env.DATABASE  /*'banksimul'*/
})
//gines vituttaa tasaisesti kaikkia, ainakin melkeen

module.exports = dbconnection