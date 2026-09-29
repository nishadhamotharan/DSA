#include <stdio.h>
#include <stdbool.h>
int A[309][309];
bool ok[309][309][309];
int main(){
    int T,R,C,L;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&R,&C,&L);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&A[i][j]);
        int ans=0;
        for(int left=0;left<C;left++){
            for(int right=left;right<C;right++){
                for(int i=0;i<R;i++){
                    int mn=A[i][left];
                    int mx=A[i][left];
                    for(int j=left;j<=right;j++){
                        if(A[i][j]<mn)
                            mn=A[i][j];
                        if(A[i][j]>mx)
                            mx=A[i][j];
                    }
                    ok[left][right][i]=(mx-mn<=L);
                }
                int height=0;
                for(int i=0;i<R;i++){
                    if(ok[left][right][i]){
                        height++;
                        int area=height*(right-left+1);
                        if(area>ans)
                            ans=area;
                    }
                    else
                        height=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
