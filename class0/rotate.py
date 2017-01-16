#-*- coding: utf-8 -*-　　 
#-*- coding: cp950 -*-　
# ===============================================================
# Name : rotate_v1.1
# Date : 2017/01/13
# By   : CharlotteHonG
# Final: 2017/01/14
# ===============================================================
# 引入python3的print
from __future__ import print_function
# ===============================================================
class Rotate:
    # 初始化
    def __init__(self, height=4, width=4):
        # 引入參數
        self.height = height
        self.width  = width
        # 成員
        self.arr = [[-1]*width for x in xrange(height)]
        self.idx_y, self.idx_x = -1, -1
        self.star = 0
        self.num = self.star
        # 初始化紀錄
        self.init = 1
        return
    # 印出
    def pri(self, name="Rotate"):
        print(name)
        for y in xrange(self.height):
            for x in xrange(self.width):
                pass
                print("{:3.0f}".format(
                    self.arr[y][x]), end=('')
                );
            print()
        print()
        return
    # 核心程式
    def run_core(self, director):
        # print("Run")
        # 修正越界
        if self.idx_y==-1:
            self.idx_y=0
        if self.idx_x==-1:
            self.idx_x=0
        # 依照最長邊跑
        for x in xrange(max(self.height, self.width)):
            # 已完成則跳出
            if (self.height*self.width-1+self.star==self.num-1):
                # print("Finish")
                return
            # print("Go")
            # 有效空值才填入
            if self.arr[self.idx_y][self.idx_x]==-1:
                self.arr[self.idx_y][self.idx_x]=self.num
                self.num += 1
            # 一方向走
            self.idx_y = self.idx_y + director[0]
            self.idx_x = self.idx_x + director[1]
            # 檢查越界
            try:
                # 0越界
                if self.arr[self.idx_y][self.idx_x] != -1:
                    # print ("0越界")
                    # 0越界- 補償
                    self.idx_y, self.idx_x = \
                        self.idx_y-diry, self.idx_x-dirx
            # 長度越界
            except:
                # print("長度越界")
                # 長度越界 - 補償
                self.idx_y, self.idx_x = \
                    self.idx_y-director[0], \
                    self.idx_x-director[1]
                return
        return
    # 跑一圈
    def run_once(self, pos=0):
        # 超出範圍修正
        if pos != xrange(3):
            pos=0
        # pos控制第一輪由哪個開始
        if self.init==0 or pos==0:
            self.run_core([0,1])
            self.init=0
        if self.init==0 or pos==1:
            self.run_core([1,0])
            self.init=0
        if self.init==0 or pos==2:
            self.run_core([0,-1])
            self.init=0
        if self.init==0 or pos==3:
            self.run_core([-1,0])
            self.init=0
        return
    # 跑全部
    def run(self, star=0, pos=0):
        # 不可小於0
        if star < 0:
            print("* Error init number fix to 0")
            star=0
        # 從多少開始
        self.star = star
        self.num = self.star
        # 修正初始位置
        if pos == 1:
            self.idx_x = self.width-1
        elif pos == 2:
            self.idx_x = self.width-1
            self.idx_y = self.height-1
        elif pos == 3:
            self.idx_y = self.height-1
        # 跑最短邊/2+1次
        for x in xrange(min(self.height, self.width)/2+1):
            self.run_once(pos)
        return
# ===============================================================
# 主程式
def main():
    # 建立物件
    rot = Rotate(4, 4)
    rot.run(1, 1)
    rot.pri("form 0 init")
# ===============================================================
# 本地程式
if __name__ == '__main__':
    main()
# ===============================================================
