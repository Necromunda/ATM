const db = require("../dbconnection");

const transfers = {
  getById: function(id, callback) {
    return db.query('select transfer_id, amount, date_format(date, "%d-%m-%Y %H:%i:%s") as date, card_number, accounts_account_id from transfers where accounts_account_id=?', [id], callback);
  },
  getByDate: function(id, date, callback) {
    return db.query('select transfer_id, amount, date_format(date, "%d-%m-%Y %H:%i:%s") as date, card_number, accounts_account_id from transfers WHERE date_format(date, "%d-%m-%Y %H:%i:%s") LIKE concat(?,"%") and accounts_account_id=?;', [date, id], callback);
  },
  getCustom: function(id, bot, top, callback) {
    return db.query('call getNextAndPrevTransfers(?,?,?)', 
    [id, bot, top], callback);
  },
  add: function(transfers, callback) {
    return db.query(
      'insert into transfers (amount,date,card_number,accounts_account_id) values(?,?,?,?)',
      [transfers.amount, transfers.date, transfers.card_number, transfers.accounts_account_id],
      callback);
  }, 
  delete: function(id, callback) {
    return db.query('delete from transfers where transfer_id=?', [id], callback);
  },
  update: function(id, transfers, callback) {
    return db.query(
      'update transfers set amount=?, date=?, card_number=?, accounts_account_id=? where transfer_id=?',
      [transfers.amount, transfers.date, transfers.card_number, transfers.accounts_account_id, id],
      callback);
  }
};

module.exports = transfers