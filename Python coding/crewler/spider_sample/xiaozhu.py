from bs4 import BeautifulSoup
import requests
import time

urls = ['http://bj.xiaozhu.com/search-duanzufang-p{}-0/'.format(str(i)) for i in range(1,4)]

def get_xiaozhu_info(url):
    web = requests.get(url)
    soup = BeautifulSoup(web.text, 'lxml')
    time.sleep(2)
    titles = soup.select('div.result_intro > a > span.result_title')
    prices = soup.select('span.result_price')
    comments = soup.select('span.commenthref')
    for title,price,comment in zip(titles,prices,comments):
        data = {
            'title':title.get_text(),
            'price':price.get_text(),
            'comment':comment.get_text().lstrip('\n                     - ').rstrip(),
        }
        print(data)


for url in urls:
    get_xiaozhu_info(url)

