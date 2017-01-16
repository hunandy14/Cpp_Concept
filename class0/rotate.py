# encoding: utf-8
# ===============================================================
# 引入python3的print
from __future__ import print_function
# ===============================================================
# 筆記：
# 1. 跑幾次的偵測
# 2. 找最長邊
# 3. 改良任意點開始繞
# 4. 反繞
class Rotate:
    # 初始化
    def __init__(self, height, width):
        # 引入參數
        self.height = height
        self.width  = width
        # 成員
        self.arr = [[-1]*width for x in xrange(height)]
        self.idx_y, self.idx_x = -1, -1
        self.star = 0
        # 最長邊

    # 印出
    def pri(self):
        for y in xrange(self.height):
            for x in xrange(self.width):
                pass
                print("{:3.0f}".format(
                    self.arr[y][x]), end=('')
                );
            print()
    # 核心程式
    def run_core(self, director):
        # print("Run")
        # 修正越界
        if self.idx_y==-1:
            self.idx_y=0
        if self.idx_x==-1:
            self.idx_x=0
        # 依照最長邊跑
        for x in xrange(self.width):
            # 有效空值才填入
            if self.arr[self.idx_y][self.idx_x]==-1:
                self.arr[self.idx_y][self.idx_x]=self.star
                self.star += 1
            # 一方向走
            self.idx_y = self.idx_y + director[0]
            self.idx_x = self.idx_x + director[1]
            # 檢查越界
            try:
                # 0越界
                if self.arr[self.idx_y][self.idx_x] != -1:
                    # 0越界- 補償
                    self.idx_y, self.idx_x = \
                        self.idx_y-diry, self.idx_x-dirx
            # 長度越界
            except:
                # 長度越界 - 補償
                self.idx_y, self.idx_x = \
                    self.idx_y-director[0], \
                    self.idx_x-director[1]
    # 跑一圈
    def run_once(self):
        self.run_core([0,1])
        self.run_core([1,0])
        self.run_core([0,-1])
        self.run_core([-1,0])
    # 跑全部
    def run(self):
        for x in xrange( int(round(self.width/2))+1 ):
            self.run_once()
# ===============================================================
# 主程式
def main():
    # 建立物件
    rot = Rotate(5, 5)
    rot.run()
    rot.pri()
# ===============================================================
# 本地程式
if __name__ == '__main__':
    main()
# ===============================================================