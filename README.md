# Temperature Control System
Design and implementation of a temperature control system with an Arduino UNO board

* * *
## The following components were used for the development of this control system:
* Arduino UNO
* Temperature sensor
* relay
* fan
* RGB led
***
## Arduino configuration:
* Analog input A0
  Used for the temperature sensor input, through which we will obtain the system temperature.
* Digital inputs (PWM) 3, 5 and 6 
  Used for the rgb led, through which, varying its values between 0 and 255 we will obtain different desired colors.
* Digital input 13 
  Used to activate the fan. First it will activate the BJT PNP transistor and then the relay and the fan.
***
## System Diagram
![Diagrama](https://iamdavidcasero.files.wordpress.com/2020/06/untitled-sketch_bb.jpg?w=2048)
## Operation
The system works as follows:
The operation of the cooling system is very simple. The temperature sensor indicates the ambient temperature or the temperature at which the system is operating.

When the temperature exceeds an imposed limit, in this case 25 ºC, the output is activated, activating the BJT PNP transistor, which then activates the relay and makes it supply voltage to the fan that will start moving and cooling the system.

The fan will turn off when the system temperature is 23 ºC. On the other hand, the RGB led will indicate, with different colours, the status or temperature of the system.

When the temperature is less than 20 ºC the led will light up in green. As the temperature increases, the led will change colour, from green to yellow and then to orange, until it reaches the limit of 40 ºC, from which the led turns to red indicating the danger that such a temperature represents.
