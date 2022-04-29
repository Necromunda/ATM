import React from 'react';
import { useEffect, useState } from 'react';
import { useNavigate } from "react-router-dom";

const Transfers = () => {

  const navigate = useNavigate();

    const token = localStorage.getItem("token");
    const card = localStorage.getItem("card");

    const [iban, setIban] = useState(null);
    const [amount, setAmount] = useState(null);
    const [transfers, setTransfers] = useState("");
    const [accountID, setAccountID] = useState("");

    const getAccountNumber = async () => {
        const response = await fetch(`https://banksimul-api.herokuapp.com/cards/accountId/${card}`, {
            method: 'GET',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${token}`
            }
        });
        const data = await response.json();
        console.log("Account number" +data.accounts_account_id);
        setAccountID(data.accounts_account_id);
    }

    useEffect(() => {
        getAccountNumber();
    }, []);


    const getTransfers = async () => {
        const headertoken = "token " + token;
        const response = await fetch(`https://banksimul-api.herokuapp.com/transfers/${accountID}`, { // Tähän parempi url, kovakoodauksen sijaan id muuttujaan
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
        <div className='content'>
            <h3>Hae tilisiirrot</h3>
            <button onClick={getTransfers}>Hae</button>
            <button onClick={() => navigate("/")}>
                Etusivulle
            </button>
            <p>{transfers}</p>

        </div>
        </div>
    );

  };
  
  
export default Transfers;