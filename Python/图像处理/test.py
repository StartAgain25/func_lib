#-*-coding:utf-8
'''
	py3
'''

import cv2.cv2 as cv
import numpy as np

img = cv.imread("swim.jpg")

cv.imshow("傅衍楚",img)
cv.waitKey(0)
cv.destroyAllWindows()
print(img.shape)
print(type(img))



