var express = require('express');
const jwt = require('jsonwebtoken');

const verifyToken = (req, res, next) => {
    const authHeader = req.headers['authorization'];
    if (typeof authHeader !== 'undefined') {
        const decoded = jwt.verify(authHeader, process.env.JWT_SECRET);
        console.log(decoded);
        next();
    } else {
        res.sendStatus(403);
    }
}

module.exports = verifyToken;

