 #include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
  char *c=0;
  int i=0,j=0,s=0,k=0,z=0,y=0,x=0,u=0,v=0,es=0;
  clrscr();
  ifstream fin("input.txt");
  if(!fin)
  {
  cout<<"\nerror while opening file";
  }
  fin.getline(c,800);
  s=strlen(c);
  fin.close();
  ofstream fout("output.txt");
  fout<<"the input is " <<c<<endl;
  for(i=0;i<s;i++)
  { if(c[i]==0)
  {
  exit(0);
  }
    if(isalpha(c[i])&&c[i+1]!='/'&&c[i+1]!='*'&&c[i+1]!='.')
       {
       cout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       fout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       j++;
       es=j;
       }
    if(isalpha(c[i])&&c[i+1]=='.'&&isalpha(c[i+2]))
       {

       cout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       fout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       j++;
       cout<<"\nq["<<j<<","<<c[i+2]<<"]--->"<<j+1;
       fout<<"\nq["<<j<<","<<c[i+2]<<"]--->"<<j+1;
       j++;
       i+=2;
       es=j;
       }
    if(isalpha(c[i])&&c[i+1]=='/'&&isalpha(c[i+2]))
       {
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       cout<<"\nq["<<j<<",e]--->"<<j+2;
       fout<<"\nq["<<j<<",e]--->"<<j+2;
       j++;
       cout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+2;
       fout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+2;
       j++;
       cout<<"\nq["<<j<<","<<c[i+2]<<"]--->"<<j+2;
       fout<<"\nq["<<j<<","<<c[i+2]<<"]--->"<<j+2;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j+2;
       fout<<"\nq["<<j<<",e]--->"<<j+2;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       j++;
       i+=2;
       es=j;
       }


    if(isalpha(c[i])&&c[i+1]=='*')
       {
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       cout<<"\nq["<<j<<",e]--->"<<j+3;
       fout<<"\nq["<<j<<",e]--->"<<j+3;
       j++;
       cout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       fout<<"\nq["<<j<<","<<c[i]<<"]--->"<<j+1;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j-1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j-1;
       j++;
       es=j;
       }
    if(c[i]==')'&&c[i+1]=='*'&&isalpha(c[i-1])&&isalpha(c[i-3])&&c[i-2]=='/')
      {
       cout<<"\nq["<<j-7<<",e]--->"<<j;
       fout<<"\nq["<<j-7<<",e]--->"<<j;
       cout<<"\nq["<<j-1<<",e]--->"<<j-6;
       fout<<"\nq["<<j-1<<",e]--->"<<j-6;
       es=j;
      }
    if(c[i]=='(')
      {
      for(k=i;k<=s;k++)
      {
  if(c[k]==')')
   {
   z=k;
   break;
   }
      }
      for(k=i;k<z;k++)
      {
   if(c[k]=='/')
   {
   y=k;
   break;
   }
      }
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       j++;
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       cout<<"\nq["<<j<<",e]--->"<<j+2;
       fout<<"\nq["<<j<<",e]--->"<<j+2;
       x=j+2;
       u=j;  // starting state j=1
       j++;
       es=j;
      for(k=i;k<=y;k++)
 {

 if(isalpha(c[k])&&c[k+1]!='*'&&c[k+1]!='.')
    {
    cout<<"\nq["<<j<<","<<c[k]<<"]--->"<<j+2;
    fout<<"\nq["<<j<<","<<c[k]<<"]--->"<<j+2;
    j+=2;
    es=j;
   }
  if(isalpha(c[k])&&c[k+1]=='.'&&isalpha(c[k+2]))
      {
      cout<<"\nq["<<j<<","<<c[k]<<"]--->"<<j+2;
      fout<<"\nq["<<j<<","<<c[k]<<"]--->"<<j+2;
      j+=2;
      cout<<"\nq["<<j<<","<<c[k+2]<<"]--->"<<j+2;
      fout<<"\nq["<<j<<","<<c[k+2]<<"]--->"<<j+2;
      j+=2;
      k++;
      es=j;
   }

 }
  for(k=y;k<=z;k++)
 {

 if(isalpha(c[k])&&c[k+1]!='/'&&c[k+1]!='*'&&c[k+1]!='.')
    {
    cout<<"\nq["<<x<<","<<c[k]<<"]--->"<<x+2;
    fout<<"\nq["<<x<<","<<c[k]<<"]--->"<<x+2;
    x+=2;
    }
  if(isalpha(c[k])&&c[k+1]=='.'&&isalpha(c[k+2]))
     {
      cout<<"\nq["<<x<<","<<c[k]<<"]--->"<<x+2;
      fout<<"\nq["<<x<<","<<c[k]<<"]--->"<<x+2;
      x+=2;
      cout<<"\nq["<<x<<","<<c[k+2]<<"]--->"<<x+2;
      fout<<"\nq["<<x<<","<<c[k+2]<<"]--->"<<x+2;
      x+=2;
      k+=2;
     }
 }
 if(j<x)
 {
  cout<<"\nq["<<j<<",e]--->"<<x+1;
  fout<<"\nq["<<j<<",e]--->"<<x+1;
  cout<<"\nq["<<x<<",e]--->"<<x+1;
  fout<<"\nq["<<x<<",e]--->"<<x+1;
  j=x+1;
  v=j;    //last state
  cout<<"\nq["<<j<<",e]--->"<<j+1;
  fout<<"\nq["<<j<<",e]--->"<<j+1;
  j++;
  i=i+z;
  es=j;
 }
 else
 {
       cout<<"\nq["<<j<<",e]--->"<<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       cout<<"\nq["<<x<<",e]--->"<<j+1;
       fout<<"\nq["<<x<<",e]--->"<<j+1;
       j=j+1;
       v=j;    //last state
       cout<<"\nq["<<j<<",e]--->" <<j+1;
       fout<<"\nq["<<j<<",e]--->"<<j+1;
       j++;
       i=i+z;
       es=j;
 }

 if (c[z+1]=='*')
   {
    cout<<"\nq["<<u-1<<",e]--->" <<v+1;
    fout<<"\nq["<<u-1<<",e]--->"<<v+1;
    cout<<"\nq["<<v<<",e]--->" <<u;
    fout<<"\nq["<<v<<",e]--->"<<u;
    }

 }
  }
    cout<<"\n starting state is 0";
    fout<<"\n starting state is 0";
    cout<<"\n ending state is "<<es;
    fout<<"\n ending state is "<<es;
  fout.close();
  getch();
  return(0);
}