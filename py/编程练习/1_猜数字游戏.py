import random
ans = random.randint(1,10)
num = 0
print("=== 欢迎来到猜数字游戏! ===")
print("我已经想好了一个1到10之间的数字,你能猜出来吗?")

while True:
    guess = int(input("\n请输入你的猜测:"))
    num = num + 1
    if guess == ans:
        print("猜对了!")
        break
    else:
        if num < guess:
            print("太大啦,再试试!")
        else:
            print("太小啦,再试试!")

print("你总共猜了",num,"次!",sep="")


