# GROUP 1 : Pankkiautomaattisovellus

## Asennusohje
Aja api kansiossa komento npm install. Sitten sovellus käynnistyy komennolla npm start.

### .env
Luo api kansioon .env tiedosto ja lisää sinne seuraavat muuttujat:

    HOST = "sql11.freemysqlhosting.net"
    USER = "sql11488057"
    PASSWORD = "YJX8tWcMYn"
    DATABASE = "sql11488057"
    AUT_TOKEN = ""  

Aja komentorivillä komento "node create_token" ja kopioi siitä tuleva merkkijono muuttujan AUT_TOKEN arvoksi.

### Tietokanta
Tietokantaa isännöi freemysqlhosting.net.

### REST-api
REST-apia isännöi heroku.com

## ER-kaavio
Tietokannan ER-kaavio näyttää tältä. 
<img src="Documents/banksimul-db-27-4.png">

## Ohjelman käyttöliittymät
Syötä kortti. 
<img src="Documents/insert-card-window.png">

Syötä pin. 
<img src="Documents/insert-pin-window.png">

Valitse credit tai debit. 
<img src="Documents/debit-or-credit-window.png">

Pääkäyttöliittymä. 
<img src="Documents/main-bank-interface-window.png">

Nosta rahaa. 
<img src="Documents/draw-money-window.png">
