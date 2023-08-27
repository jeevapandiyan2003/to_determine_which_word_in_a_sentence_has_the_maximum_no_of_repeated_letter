#include <iostream>
#include<string>
using namespace std;
void process(string arx[10],int range)
{
  
  int sortn[10];//to store the repetatio number for each word
  for(int k=0;k<=range;k++)//to find the above comment
  {
    string samp=arx[k];
    for(int i=0;i<samp.size();i++)//making that in accending order
    {
      char mini=samp[i];
      for(int j=i+1;j<samp.size();j++)
      { 
        if(samp[j]<mini)
        {
          samp[i]=samp[j];
          samp[j]=mini;
          mini=samp[i];
          
        }
        
      }
    }
    int chartt=0;
    int repeat=1;
    char min=samp[0];
    
    for(int z=1;z<samp.size();z++)// find the no of repeation occureed in a word and storing it in array
    {
      if(samp[z]==min)
      {
        repeat+=1;//no of repetation of single letter
      }
      else
      {
        if(repeat>1)
        {
          chartt+=1;// if there is a repeation in letter then add 1 that reperesent the one letter is repeated
          
        }
        repeat=1;
        min=samp[z];
      }
      if(z==samp.size()-1)// ending two letter is repeated
      {
        if(repeat>1)
        {
          chartt+=1;
          
        }
      }
    }
    sortn[k]=chartt;
    
  }
  int samp=sortn[0];
  int indexx=0;
  for(int rr=1;rr<=range;rr++)// finding the index for which has the most repeated letter
  {
    if(sortn[rr]>samp)
    {
      samp=sortn[rr];
      indexx=rr;
    }
  }
  cout<<arx[indexx];//returnig the word with maximum repetation
}

int main() 
{
 string sent;
 int x=0;
 getline(cin,sent);
 string arr[10];
 string sum="";
 for(int i=0;i<sent.size();i++)//to separate a sentence into words and puting in array
 {
   if(sent[i]!=' ')
   {
     sum+=sent[i];
   }
  
   else
   {
     arr[x]=sum;
     x+=1;
     sum="";
   }
   if(i==(sent.size())-1)
   {
     arr[x]=sum;
   }
 }
 process(arr,x);// to print the word with maximum number of repetation
}