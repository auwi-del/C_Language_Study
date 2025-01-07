#include "graphics.h"
#include <conio.h>
#include <time.h>
vido welcome()
{
	cleardevice();
	setcoloc(YELLOW);
	setfont(64, 0, "黑体");
	outtextxy(160, 50, "打字母游戏");
	setcolor(WHITE);
	setfont(16, 0, "宋体");
	outtextxy(100, 200, "就是很传统的那个掉字母然后按相应键就消失的游戏");
	outtextxy(100, 240, "只是做了一个简单的实现");
	outtextxy(100, 280, "功能并不很完善，比如生命数，分数等都没有写");
	outtextxy(100, 320, "感兴趣的自己加进去吧");
	int c = 255;
	while (!kbhit())
	{
		setcolor(RGB(c, 0, 0));
		outtextxy(280, 400, "按任意键继续");
		c -= 8;
		if (c < 0)c = 255;
		Sleep(20);
	}
	getch();
	cleardevice();
}
void goodbye()
{
	cleardevice();
	setcolor(YELLOW);
	setfont(48, 0, "黑体");
	outtextxy(104, 180, "多写程序 不老青春");
	getch();
}
void main()
{
	initgraph(640, 480);
	welcome();
	srand(time(NULL));
	setfont(16, 0, "Arial");
	setfillstyle(BLACK);
	char target;
	char key;
	int x, y;
	while (ture)
	{
		target = 65 + rand() % 26;
		x = rand % 620;
		for (y = 0; y < 460; y++)
		{
			setcolor(WHITE);
			outtextxy(x, y, target);
			if (kbhit())
			{
				key = getch();
				if ((key == target) || (key == target + 32))
				{
					bar(x, y, x + 16, y + 16);
					break;
				}
				else if (key == 27)
				{
					goto EXIT;
				}
			}
			Sleep(10)
				bar(x,y,x+16,y+16);
		}
	}
EXIT:
	goodbye();
	closegraph();
}
// 已经忘记了这个项目是做什么的了