# this func should be custom by user


class MessageMaker(object):
    """
    To use this class, U should custom UR own message builder by
    extends this class
    or write a new one
    """
    # pre-process the text
    def __init__(self):
        self.text = ''
        self.message = ''
        self.title = ''

    def input_text(self, text):
        self.text = text
        return self

    def get_message(self):
        # get message
        return self.message

    def get_title(self):
        # get title
        return self.title


class MMTest1(MessageMaker):
    """
    This class is a extend example
    """
    def get_message(self):
        self.message = self.text
        return self.message

    def get_title(self):
        self.title = 'New title'
        return self.title
