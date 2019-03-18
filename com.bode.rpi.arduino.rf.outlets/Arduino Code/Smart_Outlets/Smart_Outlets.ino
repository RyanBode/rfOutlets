/* INFO
 * Author   : Ryan Bode
 * Class    : TSM 435
 * Professor: Bhalerao
 * Project  : "Smart Outlets"
 * Date Due : 12/19/18
 * Last Edit: 12/07/18
 */
// define and initialize boolean variable to store on/off states
// define photosensor pin in case i decide to implement it
// #define pSensor A0

// define pirSensor pin for future implementation
// #define pirSensor 10  

// define boolean array to record device states
boolean device[4]= {false,false,false,false}; 

// define integer value for pirSensor telling whether 0-LOW or 1-HIGH
// int pirValue = 0;

/* void setup()
 * in setup() set pinModes for pins attatched to relay and then begin 
 * serial connection for rx/tx with raspberrypi set pSensor pin to 
 * activate internal 20Kohm pullup resistor in code to eliminate need for 
 * external pullup resistor
 */
void setup()  
{
  for(int i=2; i<10;i++)
   pinMode(i,OUTPUT);
  Serial.begin(9600);
}

/* void loop()
 * Use loop() method to read serial data then trigger a button to be pressed
 * on the remote of the outlets and store whether the device is on or off 
 * into relay array variable in case i want to use that info to update flask page 
 * to display whether or not the appliance or device is on or off
 */
void loop() 
{
  int ser=0;
  if(Serial.available()) //should recieve 1-4 for serial data
    ser=Serial.read()-'0';
  if(ser>0 && ser<5)
    device[ser-1]=relayTrigger(ser-1); // device[ser-1] for off by 1 using array
}

/* boolean relayTrigger(int r)
 * relays will be connected/soldered to button pins on remote to simulate button 
 * presses by setting relay high then low, thus opening and closing connections
 * of the hardware button on remote. The simulated button push will activate 
 * the relay inside the wireless outlets flipping it on and off
 */
boolean relayTrigger(int d)
{
  if(device[d]==true)
  {
    for(int z=0;z<3;z++)
    {
      digitalWrite(d*2+3,HIGH);
      delay(100);
      digitalWrite(d*2+3,LOW);
      delay(100);
    }
    return false;
  }
  else
  {
    for(int z1=0;z1<3;z1++)
    {
      digitalWrite(d*2+2,HIGH);
      delay(100);
      digitalWrite(d*2+2,LOW);
      delay(100);
    }
    return true; 
  }
}

/* boolean lightRelayTrigger(int r)
 * relays will be connected/soldered to button pins on remote to simulate button 
 * presses by setting relay high then low, thus opening and closing connections
 * of the hardware button on remote. The simulated button push will activate 
 * the relay inside the wireless outlets flipping it on and off
 */
boolean lightRelayTrigger(int r)
{
  for(int i=0;i<3;i++)
  {
    digitalWrite(r,HIGH);
    delay(100);
    digitalWrite(r,LOW);
    delay(100); 
  }
  return true;
}
