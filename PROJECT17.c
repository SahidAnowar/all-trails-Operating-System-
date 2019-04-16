#include<stdio.h>
 
void main()
{
    int bt[20],p[20],wt[20],tat[20],at[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        printf("\nEnter Arrival Time:\n");
        scanf("%d",&at[i]);
        bt[i]=2*at[i];
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in descending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 	int c=0;
    printf("\nProcess\t  processnumber\t  Burst Time\t  Waiting Time\t  Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t  %d\t  \t  %d\t  \t  %d\t   \t\t%d",p[i],c,bt[i],wt[i],tat[i]);
        c++;
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
