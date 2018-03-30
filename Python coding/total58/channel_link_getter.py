from bs4 import BeautifulSoup
import requests
import pymongo


start_url = 'http://cd.58.com/sale.shtml'
host_url = 'http://cd.58.com/'

client = pymongo.MongoClient('localhost', 27017)
items = client['items']
channel_urls = items['channel_urls']

channel_list = []
# channel_list = '''
# http://cd.58.com//shouji/
# http://cd.58.com//tongxunyw/
# http://cd.58.com//danche/
# http://cd.58.com//diandongche/
# http://cd.58.com//diannao/
# http://cd.58.com//shuma/
# http://cd.58.com//jiadian/
# http://cd.58.com//ershoujiaju/
# http://cd.58.com//yingyou/
# http://cd.58.com//fushi/
# http://cd.58.com//meirong/
# http://cd.58.com//yishu/
# http://cd.58.com//tushu/
# http://cd.58.com//wenti/
# http://cd.58.com//bangong/
# http://cd.58.com//shebei.shtml
# http://cd.58.com//chengren/
# '''

def get_channel_urls():
    wb_data = requests.get(start_url)
    soup = BeautifulSoup(wb_data.text, 'lxml')
    links = soup.select('ul > li.ym-tab > span > a')
    for link in links:
        suffix = link.get('href')
        if suffix:
            page_url = host_url + suffix
            print(page_url)
            channel_urls.insert_one({'url': page_url})
            channel_list.append(str(page_url))
        else:
            pass
    # print(channel_list)


# get_channel_urls()
