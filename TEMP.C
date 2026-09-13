#include<msk.h>

char select_temp,read_temp[20]=" ",temp_result1[20],temp_result2[20],temp_result3[20];

void select_temperature();
void enter_temperature(int val,char str1[],char str2[],char str3[],char str4[],int val1);
void print_temperature(char str1[]);
void calc_temp(int val);
void border();
void loading();





void select_temperature()
{
	while(1)
	{
		cld();
		border();
		settextstyle(0,0,2);// font, direction, size
		otxy(170,25,"SELECT A TEMPERATURE");
		settextstyle(1,0,2);
		otxy(x-220,y-30,"Enter Esc For Back");
		////////\\\\\\\\
		setcolor(6);
		setfillstyle(1,1);

		bar(98,152,292,108);
		rect(100,150,290,110);rect(98,152,292,108);

		bar(338,152,532,108);
		rect(340,150,530,110);rect(338,152,532,108);

		bar(98,282,292,238);
		rect(100,280,290,240);rect(98,282,292,238);

		bar(338,282,532,238);
		rect(340,280,530,240);rect(338,282,532,238);

		//COLOR
		 setcolor(10);
		 settextstyle(2,0,5); // FONT,DIRECTION,SIZE

		otxy(168,115,"KELVIN");
		otxy(155,128,"TEMPERATURE");

		otxy(392,115,"CELSIUS");
		otxy(395,128,"TEMPERATURE");

		otxy(168,246,"FAHRENHEIT");
		otxy(155,258,"TEMPERATURE");

		otxy(392,246,"REAUMUR");
		otxy(395,258,"TEMPERATURE");

		setcolor(14);
		settextstyle(8,0,1);
		otxy(80,110,"1.");
		otxy(320,110,"2.");
		otxy(80,240,"3.");
		otxy(320,240,"4.");

		select_temp=getch();
		if(select_temp=='1')
		{
			enter_temperature(1,"kelvin","celsius","fahrenheit","reaumur",1);
		}
		else if(select_temp=='2')
		{
			enter_temperature(2,"celsius","kelvin","fahrenheit","reaumur",1);
		}
		else if(select_temp=='3')
		{
			enter_temperature(3,"fahrenheit","kelvin","celsius","reaumur",1);
		}
		else if(select_temp=='4')
		{
			enter_temperature(4,"reaumur","kelvin","celsius","fahrenheit",1);
		}
		else if(select_temp==27)
		{
			break;
		}
	}
}

void enter_temperature(int val,char str1[],char str2[],char str3[],char str4[],int val1)
{
	char ch;
	int i=0,j=0;
	double check;

	if(val1==1)
		loading();

	label:
	border();
	setcolor(15);
	//input box
	setfillstyle(9,1);
	bar(20,170,250,270);
	rect(19,169,249,271);
	setfillstyle(1,0);
	bar(31,216,234,249);
	rect(30,215,235,250);
	setcolor(15);
	settextstyle(0,0,1);
	otxy(212,235,"--");

	//box 1
	setfillstyle(9,4);
	bar(360,40,590,140);
	rect(359,39,589,141);
	setfillstyle(1,0);
	bar(371,86,574,119);
	rect(370,85,575,120);

	//box2
	setfillstyle(9,4);
	bar(360,170,590,270);
	rect(359,169,589,271);
	setfillstyle(2,0);
	bar(371,216,574,249);
	rect(370,215,575,250);

	//box3
	setfillstyle(9,4);
	bar(360,300,590,400);
	rect(359,299,589,401);
	setfillstyle(2,0);
	bar(371,346,574,379);
	rect(370,345,575,380);

	setcolor(15);
	settextstyle(1,0,2);
	otxy(40,180,str1);
	otxy(380,50,str2);
	otxy(380,180,str3);
	otxy(380,310,str4);
	settextstyle(1,0,2);
	otxy(x-220,y-30,"Enter Esc For Back");

	i=0;
	while(1)
	{
		label1:
		read_temp[i]=getch();
		if(read_temp[i]==27||(read_temp[i]=='-'&&i==0)||(read_temp[i]>='0'&&read_temp[i]<='9')||read_temp[i]==8||read_temp[i]=='.'||read_temp[i]=='='||read_temp[i]=='c'||read_temp[i]=='C')
		{
			if(read_temp[i]=='c'||read_temp[i]=='C')
			{
				for(j=0;j<20;j++)
				{
					read_temp[i]='0';
					temp_result1[i]=0;
					temp_result2[i]=0;
					temp_result3[i]=0;
				}
				goto label;
			}
			else if(read_temp[i]==27)
				break;
			else if(read_temp[i]==8 && i>0)//backspace ascii value
			{
				i--;
				read_temp[i]='\0';
				print_temperature(str1);
			}
			else if(read_temp[i]=='=')
			{
				if(i>0)
				{
					read_temp[i]='\0';
					print_temperature(str1);
					if(val==1)
					{
							calc_temp(val);

					}
					else if(val==2)
					{

							calc_temp(val);

					}
					else if(val==3)
					{
							calc_temp(val);

					}
					else if(val==4)
					{
							calc_temp(val);

					}
					settextstyle(1,0,2);
					otxy(10,y-30,"Enter C To Clear");
					break;
				}
				else
				{
					cleardevice();
					goto label;
				}
			}
			else
			{
				read_temp[++i]='\0';
				print_temperature(str1);
			}
		}
	}
}
void print_temperature(char str1[])
{
	char ch[15];

	//input box
	setfillstyle(9,1);
	bar(20,170,250,270);
	rect(19,169,249,271);
	setfillstyle(1,0);
	bar(31,216,234,249);
	rect(30,215,235,250);
	setcolor(15);
	settextstyle(0,0,1);

	setcolor(15);
	settextstyle(1,0,2);
	otxy(40,180,str1);


	setcolor(15);
	settextstyle(0,0,1);
	spf(ch,"%s",read_temp);
	otxy(223-((strlen(ch)-1)*8),235,ch);
}

void calc_temp(int val)
{
	float resultt=atof(read_temp);
	char ch;
	settextstyle(0,0,1);
	if(val==1)
	{
		spf(temp_result1,"%.4f",(resultt-273.15));
		otxy(555-((strlen(temp_result1)-1)*8),106,temp_result1);

		spf(temp_result2,"%.4f",((resultt-273.15)*1.8+32));
		otxy(555-((strlen(temp_result2)-1)*8),235,temp_result2);

		spf(temp_result3,"%.4f",((resultt-273.15)*4)/5);
		otxy(555-((strlen(temp_result3)-1)*8),365,temp_result3);

		settextstyle(1,0,2);
		otxy(10,y-30,"Enter C To Clear");

		label1:
		ch=getch();
		if(ch=='c'||ch=='C')
		{
			enter_temperature(1,"kelvin","celsius","fahrenheit","reaumur",0);
		}
		else if(ch!=27)
			goto label1;

	}
	else if(val==2)
	{
		spf(temp_result1,"%.4f",(resultt+273.15));
		otxy(555-((strlen(temp_result1)-1)*8),106,temp_result1);

		spf(temp_result2,"%.4f",(resultt*1.8)+32);
		otxy(555-((strlen(temp_result2)-1)*8),235,temp_result2);

		spf(temp_result3,"%.4f",((resultt*4)/5));
		otxy(555-((strlen(temp_result3)-1)*8),365,temp_result3);

		settextstyle(1,0,2);
		otxy(10,y-30,"Enter C To Clear");

		label2:
		ch=getch();
		if(ch=='c'||ch=='C')
		{
			enter_temperature(2,"celsius","kelvin","fahrenheit","reaumur",0);
		}
		else if(ch!=27)
			goto label2;
	}
	else if(val==3)
	{
		spf(temp_result1,"%.4f",(resultt-32)*5/9+273);
		otxy(555-((strlen(temp_result1)-1)*8),106,temp_result1);

		spf(temp_result2,"%.4f",((resultt-32)*5/9));
		otxy(555-((strlen(temp_result2)-1)*8),235,temp_result2);

		spf(temp_result3,"%.4f",((resultt-32)*4/9));
		otxy(555-((strlen(temp_result3)-1)*8),365,temp_result3);

		settextstyle(1,0,2);
		otxy(10,y-30,"Enter C To Clear");

		label3:
		ch=getch();
		if(ch=='c'||ch=='C')
		{
			enter_temperature(3,"fahrenheit","kelvin","celsius","reaumur",0);
		}
		else if(ch!=27)
			goto label3;
	}
	else
	{
		spf(temp_result1,"%.4f",(resultt)*5/4+273.15);
		otxy(555-((strlen(temp_result1)-1)*8),106,temp_result1);

		spf(temp_result2,"%.4f",((resultt)*5/4));
		otxy(555-((strlen(temp_result2)-1)*8),235,temp_result2);

		spf(temp_result3,"%.4f",((resultt)*(9/4)+32));
		otxy(555-((strlen(temp_result3)-1)*8),365,temp_result3);

		settextstyle(1,0,2);
		otxy(10,y-30,"Enter C To Clear");

		label4:
		ch=getch();
		if(ch=='c'||ch=='C')
		{
			enter_temperature(4,"reaumur","kelvin","celsius","fahrenheit",0);
		}
		else if(ch!=27)
			goto label4;
	}

}
