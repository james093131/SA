#define randomnum_max 1
#define randomnum_min 0.5
#define A 0.4
#define temperature 1
#include "normal.hpp"
#include<math.h>
void NeighborSelection(char *,int );
double SAformula(int   ,int );
double randomminmax();
void update(double ,double ,char *,char *,int ,int &,int ,double &);
void SA(char *,int &,int ,int ,double);
void run(char *,int &,int ,int ,double ,int ,int *);
