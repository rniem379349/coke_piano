# Coke piano .py script
# Date: 12.03.2017
# Creators:
#     - Piotr Dec
#     - Robert Niemiec
#     - Marcin Ściborowski

import serial
import mido

if __name__ == "__main__":
    # initialize mido lib for output
    out = mido.open_output()

    # initialize serial connection to the arduino port
    serial_port = "com3"
    with serial.Serial(serial_port, 19200) as ser:
        while(1):
            val = ser.readline()
            print "val: ", val
            val = int(val)

            try:
                out.send(mido.Message('note_on', note=val+60, velocity=120, channel=0))
            except TypeError:
                pass