import jieba
import jieba.analyse
import numpy as np
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn import svm


class Model(object):
    def __init__(self, true_model, X_shape, flag):
        self.true_model = true_model
        self.X_shape = X_shape
        self.flag = flag



class S_filter(object):

    def __init__(self, text_file_inside=None):
        self.text_file_inside = text_file_inside




    #read_text
    def read_data_text(self, fpath, with_stopwords = False):
        file = open(fpath, 'r', encoding="utf-8")
        text_file = []
        while 1:
            file_line = file.readline()
            if not file_line:
                break
            text_file.append(file_line.strip('\n'+'\t'+'\r'))
        self.text_file_inside = text_file


        if with_stopwords == True:
            stopfile = open('/Users/hahn/Desktop/中文停用词库.txt', 'rb').read().decode('gb2312')   #get stop-words
            stopwords = []
            for line in stopfile:
                stop_line_words = line.strip()
                if stop_line_words != '':
                    stopwords.append(stop_line_words)
            feature_text = []
            for txt in text_file:
                txt_line_word = ''
                seg_list = jieba.cut(txt, cut_all=False)
                for key_word in seg_list:
                    if key_word not in stopwords:
                        txt_line_word = txt_line_word + key_word + ' '
                feature_text.append(txt_line_word.rstrip(' '))
        else:
            feature_text = []

            for txt in text_file:
                txt_line_word = ''
                seg_list = jieba.cut(txt, cut_all=False)
                for key_word in seg_list:
                    txt_line_word = txt_line_word + key_word + ' '
                feature_text.append(txt_line_word.rstrip(' '))

        return feature_text


    # read tag
    def read_data_tag(self, tag_path):
        tag_file = open(tag_path, 'r', encoding='utf-8')
        tag = []
        while 1:
            tag_line = tag_file.readline()
            if not tag_line:
                break
            tag.append(int(tag_line.strip('\n'+'\r'+'\t')))

        return tag


    # fit model
    def train_model(self, feature_text, tag):
        vectorizer = CountVectorizer()
        transformer = TfidfTransformer()
        tfidf = transformer.fit_transform(vectorizer.fit_transform(feature_text))
        weight = tfidf.toarray()
        true_model = svm.SVR()

        true_model.fit(weight, tag)
        x_shape = np.shape(weight)[1]

        pos_flag = 0
        neg_flag = 0
        n_pos_flag = 0
        n_neg_flag = 0
        for i in range(len(tag)):
            if tag[i] == 0:
                n_pos_flag += 1
                pos_flag += true_model.predict(weight[i])
            else:
                n_neg_flag += 1
                neg_flag += true_model.predict(weight[i])
        flag = (pos_flag/n_pos_flag + neg_flag/n_neg_flag)/2


        model = Model(true_model, x_shape, flag)
        return model

    def predict(self, model, predict_txt):

        text_file = self.text_file_inside
        text_file.append(predict_txt)
        feature_text = []
        for txt in text_file:
            line_word = ''
            seg_list = jieba.cut(txt, cut_all=False)
            for key_word in seg_list:
                line_word = line_word + key_word + ' '
            feature_text.append(line_word.rstrip(' '))
        vectorizer = CountVectorizer()
        transformer = TfidfTransformer()
        tfidf = transformer.fit_transform(vectorizer.fit_transform(feature_text))
        weight = tfidf.toarray()
        pre_tf = weight[-1]
        row = np.shape(weight)[1]
        pre_tf.shape = (row, 1)
        pre_tf = np.transpose(pre_tf)
        res = model.true_model.predict(pre_tf)
        flag = model.flag
        if res < flag:
            print('Positive')
        else:
            print('Negative')
        return

