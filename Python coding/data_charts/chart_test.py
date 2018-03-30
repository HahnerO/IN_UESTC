# from charts import plot
from matplotlib import pyplot as plt
from pymongo import MongoClient

client = MongoClient('localhost', 27017)
items = client['items']
item_info = items['item_info']

area_list = []
for i in item_info.find():
    area_list.append(i['area'])
area_index = list(set(area_list))

post_times = []
size = []
total_times = 0
pt = 0
for index in area_index:
    time = area_list.count(index)
    post_times.append(time)
    total_times += time
for pt in range(0, len(post_times)):
    size.append(100 * (post_times[pt] / total_times))

# print(size)

# active below to use charts-ver in jupyter notebook
# def data_modify(types):
#     length = 0
#     if length <= len(area_index):
#         for area, times in zip(area_index, post_times):
#             data = {'name': area, 'data': [times], 'type': types}
#             yield data
#             length += 1
#
# series = [i for i in data_modify('column')]
# plot{series, show='inline', options=dict(title=dict(text='Second_hand items in CDC'))}

plt.pie(size,
        labels=area_index,
        labeldistance=1.1,
        autopct='%3.1f%%',
        shadow=False,
        startangle=90,
        pctdistance=0.6
        )

plt.axis('equal')
plt.legend()
plt.show()
