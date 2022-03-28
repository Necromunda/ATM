const db = require("../dbconnection");

const transfers = {
    getById: function(id, callback) {
        return db.query('select * from transfers where accounts_accounts_id=?', [id], callback);
      }
}

module.exports = transfers