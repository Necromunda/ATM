const db = require('../dbconnection');

const cards = {
  getById: function(id, callback) {
    return db.query('select * from cards where accounts_account_id=?', [id], callback);
  },
  add: function(cards, callback) {
    return db.query(
      'insert into cards (card_number, pin_code, locked, accounts_account_id, users_user_id) values(?,?,?,?,?)',
      [cards.card_number, cards.pin_code, cards.locked, cards.accounts_account_id, cards.users_user_id ],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from cards where accounts_account_id=?', [id], callback);
  },
  update: function(id, cards, callback) {
    return db.query(
      'update cards set card_number=?, pin_code=?, locked=?, accounts_account_id=?, users_user_id=? where id_cards=?',
      [cards.card_number, cards.pin_code, cards.locked, cards.accounts_account_id, cards.users_user_id, id],
      callback
    );
  }
};
module.exports = cards;