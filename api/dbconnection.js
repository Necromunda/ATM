const dotenv = require("dotenv");

const mysql = require('mysql');
dotenv.config();

const dbconnection = mysql.createPool({
    host:'localhost',
    user: 'root',
    password: 'salasana',
    database: 'banksimul'
})

module.exports = dbconnection