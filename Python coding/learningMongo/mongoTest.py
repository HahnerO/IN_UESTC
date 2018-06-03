from pymongo import MongoClient

host = 'localhost'
port = 27017

client = MongoClient(host, port)
test = client['test']
sheet_tab = test['sheet_tab']

# path = '/Users/hahn/Desktop/hp.txt'
# with open(path, 'r', encoding='GB18030') as f:
#     lines = f.readlines()
#     for index, line in enumerate(lines):
#         data = {
#             'index': index,
#             'line': line,
#             'words': len(line.split())
#         }
#         sheet_tab.insert_one(data)

for item in sheet_tab.find({'words': {'$lt':5}}):
    print(item)
