#include <vector>
#include <string>
#include <cmath>
using namespace std;
class TheSwapsDivOne{
public:
	int a[2510];
	double find(vector <string> sequence, int k){
		int n=0,S=0;
		for(int i=0;i<sequence.size();i++)
			for(int j=0;j<sequence[i].length();j++)S+=(a[n++]=sequence[i][j]-'0');
		double E=0,P=1.0/n+(1-1.0/n)*pow(1-2.0/(n-1),k);
		for(int i=0;i<n;i++)E+=(a[i]*P+(S-a[i])*(1-P)/(n-1))*(i+1)*(n-i)*2/n/(n+1);
		return E;
	}
};
urn E;
	}
};
eturn 0;
		if(vis[i][s1][s2])return dis[i][s1][s2];
		vis[i][s1][s2]=1;
		dis[i][s1][s2]=is_line[i]?
			min(dfs(i+1,m,s1?s1-1:0,s2+1)+!s1,dfs(i+1,m,s1+1,s2?s2-1:0)+!s2):
			dfs(i+1,m,s1||!left_in[i]?s1+(left_in[i]?-1:left_out[i]?1:0):0,s2||!right_in[i]?s2+(right_in[i]?-1:right_out[i]?1:0):0)+(!s1&&left_in[i])+(!s2&&right_in[i]);
		return dis[i][s1][s2];
	}
	int minimumTunnels(vector <string> frame){
		int R=frame.size(),C=frame[0].length(),vx[4]={-1,0,0,1},vy[4]={0,-1,1,0},ans=0;
		if(C==1){ // ����ֻ��һ�е����
			for(int i=0;i<R;i++)if(X(i,0))return 1;
			return 0;
		}
		for(int i=0;i<R;i++)for(int j=0;j<C;j++)if(X(i,j)){ // �ҳ����������ڵ�·�� 
			int deg=0;
			for(int d=0;d<4&&deg<2;d++)if(X(i+vx[d],j+vy[d]))deg++;
			if(deg==2)continue;
			int sx=i,sy=j,tx=i,ty=j,tmp;
			while(X(tx,ty)){
				frame[tx][ty]='.';
				for(int d=0;d<4;d++)if(X(tx+vx[d],ty+vy[d])){tx+=vx[d],ty+=vy[d];break;}
			}
			if(sx>tx||sx==tx&&sy>ty)tmp=sx,sx=tx,tx=tmp,tmp=sy,sy=ty,ty=tmp;
			// �е���һ�еĵ�������(�ᱻ������in=out=1)
			if(!sx&&!tx&&sy==ty){
				ans++;
				if(!sy)left_out[0]=1; // U->L
				else if(sy==C-1)right_out[0]=1; // U->R
			}
			else if(!sy){
				if(!ty)left_in[sx]=1,!sx||tx>sx+1?left_out[tx]=1:1; // L->L���ǵ�һ�����в��ʱתΪL->D
				else if(ty==C-1)sx==tx?is_line[sx]=1:left_in[sx]=right_out[tx]=1; // L->R��������ͬһ��
				else if(!tx)ans++,left_out[sx]=1; // L->U��תΪU->L
				else left_in[sx]=1; // L->D
			}
			else if(sy==C-1){
				if(!ty)right_in[sx]=left_out[tx]=1; // R->L
				else if(ty==C-1)right_in[sx]=1,!sx||tx>sx+1?right_out[tx]=1:1; // R->R���ǵ�һ�����в��ʱתΪR->D
				else right_in[sx]=1; // R->D
			}
			else if(!sx){
				ans++;
				if(!ty)left_out[tx]=1; // U->L
				else if(ty==C-1)right_out[tx]=1; // U->R
			}
			else if(!ty)left_in[tx]=1; // D->L��תΪL->D
			else if(ty==C-1)right_in[tx]=1; // D->R��תΪR->D
		}
		return ans+dfs(0,R,0,0);
	}
};
1; // D->R��תΪR->D
		}
		return ans+dfs(0,R,0,0);
	}
};
j),type[j]=find_val(j),select[j]=0;
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