import requests
from bs4 import BeautifulSoup

def get_item_info(url):
    wb_data = requests.get(url)
    soup = BeautifulSoup(wb_data.text, 'lxml')

    titles = soup.select('h1.info_titile')
    title = titles[0].text

    now_prices = soup.select('span.price_now > i')
    # ori_prices = soup.select('b.price_ori')
    now_price = now_prices[0].text
    # ori_price = ori_prices[0].text

    views = soup.select('span.look_time')
    view = views[0].text

    areas = soup.select('div.palce_li > span > i')
    area = areas[0].text

    cates = soup.select('span.crb_i > a')
    cate = cates[-1].text.strip()

    data = {
        'title': title,
        'now_price': now_price,
        # 'ori_price': ori_price,
        'view': view,
        'area': area,
        'cate': cate
    }
    return data

def get_gamebox(urls):
    for url in urls:
        wb_data = requests.get(url)
        soup = BeautifulSoup(wb_data.text, 'lxml')
        item_urls = soup.select('td.t > a.t')
        game_datas = []

        for item_url in item_urls:
            link = item_url.get('href')
            if 'zhuanzhuan' in link:
                game_datas.append(get_item_info(link))

    return game_datas


def gamebox_range(start=1, end=1):
    start = start
    end = end
    urls = []
    url = 'http://cd.58.com/youxiji/pn'
    for i in range(start, end + 1):
        urls.append(url + str(i) + '/')
    return urls

page_range = gamebox_range(1, 2)
datas = get_gamebox(page_range)
for data in datas:
    print(data)

