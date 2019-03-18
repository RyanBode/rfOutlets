# rfOutlets
# Ryan Bode
# 12/10/18
# Control RF outlets using Raspberry Pi and/or Arduino
This project was just a proof of concept for me.  I wanted to learn more about serial communication between two devices.
I ended up using the built in wifi of the raspberry pi to accept input from a python Flask server.  This then sent integers to the arduino.
The arduino then uses these integers to decide which of 8 relays to flip to actuate buttons on a remote.
