const db = require("../dbconnection");

const accounts = {
    getById: function(id, callback) {
        return db.query('SELECT * FROM accounts WHERE account_id=?', [id], callback);
    },
    getAll: function(callback) {
       return db.query('SELECT * FROM accounts', callback);
    },
    getCredit: function(id, callback) {
        return db.query('SELECT credit FROM accounts where account_id=?', [id], callback);
    },
    getIban: function(id, callback) {
        return db.query('SELECT iban FROM accounts where account_id=?', [id], callback);
    },
    execDebitTransaction: function(transaction, callback) {
        return db.query('call debit_transfer(?,?,?,?)',
        [transaction.senderIban, transaction.receiverIban, transaction.amount, transaction.date], callback);
    },
    execCreditTransaction: function(transaction, callback) {
        return db.query('call credit_transfer(?,?,?,?)',
        [transaction.senderIban, transaction.receiverIban, transaction.amount, transaction.date], callback);
    },
    add: function(accounts, callback) {
      return db.query(
       'INSERT INTO accounts (iban,balance) VALUES(?,?)',
        [accounts.iban, accounts.balance], callback);
    },
    update: function(id, accounts, callback) {
       return db.query('UPDATE accounts SET iban=?, balance=? WHERE account_id=?',
       [accounts.iban, accounts.balance, id], callback);
    },
    delete: function(id, callback) {
        return db.query('DELETE FROM accounts WHERE account_id=?', 
        [id], callback);
    }
};

module.exports = accounts;