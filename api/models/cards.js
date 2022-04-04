const db = require('../dbconnection');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const cards = {
  getById: function(id, callback) {
    return db.query('select * from cards where accounts_account_id=?', [id], callback);
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
  delete: function(id, callback) {
    return db.query('delete from cards where accounts_account_id=?', [id], callback);
  },
  update: function(id, cards, callback) {
    bcrypt.hash(cards.pin_code, saltRounds, function(err, hashed_pin_code)
    {
      return db.query(
        'update cards set card_number=?, pin_code=?, locked=?, accounts_account_id=?, users_user_id=? where accounts_account_id=?', //, accounts_account_id, users_user_id & ,?,?
        [cards.card_number, hashed_pin_code, cards.locked, cards.accounts_account_id, cards.users_user_id, [id]], //, cards.accounts_account_id, cards.users_user_id 
        callback
      );
    });
    
  }
};
module.exports = cards;