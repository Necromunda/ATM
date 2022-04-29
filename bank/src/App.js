import { useContext } from 'react';
import { useEffect, useState } from 'react';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import './App.css';
import Home from './components/Home';
import BankTransfer from './components/Banktransfer';
import Transfers from './components/Transfers';


function App() {
    const [token, setToken] = useState(null);
    const [user, setUser] = useState(null);
    const [password, setPassword] = useState(null);
  
    const login = async () => {
      const response = await fetch('https://banksimul-api.herokuapp.com/login', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          card_number: user,
          pin_code: password
        })
      });
      if(response.status === 200) {
        const data = await response.text();
        console.log("server response: " + data);
        if(data != "false") {
          setToken(data);
        }
        else {
          alert("Wrong card number or pin code");
        }
      }
      else {
        alert("error");
      }
    };
  
  
    if(!token) {
      return(
        <div className="App">
          <header className="App-header">
            <h1>Welcome to the Bank</h1>
          </header>
          <p>Please log in to continue</p>
          <input type="text" placeholder="card_number" onInput={e => setUser(e.target.value)}/>
          <input type="password" placeholder="pin_code" onInput={e => setPassword(e.target.value)} />
          <button onClick={login}>Login</button>
        </div>
      )
    }
  

  return (
    <BrowserRouter>
      <Routes>
          <Route path="/" element={<Home/>}>
          </Route>
          <Route path= "/banktransfer" element={<BankTransfer/>}>
          </Route>
          <Route path= "/transfers" element={<Transfers/>}>
          </Route>
      </Routes>
    </BrowserRouter>
  );
}

export default App;
