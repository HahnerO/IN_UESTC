# !/usr/bin/python
# -*- coding: utf-8 -*-
__author__ = 'Hahn(HahnerO@163.com)'

import requests
import logging
from config import *


# the class below is message pusher
class PusherBuilder(object):
    """
    To use this class, U can just instancing with params or use setter
    U can get and check the params with getter
    Also it has a logger part, U can log any of UR message
    When U think it's OK to push, then just push it!
    """
    def __init__(self,
                 title=message_title,
                 content=message_content,
                 url=extra_url,
                 priority=message_priority,
                 sender=sender_device,
                 receiver=receiver_devices):
        self.title = title
        self.content = content
        self.url = url
        self.priority = priority
        self.sender = sender
        self.receiver = receiver
        self.logger = None
        self.log_is_on = False
        self.log_mode_info = None
        self.log_mode_debug = None
        self.log_mode_warning = None
        # check the config to see if logger is on
        if LOG_ON:
            self.log_on()

    # normal getter and setter
    def set_title(self, title):
        self.check_and_log('Set title: ' + title, log_mode=self.log_mode_debug)
        self.title = title
        return self

    def get_title(self):
        return self.title

    def set_content(self, content):
        self.check_and_log('Set content: ' + content, log_mode=self.log_mode_debug)
        self.content = content
        return self

    def get_content(self):
        return self.content

    def set_url(self, url):
        self.check_and_log('Set url: ' + url, log_mode=self.log_mode_debug)
        self.url = url
        return self

    def get_url(self):
        return self.url

    def set_priority(self, priority):
        while True:
            if priority == NORMAL:
                self.check_and_log('Set priority: NORMAL', log_mode=self.log_mode_debug)
                break
            if priority == URGENT:
                self.check_and_log('Set priority: URGENT', log_mode=self.log_mode_debug)
                break
            else:
                print('Wrong priority setting, please input again!'
                      '0 or None for normal, 1 for urgent\n')
                priority = input()
                continue

        self.priority = priority
        return self

    def get_priority(self):
        if self.priority == 0:
            print('Normal')
        else:
            print('Urgent')
        return self.priority

    def set_sender(self, sender):
        self.check_and_log('Set senderID: ' + sender, log_mode=self.log_mode_debug)
        self.sender = sender
        return self

    def get_source(self):
        return self.sender

    def set_receiver(self, receiver):
        self.check_and_log('Set receiverID: ' + receiver, log_mode=self.log_mode_debug)
        self.receiver = receiver
        return self

    def get_receiver(self):
        return self.receiver

    # logger part
    def log_on(self):
        # you can also custom your own logger by editing code below
        # logging.basicConfig(filename='./push_logger.log')
        # self.logger = logging.getLogger('push_logger')
        # self.logger.setLevel(logging.DEBUG)
        # handler = logging.StreamHandler()
        # handler.setLevel(logging.DEBUG)
        # formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
        # handler.setFormatter(formatter)
        # self.logger.addHandler(handler)

        logging.basicConfig(
            filename='./push_logger.log',
            filemode='a',
            format='%(asctime)s - %(levelname)s - %(message)s',
            level=logging.DEBUG
        )
        self.logger = logging.getLogger("pushLogger")
        self.log_is_on = True
        self.log_mode_info = 0
        self.log_mode_debug = 1
        self.log_mode_warning = 2
        return self

    def log_off(self):
        self.log_is_on = False
        self.logger = None
        self.log_mode_info = None
        self.log_mode_debug = None
        self.log_mode_warning = None
        return self

    def check_and_log(self, message_to_log, log_mode=0):
        # if log is on
        if not self.log_is_on:
            return self
        # log is on but there is no logger
        if not self.logger:
            print('Logger has been removed, please turn it on by using func log_on()')
            print('Or you can turn it off by using func log_off()')
            return self
        # now logging
        else:
            if log_mode == self.log_mode_info:
                self.logger.info(message_to_log)
                return self
            if log_mode == self.log_mode_debug:
                self.logger.debug(message_to_log)
                return self
            if log_mode == self.log_mode_warning:
                self.logger.warn(message_to_log)
                return self
            else:
                print('U may changed the log mode value!!!')
                print('Please turn it on again by using func log_on()')
                return self

    # push part
    def is_ready2push(self):
        if self.sender == '':
            self.check_and_log('Try to push, but no sender', log_mode=self.log_mode_warning)
            print('No sender, please set it by using func set_sender()')
            return False
        if self.receiver == '':
            self.check_and_log('Try to push, but no receiver', log_mode=self.log_mode_warning)
            print('No receiver, please set it by using func set_receiver()')
            return False
        if self.content == '':
            self.check_and_log('Try to push, but no content', log_mode=self.log_mode_warning)
            print('No content, please set it by using func set_content()')
            return False
        if self.url == '' and self.title == '':
            self.check_and_log('No URL and TITLE in this push', log_mode=self.log_mode_info)
            print('Push is ready but with no title and url')
            return True
        if self.url == '' and self.title != '':
            self.check_and_log('No URL in this push', log_mode=self.log_mode_info)
            print('Push is ready but with no url')
            return True
        if self.url != '' and self.title == '':
            self.check_and_log('No TITLE in this push', log_mode=self.log_mode_info)
            print('Push is ready but with no title')
            return True
        else:
            self.check_and_log('This push is with every params', log_mode=self.log_mode_info)
            print('Push is ready!')

    def push(self):
        if not self.is_ready2push():
            return
        self.check_and_log('Message is : '' ' +
                           self.title + ':' +
                           self.content + ' '' priority is ' +
                           self.priority + ' More  to ' +
                           self.url, log_mode=self.log_mode_debug
                           )
        self.check_and_log('From sender: ' +
                           self.sender + ' to receiver: ' +
                           self.receiver, log_mode=self.log_mode_debug
                           )
        requests.post("https://api.alertover.com/v1/alert",
                      data={"source": self.sender,
                            "receiver": self.receiver,
                            "content": self.content,
                            "title": self.title,
                            'url': self.url,
                            'priority': self.priority
                            })
        self.check_and_log('Push successfully!', log_mode=self.log_mode_info)
        print('Message has been pushed')
        return


# the func below is the authority way for U to push a message
# def push(title, message, url='', sender=sdr_group, receiver=rsv_devs):
#     requests.post("https://api.alertover.com/v1/alert",
#                   data={"source": sender,
#                         "receiver": receiver,
#                         "content": message,
#                         "title": title,
#                         'url': url,
#                         'priority': priority
#                         })


# below is the way to push, don't forget set your own sender and receiver!

# p = PusherBuilder()
# p.set_title('test_class').set_content('emmmmmmmm').set_url('www.baidu.com').set_priority(0).push()
