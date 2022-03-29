const db = require('../dbconnection');

const users = {
  getById: function(id, callback) {
    return db.query('select * from users where user_id=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from users', callback);
  },
  add: function(users, callback) {
    return db.query(
      'insert into users (fname,lname,address,phone) values(?,?,?,?)',
      [users.fname, users.lname, users.address, users.phone], callback);
  }
};

module.exports = users;