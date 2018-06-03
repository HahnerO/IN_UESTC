# -*- coding: UTF-8 -*-

# https://weibo.com/misswar3
# ?is_ori=1&key_word=&start_time=2018-03-01&end_time=2018-06-02
# &is_search=1&is_searchadv=1#_0

# https://weibo.com/misswar3
# ?pids=Pl_Official_MyProfileFeed__21
# &is_search=1&visible=0&is_ori=1
# &end_time=2018-06-02&is_tag=0
# &profile_ftype=1&page=2#feedtop

# start_chrome -- input_data -- scroll_down -- find_card_info -- save -- find_next -- loop

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from csv import writer as csv_w
from csv import reader as csv_r
import os

base_url = 'https://weibo.com/'

def start_chrome():
    driver = webdriver.Chrome(executable_path='./chromedriver')
    driver.start_client()
    return driver

def get_query(start_time, end_time):
    raw_query = '?is_ori=1&key_word=&start_time={start_time}&end_time={end_time}&is_search=1&is_searchadv=1#_0'
    query = raw_query.format(
        start_time=start_time,
        end_time=end_time
    )
    # print(query)
    return query

def scroll_down(times, sleep_time):
    html = drver.find_element_by_tag_name('html')
    # form -- input
    for _ in range(times):
        print(_)
        html.send_keys(Keys.END)
        time.sleep(sleep_time)

def find_cards_info():
    cards_sel = 'div.WB_feed_detail'
    cards = drver.find_elements_by_css_selector(cards_sel)
    info_list = []

    content_sel = 'div.WB_text.W_f14'
    date_sel = 'div.WB_from.S_txt2'
    link_sel = 'div.WB_from.S_txt2 > a:nth-child(1)'
    for card in cards:
        # print(card)
        content = card.find_element_by_css_selector(content_sel).text
        date = card.find_element_by_css_selector(date_sel).text
        link = card.find_element_by_css_selector(link_sel).get_attribute('href')

        info_list.append([bytes(content, encoding='utf8'), bytes(date, encoding='utf8'), bytes(link, encoding='utf8')])
    return info_list

def find_next():
    next_sel = 'a.page.next'
    next_page = drver.find_element_by_css_selector(next_sel).get_attribute('href')
    print(next_page)
    if not next_page:
        print('Done to the bottle')
        exit(1)
    return next_page

def save(info_list, name):
    full_path = './' + name + '.csv'
    if os.path.exists(full_path):
        with open(full_path, 'a') as f:
            writer = csv_w(f)
            for info in info_list:
                try:
                    writer.writerows(info)
                except:
                    print('can''t  encode this line')
    else:
        with open(full_path, 'w+') as f:
            writer = csv_w(f)
            for info in info_list:
                try:
                    writer.writerows(info)
                except:
                    print('can''t  encode this line')
    print('This write is done!')




def main_crawler(full_url, scrool_times=5, scroll_sleep_time=2):
    drver.get(full_url)
    time.sleep(6)
    scroll_down(scrool_times, scroll_sleep_time)
    info_list = find_cards_info()
    # print(info_list)
    save(info_list, star_name)
    # csv_reader(star_name)
    next_page = find_next()
    if next_page:
        main_crawler(next_page)

def csv_reader(name):
    full_path = './' + name + '.csv'
    if os.path.exists(full_path):
        with open(full_path, 'r') as f:
            reader = csv_r(f)
            for item in reader:
                for _ in item:
                    print(_)


star_name = 'misswar3'
drver = start_chrome()
full_url = base_url + star_name + get_query('2018-04-01', '2018-06-01')
# print(full_url)
input()
main_crawler(full_url)
# csv_reader(star_name)


