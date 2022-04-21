const db = require('../dbconnection');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const cards = {
  getById: function(card_number, callback) {
    return db.query('select * from cards where card_number=?', [card_number], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM cards', callback);
  },
  getNameByCardNumber: function(card_number, callback) {
    return db.query('select group_concat(fname," ", lname) as "fullname" from users where user_id in (select cards.users_user_id from cards where card_number=?)',
    [card_number], callback);
  },
  getBalanceByCardNumber: function(card_number, callback) {
    return db.query('select balance from accounts where account_id in (select accounts_account_id from cards where card_number=?)',
    [card_number], callback);
  },
  getAccountId: function(card_number, callback) {
    return db.query('select accounts_account_id from cards where card_number=?',
    [card_number], callback);
  },
  add: function(cards, callback) {
    bcrypt.hash(cards.pin_code, saltRounds, function(err, hashed_pin_code)
    {
      return db.query(
        'insert into cards (card_number, pin_code, locked, accounts_account_id, users_user_id) values(?,?,?,?,?)', //, accounts_account_id, users_user_id & ,?,?
        [cards.card_number, hashed_pin_code, cards.locked, cards.accounts_account_id, cards.users_user_id], //, cards.accounts_account_id, cards.users_user_id 
        callback
      );
    });
  },
  delete: function(card_number, callback) {
    return db.query('delete from cards where card_number=?', [card_number], callback);
  },
  update: function(card_number, cards, callback) {
    bcrypt.hash(cards.pin_code, saltRounds, function(err, hashed_pin_code)
    {
      return db.query(
        'update cards set pin_code=?, locked=?, accounts_account_id=?, users_user_id=? where card_number=?', //, accounts_account_id, users_user_id & ,?,?
        [hashed_pin_code, cards.locked, cards.accounts_account_id, cards.users_user_id, [card_number]], //, cards.accounts_account_id, cards.users_user_id 
        callback
      );
    });
  },
  updateBalance: function(id, accounts, callback) {
    return db.query('UPDATE accounts SET balance=balance-? WHERE account_id in (select accounts_account_id from cards where card_number=?);',
    [accounts.balance, id], callback);
  }
};
module.exports = cards;