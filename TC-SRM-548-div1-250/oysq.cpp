#line 2 "KingdomAndTrees.cpp"  
#include <bits/stdc++.h> 

using namespace std;  

#define ui unsigned
#define ll long long

#define pii std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second

#define SZ(x) (int)(x).size()
#define pb push_back

template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(x > y) x = y;}


class KingdomAndTrees {  
public:
	bool check(int X, const std::vector<int> &h) {
		int last = 0;
		// try to minimize each element
		for(int i = 0; i < SZ(h); ++i) {
			if(h[i] <= last) {
				if(h[i] + X <= last) return false;
				else last++;
			}
			else last = std::max(h[i] - X, last + 1);
		}
		return true;
	}
	int minLevel(vector <int> h) {  
		int l = 0, r = 1e9;
		// binary search
		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(mid, h)) r = mid;
			else l = mid + 1;
		}
		return l;
	}  
};  
