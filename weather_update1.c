#include<stdio.h>
#include<string.h>
#define ss 5            //struct size
char citykey[10];
int ch,flag=0,codekey,mm;
typedef struct weather{
    unsigned int citycode;
    char cityname[10];
    int temp;
    int humidity;
    int pressure;
}weather;
const int name_length=20;
void displaysingle(const weather*);             //display single record
void displayAll(const weather*,int);            //display all records
weather* find(weather*,int,int);          //find record by city code
weather* findc(weather*,int,char*);      //find record by  city name
int main(void)
{
    weather wptr[ss]={{10000,"Bangalore",20,40,2},{10001,"Pune",18,50,3},{10002,"Delhi",10,10,1},{10003,"Chennai",24,10,5},{10004,"Kolkata",15,35,4}};
    displayAll(wptr,5);
    printf("\n\n");
    printf("Enter your choice\n\n");
    do
    {
      printf("1 - Print all city  records.\n2 - Find city record by entering city code\n");
      printf("3 - Find city record by entering city name\n");
      scanf("%d",&ch);
      if(ch==1)
      {
         displayAll(wptr,ss);
      }
      else  if(ch==2)
      {
         printf("\nEnter city code to be searched:\t");
         scanf("%d",&codekey);
         weather *f1=find(wptr,ss,codekey);
         displaysingle(f1);
      }
      else if(ch==3)
      {
         printf("\nEnter city name to be searched:\t");
         scanf("%s",&citykey);
         weather *f1=findc(wptr,ss,&citykey);
         displaysingle(f1);
      }
      else
      {
            printf("\nInvalid Input");
      }
      printf("\n\nEnter 1 to return to main menu\t");
      scanf("%d",&mm);
      if (mm!=1)
        flag=1;
    }while(flag==0);
    return 0;
}
void displaysingle(const weather *ptr)
{
    printf("City Code->%u\t City Name->%s\t Temperature->%d\t Humidity->%d\t Pressure->%d\n",ptr->citycode,ptr->cityname,ptr->temp,ptr->humidity,ptr->pressure);
}

void displayAll(const weather *f,int n)
{
    const weather *pc=f;
    for(int i=0;i<n;i++)
        displaysingle(pc++);
}

weather* find(weather *f1,int n,int cc)
{
    weather *pc=f1;
    for(int i=0;i<n;i++)
    {
     if ((pc->citycode)==cc)
            return pc;
     pc++;
    }

}

weather* findc(weather *f2,int n,char* cc)
{
    weather *pc=f2;
    for(int i=0;i<n;i++)
    {
     if (strcmp((pc->cityname),cc)==0)
            return pc;
     pc++;
    }

}


