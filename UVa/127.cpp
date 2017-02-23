#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

struct card{
    char s;
    char n;
    inline bool operator==(const card& a) {
        return this->s == a.s || this->n == a.n;
    }
};

int main() {
    string str1, str2;
    while ( getline(cin,str1) && getline(cin,str2)) {
        vector< stack<card> > v(52);
        card c;
        for (int i = 0; i < 26; i++) {
            c.s = str1[3*i];
            c.n = str1[3*i+1];
            v[i].push(c);
            c.s = str2[3*i];
            c.n = str2[3*i+1];
            v[i+26].push(c);
        }
        for (int i = 1; i < v.size(); i++) {
            if (i-3 >= 0 && v[i].top() == v[i-3].top()) {
                v[i-3].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) v.erase(v.begin()+i);
                i-=4;
                //for (int j=0;j<v.size();j++) cout<<v[j].top().s<<v[j].top().n<<" ";
                //cout<<endl;
            } else if (i-1 >= 0 && v[i].top() == v[i-1].top()) {
                v[i-1].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) v.erase(v.begin()+i);
                i-=2;
                //for (int j=0;j<v.size();j++) cout<<v[j].top().s<<v[j].top().n<<" ";
                //cout<<endl;
            }
        }
        if (v.size() == 1) cout<<"1 pile remaining:";
        else cout<< v.size()<<" piles remaining:";

        for (int i = 0; i < v.size(); i++) {
            if(v[i].size()) cout<<" "<<v[i].size();
        }
        cout<<endl;
    }
    return 0;
}



