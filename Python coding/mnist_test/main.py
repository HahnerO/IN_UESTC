import numpy as np
from numpy import *
import tensorflow as tf
from flask import Flask, jsonify, render_template, request

from mnist import model

x = tf.placeholder('float', [None, 784])
sess = tf.Session()

with tf.variable_scope('regression'):
    y1, variables = model.regression(x)
saver = tf.train.Saver(variables)
saver.restore(sess, 'mnist/data/regression.ckpt')

with tf.variable_scope('convolutional'):
    keep_prob = tf.placeholder('float')
    y2, variables = model.convolutional(x, keep_prob)
saver = tf.train.Saver(variables)
saver.restore(sess, 'mnist/data/convolutional.ckpt')

def regression(input):
    return sess.run(y1, feed_dict={x: input}).flatten().tolist()

def convolutional(input):
    return sess.run(y2, feed_dict={x: input, keep_prob: 1.0}).flatten().tolist()

app = Flask(__name__)

@app.route('/api/mnist', methods=['post', 'get'])
def mnist():
    input_data = ((255 - np.array(request.json, dtype=uint8)) / 255.0).reshape(1, 784)
    output1 = regression(input_data)
    output2 = convolutional(input_data)
    return jsonify(result=[output1, output2])

@app.route('/')
def main():
    return render_template('index.html')

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0', port=8000)
