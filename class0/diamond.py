# encoding: utf-8
 
# 引入python3的print
from __future__ import print_function
 
# 核心
def core(level, idx):
    # 空白
    for x in xrange(0, level-idx):
        print(' ', end='')
    # 星星
    for x in xrange(0, (idx*2)+1):
        print('*', end='')
    # 換行
    print('')
 
# 驅動
def diamond(level):
    # 上半部
    for x in xrange(0, level):
        core(level, x)
    # 下半部
    for x in xrange(level-2, -1, -1):
        core(level, x)
 
# 主程式
def main():
    diamond(3)
 
# 本地程式
if __name__ == '__main__':
    main()