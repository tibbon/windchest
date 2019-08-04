/*
  Use this with an Arduino to send serial data over for processing in the example
  Not what we'll use in the end; but this gives us real serial data we can work with
  Probably way more people "jumping" on it than would normally happen. 

  You'll have to set the input serial device in TD to something like `/dev/cu.usbSerial-14120`
*/

const int num_inputs = 15;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  randomSeed(analogRead(0));
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);
  for(int x = 0; x < num_inputs; x++) {
    Serial.print(random(0,2)); // Why it's 0-2? I dunno
    Serial.print(","); // Comma separates the serial
  }
   
  Serial.print('\n'); // Does a newline
//  Test all buttons pressed
//  Serial.print("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, \n");

}
