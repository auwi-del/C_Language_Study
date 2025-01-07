#include <stdio.h>
#include <string.h>

#include "List.c"
#include "Menu.c" 

// #define DEBUG
#define FILENAME "save.txt"

int Editor( List* LIST );           // 传入 [管理链表] 的指针, 最核心功能, 命令功能尽在于此
int Save( List *LIST, char *fileName );     // 保存到文件里头
int Read( List *LIST, char *fileName );     // 从文件里头读取链表数据
int Confirm();                      // 确认用户输入
int GetInput_help();                // 显示帮助菜单
int Average( Node *NODE, int len ); // 单个节点求平均
int ListAvg( List *LIST );          // 全部暂存数据求平均

// main 中 main 
#ifndef DEBUG

int main()
{
    int i, j, k;
    int input;

    List* students = mkList();

    while(1)
    {
        DrawMenu();
        // scanf( "%d", &input );
        // getchar();              // get掉 '\n'

        printf("\t");
        system( "pause" );

        if ( /*input ==*/ 1 )
        {
            Editor( students );
            see_the_list( students );
        }
        
    }

    system( "pause" );
    
}

#endif



// 读取输入的功能
//  读取用户的输入， 直到用户输入 'exit' 才退出
 
int Editor( List* LIST )
{
    Node* p = LIST -> last;         // 目光放在链表的尾指针上
    int a, b, c, d, e, i, j, SCANED;
    
    // 打印帮助文档.
    GetInput_help();
    
    char input[ 10 ] = {};
    while( 1 )
    {
        // 读取命令, 如果是输入, 那就正常, 如果不是, 那就按照命令处理
        for ( i = 0; i < STRLEN; i++ )
        {
            input[i] = getchar();
            if ( ( input[i] == ' ' ) || ( input[i] == '\n' ) )
            {
                input[i] = '\0';        // 结束符
                break;
            }
        }

        // 命令: exit
        if( !strcmp( input, "exit" ) )
        {
            printf( "输入结束\n" );
            break;
        }

        // 命令: save
        if( !strcmp( input, "save" ) )
        {
            printf( "保存将会覆盖现有存档文件, 是否保存? ( y / n )\n" );
            if( Confirm() )
            {
                printf( "开始保存...\n" );
                Save( LIST, FILENAME );
                printf( "保存完成！\n");
            } else {
                printf( "已取消, 继续正常输入.\n" );
            }
            

            continue;
        }

        // 命令: read
        if( !strcmp( input, "read" ) )
        {
            printf( "读取将会覆盖现有链表数据, 是否读取? ( y / n )\n" );

            if( Confirm() ) {
                printf( "\n开始读取...\n" );
                Read( LIST, FILENAME );         // 读取
                p = LIST->last;                 // 指针指向最后的节点, 该节点为空, 即将被写入
                printf( "读取完成！\n继续正常输入\n\n");
            } else {
                printf( "已取消, 继续正常输入.\n" );
            }
            continue;
        }

        // 命令: avge
        if( !strcmp( input, "avge" ) )
        {
            printf( "开始计算平均数\n" );
            ListAvg( LIST );
            see_the_list( LIST );
            printf( "\n\n平均数计算完成!\n\n");
            continue;
        }

        // 命令: sort
        if( !strcmp( input, "sort" ) ) 
        {
            printf( "开始排序\n" );
            LIST = Sort( LIST );
            p = LIST->last;         // LIST更换了位置, p得保持!!
            see_the_list( LIST );

            printf( "\n\n排序完成!\n\n");
            continue;
        }

        // 命令: see
        if( !strcmp( input, "see" ) )
        {
            see_the_list( LIST );
            printf( "以上是链表中暂存的数据, 请继续输入:\n" );
            continue;
        }

        // 命令: help
        if( !strcmp( input, "help" ) )
        {
            GetInput_help();
            continue;
        }
        
        strcpy( p -> name, input);              // 将char* input写入p->name
        
        // 数值的输入
        // 这一行一定要多加上末尾的 '\n' 号.
        SCANED = scanf( "%d, %d, %d, %d, %d", &(p->score[0]), &(p->score[1]), &(p->score[2]), &(p->score[3]), &(p->score[4])  );
		Average( p, 5 );
        while( getchar() != '\n' );              // 将剩下的字符一笔带过
		
        

		// 检测scanf了多少个 
		if ( SCANED <= 1 )
        {
            printf( "读取到的 分数 参数少于1个!(输入exit可退出重进)\n" );
            continue;
        }
			
		
        Node_add( LIST );
        p = p->Next;
    }
}


/*
=================================================================================

						   文 件 读 写 


文件的结构:
+++++++++++++++++++++++++++  [ save.stu ] +++++++++++++++++++++++++++++++++

[ (int)链表的长度n ]
1 [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10],\n
2 [ 节点2 ] 
...
n [节点n]
end

---------------------------- 测试内容 -------------------------------------
文件的结构：
【 一共有几个节点（int）n】
【 节点1 】
【 节点2 】
...  
【 节点n】
 
=================================================================================
*/ 


// 传入要被写入的[控制链表结构]与[文件名指针] 
int Save( List *LIST, char *fileName )
{
    int i, j, listLen = LIST->length, num/*临时寄存变量*/;
    Node *p = LIST->head;                   // 指向当前正在处理的节点, 初始指向头节点

    FILE *fp = fopen( fileName, "w+" );   // 打开文件
    fprintf( fp, "listlen = %d\n", listLen );          // 写入链表长度
    
    for ( i = 0; i < listLen; i++ )
    {
        // 1, [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10], ave,\n
        fprintf( fp, "%d, %s, ", i, p->name );
        for ( j = 0; j < SCORLEN; j++ )
        {
            num = p->score[j];
            fprintf( fp, "%d, ", num );
        }
        fprintf( fp, "%.2f, ", p->ave );          // 写入平均数
        fprintf( fp, "\n" );
        p = p->Next;
    }
    fclose( fp );

}

// 传入 ( [控制链表结构], "文件.拓展名" ), 此函数将该文件内的数据读取到链表 LIST 中
int Read( List *LIST, char *fileName )
{
    int i, j, num, listLength;
    char c;
    Node *p = LIST->head;           // p 仍然是当前正在读写的节点

    FILE *fp = fopen( fileName, "r+" );

    fscanf( fp, "listlen = %d", &listLength );                      // 读取链表长度

    for( i = 0; i < listLength - 1; i++ )       // save 文件最后一个为空数据, 不要读取
    {
        // 1, [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10],\n
        fscanf( fp, "%d, %s, ", &num, (p->name) );


        // 去除 scanf() 在读取名字时一定会多读到的','
        for( j = 0; j < STRLEN; j++ )           
        {
            c = p->name[ j ];
            if( c == ',' )
            {
                p->name[ j ] = '\0';
                break;          // 直接跳出循环
            }
        }

        // 读取分数
        for( j = 0; j < 10; j++ )
        {
            fscanf( fp, "%d, ", &( p->score[j] ) );
        }

        // 读取小数
        fscanf( fp, "%f, ", &( p->ave ) );

        // 判断是否需要增加节点, 并增加节点
        if( p->Next == NULL )             // 如果, 当前节点的下一节点, 没有下一节点, 则:
            if( i < listLength - 1 )            // i 最终会等于 listlength, 所以应该提前一步, 少让他加一个 Node
                Node_add( LIST );

        p = p->Next;
    }
    see_the_list( LIST );

    fclose( fp );
}


// 调用本函数, 将从终端读取一个字符, y返回1, n返回0, 其他则要求用户重新输入
int Confirm()
{
    int result = -1;
    char c;
    while(1)
    {
        c = getchar();
        if( c == 'y' )
        {
            result = 1;
            break;
        }
        else if( c == 'n' )
        {
            result = 0;
            break;
        }
        else 
        {
            printf( "未知输入, 请重新输入:\n" );
            while( getchar() != '\n' );
            continue;
        }
    }
    getchar();
    return result;
}


// 简简单单的查看
int GetInput_help()
{
    printf( "\n\n\n**************   信息批量编辑器   *****************\n" );
    printf( "例: \n芙兰 100,100,100,100,100\\n \n" );
    printf( "格式为: 人名 [空格] 数字1 逗号 数字2 逗号 数字3 逗号 数字4 逗号 数字5 回车\n");
    printf( "名字后边需要有空格, 本程序会识别 5 个逗号\n" );
    printf( "\n***由于scanf()特性: \n***用户仅输入名字后未输入任何数字并换行会造成程序没有反应\n");
    printf( "***此时可以无视掉那个换行, 直接接着按格式输入5个分数,\n");
    printf( "***也建议连续输入5个以上的逗号, 回车, \n***程序报错后输入命令 exit, 重新进入本功能, 即可正常\n\n" );
    printf( "本程序有一定的输入纠错能力, 会屏蔽掉无用的输入\n为确保信息不丢失, 请尽量严格按照输入格式输入数据!\n" );
    printf( "\n\n可用命令:\nexit\t退出\nsave\t保存到文件(文件名在源代码中宏定义)\nread\t从文件中读取数据\n" );
    printf( "avge\t对所有的暂存数据进行求平均\nsort\t选择排序\nsee\t查看当前链表暂存的数据\nhelp\t重新显示本段文字\n" );
    printf( "( 非命令的输入, 将被认为是 name 变量! )\n\n" );
    
    // printf( "输入错误不要紧, 可稍后在 [编辑] 功能中增删改查.\n" );
    printf( "*****************************************************\n\n\n\n" );
}

// 传入( 节点, 前几位是有效的 ), 此函数计算平均值储存在 NODE->ave 中.
int Average( Node *NODE, int len )
{
    int i, sum;
    float result;
    for( i = 0; i < len; i++ )
    {
        sum += NODE->score[i];
    }
    NODE->score[6] = sum;       // score[6] 用来存总分
    result = sum / len;         // 计算
    NODE->ave = result;         // 存入
}

// 传入( 链表, 长度 ), 对整个链表进行求平均, 储存在LIST->avg中.
int ListAvg( List *LIST )
{
    int listlen = LIST->length - 1, i, j;
    Node *p = LIST->head;
    
    for( i = 0; i < listlen; i++ )
    {
        Average( p, 5 );
        if( p->Next != NULL )
            p = p->Next;
    }
}

#ifdef DEBUG
int main()
{
    Save();
}

#endif





