const express = require('express');
const router = express.Router();
const cards = require('../models/cards'); //<- cardsin sijasta users? Vai transfers?

router.post('/', 
function(request, response) {
  cards.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.get('/accountId/:card_number',
 function(request, response) {
  if (request.params.card_number) {
    cards.getAccountId(request.params.card_number, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.json("Not found")
        } else {
          response.json(dbResult[0]);
        }
      }
    });
  }
});

router.get('/name/:card_number',
 function(request, response) {
  if (request.params.card_number) {
    cards.getNameByCardNumber(request.params.card_number, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.json("Not found")
        } else {
          response.json(dbResult[0]);
        }
      }
    });
  }
});

router.get('/balance/:card_number',
 function(request, response) {
  if (request.params.card_number) {
    cards.getBalanceByCardNumber(request.params.card_number, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.json("Not found")
        } else {
          response.json(dbResult[0]);
        }
      }
    });
  }
});

router.get('/:card_number?',
 function(request, response) {
  if (request.params.card_number) {
    cards.getById(request.params.card_number, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        if (dbResult == '') {
          response.send("ID not found")
        } else {
          response.json(dbResult[0]);
        }
      }
    });
  } else {
    cards.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    }); 
  }
});

router.put('/updateBalance/:card_number', 
function(request, response) {
  cards.updateBalance(request.params.card_number, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.put('/:card_number', 
function(request, response) {
  cards.update(request.params.card_number, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.delete('/:card_number', 
function(request, response) {
  cards.delete(request.params.card_number, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      if (dbResult.affectedRows == 0) {
        response.send("ID not found");
      } else {
      response.json(dbResult);
      }
    }
  });
});


module.exports = router;