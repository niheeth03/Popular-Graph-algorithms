#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int dis[101]={-1};
int a[101][101]={-1};
bool visited[101]={0};
void dij(int x,int nodes){
	visited[x]=1;
	for(int i=0;i<nodes;i++){
		if(visited[i]==0&&a[x][i]!=-1){
			if(dis[x]+a[x][i]<dis[i]||dis[i]==-1){
				dis[i]=dis[x]+a[x][i];
			}
		}
	}
	int s=-1,smaller=-1;
	for(int i=0;i<nodes;i++){
		if((visited[i]==0)&&(dis[i]>=0)&&(s==-1||s>dis[i])){
			s=dis[i];
			smaller=i;
		}
	}
	if(smaller!=-1){
		dij(smaller,nodes);
	}
}

int main(){
	int x,y,nodes,edges,weight;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>x>>y>>weight;
		a[x][y]=weight;
		a[y][x]=weight;
	}
	dis[1]=0;
	int o=1;
	cout<<dis[2]<<endl;
	dij(o,nodes);
	for(int i=2;i<=nodes;i++){
		cout<<dis[i]<<endl;
	}
}
