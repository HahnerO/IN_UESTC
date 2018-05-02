# !/usr/bin/python
# -*- coding: utf-8 -*-
__author__ = 'Hahn/HahnerO@163.com'

from socket import *
import logging

# where your pages are
page_file = 'pages/'

# get log
logging.basicConfig(level=logging.DEBUG,
                format='%(asctime)s %(filename)s[line:%(lineno)d] %(levelname)s %(message)s',
                datefmt='%a, %d %b %Y %H:%M:%S',
                filename='myWebServer.log',
                filemode='w')

# basic config
host = 'localhost'
port = 8888
head = '''HTTP/1.1 200 OK

    '''

def web_server_main():
    # Make socket
    s = socket(AF_INET, SOCK_STREAM)
    s.bind((host, port))

    logging.info('Socket established, now listening to the connection request.')

    s.listen(5)

    # Different types of counters for the future static works if needed
    total_work_times = 0
    perfect_work_times = 0
    error_work_times = 0
    wrong_work_times = 0

    while True:
        sock, address = s.accept()

        logging.info('Get ONE, now begin to work ')

        msg = sock.recv(1024).decode()

        logging.info('Listened to the User from (ip: ' + address[0] + ', port: ' + str(address[-1]) + ')')
        logging.info('And the msg is ' + msg)

        # before getting path, it should be decode to type string first and then remove the block
        raw_path = msg.split('HTTP')[0][5:].strip()
        if '.html' in raw_path:
            path = page_file + raw_path
        else:
            path = page_file + raw_path + '.html'

        logging.info('The page which User need is in path : ' + path)

        # It's still OK if you remove the next line, I'm just making sure the program won't go wrong
        content = ''

        # the main part of dealing with the url
        if raw_path:
            content = get_page_content(path, msg)
        else:
            content = get_default_page_content(msg)

        logging.debug('Now got the content, sending to the User.')

        sock.sendall(content.encode())

        logging.debug('Send over, perfect circle!')

        sock.close()

        # for the future designer
        # total_work_times += 1
        # perfect_work_times += 1

        logging.info('ONE socket has been DONE, now get the next one.')

def get_page_content(path, msg):
    try:
        with open(path, 'rb') as reader:
            content = head + reader.read().decode()
    except IOError:
        logging.debug('Cannot find the file, now getting 404 page!')
        content = get_404_page_content(msg)
    if content.encode():
        logging.info('No read error')
    else:
        content = get_read_error_page_content(msg)
    return content

def get_default_page_content(msg):
    try:
        with open(page_file + 'base.html', 'rb') as reader:
            content = head + reader.read().decode().format(msg=msg)
    except IOError:
        content = get_read_error_page_content(msg)
    return content

def get_404_page_content(msg):
    try:
        with open(page_file + '404.html', 'rb') as reader:
            content = head + reader.read().decode().format(msg=msg)
    except IOError:
        content = get_read_error_page_content(msg)
    return content

def get_read_error_page_content(msg):
    logging.warning('Read ERROR!!!')
    with open(page_file + 'read_error.html', 'rb') as reader:
         content = head + reader.read().decode().format(msg=msg)
    return content

web_server_main()
