
# QT-sovellus
Tähän vois laittaa jotain :D

## REST_DLL
***
REST_DLL-kirjastoon saa yhteyden pirauttamalla slotille void ExecuteRestOperation(QString, QString, QString, QString);

Slotti haluaa seuraavat parametrit toimiakseen:

Token: Token lähetetään REST.dll:ään muodossa "Bearer _token_"

Metodi: tähän haluttu rest-operaatio pienin tai isoin kirjaimin, esim get taikka UPDATE

Tarkenne: rajapinnan alkuosa on kovakoodailtu kirjaston engineen, mutta loppuosaan voi vaikuttaa tarkenteella. Esimerkiksi siirtohistoriaa hakiessa voidaan tarkenteeseen laittaa transfers/1, jolloin get-metodilla saadaan siirtohistoria tililtä jonka id on 1.

Body: Metodit UPDATE sekä POST vaativat request bodyn sisältäen oleellisen datan, GET ja DELETE kelpuuttavat tyhjän stringin tähän, esimerkiksi pelkkä {} riittää.
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