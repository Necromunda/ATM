const verify = require('../models/verify');

const express = require ('express');
const router = express.Router();

router.get('/:card_number?',
 function(request, response) {
  if (request.params.card_number) {
    verify.getById(request.params.card_number, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.send(false)
        } else {
        response.send(true);
        }
      }
    });
  } else {
    response.status(403);
    response.json("missing id");
  }
});

module.exports = router;