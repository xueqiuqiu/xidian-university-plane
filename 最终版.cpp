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

     a[i][width-1]=4;//4��ʾ��� 

     for(j=0;j<width;j++)

 {

   if(a[i][j]==0)

      printf(" ");//0��ʾ�հ׽��� 

       if(a[i][j]==1)

          printf("\5");//����һ��ķ���

       if(a[i][j]==2)

      printf("|");//�ӵ�

       if(a[i][j]==3)

      printf("$"); //����л�����

       //if(a[i][j]==4)

      //printf("|");

       if(i==0&&j==width-1)

      printf("�÷֣�%d              ",score);//���Ͻ���ʾ�÷�

       if(i==1&&j==width-1)

      printf("������%d          \n",death),printf("                                                           \n"),printf("                                                                                       ");
      

       

     }

     printf("\n");

  }

}

void movebul(int a[][N])//�ӵ��ƶ� 

{

    int i,j;

    for(i=0;i<22;i++)

        for(j=0;j<width;j++)
        {
          if(i==0&&a[i][j]==2)//�ӵ������ܳ����ڵ�һ�� 
        a[i][j]=0;
        if(a[i][j]==2)
          {
             if(a[i-1][j]==3)//���зɻ� 
             score+=10,printf("\7");
             a[i][j]=0,a[i-1][j]=2;//�ӵ������ƶ� 
          }
        }
}

void movepla(int a[][N])//���˵��ƶ� 
{
    int i,j;
    for(i=21;i>=0;i--)//�����һ��������Ϊ�˱���ѵл�ֱ�ӳ�����顣��
        for(j=0;j<width;j++)
        {
           if(i==21&&a[i][j]==3)//���˵����һ�� 
      a[i][j]=0,death=death+1;//���и�ֵ0 ����Խ�硣
           if(a[i][j]==3)//�����ƶ� 
      a[i][j]=0,a[i+1][j]=3;
        }
    if(a[20][pl]==3&&a[21][pl]==1)//ײ�Ϸɻ� 
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
   printf("��������������������\n");
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
gameover:printf("��Ϸ������");

printf("���س�������");
cls();
user_input=getchar();
if(user_input=='xd')

goto start;

a1:printf("������Ϸ��ʼ,�س�����ʼ������Ϸ");
user_input=getchar();
printf("���ڸ߿��з����������������������ӿƼ���ѧ��\n");
wait();
printf("��������ʼ���Ĵ�ѧ����.");
wait();
printf("��ѧ��һ�죬�������ĸ�ĸ�����������С�");
wait();

goto a4;
a2:cls();
printf("�³��������ڷ������Ǵ���ѧУ���֣������ϵ�ѧУ�����������ӿƼ���ѧ��\n");
wait();
printf("End01:���Ȼ�����ѧУ���ֶ��Ǵ�����ʲôѧ���㲻���Ϊ����er,�䣡\n");
wait();
goto gameover;

a4:cls();
printf("��������ҪȥѧУ���أ����붼�ܼ�����");
wait();
printf("��ѡ�����ַ�ʽ����ѧУ�أ�\n");
wait();
printf("1-����У������վ������У����\n");
printf("2-����������411 916 921��\n");
printf("3-��ȥ������Ǯ\n");
s4:wait();
switch(user_input)
{
case'1':goto a6;
case'2':goto a6;
case'3':goto a5;
default:goto s4;
}
a5:cls();
printf("��ܿ�����˳�\n");
wait();
printf("˾������Ŀ�ĵ�");
wait();
printf("��ϸ������\n");
wait();
printf("1-�����Ƽ���ѧ\n");
printf("2-�������ӿƼ���ѧ");
s6:wait();
switch(user_input)
{
case'1':goto a2;
case'2':goto a8;
default:goto s6;
}
a6:cls();
printf("����û������Ҫ�ȴ�һ����Сʱ������ʲô���أ�\n");
wait();
printf("���ǣ����ó��ֻ�������Ⱥ����ʼˮȺ����Ϥ��һ��������������\n");
wait();
printf("���������ˣ�(*^��^*)����\n");
wait();
a7:cls();
printf("����ѧУ����һ��ʱ�䣬��Щʲô���أ�\n");
printf("1-���ֻ�����һ�̽��Ŵ̼��ķɻ���ս\n");
printf("2-˯����Ȼ������һ�̽��Ŵ̼��ķɻ���ս\n");
printf("˵������A D �����һ����ҷ��У��ո����ӵ�\n  ");
s7:wait();
switch(user_input)
{
case'1':case'2':goto b1;

default:goto s7;}
b1:fly();
printf("��Ϸ�湻�ˣ���Ҳ����ͣ������\n");
wait();
  goto a8;






a8:cls();
printf("�����ǵ���ѧУ�ˡ�");
wait();
printf("�����������ѧϰ�ĵط���\n");
wait();
printf("         ���״�����ְҵ����ѧԺ\n");
wait();
a9:cls();
printf("��������ȥ�����أ�\n");
printf("1-����\n");
printf("2-ʳ�ñ���\n");
s9:wait();
switch(user_input)
{
case'1':goto a11;
case'2':goto a10;
default:goto s9;
}
a10:cls();
printf("������ǳ���������ʳ���ء�");
wait();
printf("��������������úܲ����㡣");
wait();
printf("������ȥ����Ŷ����ɡ�");
wait();
a11:cls();
printf("�����������������������\n");
wait();
printf("����һ������ĺ�������������˵��һģһ��(*^��^*)����");
wait();
printf("����������Ʒ�ŵ��˴�λ��\n");
wait();
printf("����ȥʳ�ñ����ɡ�");
wait();
a12:cls();
printf("���Ŷӵ�ʱ������һ����ֵ�����");
wait();
printf("��ôû��Ů��ֽ�أ�");
wait();
printf("��ʱ�������ô����\n");
printf("1-����ν���r(�s_�t)�q����������ɫ�����Ĺ�����ԺУ����Ů����ʧ��������\n");
printf("2-û�£��Ҿ���Ů��ֽ��(*?��?*)\n");
printf("3-�������ѧУ�ˣ��q(�s^�t)�r��\n");
s12:wait();
switch(user_input)
{
case'1':goto a15;
case'2':goto a14;
case'3':goto a13;
default:goto s12;
}
a13:cls();
printf("������������");
wait();
printf("���ǣ���Ϊһ���ϸ������er����Ҫ���ڽ��ܲп����ʵ������ȥ�˷����ѣ�");
wait();
printf("��Ȼ������������PPT����Ѹʱ������ô��");
wait();
printf("End02:�������������̫��޷�������Ů����ʧ������ʵ���䣡");
wait();
goto gameover;
a14:cls();
printf("����Ȼ��Ů��ֽ��");
wait();
printf("��̫����˼���ˣ�");
wait();
printf("��л��Ϊ������Ů���������Ĺ��ף�");
wait();
printf("End03:������ر�������ͣ�ϣ�������������ú�Ŭ�������������۷壡\n");
wait();
goto gameover;
a15:cls();
printf("����ѡ���������");
wait();
printf("����˳��������˱��������Ƿ�Ҫ�������أ�\n");
printf("1-�ǵģ�������\n");
printf("2-��У԰�����һ��\n");
s15:wait();
switch(user_input)
{
case'1':goto a16;
case'2':goto a17;
default:goto s15;
}
a16:cls();
printf("��ֱ�ӻص������ᣬû���κ��ر�����鷢����\n");
wait();
printf("���ܽ����ܹԣ�����İ���ĵط����ܣ������ܰ�ȫ\n");
wait();
printf("End04������Ϊ��һ����ͨ���ص�����er,ͬʱ��Ҳ�����һ�����ʵ�ð��\n");
goto gameover;
a17:cls();
printf("���ߵ�һ����ѧ¥ǰ��\n");
printf("1-��ȥתת\n");
printf("2-����ȥ��ȥ��ĵط�����\n");
s17:wait();
switch(user_input)
{
case'1':goto a18;
case'2':goto a19;
default:goto s17;
}
a18:cls();
printf("������������������������B¥��\n");
wait();
printf("����Ȼ��B¥��·�ˡ�");
wait();
printf("����B¥�����˹��ǽ��");
wait();
printf("��Ҳ�߲����Ƕ���ѧ¥����Ϊ��һ���λ꣬Ʈ����B¥...........\n");
printf("End05������Ϊ��һ���λ꣬�Ժ��Ӳ���ȥΣ�յĵط�\n");
goto gameover;
a19:cls();
printf("����ѡ��ǳ����ǡ�\n");
wait();
printf("���ܿ����Ϥ��У԰");
wait();
printf("End06����ʵ����һ������������er,B¥�����Ժ���ȥ̽���ɣ�");
wait();
goto gameover;

}
