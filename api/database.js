const mysql = require('mysql');
const dotenv = require('dotenv');

dotenv.config();

const connection = mysql.createPool({
    host: sql11.freemysqlhosting.net,
    user: sql11482083,
    password: nHMRfbCNTC,
    database: sql11482083
});

module.exports = connection;