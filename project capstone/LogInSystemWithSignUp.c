#include<conio.h>
#include<stdio.h>
#include<string.h>
static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
void login(void);
void reg(void);
int main()
{
printf("\nWELCOME TO MY WEBSITE");
XY:
printf("\n1. LOGIN\t\t2. REGISTER");
printf("\nENTER YOUR CHOICE: ");
scanf("%d",&n);
switch(n)
  {
    case 1: login();
        break;
    case 2:reg();
        break;
    default: printf("\nNO MATCH FOUND");
        printf("\nPress Enter to re-Enter the choice");
        if(getch()==13)
        goto XY;
  }
  return 0;
}
void reg()
  {
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("hasib666.txt","w");
    printf("\nWELCOME TO REGISTER ZONE");
    for(i=0;i<100;i++)
    {
      printf("\n ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\nUSERNAME ALREDY EXISTS");
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            break;
          }
        }
      printf("\n DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[i],sizeof(w[i]),1,fp);
      fclose(fp);
      printf("\nPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        printf("\nYou are successfully registered");
        printf("\nTry login your account??\n ");
        printf("> PRESS 1 FOR YES\n  > PRESS 2 FOR NO\n");
        scanf("%d",&n);
        switch(n)
          {
              case 1: login();
                    break;
              case 2:printf("\nTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
    getch();
  }
  void login()
    {
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("hasib666.txt","r");
      printf("\nWELCOME TO LOG IN ZONE");
      for(i=0;i<1000;i++)
      {
        printf("\n  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass);
          if(checku==0&&checkp==0)
          {
            printf("\nYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\nWELCOME, HAVE A NICE DAY");
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\nWRONG PASSWORD!! Not %s??",name);
            printf("\n (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\nYou are not a Registered User\n Press enter to register yourself");
            if(getch()==13)
            reg();
          }
        }
        
        break;
      }
      getch();
    }