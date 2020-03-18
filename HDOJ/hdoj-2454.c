#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std ;

const int N = 1e3 + 10 ;
int a[N] ;

int main()
{
    int T , n ;
    for ( cin >> T ; T ; T-- ){
        int tot = 0 , edge = 0 ;
        cin >> n ;
        //for( int i=1;i<=n;i++ ) cin >> a[i] ;

        for( int i=1;i<=n;i++ ){
            cin >> a[i] ;
            tot += a[i] ;
        }


        // 判断  入度和出度
        if( tot & 1 ) {
            printf("no\n");
            continue;
        }
        // 排序，从大到小
        sort ( a+1, a+1+n , [](int u,int v){return u>v;} );

        bool flag = true ;
        for(int i = 1 ; flag && i <= n ; i++ ){
            for(int j=i+1 ; a[i] && j<=n ;j++ ){
                if( a[j] == 0 ) continue;
                a[i] -- ;
                a[j] -- ;
            }
            //注意每次操作完都需要取前K大的.
            sort( a+i+1 , a+1+n ,[](int u,int v){return u>v;} ) ;
        }
        for(int i=1;i<=n;i++){
            //cout << a[i] << " ";
            if( a[i] != 0 ){
                flag = false ;
            }
        }
        if( flag ) puts("yes");
        else puts("no");
    }
    return 0;
}
