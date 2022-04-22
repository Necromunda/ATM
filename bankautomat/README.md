
# QT-sovellus
Tähän vois laittaa jotain :D

## REST_DLL
***
REST_DLL-kirjastoon saa yhteyden pirauttamalla slotille void ExecuteRestOperation(QString, QString, QString, QString);

Slotti haluaa seuraavat parametrit toimiakseen:

token: token siinä muodossa, kuin sen saa login-reitiltä, eli esimerkiksi eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IjEyMzQ1NiIsImlhdCI6MTY0OTgzNjM5NCwiZXhwIjoxNjQ5ODM5OTk0fQ.DPrOVLtkV2P-LvqIhplF0nLC8dDOttEA5e1jzNbxwIE

metodi: tähän haluttu rest-operaatio pienin tai isoin kirjaimin, esim get taikka UPDATE

tarkenne: rajapinnan alkuosa on kovakoodailtu kirjaston engineen, mutta loppuosaan voi vaikuttaa tarkenteella. Esimerkiksi siirtohistoriaa hakiessa voidaan tarkenteeseen laittaa transfers/1, jolloin get-metodilla saadaan siirtohistoria tililtä jonka id on 1.

body: Metodit UPDATE sekä POST vaativat request bodyn sisältäen oleellisen datan, GET ja DELETE kelpuuttavat tyhjän stringin tähän, esimerkiksi pelkkä {} riittää.
***

Esimerkkikutsu REST-DLL:lle voisi olla vaikkapa seuraavanlainen:

    QString token = "token tähän";
    QString metodi = "post";
    QString tarkenne = "transfers/1";
    QString body = "{"amount": -100,"date": "2012-10-20T21:00:00.000","card_number": 1234,"accounts_account_id": 1}
    emit getREST(token, metodi, tarkenne, body);

***

REST_DLL Sisältää yhden signaalin, sendResultToExe(QString), joka lähettää serverin vastauksen yhtenä stringinä. Se voidaan tulostella esimerkiksi seuraavalla tavalla exessä:

    void MainWindow::recvResultsFromREST(QString msg)
    {
        ui->REST_results->setText(msg);
    }

Tarvittavat Signalit ja slotit, sekä niitä käyttävät connectit täytyy toki exen puolella tehdä ennenkuin kommunikointi onnistuu.