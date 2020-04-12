/***Design A Scheduler Following Non-Preemptive Scheduling Approach To Schedule 
	The Processes That Arrives At Different Units And Having Burst Time Double 
	The Arrival Time.Scheduler Selects The Process With Largest Burst Time From
	The Queue For The Execution. Process Is Not Being Preempted Until It Finishes
	Its Service Time.Compute The Average Waiting Time And Average Turnaround Time. 
    What Should Be The Average Waiting Time If Processes Are Executed According
    To Shortest Job First Scheduling Approach With The Same Attribute Values.****/



#include<stdio.h>

int swap(int a,int b)
{
int temp;
temp=a;
a=b;
b=temp;
}
int main()
{

int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],bt1[10],temp,j,at[10],wt[10],tt[10],ct[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf(" -------Longest Job First Scheduling ( Non-Preemtitive )-------\n");
printf("\nEnter the No. of processes in Queue :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
        
        printf("\nFor P%d\n",i+1);
	
	label:
        printf("Arrival time:");
        scanf("%d",&at[i]);
	if (at[i]<=0)
	{
		printf("\n Arrival time should not be zero or negative!!!! Re-enter the correct arrival time \n");
		goto label;
	}	
        bt[i]=at[i]*2;
	bt1[i]=bt[i];
        printf("Burst Time:%d\n",bt[i]);
        printf("----------------------------------------");
	
}


int shortest_job_first()
{
float wavg=0,tavg=0,tsum=0,wsum=0;
for(i=0;i<n;i++)
    {
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
	swap(p[i],p[j]);
	swap(at[i],at[j]);
	swap(bt[i],bt[j]);
    }
 int val; 
    ct[0] = at[0] + bt[0]; 
    tt[0] =ct[0] - at[0]; 
    wt[0] = tt[0] - bt[0]; 
      
    for(int i=1; i<n; i++) 
    { 
        temp = ct[i-1]; 
        int low = bt[i]; 
        for(int j=i; j<n; j++) 
        { 
            if(temp >= at[j] && low >= bt[j]) 
            { 
                low = bt[j]; 
                val = j; 
            } 
        }
        ct[val] = temp + bt[val]; 
    tt[val] =ct[val] - at[val]; 
    wt[val] = tt[val] - bt[val]; 
        
	 
	swap(p[i],p[val]);

	swap(at[i],at[val]);
	
	swap(bt[i],bt[val]);
	
	swap(ct[i],ct[val]);
	
	swap(wt[i],wt[val]);
	
	swap(tt[i],tt[val]);
    } 
for(int i=0;i<n;i++)
{
wsum=wsum+wt[i];
tsum=tsum+tt[i];
}
wavg=wsum/n;
tavg=tsum/n;

printf("\n RESULT:-");

printf("\nProcess\t Burst\t Arrival\t C.T\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
	printf("\n p%d\t %d\t %d\t\t %d\t %d\t\t\t%d",p[i],bt[i],at[i],ct[i],wt[i],tt[i]);
}

printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f\n",tavg);
return 0;

}

int longest_job_first()

{
for(int i=0;i<n;i++)
    {
        int pos=i;
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

	temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }


for(j=0;j<n;j++)
{
	btime=btime+bt[j];
	min=bt[k];
		for(i=k;i<n;i++)
			{
			if (btime>=at[i] && bt[i]>min)
				{
					swap(p[i],p[k]);

					swap(at[i],at[j]);

					swap(bt[i],bt[j]);
				}
			}
	k++;
}
//waiting time average
wt[0]=0;
for(i=1;i<n;i++)
{
		wt[i]=0;
		for(int j=0;j<i;j++)
			wt[i]+=bt[j];
		wsum+=wt[i];
}
wavg=(wsum/n);

	for(i=0;i<n;i++)
	{
	tt[i]=bt[i]+wt[i];
	tsum=tsum+tt[i];
	}

tavg=(tsum/n);

printf("\n RESULT:-");

printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
	printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
}

printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f\n",tavg);
return 0;
}
printf("\nshortest job first\n");
shortest_job_first();
printf("***************************************************************\n");
printf("\nLongest job first\n");
longest_job_first();



}

//***************************************************************

