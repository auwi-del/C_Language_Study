#include <stdio.h>

int main()
{
    int i, t, input, ans;
    // 每一行开始的第一个数字, 都表明其后跟着几个数字, 比如说
    // 4 1 2 3 4, 就表明本行有 [四个有效数字], 分别是1, 2, 3, 4

    // 当尝试读取失败时, 说明输入文件结束了, 所以当scanf("%d",&t)==EOF , 结束程序
    // t 代表 times, 就是本行要读取多少次, 即, (本行一共有多少数字)-1
    while( scanf( "%d", &t ) != EOF /*虽然这句填到括号里了, 其实是一处活用
                                    这一句代码既能被运行, 又能当作循环进行下去的条件
                                    这里挺巧妙, 多想想可以理解的!
                                    然后你别看我写这么多, 这叫多行注释, 不会影响程序运行的, #龇牙# */)
    {
        // 在这个while里头, 每一次循环都对应着一行
        input = ans = 0;
        for( i = 0; i < t; i++ )
        {
            scanf( "%d", &input );      // 读取每个数字, 一行一共会读取 t 次, 每次运行到这行读一个, 存到input变量里
            
            if( input % 2 != 0 )        // 当它不是偶数, 就开始处理
            {
                if( ans == 0 )
                    ans++;              // ans的初始值为0, 是为了防止一行一个奇数都没有的时候. 那时候答案是0.
                                        // 所以当我们发现第一个奇数的时候, 就将ans设为1, 方便乘积计算 #龇牙#
                ans *= input;           // 应该不用说吧.......算了还是说了, 就是乘积
            }
        }
        printf( "%d\n", ans );          // 当程序运行到这一行, 说明输入文件的一行处理完毕了, 该输出了...
        // 然后,,,
        // 处理,,,
        // 下一行........
        // 因为这是循环.........
    }
}