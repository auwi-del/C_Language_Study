#include <stdio.h>
int main()
{
    int i,j,c=0,count=0,n,m;
    float a[51][6],s=0,b[6];//ѧ���ĸ��Ƴɼ�,s��ÿ�����ܷ���,n��ѧ����m����Ŀ
    while(scanf("%d %d",&n,&m)!=EOF)            // <- ����Ӧ���� while ( 1 ) ��! 
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%f",&a[i][j]);
            }
            
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                s=s+a[i][j];
            }
            printf("%.2f ",s/((float) m ) );
            s=0;
        }
        printf("\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                b[i]+=a[j][i];
            }
            b[i]=b[i]/((float) n);
            printf("%.2f ",b[i]);
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(b[j]<=a[i][j])
                {
                    c++;
                    if(c==m)
                        {
                            count++;
                        }
                } 
                
            }
            c=0;
        }
        printf("%d\n",count);
        count=0;
       
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                a[i][j]=0;
                b[j]=0;
            }
            
        }
    }
    
}