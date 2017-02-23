
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,b,c,d,g,e,i;
	FILE* inf = fopen("magicin.txt","r");
	FILE* outf = fopen("magicout.txt","w");
	fscanf(inf,"%d %d %d",&a, &b, &d);
	c = 1 + (((d-b)>0)? d-b : 0);
	g = 1 + (((b-d)>0)? b-d : 0);
	int sum = a+b+c;
	i = sum -(c+g);
	e = sum -(b+c);
	fprintf(outf,"%d %d %d\n",a,b,c);
	fprintf(outf,"%d %d %d\n",d,e,g);
	fprintf(outf,"%d %d %d\n",g,c,i);
	fclose(inf);
	fclose(outf);
	return 0;
}



