#include<stdio.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<vector>
#include<math.h>
using namespace std;


typedef vector<char> c1d;
typedef vector<int> i1d;


i1d DRAW;

c1d create(c1d arr,int size)
{
	for(int i=0;i<size;i++)
	{
  	int a=rand()%2;
    char c =a+'0';
    arr[i]=c;
    }
    return arr;
}
 void Print(c1d arr,int size){
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
} 
int Evaluate(c1d arr,int size)
{
	int optimal=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]=='1')
			optimal++;
	}
	return optimal;
}
void add(c1d arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			i--;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			chc=0;
			break;
		}
	} 
}
void sub (c1d arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			chc=0;
			break;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			i--;
		}
	} 
}
int avg(i1d arr,int len)
{
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
		cout<<"RUN"<<i+1<<':'<<arr[i]<<endl;
	}
	int avg=sum/len;
	return avg;
}
i1d i1davg(i1d arr,int run)
{
	i1d sum;
    sum.resize(arr.size());
	for(int i=0;i<arr.size();i++)
	{
		sum [i]= arr[i]/run;
	}
	return sum;
}
void compare(c1d arr,c1d temp,int len,int &opt,int curropt)
{
	if(curropt>=opt)
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=temp[i];
		}
		opt=curropt;
	}

	
}