# coke_piano
An arduino project using capacitive sensors and .py midi script. Designed on Arduino Uno and using Python 2.7.

# Description
The arduino script initializes 16 capacitive sensors, which are connected to separate conductive objects (e.g. tin cans). It senses when one of those objects has been touched and sends an integer through serial connection to the .py script, which takes the recieved number and plays the corresponding midi key note.

# Requirements
- Arduino board (preferrably Uno)
- Arduino IDE with the Capacitive library installed (http://www.arduino.org/learning/reference/Capacitive)
- 16 conductive objects
- 16 1M resistors
- wiring
- Python 2.7 with the following installed libraries:
  . pySerial (https://pyserial.readthedocs.io/en/latest/pyserial.html)
  . mido (http://mido.readthedocs.io/en/latest/#)
