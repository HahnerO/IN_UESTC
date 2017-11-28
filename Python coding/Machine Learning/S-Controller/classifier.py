from class_pac import S_filter



sf = S_filter()
txt = sf.read_data_text('/Users/hahn/Desktop/test.txt')
print(txt)
tag = sf.read_data_tag('/Users/hahn/Desktop/test_tag.txt')
print((sf.read_data_tag('/Users/hahn/Desktop/test_tag.txt')))
model = sf.train_model(txt, tag)
print(model.flag)
print(sf.text_file_inside)
sf.predict(model, '中国好帅')
