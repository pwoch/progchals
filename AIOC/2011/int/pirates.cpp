#include <fstream>


using namespace std;


int main() {
	ifstream in ("piratein.txt");		
	ofstream out ("pirateout.txt");
	int l,x,y;
	in >>l >>x >>y;
	out<< min(x+y,2*l-(x+y))<<endl;
	return 0;
}


