import cv2

ori_img=cv2.imread('1.png')
#读取图像

gray_img=cv2.cvtColor(ori_img,cv2.COLOR_BGR2GRAY)


blur_img=cv2.GaussianBlur(ori_img,(11,11),0)
#应用高斯模糊
#(11,11):卷积核大小(必须为奇数),越大越模糊
#0:标准差(0表示自动计算),越大越模糊

cv2.imshow('image',ori_img)
cv2.imshow('gray_image',gray_img)
cv2.imshow('blur_image',blur_img)
cv2.waitKey(0)
cv2.destroyAllWindows()