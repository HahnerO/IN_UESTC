from multiprocessing import Pool
from channel_link_getter import channel_list
from get_page_items import get_items_from
from get_page_items import get_item_info
from get_page_items import url_list

def get_all_links_from(channel):
    for num in range(1, 101):
        get_items_from(channel, num)

if __name__ == '__main__':
    pool = Pool()
    # pool.map(get_all_links_from, channel_list)
    urls = []
    for url in url_list.find():
        # if 'tongxunyw' in url:
        #     pass
        # else:
            urls.append(url.get('url'))
    pool.map(get_item_info, urls)
    # print(urls)
