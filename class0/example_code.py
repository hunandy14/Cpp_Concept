# encoding: utf-8
# 第一行加了才能打中文註解

# 引入python3的print
from __future__ import print_function

# 副程式(任何型態)
def pri(a, b):
    print (a, b)
    # 隨意加字串
    a = a+"==="
    print (a, b)
    # 轉型
    s = a + str(b)
    print (s)

# 主程式
def main():
    # 印出
    print ("Hello")

    # for用法
    for i in range(10):
        # end=''才不會跳行
        print (i,end='')
        # if用法
        if i == 8 :
            break;
    # /n跳行
    print ("")
    # 呼叫副程式
    pri("str=", 10)

# 本地程式
if __name__ == '__main__':
    main()
