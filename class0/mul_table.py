#-*- coding: utf-8 -*-　　 
#-*- coding: cp950 -*-　
# ===============================================================
# Name : 
# Date : 2017/01/13
# By   : CharlotteHonG
# Final: 2017/01/14
# ===============================================================
# 引入python3的print
from __future__ import print_function
# import sys
# sys.stdout.softspace=0
# ===============================================================
class Mul_table:
    # 初始化
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2
    # 核心
    def core(self, star=1, end=0):
        if star > end:
            end=self.n2
        for y in xrange(1,self.n1+1):
            for x in xrange(star,end+1):
                print(x, end=('x'))
                print(y, end=('='))
                print("{:2d}".format(x*y), end=(', '))
            print()
        print()
    def pri(self, w):
        # 繪製指定範圍
        for x in xrange(1, self.n2+1, w):
            # 定制範圍
            if (x+w-1)>self.n2:
                x2=self.n2
            else:
                x2=x+w-1
            # 印出
            self.core(x, x2)
# ===============================================================
# 主程式
def main():
    mul = Mul_table(2, 5)
    mul.pri(3)
    mul2 = Mul_table(3, 7)
    mul2.pri(4)
# ===============================================================
# 本地程式
if __name__ == '__main__':
    main()
# ===============================================================