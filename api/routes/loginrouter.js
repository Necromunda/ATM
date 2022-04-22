const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.card_number && request.body.pin_code){
      const card_number = request.body.card_number;
      const pin_code = request.body.pin_code;
        login.checkpin_code(card_number, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin_code,dbResult[0].pin_code, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ username: card_number });
                  response.send(token);
                }
                else {
                    console.log("wrong pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("card does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("card number or pincode missing");
      response.send(false);
    }
  }
);

function generateAccessToken(username) {
  dotenv.config();
  return jwt.sign(username, process.env.AUT_TOKEN, { expiresIn: '3600s' });
}

module.exports=router;

