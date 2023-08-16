int MQ2 = A0; // Define MQ2 gas sensor pin at A0
int val = 0; // declare variable
int buzzer = 3; // Define the buzzer pin at D3
void setup ()
{
Serial.begin (9600); // Set the serial port baud rate to 9600
pinMode (MQ2, INPUT); // MQ2 gas sensor as input
pinMode (buzzer, OUTPUT); // Set the digital IO pin mode for output
pinMode (7, OUTPUT); //define D7 pin as output
pinMode (6, OUTPUT); //define  D6 pin as output
}
void loop ()
{
val = analogRead (MQ2); // Read the voltage value of A0 port and assign it to val
Serial.println (val); // Serial port sends val value
if (val> 80)
{
   digitalWrite (7, LOW);
   digitalWrite (6, HIGH); // Reverse rotation of the fan motor
   tone (buzzer, 589);
   delay(300);
}
else
{
  digitalWrite (7, LOW);
  digitalWrite (6, LOW); // The motor stops rotating
  noTone (buzzer);
}
}
