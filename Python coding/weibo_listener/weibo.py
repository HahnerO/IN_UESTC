from selenium import webdriver
import time

url = 'https://weibo.com/1371731565/GjuO2dtWG?from=page_1005051371731565_profile&wvr=6&mod=weibotime&type=comment'

def start_chrome():
    driver = webdriver.Chrome(executable_path='./chromedriver')
    driver.start_client()
    return driver

def find_info():
    # css_selector
    sel = 'span > span.line.S_line1 > span > em:nth-child(2)'
    elements = driver.find_elements_by_css_selector(sel)
    return [el.text for el in elements[1:]]

def info_syntax_change(old_info):
    info = []
    for _ in old_info:
        info.append(int(_))
    return info

while True:
    driver = start_chrome()
    driver.get(url)
    time.sleep(5)
    info = info_syntax_change(find_info())
    time.sleep(1)
    print(info)
    repo = info[0]
    comm = info[1]
    like = info[2]
    if repo > 1000:
        print('The weibo U listening has ' + str(repo) + ' repost')
        break
    else:
        print('Nothing happened')

    time.sleep(5 * 60)


print('Done')

