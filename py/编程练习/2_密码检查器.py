print("=== 密码安全检查器 ===")

num = 0
password = input("\n请输入你的密码:")
has_digit = any(char.isdigit() for char in password)
has_alpha = any(char.isalpha() for char in password)
print("检查中……")

print("\n检查结果:\n")
print("长度检查:",end=" ")
if len(password) >= 8:
    print("通过")
    num = num + 1
else:
    print("不通过")
print("数字检查:",end=" ")
if has_digit:
    print("通过")
    num = num + 1
else:
    print("不通过")
print("字母检查:",end=" ")
if has_alpha:
    print("通过")
    num = num + 1
else:
    print("不通过")

print("\n密码安全等级:",end=" ")
if num == 3:
    print("强密码")
elif num == 2:
    print("中等密码")
elif num == 1:
    print("弱密码")
else:
    print("很不安全的密码")