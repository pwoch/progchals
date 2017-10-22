#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, vector<int> > p;
map<string, vector<int> > m;

vector<p > v;

bool cmp1(p a, p b) {
    return !a.first.compare(b.first);
}
bool cmp2(p a, p b) {
    return a.second[4] > b.second[4];
}
bool cmp3(p a, p b) {
    int d1 = a.second[4] - a.second[5];
    int d2 = b.second[4] - b.second[5];
    return d1 > d2;

}
bool cmp4(p a, p b) {
    int d1 = a.second[6];
    int d2 = b.second[6];
    return d1 > d2;

}

int main() {
    int N, n;
    string s;
    cin >>N;
    for (int i=0; i<N; i++) {
        cin.ignore();
        getline(cin, s);
        for (int j=0; j<7; j++) {
            cin >>n;
            m[s].push_back(n);
        }
    }
    int G;
    cin >>G;
    string t1, t2;
    int s1, s2;
    for (int i=0; i<G; i++) {
        cin.ignore();
        getline(cin, t1);
        cin >>s1;
        cin.ignore();
        getline(cin, t2);
        cin >>s2;
        //update MP
        m[t1][0]++;
        m[t2][0]++;
        //update GF
        m[t1][4]+=s1;
        m[t2][4]+=s2;
        //update GA
        m[t1][5]+=s2;
        m[t2][5]+=s1;

        if (s1 == s2) {
            //update ties
            m[t1][2]++;
            m[t2][2]++;
            //points
            m[t1][6]+=1;
            m[t2][6]+=1;
        } else {
            if (s2 > s1) {
                //Swap t1 with t2
                string t3 = t1;
                t1=t2;
                t2=t3;
            }
            //update win/loss
            m[t1][1]++;
            m[t2][3]++;
            //update points
            m[t1][6]+=3;
        }
    }
    
    for (map<string, vector<int> >::iterator it = m.begin(); it != m.end(); ++it) {
        //pair<string, vector<int> > tmp = *it;
        //vector<int> v1;
        //for (int i=0; i<7; i++) v1.push_back(tmp.second[i]);
        p np = p(it->first, vector<int> (it->second));
        v.push_back(np);
    }

    stable_sort(v.begin(), v.end(), cmp1);
    stable_sort(v.begin(), v.end(), cmp2);
    stable_sort(v.begin(), v.end(), cmp3);
    stable_sort(v.begin(), v.end(), cmp4);

    for (int i=0; i<v.size(); i++) {
        cout << v[i].first;
        for (int j=0; j<7; j++) {
            cout <<" "<<v[i].second[j];
        }
        cout <<endl;
    }
}

