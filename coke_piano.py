# Coke piano .py script
# Date: 12.03.2017
# Creators:
#     - Piotr Dec
#     - Robert Niemiec
#     - Marcin Ściborowski

import serial
import mido
from msvcrt import getch
import time

# initialize mido lib for output
out = mido.open_output()

# define the keys whose codes correspond to the notes in the mido lib
keys = ["a", "w", "s", "e", "d", "f", "t", "g", "y", "h", "u", "j", "k", "o", "l", "p", ";"]
notes = {}
# fill the dictionary with the corresponding keycodes
for i in xrange(60, 77):
    notes[ord(keys[i-60])] = i


msg = mido.Message('note_on', note=64, velocity=120, time=1, channel=0)
msg2 = mido.Message('note_on', note=44, velocity=120, time=1, channel=1)

def run():
    for i in xrange(20, 100):
        out.send(mido.Message('note_on', note=i, velocity=120, time=1, channel=1))
        time.sleep(0.1)

def suprise():
    melody = ";p;p;jlkh adhj dyjk d;p;p;jlkh adhj dkjh"
    for j in melody:
        try:
            out.send(mido.Message('note_on', note=notes.get(ord(j)), velocity=120, time=1, channel=1))
            time.sleep(0.3)
        except TypeError:
            time.sleep(0.6)

# initialize serial connection to the arduino port
serial_port = "com3"
with serial.Serial(serial_port, 19200) as ser:
    while(1):
        val = ser.readline()
        print "val: ", val
        val = int(val)

        try:
            out.send(mido.Message('note_on', note=notes.get(ord(keys[val])), velocity=120, time=1, channel=1))
        except TypeError:
            pass

        # key = ord(getch())
        # print "key: ", key
        # if key == 27: #ESC
        #     break
        # if key == 13: #Enter
        #     out.send(msg)
        #     out.send(msg2)
        #     time.sleep(2)
        # elif key == 224: #Special keys (arrows, f keys, ins, del, etc.)
        #     key = ord(getch())
        #     if key == 80: #Down arrow
        #         run()
        #     elif key == 72: #Up arrow
        #         suprise()
        # else:
        # # handling the serial input and playing tones when the value is in range
            # try:
            #     out.send(mido.Message('note_on', note=notes[val], velocity=120, time=1, channel=1))
            # except TypeError:
            #     pass
