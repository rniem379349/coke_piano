# -*- coding: cp1250 -*-
# Coke piano .py script
# Date: 12.03.2017
# Creators:
#     - Piotr Dec
#     - Robert Niemiec
#     - Marcin Ściborowski

import serial
import mido
import sys


class Node:
    def __init__(self, val = None, next_node = None, prev_node = None):
        self.val = val
        self.prev_node = prev_node
        self.next_node = next_node


class Stack:
    def __init__(self):
        self.len = 0
        self.tail = None


    def is_empty(self):
        return self.len == 0


    def push(self, val):
        prev_tail = self.tail
        self.tail = Node(val)

        if not self.is_empty():
            self.tail.prev_node = prev_tail
            prev_tail.next_node = self.tail
        self.len += 1


    def pop(self):
        if self.is_empty:
            pass
        else:
            popped_val = self.tail.val
            self.tail = self.tail.prev_node
            self.len -= 1

    def top(self):
        if self.is_empty():
            raise ValueError("The Stack is empty")
        else:
            return self.tail.val


if __name__ == "__main__":
    # initialize mido lib for output
    out = mido.open_output()
    # initialize stack for input
    stack = Stack()
    # initialize serial connection to the arduino port
    try:
        serial_port = "com{}".format(sys.argv[1])
    except IndexError:
        serial_port = "com3"
    with serial.Serial(serial_port, 19200) as ser:
        while(1):
            val = ser.readline()
            print "val: ", val
            val = int(val)
            stack.push(val)
            stack_note = stack.top()

            try:
                out.send(mido.Message('note_on', note=stack_note+60, velocity=120, channel=0))
                stack.pop()
            except TypeError or ValueError:
                pass
