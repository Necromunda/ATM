const express = require('express');
const router = express.Router();
const users = require('../models/users_model');

router.post('/', 
function(request, response) {
  users.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
        response.json(request.body);
    }
  });
});

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    users.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.send("ID not found")
        } else {
          response.json(dbResult);
        }
      }
    });
  } else {
    users.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.put('/:id', 
function(request, response) {
  users.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      /*if (request.body.fname == '' || request.body.lname == '' || request.body.address == '' || request.body.address == '')  {
        response.send("Field was empty");
      }*/ 
      if (dbResult.affectedRows == 0) {
        response.send("ID not found");
      } else {
        response.json(dbResult);
      }
    }
  });
});

router.delete('/:id', 
function(request, response) {
  users.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      if (dbResult.affectedRows == 0) {
        response.send("ID not found")
      } else {
        response.json(dbResult);
      }
    }
  });
});

module.exports = router;