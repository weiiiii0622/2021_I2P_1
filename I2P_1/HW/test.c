#include <stdio.h>
#include <math.h>
int height[20];
int color[20];
int route[20];
void jump(int s, int e, int step);
void cost(int step);
int currentstep;
int sink[16];
int N, start, end, maxenergy, maxstep;
int main()
{
    scanf("%d %d %d", &N, &start, &end);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &height[i]);
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &color[i]);
    }
    route[1]=start;
    sink[start]=1;
    jump(start, end, 2);
    printf("%d %d\n", maxenergy, maxstep-2);
    return 0;
}

void jump(int s, int e, int step)
{
    if(s==e)
    {
        /*for(int i=1; i<step; i++)
        {
            printf("%d ", route[i]);
        }
        printf("\n");*/
        /*for(int i=1; i<=N; i++)
        {
            printf("%d ", sink[i]);
        }
        printf("\n");*/
        cost(step);
        sink[route[step]]=0;
        return;
    }
    currentstep=s+1;//1
    if(sink[currentstep]==0 && currentstep<=N && currentstep>0 )
    {
        route[step]=currentstep;
        sink[currentstep]=1;
        jump(currentstep, e, step+1);
        sink[route[step]]=0;
    }
    currentstep=s-1;//2
    if(sink[currentstep]==0 && currentstep<=N && currentstep>0 )
    {
        route[step]=currentstep;
        sink[currentstep]=1;
        jump(currentstep, e, step+1);
        sink[route[step]]=0;
    }
    currentstep=s;
    for(int i=1; i<=N; i++)//3
    {
        currentstep=s;
        if(color[i]==color[s] && i!=s)
        {
            currentstep=i;
            if(sink[currentstep]==0 && currentstep<=N && currentstep>0 )
            {
                route[step]=currentstep;
                sink[currentstep]=1;
                jump(currentstep, e, step+1);
                sink[route[step]]=0;
            }
        }
    }
    sink[route[step]]=0;
    return;
}
void cost(int step)
{
    int energy=0;
   
    for(int i=1; i<step-1; i++)
    {
        energy+=abs(height[route[i+1]]-height[route[i]])*abs(route[i+1]-route[i]);
    }
    //printf("%d %d\n", energy, step-2);
    if(energy>maxenergy)
    {
        maxenergy=energy;
        maxstep=step;
    }
    else if(energy==maxenergy)
    {
        if(maxstep<step)
        {
            maxstep=step;
        }
    }
}