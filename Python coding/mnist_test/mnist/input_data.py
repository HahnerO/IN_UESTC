from __future__ import absolute_import, division, print_function

import gzip
import os
import tempfile

import numpy
from six.moves import urllib, xrange
import tensorflow as tf
from tensorflow.contrib.learn.python.learn.datasets.mnist import read_data_sets
