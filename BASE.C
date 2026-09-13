char select_base,base_result1[30],base_result2[20],base_result3[20];

void selectbase();
void enterbase(int val,char str1[],char str2[],char str3[],char str4[],int val1);
void btoany(char cha[]);
void dtoany(char cha[]);
void otoany(char cha[]);
void hextoany(char cha[]);


void border();
void loading();

void selectbase()
{
	while(1)
	{
		cld();
		border();
		settextstyle(0,0,2);// font, direction, size
		otxy(223,25,(char *)"SELECT A BASE");
		settextstyle(1,0,2);
		otxy(x-220,y-30,(char *)"Enter Esc For Back");
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

		otxy(168,115,"BINARY");
		otxy(155,128,"  NUMBER");

		otxy(392,115,"  OCTAL");
		otxy(395,128,"  NUMBER");

		otxy(168,246,"DECIMAL");
		otxy(155,258,"  NUMBER");

		otxy(392,246,"HEXADECIMAL");
		otxy(395,258,"NUMBER");

		setcolor(14);
		settextstyle(8,0,1);
		otxy(80,110,"1.");
		otxy(320,110,"2.");
		otxy(80,240,"3.");
		otxy(320,240,"4.");

		select_base=getch();
		if(select_base=='1')
		{
			enterbase(1,"BINARY","OCTAL","DECIMAL","HEXADECIMAL",1);
		}
		else if(select_base=='2')
		{
			enterbase(2,"OCTAL","BINARY","DECIMAL","HEXADECIMAL",1);
		}
		else if(select_base=='3')
		{
			enterbase(3,"DECIMAL","BINARY","OCTAL","HEXADECIMAL",1);
		}
		else if(select_base=='4')
		{
			enterbase(4,"HEXADECIMAL","BINARY","OCTAL","DECIMAL",1);
		}
		else if(select_base==27)
		{
			break;
		}
	}
}


void enterbase(int val,char str1[],char str2[],char str3[],char str4[],int val1)
{
	if(val1==1)
	{
		loading();
	}
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

	if(val==1)
	{
		btoany(str1);
	}
	else if(val==2)
	{
		otoany(str1);
	}
	else if(val==3)
	{
		dtoany(str1);
	}
	else
	{
		hextoany(str1);
	}
}


void btoany(char cha[])
{
	char ch,binary[20]={" "};
	int val=0,j,i,num=0;
	label:
	while(1)
	{
		ch=getch();
		if(ch=='1'||ch=='0')
		{
			binary[val]=ch;
			binary[++val] ='\0';
		}
		else if(ch=='=')
		{
			if(val>0)
				break;
			else
				goto label;
		}
		else if(ch==27)
		{
			return;
		}
		else if(ch==8)
		{
			if(val>0)
				binary[--val]='\0';
			else
				goto label;
		}
		else if(ch=='c'||ch=='C')
		{
			val=0,num=0,i=0,j=0;
			for(i=0;i<20;i++)
			{
				binary[i]='\0';
			}
			goto label;
		}


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
		otxy(40,180,cha);

		settextstyle(0,0,1);
		otxy(223-((strlen(binary)-1)*8),235,binary);
	}
	j=0;
	for(i=val-1;i>=0;i--)
	{
		      num+=(pow(2,i)*(binary[j]-48));
		      j++;
	}

	spf(base_result1,"%d",num);
	otxy(555-((strlen(base_result1)-1)*8),235,base_result1);
	spf(base_result2,"%o",num);
	otxy(555-((strlen(base_result2)-1)*8),106,base_result2);
	spf(base_result3,"%X",num);
	otxy(555-((strlen(base_result3)-1)*8),365,base_result3);


	settextstyle(1,0,2);
	otxy(10,y-30,"Enter C To Clear");


	ch=getch();
	if(ch==27)
	{
		return;
	}
	else if(ch=='c'||ch=='C')
	{
		enterbase(1,"BINARY","OCTAL","DECIMAL","HEXADECIMAL",0);
	}
}


void otoany(char cha[])
{
	char ch,octal[20]={0},binary[65]={0};
	int val=0,i=0;
	long integer=0,temp=0;
	label:
	while(1)
	{
		ch=getch();
		if(ch>='0'&&ch<='7')
		{
			octal[val++]=ch;
			octal[val] ='\0';
		}
		else if(ch=='=')
		{
			if(val>0)
				break;
			else
				goto label;
		}
		else if(ch==27)
		{
			return;
		}
		else if(ch==8)
		{
			if(val>0)
				octal[--val]='\0';
			else
				goto label;
		}
		else if(ch=='c'||ch=='C')
		{
			val=0;
			for(i=0;i<20;i++)
			{
				octal[i]=0;
			}
			goto label;
		}


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
		otxy(40,180,cha);

		settextstyle(0,0,1);
		otxy(223-((strlen(octal)-1)*8),235,octal);
	}
	integer=strtol(octal,NULL,8);

	temp=integer;

	i=0;
	while(temp>0)
	{
		binary[i++]=(temp%2)+'0';
		temp/=2;
	}
	binary[i]='\0';
	strrev(binary);

	spf(base_result1,"%s",binary);
	otxy(555-((strlen(base_result1)-1)*8),106,base_result1);

	spf(base_result2,"%ld",integer);
	otxy(555-((strlen(base_result2)-1)*8),235,base_result2);

	spf(base_result3,"%lX",integer);
	otxy(555-((strlen(base_result3)-1)*8),365,base_result3);


	settextstyle(1,0,2);
	otxy(10,y-30,"Enter C To Clear");


	ch=getch();
	if(ch==27)
	{
		return;
	}
	else if(ch=='c'||ch=='C')
	{
		enterbase(2,"OCTAL","BINARY","DECIMAL","HEXADECIMAL",0);
	}
}



void dtoany(char cha[])
{
	char ch,decimal[20]=" ",binary[60]=" ";
	int val=0,num,i;
	long integer,temp;

	label:
	    while(1)
	    {
		ch=getch();
		if(ch>='0'&&ch<='9')
		{
		    decimal[val++]=ch;
		    decimal[val]='\0';
		}
		else if(ch=='=')
		{
		    if(val>0)
				break;
			else
				goto label;
		}
		else if(ch==27)
		{
		    return;
		}
		else if(ch==8)
		{
			if(val>0)
				decimal[--val]='\0';
			else
				goto label;
		}
		else if(ch=='c'||ch=='C')
		{
		    val=0;
		    for(i=0;i<20;i++)
		    {
			decimal[i]='\0';
		    }
		    goto label;
		}

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
		otxy(40,180,cha);

		settextstyle(0,0,1);
		otxy(223-((strlen(decimal)-1)*8),235,decimal);
	    }

	    integer=atoi(decimal);
	    temp=integer;

	    i=0;
	    while(temp>0)
	    {
		binary[i++]=(temp%2)+'0';
		temp/=2;
	    }
	    binary[i]='\0';
	    strrev(binary);

	    spf(base_result1,"%s",binary);
	    otxy(555-((strlen(base_result1)-1)*8),106,base_result1);

	    spf(base_result2,"%lo",integer);
	    otxy(555-((strlen(base_result2)-1)*8),235,base_result2);

	    spf(base_result3,"%lX",integer);
	    otxy(555-((strlen(base_result3)-1)*8),365,base_result3);

	    settextstyle(1,0,2);
	    otxy(10,y-30,"Enter C To Clear");

	    ch=getch();
	    if(ch==27)
	    {
		return;
	    }
	    else if(ch=='c'||ch=='C')
	    {
		enterbase(3,"DECIMAL","BINARY","OCTAL","HEXADECIMAL",0);
	    }
}



void hextoany(char cha[])
{
	    char ch,hex[20]=" ",binary_str[30]=" ";
	    int val=0,num,i;
	    long integer,temp;

	    label:
	    while(1)
	    {
		ch=getch();
		if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='F')||(ch>='a'&&ch<='f'))
		{
		    hex[val]=ch;
		    hex[++val]='\0';
		}
		else if(ch=='=')
		{
		    if(val>0)
				break;
			else
				goto label;
		}
		else if(ch==27)
		{
		    return;
		}
		else if(ch==8)
		{
			if(val>0)
				hex[--val]='\0';
			else
				goto label;
		}
		else if(ch=='c'||ch=='C')
		{
		    val=0;
		    for(i=0;i<20;i++)
			hex[i]=' ';
		    goto label;
		}

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
		otxy(40,180,cha);

		settextstyle(0,0,1);
		otxy(223-((strlen(hex)-1)*8),235,hex);
	    }

	    integer=strtol(hex,NULL,16);
	    temp=integer;

	    i=0;
	    while(temp>0)
	    {
		binary_str[i++]=(temp%2)+'0';
		temp/=2;
	    }
	    binary_str[i]='\0';
	    strrev(binary_str);

	    spf(base_result1,"%s",binary_str);
	    otxy(555-((strlen(base_result1)-1)*8),106,base_result1);

	    spf(base_result2,"%lo",integer);
	    otxy(555-((strlen(base_result2)-1)*8),235,base_result2);

	    spf(base_result3,"%ld",integer);
	    otxy(555-((strlen(base_result3)-1)*8),365,base_result3);

	    settextstyle(1,0,2);
	    otxy(10,y-30,"Enter C To Clear");

	    ch=getch();
	    if(ch==27)
	    {
		return;
	    }
	    else if(ch=='c'||ch=='C')
	    {
		enterbase(4,"HEXADECIMAL","BINARY","OCTAL","DECIMAL",0);
	    }
}
