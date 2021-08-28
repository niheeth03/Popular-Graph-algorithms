#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int a[101][101]={0};
int b[101]={0};
void bfs(int x,int n){
	b[x]=1;
	for(int i=1;i<n+1;i++){
		if(a[x][i]!=0&&a[x][i]!=-1){
			if(b[i]==0){
				b[i]=1;
				bfs(i,n);
			}
		}
	}
}
int main(){

	int n,m,x,y,weight,count=1,c2=0,c3=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>weight;
		a[x][y]=weight;
		a[y][x]=weight;
	}
    for(int i=1;i<n+1;i++){
	  for(int j=1;j<n+1;j++){
	  if(a[i][j]!=0){
	  
	        int w=a[i][j];
			a[i][j]=0;
			a[j][i]=0;
			for(int p=1;p<n+1;p++){
				b[p]=0;
			}
			bfs(1,n);
			for(int k=1;k<n+1;k++){
			    if(b[k]==0)	{
			    	bfs(k,n);
			    	count++;
				}
			}
			if(count>1){
				c2++;
			}
			a[i][j]=w;
			a[j][i]=w;
			count=1;
}
}
    
}
    int w;
     for(int i=1;i<n+1;i++){
     	for(int j=1;j<n+1;j++){
     		if(a[i][j]!=0){
     			w=a[i][j];
     			a[i][j]=-1;
     			a[j][i]=-1;
			 }
	    } 
			 for(int l=1;l<n+1;l++){
			 	b[l]=0;
			 }
		 
			 bfs(1,n);
			 for(int k=1;k<n+1;k++){
				    if(b[k]==0&&k!=i)	{
				    	bfs(k,n);
				    	count++;
					}
				}
				if(count>1){
					c3++;
				}
				for(int q=1;q<n+1;q++){
					if(a[i][q]==-1){
						a[i][q]=1;
						a[q][i]=1;
					}
				}
				count=1;
	 }


  cout<<c2/2<<endl;
  cout<<c3<<endl;
  }   


