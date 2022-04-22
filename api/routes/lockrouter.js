const lock = require('../models/cards');

const express = require ('express');
const router = express.Router();

router.put('/:card_number', 
function(request, response) {
  lock.lockCard(request.params.card_number, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      //response.json("Card locked");
      response.json(dbResult);
    }
  });
});

module.exports = router;