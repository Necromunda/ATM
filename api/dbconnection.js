const dotenv = require("dotenv");

const mysql = require('mysql2');
dotenv.config();

const dbconnection = mysql.createPool({
    host: dotenv.HOST,
    user: dotenv.USER,
    password: dotenv.PASSWORD,
    database: dotenv.DATABASE
});

module.exports = dbconnection