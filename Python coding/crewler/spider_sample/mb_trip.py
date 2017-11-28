from bs4 import BeautifulSoup
import requests

headers = {
    'User-Agent':'Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1'
}

url = 'http://www.tripadvisor.cn/Attractions-g294262-Activities-Singapore.html'

mb_date = requests.get(url,headers=headers)
soup = BeautifulSoup(mb_date.text, 'lxml')
imgs = soup.select('div.thumb.thumbLLR.soThumb > img')
for i in imgs:
    print(i.get('src'))
