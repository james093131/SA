//cmd執行方式 ./SA 100(bit數)  1000(iteration) 30(run) 
#include "SAfunction.hpp"

int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
    int iteration= atoi(argv[2]);
    int runtime = atoi(argv[3]);
	c1d onemax(len,0);
	i1d runresult(runtime);
	DRAW.resize(iteration,0);
	int opt=0;
	double T=temperature;
	int k=0;//在第幾個iteration找到最佳解
	run(onemax,opt,iteration,len,T,runtime,runresult);

}