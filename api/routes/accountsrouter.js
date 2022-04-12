const accounts = require('../models/accounts');
const express = require ('express');
const router = express.Router();

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    accounts.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }
  else {
    accounts.getAll(function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
  }
});

router.post('/', 
function(req, res) {
  accounts.add(req.body, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(req.body);
    }
  });
});

router.delete('/:id', 
function(req, res) {
  accounts.delete(req.params.id, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(dbResult);
    }
  });
});

router.put('/:id', 
function(req, res) {
  accounts.update(req.params.id, req.body, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(dbResult);
    }
  });
});

module.exports = router;