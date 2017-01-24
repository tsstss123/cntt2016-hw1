#include <vector>
#include <string>
#define ll long long
#define INF 10000000
using namespace std;
class MagicMolecule{
public:
	int n,v[51];
	ll G[51];
	int max(int a,int b){return a>b?a:b;}
	int dfs(ll S,int m){
		if(!S)return m>0?-INF:0;
		if(__builtin_popcountll(S)<m)return-INF;
		int x=0;while(!(S>>x&1))++x;
		if(!(G[x]&S))return dfs(S-(1ll<<x),m-1)+v[x];
		return max(dfs(S-(1ll<<x),m),dfs(S&~(1ll<<x|G[x]),m-1)+v[x]);
	}
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond){
		n=magicPower.size();
		for(int i=0;i<n;i++)v[i]=magicPower[i];
		for(int i=0;i<n;i++)
			for(int j=G[i]=0;j<n;j++)if(i!=j&&magicBond[i][j]=='N')G[i]|=1ll<<j;
		int ans=dfs((1ll<<n)-1,2*(n+1)/3);
		return ans<0?-1:ans;
	}
};
;
			for(int i;head<tail;head++){
				inq[i=Q[head]]=0;
				for(edge*e=first[i];e;e=e->next)if(e->cap&&D[i]+e->cost<D[e->to]){
					D[e->to]=D[i]+e->cost;
					fr[e->to]=e;
					if(!inq[e->to])inq[Q[tail++]=e->to]=1;
				}
			}
			if(D[1]==INF)return;
			int cap=INF;
			for(int i=1;i;i=fr[i]->rev->to)if(fr[i]->cap<cap)cap=fr[i]->cap;
			for(int i=1;i;i=fr[i]->rev->to)fr[i]->cap-=cap,fr[i]->rev->cap+=cap,c+=fr[i]->cost*cap;
			f+=cap;
		}
	}
	int getmin(vector <string> field){
		R=field.size();C=field[0].length();
		ne=E;memset(first,0,sizeof(first));
		int vx[4]={-1,0,0,1},vy[4]={0,-1,1,0},vz[4]={1,2,2,1},cnt=0;
		for(int i=0;i<R;i++)for(int j=0;j<C;j++)if(field[i][j]!='w'){
			if((i+j)%2){
				link(0,0,-1,i,j,0,2,0);
				for(int z=1;z<3;z++)for(int c=0;c<2;c++)link(i,j,0,i,j,z,1,c*(field[i][j]=='C'));
				for(int d=0;d<4;d++)link(i,j,vz[d],i+vx[d],j+vy[d],vz[d],1,0);
			}
			else{
				link(i,j,0,0,0,-2,2,0);
				for(int z=1;z<3;z++)for(int c=0;c<2;c++)link(i,j,z,i,j,0,1,c*(field[i][j]=='C'));
			}
			cnt++;
		}
		int f,c;mincost(f,c);
		return f==cnt?c:-1;
	}
};
s2(i+1))return 1; // 每条边内同类点必须偶数个 
			if(!t)select[id[i]]=0;undo(old);
		}
		return 0;
	}
	string getPossibility(vector <int> labels){
		for(int i=ecnt=top=opcnt=0;i<labels.size();i++) // 预处理边集
			if(labels[i]==-1)list[top++]=i;
			else for(int j=i+1;j<labels.size();j++)if(labels[i]==labels[j])ex[ecnt]=i,ey[ecnt++]=j;
		init(labels.size());
		for(int i=0;i<ecnt;i++)
			for(int j=i+1;j<ecnt;j++)if(cross(i,j)&&!link(i,j,1))return"IMPOSSIBLE"; // 输入的不合法则退出
		if(top<=12)return dfs1(0)?"POSSIBLE":"IMPOSSIBLE"; // 搜索1
		for(int j=0;j<ecnt;j++)id[j]=find_fa(j),type[j]=find_val(j),select[j]=0;
		init(labels.size());link(0,labels.size(),0);
		return dfs2(0)?"POSSIBLE":"IMPOSSIBLE"; // 搜索2
	}
};
1ll*P*(p-l)%MOD;
				}
			}
			ans=(ans+P)%MOD;
		}
		return ans; 
	}
};

			for(edge*e=first[i];e;e=e->next){
				if(siz[e->to]==n-k)dfs2(e->to,i,dep+1,ff*fv[e->to]%MOD);
			}
		}
		else for(edge*e=first[i];e;e=e->next)
			if(e->to!=fa)dfs2(e->to,i,dep+1,ff);
	}
	int getCount(vector <int> edge1, vector <int> edge2, int k){
		this->n=edge1.size()+1;this->k=k;ne=E;ans=0;
		for(int i=0;i<edge1.size();i++)link(edge1[i],edge2[i]),link(edge2[i],edge1[i]);
		init();
		if(k==1)return fac[n];
		if(2*k>n){
			init(0,-1);
			dfs1(0,-1,1);
			return ans*fac[2*k-n]%MOD*fac[n-k]%MOD*fac[n-k]%MOD;
		}
		for(int i=0;i<n;i++){
			init(i,-1);
			dfs2(i,-1,0,inv[k]);
		}
		return ans*fac[k]%MOD*fac[k]%MOD;
	}
};