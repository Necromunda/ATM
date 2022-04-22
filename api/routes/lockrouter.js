const lock = require('../models/cards');

const express = require ('express');
const router = express.Router();

router.get('/status/:card_number', 
function(request, response) {
  lock.cardLockStatus(request.params.card_number, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  });
});

router.put('/:card_number', 
function(request, response) {
  lock.lockCard(request.params.card_number, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json("Card locked");
    }
  });
});

module.exports = router;