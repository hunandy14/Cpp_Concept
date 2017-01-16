# encoding: utf-8
# 引入python3的print
from __future__ import print_function

# 印出陣列
def pri():
    global arr
    row=len(arr)
    col=len(arr[0])
    for y in xrange(row):
        for x in xrange(col):
            print("{:3.0f}".format(arr[y][x]), end=(''));
        print()
# 回報位置
def pos():
    global arr, row, col, idx, idy, num, lenth, flag
    print('pos', end=('('))
    print(idy, end=(','))
    print(idx,end=(')'))
    print(', num=', num)
# 跑
def run(diry, dirx):
    # print("Run")
    global arr, row, col, idx, idy, num, lenth
    # arr[idy][idx]=num
    # 修正越界
    if idy==-1:
        idy=0
    if idx==-1:
        idx=0

    for x in xrange(lenth):
        # 有效空值才填入
        if arr[idy][idx]==-1:
            arr[idy][idx]=num
            num += 1
        idy, idx = idy+diry, idx+dirx
        # =====================================
        # 檢查越界
        try:
            # 0越界
            if arr[idy][idx] != -1:
                # 0越界- 補償
                idy, idx = idy-diry, idx-dirx
        # 長度越界
        except:
            # 長度越界 - 補償
            idy, idx = idy-diry, idx-dirx
        # =====================================
    # pos()
# 一個循環
def cycle():
    global arr, row, col, idx, idy, num, lenth
    run(0, 1)
    run(1, 0)
    run(0, -1)
    run(-1, 0)
# 旋轉
def rotate(len):
    global arr, row, col, idx, idy, num, lenth
    arr=[[-1]*len for x in xrange(len)]
    row, col , idx, idy = len, len, -1, -1
    star = 0
    num = star
    lenth = len
    # 跑到特定數字後停止
    while num<len*len+star:
        cycle()
        print("*")
    pri()
# 主程式
def main():
    rotate(7)
# 本地程式
if __name__ == '__main__':
    main()