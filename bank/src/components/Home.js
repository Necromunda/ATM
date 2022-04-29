import React from 'react';
import { useEffect, useState } from 'react';
import { useNavigate } from "react-router-dom";

const Home = () => {

    const token = localStorage.getItem("token");

    const navigate = useNavigate();


    return (
        <div className="App">
        <header className="App-header">
            <h1>Welcome to the Bank</h1>
        </header>
            <p>Your token is: {token}</p>
            <p>
            Tähän vois laittaa vaikka tilisiirtojuttui tai jotain muuta.
            </p>
            <button onClick={() => navigate("/banktransfer")}>
                Tilisiirtoihin
            </button>
        </div>
    );

  };
  
  
export default Home;

