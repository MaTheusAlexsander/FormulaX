import json

from flask import Flask, render_template, redirect, request
from flask_socketio import SocketIO, send, emit
from flask_cors import CORS

app = Flask(__name__)
socketio = SocketIO(app)
CORS(app)

estado = {
    "Q1":0,
    "Q2":0
}
change=0
    


@app.route("/")
def rota_inicial():
    return render_template("index.html")
    
@app.route("/upload", methods = ["POST"])
def rota_upload():
    global estado
    estado = request.get_json()
    socketio.emit("atualiza",estado)
    return "200"

@app.route("/download", methods=['GET'])
def rota_download():
    global estado
    if change==1:
        change = 0
        return json.dumps(estado)
    return "1"


@socketio.on("ligarQ1")
def ligar_Q1():
    global estado, change
    change=1
    estado["Q1"] = 1

@socketio.on("desligarQ1")
def desligar_Q1():
    global estado, change
    change=1
    estado["Q1"] = 0
'''
@socketio.on("definirT1")
def definir_T1():
    global estado, change
    change=1
    estado["T1"] = tempo1

@socketio.on("definirT2")
def definir_T2():
    global estado, change
    change=1
    estado["T2"] = tempo1
'''
if __name__ == "__main__":
    app.run("0.0.0.0",port=8080)