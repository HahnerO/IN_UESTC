from bs4 import BeautifulSoup
import requests
import time
import pymongo
from tools import *
from get_ip import get_one_proxy

client = pymongo.MongoClient('localhost', 27017)
items = client['items']
url_list = items['url_list']
item_info = items['item_info']
# no_more_in_this_cate = False

# # crawler1

def get_items_from(channel, pages, who_sells = 0):
    item_list = '{}/pn{}/'.format(channel, str(pages))
    wb_data = requests.get(item_list)
    # set sleep time
    # if cn <= 6000:
    #     time.sleep(2)
    # if 6000 <= cn <= 12000:
    #     time.sleep(4)
    # if 12000 <= cn <= 30000:
    time.sleep(1)

    soup = BeautifulSoup(wb_data.text, 'lxml')
    if soup.find('td', 't'):
        for link in soup.select('td.t > a.t'):
            item_link = link.get('href').split('?')[0]
            url_list.insert_one({'url': item_link})
            print(item_link)
    else:
        # global no_more_in_this_cate
        # no_more_in_this_cate = True
        pass

# crawler 2

def get_item_info(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36'
    }
    wb_data = requests.get(url)
    time.sleep(3)
    soup = BeautifulSoup(wb_data.text, 'lxml')
    # find if it is 404
    if is_404(soup):
        return
    titles = soup.select('h1.info_titile')
    if is_exsisting(titles):
        title = titles[0].text
    else:
        title = None
    # get the elements
    now_prices = soup.select('span.price_now > i')
    ori_prices = soup.select('b.price_ori')
    if is_exsisting(now_prices):
        now_price = now_prices[0].text
    else:
        now_price = None
    if is_exsisting(ori_prices):
        old_price = ori_prices[0].text
    else:
        old_price = None

    # views = soup.select('span.look_time')
    # if tools.is_exsisting(views):
    #     view = views[0].text
    # else:
    #     view = None

    areas = soup.select('div.palce_li > span > i')
    if is_exsisting(areas):
        true_area = areas[0].text
        city = true_area.split('-')[0]
        area = true_area.split('-')[-1]
    else:
        city = None
        area = None

    # create a dictionary
    data = {
        'title': title,
        'now_price': now_price,
        'old_price': old_price,
        'city': city,
        'area': area,
        # 'view': view
    }
    print(data)
    # insert now
    item_info.insert_one(data)



# get_item_info('http://zhuanzhuan.58.com/detail/979292429981859852z.shtml')
# get_items_from('http://cd.58.com//ershoujiaju/', 2)

# for url in url_list.find():
    # if 'jump' in url.get('url'):
    #     url_list.delete_one({'_id': url.get('_id')})
    #     # print(url)
    # print(url)

# def pre_modify_item_info():
#     for item in item_info.find():
#         title = item.get('title')
#         area = item.get('area')
#         city = item.get('city')
#
#         old_price = item.get('old_price')
#         if title is None or title.strip() == '':
#             item_info.delete_one({'_id': item.get('_id')})
#         else:
#             if area is None or area.strip() == '' or area == city or city in area:
#                 item_info.update_one({'_id': item.get('_id')}, {'$set': {'area': '不明'}})
#             if old_price is None:
#                 item_info.update_one({'_id': item.get('_id')}, {'$set': {'old_price': '不明'}})
#     return

pre_modify_item_info()

# for item in item_info.find():
#     print(item)



