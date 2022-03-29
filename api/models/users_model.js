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
  },
  update: function(id, users, callback) {
    return db.query(
      'update users set fname=?, lname=?, address=?, phone=? where user_id=?',
      [users.fname, users.lname, users.address, users.phone, id], callback);
  },
  delete: function(id, callback) {
    return db.query('delete from users where user_id=?', [id], callback);
  }
};

module.exports = users;