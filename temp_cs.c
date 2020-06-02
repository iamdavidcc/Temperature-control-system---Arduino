// Statement of constants and pins
const int fan=13;           // fan constant
int temperaturePin = 0;     // temperature sensor constant
float diferencia;           // calculation constant
const int rojo=3;           // RGB red pin constant
const int verde=5;          // RGB green pin constant
const int azul=6;           // RGB blue pin constant

void setup() {
  Serial.begin(9600);   //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
  
  // pin initialization
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(fan, OUTPUT);
}

void loop() {
  // we save in the 'reading' constant the value of the temperature sensor pin reading
  int reading = analogRead(temperaturePin);
  // We perform the conversion of the reading to degrees centigrade
  float voltage = reading * 5.0;
  voltage/=1024.0;
  // we save the conversion in the variable 'temperature
  float temperature=(voltage-0.5)*100;
  // we show on the screen the value that has 'temperature' at each moment 
  Serial.print(temperature);
  Serial.println("");
  // Control of the RGB LED by means of temperature variation:
  if(temperature<20){
    analogWrite(rojo,0);        // color rojo
    analogWrite(verde,255);     // color verde
    analogWrite(azul,0);        // color azul
  }else if(temperature>=20 && temperature<27){
    // yellow colour
    analogWrite(3,(reading-120)*6.15);     
    analogWrite(5,255-(reading-120)*5.51);     
    analogWrite(6,0);   
  }
  if(temperature>=27 && temperature<33){
    // orange colour
    analogWrite(3,230+(reading-160)*0.73);     
    analogWrite(5,50-(reading-160)*0.88);     
    analogWrite(6,0);   
  }
  if(temperature>=33 && temperature<40){
    analogWrite(3,255);     
    analogWrite(5,20-(reading-170)*0.51);     
    analogWrite(6,0);   
  }else if(temperature>=40){
    // red colour - emergency
    analogWrite(3,255);     
    analogWrite(5,0);     
    analogWrite(6,0);   
  }
  // Fan activation
  // on when temperature is higher than 25ºC
  if(temperature>=25){
    digitalWrite(fan, HIGH);
  }else if (temperature<23){
    // will be ON till temperature decrease to 23ºC or lower
    digitalWrite(fan, LOW);
  }
}
