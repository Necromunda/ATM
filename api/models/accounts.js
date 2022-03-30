const db = require("../dbconnection");

const accounts = {
    getById: function(id, callback) {
        return db.query('SELECT * FROM accounts WHERE account_id=?', [id], callback);
    },
    getAll: function(callback) {
       return db.query('SELECT * FROM accounts', callback);
    },
    add: function(accounts, callback) {
      return db.query(
       'INSERT INTO accounts (iban,balance) values(?,?)',
        [accounts.iban, accounts.balance], callback);
    },
    update: function(id, accounts, callback) {
       return db.query(
    'UPDATE accounts SET iban=?, balance=? WHERE user_id=?',
    [accounts.iban, accounts.balance, id], callback);
    },
    delete: function(id, callback) {
     return db.query('DELETE FROM accounts WHERE account_id=?', [id], callback);
    }
};

module.exports = accounts;
