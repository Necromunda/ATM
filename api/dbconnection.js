const dotenv = require("dotenv");

const mysql = require('mysql2');
dotenv.config();

const dbconnection = mysql.createPool({
    host: process.env.HOST,
    user: process.env.USER,
    password: process.env.PASSWORD,
    database: process.env.DATABASE
});

module.exports = dbconnection