# https://api.pushover.net/1/messages.json?token=av8mamcyw45pbf15cu6fshsgcuctgt&user=uwiikjy4xotc8b3spct82kc9suno
# https://api.github.com/search/repositories?q=topic:opendaylight

# get_info_list -- push_it
import requests
from datetime import datetime


def get_info_list():
    api = 'https://api.github.com/search/repositories?q='
    query = 'topic:crawler+language:python+' + 'created:' + str(datetime.now()).split()[0]
    # query = 'topic:crawler+language:python+' + 'created:' + '2018-02-11'

    full_url = api + query
    print(full_url)
    res = requests.get(full_url).json()
    return res['items']


def make_message(repo_info):
    title = repo_info['name']
    url = repo_info['html_url']
    message = repo_info['description']
    token = 'av8mamcyw45pbf15cu6fshsgcuctgt'
    user = ''
    api = 'https://api.pushover.net/1/messages.json?'
    template = 'token={token}&user={user}&message={message}&title={title}&url={url}'
    query = template.format(
        token=token,
        user=user,
        message=message,
        title=title,
        url=url
    )
    full_url = api + query
    return full_url


def push_it(message):
    requests.post(message)
    print('Done this one')


def run():
    info_list = get_info_list()
    if not info_list:
        print('No push now')
        exit(1)
    for info in info_list:
        message = make_message(info)
        push_it(message)


run()
