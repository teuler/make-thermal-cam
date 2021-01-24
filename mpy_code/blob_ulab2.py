#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ---------------------------------------------------------------------
# blob.py
# Function for blob detection in images
#
# The MIT License (MIT)
# Copyright (c) 2019 Thomas Euler
# 2020-08-21, v1.0 Using new functions added to ulab's user module
#
# ---------------------------------------------------------------------
import math
import ulab as np
from ulab import numpy as np
from ulab import user
from micropython import const
from time import ticks_us, ticks_diff

# ---------------------------------------------------------------------
def spatial_filter(img, kernel, dxy=None):
  """ Call user filter function we added to ulab
  """
  np_imgf = user.spatial_filter(np.array(img), np.array(kernel), dxy)
  return list(np.array(np_imgf, dtype=np.int16))

# ----------------------------------------------------------------------------
def timed_function(f, *args, **kwargs):
  """ Use as decorator to measure the duration of a function call
  """
  myname = str(f).split(' ')[1]
  def new_func(*args, **kwargs):
    t = ticks_us()
    result = f(*args, **kwargs)
    delta = ticks_diff(ticks_us(), t)
    print('Function {} Time = {:6.3f}ms'.format(myname, delta/1000))
    return result
  return new_func

# ---------------------------------------------------------------------
@timed_function
def find_blobs_timed(img, dxy, nsd=1.0):
  return find_blobs(img, dxy, nsd)

def find_blobs(img, dxy, nsd=1.0):
  """ Detect continues area(s) ("blobs") with pixels above a certain
      threshold in an image. `img` contains the flattened image (1D),
      `dxy` image width and height, and `nsd` a factor to calculate the blob
      threshold from image mean and s.d. (thres = avg +sd *nsd).
  """
  img_array = np.array(img)
  return user.blobs(img_array, dxy, nsd)

# ---------------------------------------------------------------------
