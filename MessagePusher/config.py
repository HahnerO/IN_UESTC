# !/usr/bin/python
# -*- coding: utf-8 -*-

# please do not change the 2 params below
NORMAL = 0
URGENT = 1

# set this param to open/close log
# or u can turn it up/on by using inner method
LOG_ON = False

# 2 param below must be filled even if U don't set here
# but set here can reduce some meaningless actions before push
sender_device = ''
receiver_devices = ''

# The rest of params are default params if U don't set later during pushing
message_title = ''
message_content = ''
extra_url = ''
message_priority = NORMAL
