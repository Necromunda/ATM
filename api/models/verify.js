const db = require("../dbconnection");

const verify = {
    getById: function(card_number, callback) {
      return db.query('select * from cards where card_number=?', [card_number], callback);
    }
};
module.exports = verify;