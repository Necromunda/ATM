import React from 'react';
import { useEffect, useState } from 'react';
import { useNavigate } from "react-router-dom";

const BankTransfer = () => {

  const navigate = useNavigate();

    const token = localStorage.getItem("token");
    const card = localStorage.getItem("card");

    const [iban, setIban] = useState(null);
    const [amount, setAmount] = useState(null);
    const [accountID, setAccountID] = useState("");
    const [serverResponse, setServerResponse] = useState("");

    
    useEffect(() => {
      getAccountNumber();
    }, []);

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


    const sendTransfer = async () => {
        const headertoken = "token " + token;
        const response = await fetch('https://banksimul-api.herokuapp.com/accounts/transaction/debit', { // Tähän pankkisiirron url
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
            Authorization: headertoken
          },
          body: JSON.stringify({
            senderIban: accountID,
            receiverIban: iban,
            amount: amount,
            date: "2012-10-20T21:00:00.000",
          })
        });
        const data = await response.text();
        console.log("server response: " + data);
        setServerResponse(data);
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
            <div>
            <button onClick={sendTransfer}>Hyväksy</button>
            <button onClick={() => navigate("/")}>
                Etusivulle
            </button>
            </div>
            <p>Serverin vastaus: {serverResponse}</p>
        </div>
    );

  };
  
  
export default BankTransfer;