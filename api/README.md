# Banksimul-api

## Heroku

Projektin rajapinta on hostattu heroku-palvelussa Banksimul-api nimellä. Rajapintaa pääsee kutittelemaan osoitteesta https://banksimul-api.herokuapp.com, esimerkiksi PostManin tai Thunder Clientin avulla.

### Koodien deploy herokuun

Koodit on hostattu herokussa tekemällä ensin ilmainen sovellus "Create new app" -linkistä. Sovelluksen nimeksi on määritelty banksimul-api, ja sijainniksi eurooppa.

Koodien lisääminen herokuun onnistuu yksinkertaisesti, esimerkiksi asentamalla ensin heroku cli (Kirjoitushetkellä GitHubin ja herokun linkkaaminen ei onnistu suoraan [tietoturvaongelmien](https://status.heroku.com/incidents/2413) takia). Herokun globaali asennus onnistuu esimerkiksi seuraavalla komennolla.

`npm install -g heroku`

Herokun asentamisen jälkeen voidaan avata terminaali api-kansioon, ja suorittaa seuraavat komennot:

`heroku login`  Avaa selaimen ja ohjaa kirjautumaan herokuun

`git init`  Alustaa git-repon tähän sijaintiin

`heroku git:remote -a banksimul-api`    Yhdistää git-repon aiemmin tehtyyn heroku-sovellukseen

Lopuksi seuraavat komennot kopioivat koodit herokun master-branchiin

`git add .`

`git commit -m "Tähän informatiivinen viesti"`

`git push heroku master`

Tämän jälkeen heroku yrittää buildata projektin Procfilen avulla, ja sen puuttuessa päätyy käyttämään package.json-[tiedostosta](https://github.com/bank-2022/group1/blob/main/api/package.json#:~:text=%22-,start,-%22%3A%20%22nodemon%20./bin/www) löytyvää start-skriptiä. Helppoa ja hauskaa!




