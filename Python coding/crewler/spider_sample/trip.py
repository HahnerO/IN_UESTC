from bs4 import BeautifulSoup
import requests

headers = {
    ''
}

def get_attractions(url,date=None):
    url = 'http://www.tripadvisor.cn/Attractions-g294262-Activities-Singapore.html'
    wb_date = requests.get(url)
    soup = BeautifulSoup(wb_date.text, 'lxml')
    titles = soup.select('div.property_title > a')
    imgs = soup.select('img[width="160"]')
    cates = soup.select('div.p13n_reasoning_v2')
    for title,img,cate in zip(titles,imgs,cates):
        data = {
            'title':title.get_text(),
            'img':img.get('src'),
            'cate':list(cate.stripped_strings),
        }
        print(data)


