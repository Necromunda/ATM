const mysql = require('mysql');
const dotenv = require('dotenv');

dotenv.config();

const connection = mysql.createPool({
    host: 'localhost',
    user: 'root',
    password: 'root',
    database: 'banksimul'
});

module.exports = connection;