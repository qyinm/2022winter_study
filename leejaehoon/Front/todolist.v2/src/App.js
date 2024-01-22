import logo from './logo.svg';
import './App.css';
import { useState } from 'react';

function App() {

    let [list, setList] = useState([]);
    let [data, setData] = useState('');
    const onChange = e => {
        setData(e.target.value);
    }

    return (
    <div className="App">
      <h1>ToDoList</h1>

      <input className="list" type="text" onChange={onChange} value={data}/>
        <button onClick={()=>{
            setList([...list, data])
            data = ''
        }}>+</button>

        <ul>
            {list.map(l =>
            {return <li>{l} <button>x</button></li>})}
        </ul>


    </div>
  );
}

export default App;
