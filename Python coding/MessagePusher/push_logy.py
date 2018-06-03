# the main push logy and control page
from pusher import PusherBuilder
from message import *

# Below is the example func


def send_message():
    m = MMTest1()
    m.input_text('this is the text')
    message = m.get_message()
    title = m.get_title()
    print(message + title)
    p = PusherBuilder()
    p.set_content(message).set_title(title).push()

# send_message()
