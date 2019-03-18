from flask import Flask
from flask import render_template                                        
import serial
import os

app = Flask(__name__)
ser = serial.Serial("/dev/ttyACM0",9600)
data = '0'
t='template.html'
pinValues = [0,0,0,0]

@app.route('/')
def start():
    return render_template(t,title='Home')

@app.route('/light1Toggle')
def toggleLight1():
    data = '1'
    ser.write(bytes(data,'UTF-8'))	
    return render_template(t,title='Light 1 On')

@app.route('/light2Toggle')
def toggleLight2():
    data = '2'
    ser.write(bytes(data,'UTF-8'))	
    return render_template(t,title='Light 2 On')

@app.route('/light3Toggle')
def toggleLight3():
    data = '3'
    ser.write(bytes(data,'UTF-8'))
    return render_template(t,title='Light 3 Off')
    
@app.route('/light4Toggle')
def toggleLight4():
    data = '4'
    ser.write(bytes(data,'UTF-8'))    
    return render_template(t,title='Light 4 Off')

@app.route('/reboot')
def reboot():
    os.system("sudo reboot")

@app.route('/poweroff')
def powerOff():
    os.system("sudo poweroff")

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0', port=8080)  
