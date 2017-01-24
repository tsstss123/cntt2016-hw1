#define MOD 1000000007
class PenguinEmperor{
public:
	// 循环卷积
	int c[360];
	void mul(int*a,int*b,int n){
		for(int i=0;i<n;i++)c[i]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)c[(i+j)%n]=(c[(i+j)%n]+1ll*a[i]*b[j])%MOD;
		for(int i=0;i<n;i++)a[i]=c[i];
	}
	// f[i][j]:前i天位移为j的方案数 g[j]:daysPassed/numCities天位移为j的方案数
	int f[360][360],g[360];
	int countJourneys(int numCities, long long daysPassed){
		// 递推计算f[i][j]
		f[0][0]=1;
		for(int i=1;i<=numCities;i++){
			for(int j=0;j<numCities;j++){
				f[i][j]=f[i-1][(j+i)%numCities];
				if(i*2%numCities)(f[i][j]+=f[i-1][(j+numCities-i)%numCities])%=MOD;
			}
		}
		// 倍增计算g[j]
		g[0]=1;
		long long n=daysPassed/numCities;
		for(int i=60;i>=0;i--){
			mul(g,g,numCities);
			if(n>>i&1)mul(g,f[numCities],numCities);
		}
		// 计算答案
		int ans=0;
		for(int i=0;i<numCities;i++)ans=(ans+1ll*f[daysPassed%numCities][i]*g[(numCities-i)%numCities])%MOD;
		return ans;
	}
};
�A������
		ins(0,b[0]-a[0],c[0]-a[0]); // B-A-C
		ins(b[0]-a[0],0,c[0]-b[0]); // A-B-C
		ins(c[0]-a[0],b[0]-c[0],0); // A-C-B
		// 0��B������
		ins(a[0]-b[0],0,c[0]-b[0]);
		ins(a[0]-c[0],c[0]-b[0],0);
		ins(0,a[0]-b[0],c[0]-a[0]);
		// 0��C������
		ins(a[0]-c[0],b[0]-c[0],0);
		ins(0,b[0]-a[0],a[0]-c[0]);
		ins(a[0]-b[0],0,b[0]-c[0]);
		std::sort(items,iter);
		iter=std::unique(items,iter);
		// ��ÿ��������㷽����
		int ans=0;n+=3;
		for(int i=0;i<3;i++)a.push_back(0),b.push_back(0),c.push_back(0);
		for(item*T=items;T<iter;T++){
			bool flag=1; // flag��ʾ�Ƿ�Ϸ� 
			a[n-2]=b[n-3]=T->x+T->y;
			b[n-1]=c[n-2]=T->y+T->z;
			c[n-3]=a[n-1]=T->z+T->x;
			for(int i=0;i<n;i++)D[i]=(item){b[i]-c[i],c[i]-a[i],a[i]-b[i]};
			for(int i=0;i<n;i++){
				int&tp=V[i].x,&dis=V[i].y,&dep=V[i].z; // tp,dis,depΪÿ��������͡���A-B-C���ϵ�λ�á����
				tp=(D[i].x==T->y-T->z)|(D[i].y==T->z-T->x)<<1|(D[i].z==T->x-T->y)<<2;
				if(tp==1||tp==7)dis=T->x-T->y-D[i].z,dep=a[i]+b[i]-T->x-T->y;
				else if(tp==2)dis=T->y-T->z-D[i].x,dep=b[i]+c[i]-T->y-T->z;
				else if(tp==4)dis=T->z-T->x-D[i].y,dep=c[i]+a[i]-T->z-T->x;
				else dis=1; // �޽���� 
				if(dis%2||dep%2||dis<0||dep<0){flag=0;break;}
				dis/=2;dep/=2;
			}
			if(!flag)continue;
			sort(V,V+n);
			int P=1;
			for(int l=0,r=0;l<n&&P;l=r){ // ��ͬһλ�õĵ㹹�� 
				while(r<n&&V[l].x==V[r].x&&V[l].y==V[r].y)r++;
				if(V[l].z||l+1<r&&!V[l+1].z)P=0; // ����ǡ��һ���� 
				else for(int p=l,q=l+1;q<r;q++){
					while(V[p].z<V[q].z)p++;
					P=1ll*P*(p-l)%MOD;
				}
			}
			ans=(ans+P)%MOD;
		}
		return ans; 
	}
};
=1ll*P*(p-l)%MOD;
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
