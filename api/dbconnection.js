const dotenv = require("dotenv");

const mysql = require('mysql2');
dotenv.config();

const dbconnection = mysql.createPool({
    host:'127.0.0.1',
    user: 'root',
    password: 'root',
    database: 'banksimul'
})

module.exports = dbconnection