const db = require('../dbconnection');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const cards = {
  getById: function(id, callback) {
    return db.query('select * from cards where accounts_account_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM cards', callback);
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
  }
};
module.exports = cards;