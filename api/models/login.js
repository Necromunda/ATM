const db = require('../dbconnection');

const login={
  checkpin_code: function(card_number, callback) {
      return db.query('SELECT pin_code FROM cards WHERE card_number = ?',[card_number], callback); 
    }
};
          
module.exports = login;