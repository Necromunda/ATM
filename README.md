# GROUP 1 : Pankkiautomaattisovellus

## Asennusohje
Aja api kansiossa komento npm install. Sitten sovellus käynnistyy komennolla npm start.

### .env
Luo api kansioon .env tiedosto ja luo sinne muuttuja AUT_TOKEN. Aja komentorivillä komento "node create_token" ja kopioi siitä tuleva merkkijono muuttujan AUT_TOKEN arvoksi.

### Tietokanta
```
CREATE DEFINER=`root`@`localhost` PROCEDURE `prac`(IN id int, IN bot int, IN top int)
BEGIN
SELECT * FROM (SELECT transfer_id, amount, date_format(DATE, "%d.%m.%y, %h:%m:%s") AS DATE, card_number, accounts_account_id FROM transfers 
WHERE accounts_account_id=id AND transfer_id BETWEEN bot AND top ORDER BY transfer_id DESC) sub ORDER BY transfer_id ASC;
END
```

## ER-kaavio
Tietokannan ER-kaavio näyttää tältä <img src="Documents/tietokanta-er-kaavio.png">
