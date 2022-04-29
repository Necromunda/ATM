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
        <h2>Pankin etusivu</h2>
        <p>Jotain tekstiä</p>
            <button onClick={() => navigate("/banktransfer")}>
                Uusi tilisiirto
            </button>
            <button onClick={() => navigate("/transfers")}>
                Siirtohistoria
            </button>
        </div>
    );

  };
  
  
export default Home;

