from bs4 import BeautifulSoup
import requests
import time

url = 'https://knewone.com/discover?page='

def get_page(url, data = None):
    wb_data = requests.get(url)
    soup = BeautifulSoup(wb_data.text, 'lxml')

    # print(soup)

    igs = soup.select('a.cover-inner > img')
    titles_and_links = soup.select('section.content > h4 > a')

    if data==None:
        for img, title_link in zip(igs, titles_and_links):
            data = {'img': img.get('src'), 'title': title_link.get('title'), 'link': title_link.get('href')}
            print(data)


def get_more_pages(start, end):
    for i in range(start, end):
        get_page(url+str(i))
        time.sleep(2)


get_more_pages(1, 10)



