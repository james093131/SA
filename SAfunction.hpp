#define randomnum_max 1
#define randomnum_min 0.5
#define A 0.4
#define temperature 1
#include "normal.hpp"

c1d NeighborSelection(c1d arr,int size){
	int ran=rand()%size;
	if(arr[ran]=='1')
		arr[ran]='0';
	else
		arr[ran]='1';

    return arr;
}
double SAformula(int newsol  ,int currsol)
{
    double pa=exp((newsol-currsol)/temperature);
    return pa;
}
double randomminmax()
{
    double r = (randomnum_max - randomnum_min) * rand() / (RAND_MAX + 1.0) + randomnum_min;
    return r;
}
c1d update(double r,double pa,c1d newarr,c1d currarr,int len,int &opt,int curropt,double &T)
{
	T=A*T;
    if(pa>r)
    {
		
		opt=curropt;
        return newarr;
	}
    else{
        return currarr;
    }
}
void SA(c1d arr,int &opt,int iteration,int len,double T)
{
		int k=0;
		while(k<iteration)
		{
			c1d temp(len);
			for(int i=0;i<len;i++)
			{
				temp[i]=arr[i];
			}
			temp = NeighborSelection(temp,len);
            int curropt=Evaluate(temp,len);
            double pa =SAformula(curropt,opt);
            double r=randomminmax();
            arr = update(r,pa,temp,arr,len,opt,curropt,T);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
            DRAW[k] += opt;
			// if(opt==len)
			// 	break;			
			k++;
		}
}
void run(c1d arr,int &opt,int iteration,int len,double T,int run,i1d result)
{
	int r=0;
	while(r<run)
	{
		cout<<len<<"bits"<<endl;
		c1d   arr(len);
		arr = create(arr,len);
		opt=Evaluate(arr,len);
        cout<<opt<<endl;
		SA(arr,opt,iteration,len,T);
		result[r]=opt;
		r++;
	}
    int avgiteration=avg(result,run);
    DRAW = i1davg(DRAW,run);
	cout<<"Average Optima :"<<avgiteration<<endl;
	fstream file;//寫檔
	file.open("SAresult.txt",ios::out);
    for(int i=0;i<DRAW.size();i++)
    {
        file<<i<<' '<<DRAW[i]<<endl;
    }
}