import cv2

ori_img=cv2.imread('test.png')
#读取图像

gray_img=cv2.cvtColor(ori_img,cv2.COLOR_BGR2GRAY)
blur_img=cv2.GaussianBlur(ori_img,(11,11),0)
#处理图像

cv2.imshow('image',ori_img)
cv2.imshow('gray_image',gray_img)
cv2.imshow('blur_image',blur_img)

cv2.waitKey(0)
cv2.destroyAllWindows()