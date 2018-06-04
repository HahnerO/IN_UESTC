# !/usr/bin/python
# -*- coding: utf-8 -*-
__author__ = 'Hahn(HahnerO@163.com)'

# This class should be custom by user


class MessageMaker(object):
    """
    To use this class, U should custom UR own message builder by
    extends this class
    or write a new one
    """
    # pre-process the text
    def __init__(self):
        self.text = ''
        self.content = ''
        self.title = ''

    def input_text(self, text):
        self.text = text
        return self

    def get_content(self):
        # get content
        return self.content

    def get_title(self):
        # get title
        return self.title
