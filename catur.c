#include <stdio.h>
#include <stdlib.h> 

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
  
// initializing the matrix. 
int dp[8][8] = { 0 }; 
  
int getsteps(int x, int y,  
             int tx, int ty) 
{ 
    // Jika knight berada di target  
    // posisi kembali 0
    if (x == tx && y == ty) 
        return dp[0][0]; 
    else { 
          
        // jika sudah dihitung maka kembalikan 
        // value. Ambil perbedaan yang mutlak 
        if (dp[abs(x - tx)][abs(y - ty)] != 0) 
            return dp[abs(x - tx)][abs(y - ty)]; 
              
        else { 
  
            // there will be two distinct positions 
            // from the knight towards a target. 
            // if the target is in same row or column 
            // as of knight than there can be four 
            // positions towards the target but in that 
            // two would be the same and the other two 
            // would be the same. 
            int x1, y1, x2, y2; 
              
            // (x1, y1) and (x2, y2) are two positions. 
            // these can be different according to situation. 
            // From position of knight, the chess board can be 
            // divided into four blocks i.e.. N-E, E-S, S-W, W-N . 
            if (x <= tx) { 
                if (y <= ty) { 
                    x1 = x + 2; 
                    y1 = y + 1; 
                    x2 = x + 1; 
                    y2 = y + 2; 
                } else { 
                    x1 = x + 2; 
                    y1 = y - 1; 
                    x2 = x + 1; 
                    y2 = y - 2; 
                } 
            } else { 
                if (y <= ty) { 
                    x1 = x - 2; 
                    y1 = y + 1; 
                    x2 = x - 1; 
                    y2 = y + 2; 
                } else { 
                    x1 = x - 2; 
                    y1 = y - 1; 
                    x2 = x - 1; 
                    y2 = y - 2; 
                } 
            } 
              
            // ans will be, 1 + minimum of steps  
            // required from (x1, y1) and (x2, y2). 
            dp[abs(x - tx)][abs(y - ty)] =  
                           min(getsteps(x1, y1, tx, ty),  
                           getsteps(x2, y2, tx, ty)) + 1; 
                             
            // exchanging the coordinates x with y of both 
            // knight and target will result in same ans. 
            dp[abs(y - ty)][abs(x - tx)] =  
                           dp[abs(x - tx)][abs(y - ty)]; 
            return dp[abs(x - tx)][abs(y - ty)]; 
        } 
    } 
}

int convert(char c){
    if(c=='A'){
        c = 1;
    }
    if(c=='B'){
        c = 2;
    }
    if(c=='C'){
    	c = 3;
    }
    if(c=='D'){
    	c = 4;
    }
    if(c=='E'){
    	c = 5;
    }
    if(c=='F'){
    	c = 6;
    }
    if(c=='G'){
    	c = 7;
    }
    if(c=='H'){
    	c = 8;
    }
} 
  
// Driver Code 
int main() 
{  
    // size of chess board n*n 
    int n = 8; 
      
    // (x, y) coordinate of the knight. 
    // (tx, ty) coordinate of the target position.
	int t;
	scanf("%d\n", &t);
	for(int i = 0; i < t; i++){
		int ans;
		int y, ty;
		char cx, ctx;
    	scanf("%c%d %c%d", &cx, &y, &ctx, &ty);
		int x = convert(cx);
    	int tx = convert(ctx); 
    // (Exception) these are the four corner points  
    // for which the minimum steps is 4. 
    	if ((x == 1 && y == 1 && tx == 2 && ty == 2) ||  (x == 2 && y == 2 && tx == 1 && ty == 1)) 
            ans = 4; 
    	else if ((x == 1 && y == n && tx == 2 && ty == n - 1) || (x == 2 && y == n - 1 && tx == 1 && ty == n)) 
            ans = 4; 
    	else if ((x == n && y == 1 && tx == n - 1 && ty == 2) || (x == n - 1 && y == 2 && tx == n && ty == 1)) 
                ans = 4; 
    	else if ((x == n && y == n && tx == n - 1 && ty == n - 1) || (x == n - 1 && y == n - 1 && tx == n && ty == n)) 
                ans = 4; 
    	else { 
        // dp[a][b], here a, b is the difference of 
        // x & tx and y & ty respectively. 
        	dp[1][0] = 3; 
        	dp[0][1] = 3; 
        	dp[1][1] = 2; 
        	dp[2][0] = 2; 
        	dp[0][2] = 2; 
        	dp[2][1] = 1; 
        	dp[1][2] = 1; 
  			ans = getsteps(x, y, tx, ty); 
    	} 
  		printf("Case #%d: %d\n", i+1, ans);
	}
  
    return 0; 
} 
