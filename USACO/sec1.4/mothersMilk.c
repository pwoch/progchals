/*
ID: wochnow1 
LANG: C
TASK: milk3
*/
#include <stdio.h>

int m[30][30][30];
int amax,bmax,cmax;

void find(int a,int b,int c){

	if (m[a][b][c]==0){
		m[a][b][c]=1;
		//1->2
		if (a>bmax-b) find(a-bmax+b,bmax,c); else find(0,a+b,c);
		//1->3
		if (a>cmax-c) find(a-cmax+c,b,cmax); else find(0,b,a+c);
		//2->3
		if (b>cmax-c) find(a,b-cmax+c,cmax); else find(a,0,b+c);
		//2->1
		if (b>amax-a) find(amax,b-amax+a,c); else find(a+b,0,c);
		//3->1
		if (c>amax-a) find(amax,b,c-amax+a); else find(a+c,b,0);
		//3->2
		if (c>bmax-b) find(a,bmax,c-bmax+b); else find(a,b+c,0);
	}
}

int main(){


	FILE *in,*out;
	in=fopen("milk3.in","r");
	out=fopen("milk3.out","w");
	int i,j,k,flag=0;
	for (i=0;i<=20;i++)
		for (j=0;j<=20;j++)
			for (k=0;k<=20;k++) m[i][j][k]=0;
	fscanf(in,"%d %d %d",&amax,&bmax,&cmax);

	find(0,0,cmax);

	for (i=0;i<=cmax;i++)
		for (j=0;j<=bmax;j++)
			if (m[0][j][i]==1){
				if (flag==0){fprintf(out,"%d",i);
					flag=1;}
				else fprintf(out," %d",i);
				break;
			}
	fprintf(out,"\n");
	return 0;
}

