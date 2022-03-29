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

router.post('/', 
function(req, res) {
  transfers.add(req.body, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(req.body);
    }
  });
});

router.delete('/:id', 
function(req, res) {
  transfers.delete(req.params.id, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(dbResult);
    }
  });
});


router.put('/:id', 
function(req, res) {
  transfers.update(req.params.id, req.body, function(err, dbResult) {
    if (err) {
      res.json(err);
    } else {
      res.json(dbResult);
    }
  });
});



module.exports = router;