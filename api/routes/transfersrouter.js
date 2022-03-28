const transfers = require('../models/transfers');

const express = require ('express');
const router = express.Router();

// Palauttaa parametrinä annetun tilin siirtohistorian
router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    transfers.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
  else{
      response.status(403);
      response.json("missing id");
  }
});

module.exports = router;