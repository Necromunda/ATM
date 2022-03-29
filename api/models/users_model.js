const db = require('../database');

const users = {
  add: function(users, callback) {
    return db.query(
      'insert into users (fname,lname,adress,phone) values(?,?,?,?)',
      [users.fname, users.lname, users.address, users.phone],
      callback
    );
  }
};

module.exports = users;