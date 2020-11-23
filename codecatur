#include<bits/stdc++.h>
using namespace std;

char adj[9][9];
int dist[9][9];
int vis[9][9];

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

bool isValid(int x,int y)
{
    if(x<1 || x>8 || y<1 || y>8)
      return false;
    
    if(vis[x][y]==1)
      return false;
    
    return true;
}

int bfs(int srcX,int srcY,int endX,int endY)
{
	dist[srcX][srcY]=0;
	queue<pair<int,int> > q;
	q.push({srcX,srcY});
	vis[srcX][srcY]=1;
	

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		vis[x][y]=1;
		q.pop();
		int d = dist[x][y];
		
		if(x==endX && y==endY)
		  return d;
		
		for(int i=0;i<7;i++)
		{
		    if(isValid(x+dx[i],y+dy[i]))
		    {
		        dist[x+dx[i]][y+dy[i]]=d+1;
		        vis[x+dx[i]][y+dy[i]]=1;
		        q.push({x+dx[i], y+dy[i]});
		        
		    }
		}
		
		
	}
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        for(int i=1;i<=8;i++)
           for(int j=1;j<=8;j++)
             vis[i][j]=0;
             
        char a,b;  int srcX,srcY,endX,endY;
        cin>>a>>b;
        
	    srcX = a-'A'+1; srcY=b-'0';
	    
	    cin>>a>>b;
	    endX=a-'A'+1;endY=b-'0';
	    
	  bfs(srcX,srcY,endX,endY);
	  cout<<dist[endX][endY]<<endl;
    }
	return 0;
}
