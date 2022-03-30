var jwt = require('jsonwebtoken');

// Luo tokenin postmanilla testailua varten
const signIn = () => {
    const token = jwt.sign({
        userId: 1,
        username: 'admin',
        role: 'admin'
    }, process.env.JWT_SECRET, { expiresIn: '1h' });
    console.log (token);
}

signIn();