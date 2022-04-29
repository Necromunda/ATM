import React from 'react';
import { useEffect, useState } from 'react';

const Transfers = () => {

    const token = localStorage.getItem("token");

    const [iban, setIban] = useState(null);
    const [amount, setAmount] = useState(null);
    const [transfers, setTransfers] = useState("");


    const getTransfers = async () => {
        const headertoken = "token " + token;
        const response = await fetch('https://banksimul-api.herokuapp.com/transfers/1', { // Tähän parempi url, kovakoodauksen sijaan id muuttujaan
          method: 'GET',
          headers: {
            'Content-Type': 'application/json',
            Authorization: headertoken
          },
        });
        const data = await response.text();
        console.log("server response: " + data);
        setTransfers(data)
      };


    return (
        <div className="App">
        <header className="App-header">
            <h1>Welcome to the Bank</h1>
        </header>
            <p>Your token is: {token}</p>
            <h3>Hae tilisiirrot</h3>
            <button onClick={getTransfers}>Hae</button>
            <p>{transfers}</p>
        </div>
    );

  };
  
  
export default Transfers;