#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define N 35
void print(int [][N]);
void movebul(int [][N]);
void movepla(int [][N]);int scr[22][N]={0},pl=9,width=25,speed=3,density=30,score=0,death=0;
int choice;
char a=0,b=0,c=0,d=0;
int user_input;



void hide()
 {
 	HANDLE hout;
     CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(hout, &cursor_info);
 }


void gotoxy(int x,int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}


void print(int a[][N])

{
   gotoxy(0,0);
   //system("cls");
hide();
   int i,j;

   for(i=0;i<22;i++)

   {

     a[i][width-1]=4;//4表示框架 

     for(j=0;j<width;j++)

 {

   if(a[i][j]==0)

      printf(" ");//0表示空白界面 

       if(a[i][j]==1)

          printf("\5");//输出我机的符号

       if(a[i][j]==2)

      printf("|");//子弹

       if(a[i][j]==3)

      printf("$"); //输出敌机符号

       //if(a[i][j]==4)

      //printf("|");

       if(i==0&&j==width-1)

      printf("得分：%d              ",score);//右上角显示得分

       if(i==1&&j==width-1)

      printf("死亡：%d          \n",death),printf("                                                           \n"),printf("                                                                                       ");
      

       

     }

     printf("\n");

  }

}

void movebul(int a[][N])//子弹移动 

{

    int i,j;

    for(i=0;i<22;i++)

        for(j=0;j<width;j++)
        {
          if(i==0&&a[i][j]==2)//子弹不可能出现在第一行 
        a[i][j]=0;
        if(a[i][j]==2)
          {
             if(a[i-1][j]==3)//击中飞机 
             score+=10,printf("\7");
             a[i][j]=0,a[i-1][j]=2;//子弹向上移动 
          }
        }
}

void movepla(int a[][N])//敌人的移动 
{
    int i,j;
    for(i=21;i>=0;i--)//从最后一行往上是为了避免把敌机直接冲出数组。、
        for(j=0;j<width;j++)
        {
           if(i==21&&a[i][j]==3)//敌人到最后一行 
      a[i][j]=0,death=death+1;//底行赋值0 以免越界。
           if(a[i][j]==3)//向下移动 
      a[i][j]=0,a[i+1][j]=3;
        }
    if(a[20][pl]==3&&a[21][pl]==1)//撞上飞机 
     death++;
}



void setting(void)

{

     int sw=0,i,j;
system("cls");
}
void wait()
{
Sleep(100);
user_input=getchar();	
}
void menu(void)

{
   printf("。。。。。。。。。。\n");
   wait();
}


void cls()
{
Sleep(100);
//gotoxy(0,0);
system("cls");	
}
int fly()
{  menu();
    int i=0,j=0;
    scr[21][pl]=1;
    scr[0][5]=3;
    while(death<=10)
    {
  if(kbhit())
  switch(getch())
      {
      case 'a':case 'A':
       if(pl>0)
      scr[21][pl]=0,scr[21][--pl]=1;
   break;
          case 'd':case 'D':
       if(pl<width-2)
      scr[21][pl]=0,scr[21][++pl]=1;
               break;
          case ' ':
       scr[20][pl]=2;
       break; 
      }
  if(++j%30==0)
      {
     j=0;srand(time(NULL));
      scr[0][rand()%width]=3;
      }
      if(++i%9==0)
         movepla(scr);
      movebul(scr);
  
      print(scr);
      if(i==30000)
     i=0;
   }
   return death;}


int main(int argc, char *argv[])
{
	int death=0;
start:cls();
goto a1;
gameover:printf("游戏结束。");

printf("按回车键继续");
cls();
user_input=getchar();
if(user_input=='xd')

goto start;

a1:printf("现在游戏开始,回车键开始您的游戏");
user_input=getchar();
printf("你在高考中发挥正常，考上了西安电子科技大学。\n");
wait();
printf("您即将开始您的大学生活.");
wait();
printf("开学第一天，您和您的父母到达了西安市。");
wait();

goto a4;
a2:cls();
printf("下车后您终于发现您记错了学校名字，您考上的学校叫做西安电子科技大学。\n");
wait();
printf("End01:你居然连你的学校名字都记错，还上什么学，你不配成为西电er,卒！\n");
wait();
goto gameover;

a4:cls();
printf("接下来就要去学校了呢，想想都很激动。");
wait();
printf("您选择哪种方式到达学校呢？\n");
wait();
printf("1-乘坐校车（火车站机场老校区）\n");
printf("2-乘坐公交（411 916 921）\n");
printf("3-打车去，我有钱\n");
s4:wait();
switch(user_input)
{
case'1':goto a6;
case'2':goto a6;
case'3':goto a5;
default:goto s4;
}
a5:cls();
printf("你很快就上了车\n");
wait();
printf("司机问你目的地");
wait();
printf("仔细想了想\n");
wait();
printf("1-西安科技大学\n");
printf("2-西安电子科技大学");
s6:wait();
switch(user_input)
{
case'1':goto a2;
case'2':goto a8;
default:goto s6;
}
a6:cls();
printf("车还没来，需要等待一个多小时，做点什么好呢？\n");
wait();
printf("于是，你拿出手机看新生群，开始水群，熟悉了一遍新生报道流程\n");
wait();
printf("车终于来了，(*^▽^*)开心\n");
wait();
a7:cls();
printf("到达学校还有一段时间，干些什么好呢？\n");
printf("1-玩手机，来一盘紧张刺激的飞机大战\n");
printf("2-睡觉，然后再玩一盘紧张刺激的飞机大战\n");
printf("说明：按A D 控制我机左右飞行，空格发射子弹\n  ");
s7:wait();
switch(user_input)
{
case'1':case'2':goto b1;

default:goto s7;}
b1:fly();
printf("游戏玩够了，车也缓慢停了下来\n");
wait();
  goto a8;






a8:cls();
printf("总算是到达学校了。");
wait();
printf("这就是您即将学习的地方。\n");
wait();
printf("         北雷村男子职业技术学院\n");
wait();
a9:cls();
printf("您决定先去哪里呢？\n");
printf("1-宿舍\n");
printf("2-食堂报道\n");
s9:wait();
switch(user_input)
{
case'1':goto a11;
case'2':goto a10;
default:goto s9;
}
a10:cls();
printf("这真的是超级豪华的食堂呢。");
wait();
printf("手上拿着行李真得很不方便。");
wait();
printf("还是先去宿舍放东西吧。");
wait();
a11:cls();
printf("这就是您超级豪华的宿舍呢\n");
wait();
printf("两室一厅，真的和招生简章上面说的一模一样(*^▽^*)开心");
wait();
printf("您将行李物品放到了床位上\n");
wait();
printf("现在去食堂报道吧。");
wait();
a12:cls();
printf("您排队的时候发现了一个奇怪的现象，");
wait();
printf("怎么没有女孩纸呢？");
wait();
printf("此时，你会怎么做？\n");
printf("1-无所谓啊╮(╯_╰)╭，西电是特色鲜明的工科类院校，男女比例失调很正常\n");
printf("2-没事，我就是女孩纸呢(*?▽?*)\n");
printf("3-不读这个学校了，╭(╯^╰)╮哼\n");
s12:wait();
switch(user_input)
{
case'1':goto a15;
case'2':goto a14;
case'3':goto a13;
default:goto s12;
}
a13:cls();
printf("您很有魄力，");
wait();
printf("但是，作为一个合格的西电er，就要敢于接受残酷的事实，勇于去克服困难，");
wait();
printf("不然，当看到卡成PPT的易迅时，您怎么办");
wait();
printf("End02:您心理承受能力太差，无法接受男女比例失调的事实，卒！");
wait();
goto gameover;
a14:cls();
printf("您居然是女孩纸，");
wait();
printf("这太不可思议了，");
wait();
printf("感谢您为西电男女比例做出的贡献，");
wait();
printf("End03:您真的特别棒，加油，希望在西电的四年好好努力，走上人生巅峰！\n");
wait();
goto gameover;
a15:cls();
printf("您的选择很正常，");
wait();
printf("您很顺利的完成了报道。您是否要回宿舍呢？\n");
printf("1-是的，回宿舍\n");
printf("2-在校园里面逛一逛\n");
s15:wait();
switch(user_input)
{
case'1':goto a16;
case'2':goto a17;
default:goto s15;
}
a16:cls();
printf("您直接回到了宿舍，没有任何特别的事情发生。\n");
wait();
printf("您很谨慎很乖，不在陌生的地方乱跑，这样很安全\n");
wait();
printf("End04：您成为了一个普通朴素的西电er,同时您也错过了一场精彩的冒险\n");
goto gameover;
a17:cls();
printf("您走到一栋教学楼前面\n");
printf("1-进去转转\n");
printf("2-不进去，去别的地方看看\n");
s17:wait();
switch(user_input)
{
case'1':goto a18;
case'2':goto a19;
default:goto s17;
}
a18:cls();
printf("您无意中来到了西电有名的B楼。\n");
wait();
printf("您果然在B楼迷路了。");
wait();
printf("您在B楼遇见了鬼打墙，");
wait();
printf("再也走不出那栋教学楼，成为了一缕游魂，飘荡在B楼...........\n");
printf("End05：您成为了一缕游魂，乖孩子不会去危险的地方\n");
goto gameover;
a19:cls();
printf("您的选择非常明智。\n");
wait();
printf("您很快就熟悉了校园");
wait();
printf("End06：您实在是一个聪明的西电er,B楼还是以后再去探索吧！");
wait();
goto gameover;

}
