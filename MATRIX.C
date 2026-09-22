	#include "msk.h"

char select_operation='1';

void border();
void loading();

void main()
{
	int gd=DETECT,gm;
	char key;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	loading();

	border();
	while(1)
	{
		setcolor(15);
		settextstyle(0,0,2);// font, direction, size
		otxy(175,25,"MATRIX OPERATIONS");
		settextstyle(1,0,5);
		setfillstyle(2,0);
		bar(x-114,y-55,x-20,y-12);
		setcolor(15);
		otxy(x-110,y-60,"EXIT");

		setcolor(6);
		setfillstyle(1,1);

		bar(48,152,212,108);//dim
		rect(48,152,212,108);

		bar(232,152,396,108);//enter values
		rect(232,152,396,108);

		bar(416,152,580,108);//edit values
		rect(416,152,580,108);
		///////////\\\\\\\\\\\/////////////\\\\\\\\\\\\\//////////////////////
		bar(48,206,212,162);//select matrices
		rect(48,206,212,162);

		bar(232,206,396,162);//|det|
		rect(232,206,396,162);

		bar(416,206,580,162);//transpose
		rect(416,206,580,162);

		setcolor(10);
		settextstyle(2,0,5);
		// FONT,DIRECTION,SIZE

		otxy(108,115,"GIVE");
		otxy(95,128,"DIMENSIONS");

		otxy(292,115,"ENTER");
		otxy(290,128,"VALUES");

		otxy(476,115,"EDIT");
		otxy(470,128,"VALUES");

		otxy(105,168,"SELECT");
		otxy(105,181,"MATRIX");

		otxy(260,168,"DETERMINANT OF");
		otxy(290,183,"MATRIX");

		otxy(456,168,"TRANSPOSE OF");
		otxy(480,182,"MATRIX");

		setcolor(7);

		if(select_operation=='1')
			rect(50,150,210,110);
		else if(select_operation=='2')
			rect(234,150,394,110);
		else if(select_operation=='3')
			rect(418,150,578,110);
		else if(select_operation=='4')
			rect(50,204,210,164);
		else if(select_operation=='5')
			rect(234,204,394,164);
		else if(select_operation=='6')
			rect(418,204,578,164);
		else if(select_operation=='7')
			rect(x-114,y-55,x-20,y-12);

		key=getch();
		if(key==IS_AK)
		{
			key=getch();
			if(key==AK_LEFT)
			{
				if(select_operation=='1')
					select_operation='7';
				else
					select_operation--;
			}
			else if(key==AK_UP)
				select_operation=select_operation-3;
			else if(key==AK_RIGHT)
			{
				if(select_operation=='7')
					select_operation='1';
				else
					select_operation=select_operation++;
			}
			else if(key==AK_DOWN)
				select_operation=select_operation+3;

			if(select_operation>'7')
				select_operation='7';
			if(select_operation<'1')
				select_operation='1';
		}
		else if(key==ENTER)
		{
			if(select_operation=='7')
					break				;
		}
	}
	closegraph();
}

void border()
{
	setcolor(13);
	rect(0,0,x,y);

	setfillstyle(6,9);
	floodfill(1,1,13);

	setcolor(15);
	rect(4,4,x-4,y-4);

	setfillstyle(1,0);
	floodfill(5,5,15);
}

void loading()
{
	int _x,_y,i=0,j=0;
	cleardevice();
	setcolor(1);
	settextstyle(0,0,4);
	moveto(20,getmaxy()/2-30);
	outtext("L O A D I N G");

	_x=getx();
	_y=gety();

	for(i=0;i<2;i++)
	{
		for(j=2;j<8;j++)
		{
			moveto(_x,_y);

			setcolor(++j);
			outtext(" .");
			delay(40);

			setcolor(j);
			outtext(" .");
			delay(40);

			setcolor(--j);
			outtext(" .");
			delay(40);
		}
	}
	cleardevice();
}