from get_page_items import url_list
from get_page_items import item_info

def is_exsisting(pare):
    if pare:
        return 1
    else:
        return 0

def is_404(soup = None):
    find_404 = soup.find('script', type='text/javascript')
    if find_404:
        return '404' in find_404
    return

def pre_modify_item_info():
    for item in item_info.find():
        title = item.get('title')
        area = item.get('area')
        city = item.get('city')

        old_price = item.get('old_price')
        if title is None or title.strip() == '':
            item_info.delete_one({'_id': item.get('_id')})
        else:
            if area is None or area.strip() == '' or area == city or city in area:
                item_info.update_one({'_id': item.get('_id')}, {'$set': {'area': '不明'}})
            if old_price is None:
                item_info.update_one({'_id': item.get('_id')}, {'$set': {'old_price': '不明'}})
    return

def pre_modify_url_list():
    for url in url_list.find():
        if 'jump' in url.get('url'):
            url_list.delete_one({'_id': url.get('_id')})
        print(url)
    return



