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
    def __init__(self, y, x):
        self.y = y
        self.x = x
    # 核心
    def core(self, idx):
        if idx != 0:
            print("{:3}".format(idx), end=(''))
        # 非零修正
        else:
            print("{:3}".format(''), end=(''))
            idx=1
        # 核心
        for x in xrange(1, self.x+1):
            print("{:3}".format(x*idx), end=(''))
        print()
    # 表格
    def pri(self):
        for x in xrange(self.y+1):
            self.core(x)
        print()
# ===============================================================
# 主程式
def main():
    Mul_table(3,4).pri()
    Mul_table(5,5).pri()
# ===============================================================
# 本地程式
if __name__ == '__main__':
    main()
# ===============================================================