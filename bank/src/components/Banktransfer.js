import React from 'react';
import { useEffect, useState } from 'react';

const BankTransfer = () => {

    const token = localStorage.getItem("token");

    const [iban, setIban] = useState(null);
    const [amount, setAmount] = useState(null);


    const sendTransfer = async () => {
        const headertoken = "token " + token;
        const response = await fetch('https://banksimul-api.herokuapp.com/xxxxx', { // Tähän pankkisiirron url
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
            Authorization: headertoken
          },
          body: JSON.stringify({
            iban: iban,
            amount: amount
          })
        });
        const data = await response.text();
        console.log("server response: " + data);
      };


    return (
        <div className="App">
        <header className="App-header">
            <h1>Welcome to the Bank</h1>
        </header>
            <p>Your token is: {token}</p>
            <h3>Uusi tilisiirto</h3>
            <input type="text" placeholder="Vastaanottajan tilinumero" onInput={e => setIban(e.target.value)}/>
            <input type="text" placeholder="Summa" onInput={e => setAmount(e.target.value)} />   
            <button onClick={sendTransfer}>Hyväksy</button>
        </div>
    );

  };
  
  
export default BankTransfer;