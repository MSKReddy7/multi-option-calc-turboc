#include "msk.h"

void select_temperature(); // Forward declaration from temp.c

#include "temp.c"
#include "base.c"

char evaluate[60]={0},expression[30]={0};double result[30]={0};

void drawbk();

void show_calcs();
int select_calc();
void calculator();
void printexpression();
void infix(char s[]);
int precision(char c);
int isinteger(float number);

void border();
void start();
void loading();

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	start();
	while(1)
	{
		cleardevice();
		show_calcs();
		if(!select_calc()) break;
	}

	closegraph();
}

void show_calcs()
{
	border();
	settextstyle(0,0,2);// font, direction, size
	otxy(170,25,"SELECT A CALCULATOR");
	settextstyle(1,0,2);
	otxy(x-190,y-30,"Enter Esc To Exit");
	////////\\\\\\\\
	setcolor(6);
	setfillstyle(1,1);

	bar(208,152,402,108);
	rect(210,150,400,110);rect(208,152,402,108);

	bar(208,217,402,173);
	rect(210,215,400,175);rect(208,217,402,173);

	bar(208,282,402,238);
	rect(210,280,400,240);rect(208,282,402,238);

	bar(208,347,402,303);
	rect(210,345,400,305);rect(208,347,402,303);
	//COLOR
	setcolor(10);
	settextstyle(2,0,5); // FONT,DIRECTION,SIZE

	otxy(278,115,"DEFAULT");
	otxy(265,128,"CALCULATOR");

	otxy(262,182,"TEMPERATURE");
	otxy(265,194,"CALCULATOR");

	otxy(280,246," BASE");
	otxy(265,258,"CALCULATOR");

	otxy(280,311,"MATRIX");
	otxy(265,323,"CALCULATOR");

	setcolor(14);
	settextstyle(8,0,1);
	otxy(178,100,"1.");
	otxy(178,165,"2.");
	otxy(178,230,"3.");
	otxy(178,295,"4.");
}

int select_calc()
{
	char calc;
	read:
	calc=getch();

	if(calc=='1')
		calculator();
	else if(calc=='2')
		select_temperature();
	else if(calc=='3')
		selectbase();
	else if(calc=='4')
		calculator();
	else if(calc==27)
		return 0;
	else
		goto read;

	return 1;
}

void calculator()
{
	char var;
	int i=0,j=0;
	loading();

	label:
	border();

	settextstyle(1,0,2);
	otxy(x-75,y-40,"BACK");
	rectangle(555,435,620,468);

	settextstyle(0,0,1);
	//border of calc
	setfillstyle(1,1);
	bar(166,56,422,412);
	setcolor(15);
	rect(166,56,422,412);

	//output screen of calc
	setfillstyle(1,8);
	bar(171,61,417,142);
	setcolor(0);
	rect(171,61,417,142);

	//input screen of calc
	setcolor(0);
	rect(174,64,414,100);//180 90
	setcolor(15);

	//-- in the text screen
	settextstyle(0,0,1);
	otxy(395,90,"--");

	// 0 in the result screen
	settextstyle(1,0,3);
	otxy(398,114,"0.");

	settextstyle(0,0,1);
	//buttons screen of calc
	setfillstyle(1,9);
	bar(171,152,417,406);
	setcolor(0);
	rect(171,151,417,406);

	//buttons
	setcolor(0);
	setfillstyle(1,9);

	bar(180,210,230,250);
	rect(180,210,230,250);
	otxy(200,226,"7");

	bar(240,210,290,250);
	rect(240,210,290,250);
	otxy(260,226,"8");

	bar(300,210,350,250);
	rect(300,210,350,250);
	otxy(320,226,"9");

	bar(180,260,230,300);
	rect(180,260,230,300);
	otxy(200,276,"4");

	bar(240,260,290,300);
	rect(240,260,290,300);
	otxy(260,276,"5");

	bar(300,260,350,300);
	rect(300,260,350,300);
	otxy(320,276,"6");

	bar(180,310,230,350);
	rect(180,310,230,350);
	otxy(200,326,"1");

	bar(240,310,290,350);
	rect(240,310,290,350);
	otxy(260,326,"2");

	bar(300,310,350,350);
	rect(300,310,350,350);
	otxy(320,326,"3");

	bar(240,360,290,400);
	rect(240,360,290,400);
	otxy(260,376,"0");

	setfillstyle(1,1);

	bar(300,160,350,200);
	rect(300,160,350,200);
	otxy(320,176,"^");

	bar(360,210,410,250);
	rect(360,210,410,250);
	otxy(380,226,"+");

	bar(360,260,410,300);
	rect(360,260,410,300);
	otxy(380,276,"_");

	bar(360,310,410,350);
	rect(360,310,410,350);
	otxy(381,326,"*");

	bar(180,360,230,400);
	rect(180,360,230,400);
	otxy(200,376,".");

	bar(300,360,350,400);
	rect(300,360,350,400);
	otxy(320,376,"/");

	setfillstyle(1,4);

	bar(180,160,230,200);
	rect(180,160,230,200);
	settextstyle(1,0,1);
	otxy(200,170,"C");

	bar(360,160,410,200);
	rect(360,160,410,200);
	settextstyle(0,0,0);
	drawbk();

	setfillstyle(1,3);
	bar(240,160,290,200);
	rect(240,160,290,200);
	otxy(253,178,"SCI ");

	setfillstyle(1,2);
	bar(360,360,410,400);
	rect(360,360,410,400);
	otxy(380,376,"=");

	i=0;
	while(1)
	{
		label1:
		expression[i]=getch();
		if((expression[i]>='0'&&expression[i]<='9')||expression[i]=='c'||expression[i]=='C'||expression[i]==27||expression[i]=='.'||expression[i]=='='||expression[i]=='+'||expression[i]=='-'||expression[i]=='/'||expression[i]=='*'||expression[i]=='^'||expression[i]==8||expression[i]=='('||expression[i]==')')
		{
			if(expression[i]=='c'|| expression[i]=='C')
			{
				for(j=0;j<30;j++)
				{
					expression[i]='0';
					result[i]=0;
				}
				goto label;
			}
			else if(expression[i]==27)//esc ascii value
				return;
			else if(expression[i]==8)//backspace ascii value
			{
				if(i>0)
				{
					i--;
					expression[i]='\0';
					printexpression();
					goto label1;
				}
				else
				{
					cleardevice();
					goto label;
				}
			}
			else if(expression[i]=='=')
			{
				if(i>0)
				{
					expression[i]='\0';
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
				expression[i+1]='\0';
				printexpression();
			}
		}
		else
			goto label1;

		i++;
	}

	infix(expression);

	label2:
	var=getch();
	if(var=='C'||var=='c')
	{
		for(j=0;j<30;j++)
		{
			expression[j]='0';
			result[j]=0;
		}
		goto label;
	}
	else if(var!=27)//esc key
		goto label2;
}

void printexpression()
{
	// Output screen of calc
	setfillstyle(1,8);
	bar(171,61,417,142);
	setcolor(0);
	rect(171,61,417,142);
	// Input screen of calc
	setcolor(0);
	bar(396,80,413,99);
	rect(174,64,414,100);
	bar(390,75,410,95);

	setcolor(15);
	settextstyle(0,0,1);
	setcolor(15);
	otxy(400-((strlen(expression)-1)*8),90,expression);
}

int precision(char c)
{
	if(c=='^')
		return 3;
	else if(c=='/'||c=='*')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}

int isinteger(float number)
{
	int integerpart;
	double fractionalpart;

	integerpart=(int)number;
	fractionalpart=number-integerpart;

	if(fractionalpart==0)
		return 1;
	return 0;
}

void infix(char s[])
{
	int resultindex=-1;
	char stack[30];
	int stackindex=-1;
	int i=0,tempindex=0;
	double a,b;
	char temp1[30];
	char temp[30];

	check:
	i=0;
	while(i<strlen(s))
	{
		if((s[i]=='+'||s[i]=='-')&&s[i+1]=='(')
		{
			int j=0,k=0,a=0;
			while(j<=i)
			{
				evaluate[j]=s[k];
				j++;
				k++;
			}
			evaluate[j]='1';
			evaluate[++j]='*';
			while(j<=strlen(s))
			{
				j++;
				evaluate[j]=s[k];
				evaluate[j+1]='\0';
				k++;
			}
			s[j+1]='\0';
			for(a=0;a<strlen(evaluate);a++)
			{
				s[a]=evaluate[a];
			}
			goto check;
		}
		else if(i==strlen(s)-1)
		{
			break;
		}
		i++;
	}
	i=0;
	while(i<strlen(s))
	{
		if((s[i]>='0'&&s[i]<='9')&&s[i+1]=='(')
		{
			int j=0,k=0,a=0;
			while(j<=i)
			{
				evaluate[j]=s[k];
				j++;
				k++;
			}
			evaluate[j]='*';
			while(j<strlen(s))
			{
				j++;
				evaluate[j]=s[k];
				evaluate[j+1]='\0';
				k++;
			}
			s[j+1]='\0';
			for(a=0;a<strlen(evaluate);a++)
			{
				s[a]=evaluate[a];
			}
			goto check;
		}
		else if(i==strlen(s)-1)
		{
			break;
		}
		i++;
	}
	i=0;
	while(i<strlen(s))
	{
		char c=s[i];
		if ((c=='-'||c=='+')&&(i==0||s[i-1]=='^'||s[i-1]=='('||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'))
		{
			i++;
			temp[0]=c;
			tempindex=1;

			while ((s[i]>='0'&&s[i]<='9')||s[i]=='.')
			{
				temp[tempindex++]=s[i++];
			}

			temp[tempindex] = '\0';
			result[++resultindex] = atof(temp);  // Convert to a negative number and store it
			i--;
		}
		else if((c>='0'&&c<='9')||c=='.')
		{
			int tempindex=0;
			while((s[i]>='0'&&s[i]<='9')||s[i]=='.')
			{
				temp[tempindex++]=s[i++];
			}
			temp[tempindex]='\0';
			result[++resultindex]=atof(temp);
			i--;
		}
		else if(c=='(')
		{
		    stack[++stackindex]=c;
		}
		else if(c==')')
		{
			while(stackindex>=0&&stack[stackindex]!='(')
			{
				b=result[resultindex--];
				a=result[resultindex--];
				switch(stack[stackindex])
				{
					case '+':result[++resultindex]=a+b;break;
					case '-':result[++resultindex]=a-b;break;
					case '*':result[++resultindex]=a*b;break;
					case '/':
						if(b==0)
						{
							settextstyle(1,0,3);
							otxy(360,114,"Error");//Division by zero
							return;
						}
						else
							result[++resultindex]=a/b;
						break;
					case '^':result[++resultindex]=pow(a,b);break;
					default:
						settextstyle(1,0,3);
						otxy(360,114,"Error");//Invalid operator
						return;
				}
				stackindex--;
		    }
		    if(stackindex<0||stack[stackindex]!='(')
		    {
				settextstyle(1,0,3);
				otxy(360,114,"Error");//Mismatched parentheses
				return;
		    }
		    stackindex--;
		}
		else
		{
			while(stackindex>=0&&precision(c)<=precision(stack[stackindex]))
			{
				b=result[resultindex--];
				a=result[resultindex--];
				switch(stack[stackindex])
				{
				    case '+':result[++resultindex]=a+b;break;
				    case '-':result[++resultindex]=a-b;break;
				    case '*':result[++resultindex]=a*b;break;
				    case '/':
						if(b==0)
						{
						    settextstyle(1,0,3);
						    otxy(360,114,"Error");//Division by zero
						    return;
						}
						else
							result[++resultindex]=a/b;
						break;
				    case '^':result[++resultindex]=pow(a,b);break;
				    default:
						settextstyle(1,0,3);
						otxy(360,114,"Error");//Invalid operator
						return;
				}
				stackindex--;
		    }
		    stack[++stackindex]=c;
		}
		i++;
	}
	while(stackindex>=0&&resultindex>0)
	{
		b=result[resultindex--];
		a=result[resultindex--];
		switch(stack[stackindex])
		{
		    case '+':result[++resultindex]=a+b;break;
		    case '-':result[++resultindex]=a-b;break;
		    case '*':result[++resultindex]=a*b;break;
		    case '/':
				if(b==0)
				{
				    settextstyle(1,0,3);
				    otxy(360,114,"Error");//Division by zero
				    return;
				}
				else
					result[++resultindex]=a/b;
				break;
		    case '^':result[++resultindex]=pow(a,b);break;
		    default:
				settextstyle(1,0,3);
				otxy(360,114,"Error");//Invalid operator
				return;
		}
		stackindex--;
	}
	if(stackindex>=0)
	{
		settextstyle(1,0,3);
		otxy(360,114,"Error");//Mismatched operators or parentheses
	}
	else
	{
		if(isinteger(result[0])==1)
		{
			settextstyle(1,0,3);
			spf(temp1,"%.0f",result[0]);
			otxy(400-((strlen(temp1))-1)*15,114,temp1);
		}
		else
		{
			settextstyle(1,0,3);
			spf(temp1,"%.5f",result[0]);
			otxy(400-((strlen(temp1))-1)*15,114,temp1);
		}
	}
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

void start()
{
	border();

	setcolor(4);
	settextstyle(0,0,4);
	moveto(20,getmaxy()/2-30);
	outtext("C ");
	delay(250);
	outtext("A ");
	delay(250);
	outtext("L ");
	delay(250);
	outtext("C ");
	delay(250);
	outtext("U ");
	delay(250);
	outtext("L ");
	delay(250);
	outtext("A ");
	delay(250);
	outtext("T ");
	delay(250);
	outtext("O ");
	delay(250);
	outtext("R ");
	delay(500);
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

void drawbk()
{
	setcolor(0);
	settextstyle(2,0,7);
	//rectangle
	rect(381,170,401,190);
	//triangles
	line(372,180,381,170);
	line(372,180,381,190);
	//to clear left side line
	bar(381,171,382,189);
	//text
	otxy(386,168,"X");

	settextstyle(0,0,0);
}