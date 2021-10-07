          




          for( int i = 1; i <= m; i++){
               for( int j = i; j <= m; j++){
                    long s = 0, maxi = -INF, mini = 0;
                    for( int k = 1; k <= n; k++){
                         s += dp[k][j] - dp[k][i - 1];
                         maxi = max( maxi, s - mini);
                         mini = min( mini, s);
                    }
                    ans = max( ans, maxi);
               }
         }