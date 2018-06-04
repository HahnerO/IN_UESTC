# !/usr/bin/python
# -*- coding: utf-8 -*-
__author__ = 'Hahn(HahnerO@163.com)'

import requests

sdr_rsv_me = ''

sdr_group = ''
rsv_devices = ''


# the class below is message pusher
class PusherBuilder(object):
    """
    To use this class, U can just instancing with params or use setter
    U can get and check the params with getter
    When U think it's OK to push, then just push it!
    """
    def __init__(self,
                 title='',
                 content='',
                 url='',
                 priority=0,
                 source=sdr_group,
                 receiver=rsv_devices):
        self.title = title
        self.content = content
        self.url = url
        self.priority = priority
        self.source = source
        self.receiver = receiver

    def set_title(self, title):
        self.title = title
        return self

    def get_title(self):
        print(self.title)
        return self.title

    def set_content(self, content):
        self.content = content
        return self

    def get_content(self):
        print(self.content)
        return self.content

    def set_url(self, url):
        self.url = url
        return self

    def get_url(self):
        print(self.url)
        return self.url

    def set_priority(self, priority):
        while True:
            if priority != 0 and priority != 1:
                print('Wrong priority setting, please input again!'
                      '0 or None for normal, 1 for urgent\n')
                priority = input()
                continue
            else:
                break
        self.priority = priority
        return self

    def get_priority(self):
        if self.priority == 0:
            print('Normal')
        else:
            print('Urgent')
        return self.priority

    def set_source(self, source):
        self.source = source
        return self

    def get_source(self):
        print(self.source)
        return self.source

    def set_receiver(self, receiver):
        self.receiver = receiver
        return self

    def get_receiver(self):
        print(self.receiver)
        return self.receiver

    def push(self):
        requests.post("https://api.alertover.com/v1/alert",
                      data={"source": self.source,
                            "receiver": self.receiver,
                            "content": self.content,
                            "title": self.title,
                            'url': self.url,
                            'priority': self.priority
                            })
        print('pushed')

# the func bellow is the authority way for U to push a message
# def push(title, message, url='', sender=sdr_group, receiver=rsv_devs):
#     requests.post("https://api.alertover.com/v1/alert",
#                   data={"source": sender,
#                         "receiver": receiver,
#                         "content": message,
#                         "title": title,
#                         'url': url,
#                         'priority': priority
#                         })


# Actually the func below cannot be used,it just shows U how to push
def push_to_me():
    requests.post("https://api.alertover.com/v1/alert",
                  data={"source": 'Alertover',
                        "receiver": sdr_rsv_me,
                        "content": "test2",
                        "title": "hello"
                        })


# below is the way to push

# pusher = PusherBuilder('test3', '1111', 'www.baidu.com', 1)
# push_to_me()
# p = PusherBuilder()
# p.set_title('test_class').set_content('emmmmmmmm').set_url('www.baidu.com').set_priority(0).push()
