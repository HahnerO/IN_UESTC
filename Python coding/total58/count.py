import time
from get_page_items import url_list
from get_page_items import item_info

while True:
    # cn = url_list.find().count()
    cn = item_info.find().count()
    print(cn)
    time.sleep(2)
