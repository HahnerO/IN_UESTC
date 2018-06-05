# !/usr/bin/python
# -*- coding: utf-8 -*-

# The main push logy and control page

from pusher import PusherBuilder
from message import MessageMaker

# This is where U write UR code logy and run


def send_message():
    p = PusherBuilder()
    p.log_on()
    p.set_title('test_class').set_content('hahahahaha').set_url('www.baidu.com').set_priority(0)
    # p.set_sender('s-158d9935-8363-4b13-bdab-70bb7db8')
    p.push()


send_message()
