from flask import Flask
from flask import render_template                                        
import serial
import os

app = Flask(__name__)
ser = serial.Serial("/dev/ttyACM0",9600)
t='template.html'

@app.route('/')
def start():
    return render_template(t,title='Home')

@app.route('/light1Toggle')
def toggleLight1():
    ser.write(bytes(1,'UTF-8'))	
    return render_template(t,title='Light 1 On')

@app.route('/light2Toggle')
def toggleLight2():
    ser.write(bytes(2,'UTF-8'))	
    return render_template(t,title='Light 2 On')

@app.route('/light3Toggle')
def toggleLight3():
    ser.write(bytes(3,'UTF-8'))
    return render_template(t,title='Light 3 Off')
    
@app.route('/light4Toggle')
def toggleLight4():
    ser.write(bytes(4,'UTF-8'))    
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