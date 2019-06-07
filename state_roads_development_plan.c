/* The government of a state want to divide different cities in the state ,such that each city is connected to other city ,but as the government did not
have much fund ,so they want to construct those Highway which cost miniumum. 
*/

#include<stdio.h>
#define max 50
#define max_distance 100000000 // ten crores

void calculate(int[max][max],int,int);
int check(int[max][max],int);

int main()
{
	int n,i,j,min=0;
	int graph[max][max],cost,temp;

	printf("Cost of constructing Highway per Km = Rs ");
	scanf("%d",&cost);
	printf("Enter number of cities in the state =");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		graph[i][i]=max_distance;
	}
	printf("\n\nEnter the distance between cities in Kms \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				printf("Distance between city %d and city %d = ",i+1,j+1);
				scanf("%d",&graph[i][j]);
			}
		}
	}
	calculate(graph,n,cost);

	
}
void calculate(int graph[max][max],int n,int cost)
{
	int i,j,p,q,min=1000;
	int t=1,spanning[max][max];
	int total=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			spanning[i][j]=0;
		}
	}
	
	while(t<=n-1)
	{
		
		min=1000;	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(graph[i][j]<min)
				{
					min=graph[i][j];
					p=i;
					q=j;
				}
			}
		}
		spanning[p][q]=min;
		spanning[q][p]=min;
		if(check(spanning,n))
		{
			graph[p][q]=1000;
			graph[q][p]=1000;
			t++;	
		}	
		else
		{
			spanning[p][q]=0;
			spanning[q][p]=0;
			graph[p][q]=1000;
			graph[q][p]=1000;
		
		}
	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			spanning[i][j]=spanning[i][j]*cost;
			total=total+spanning[i][j];
		}
	}
	
	total=total/2;
	printf("\nThe total minimum cost of project will be Rs %d and total minimum distance of highway is %d Kms\n\n",total,total/cost);

	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(spanning[i][j]!=0)
			{
				printf("city %d and city %d are connected\n",i+1,j+1);
			}
			
		}
	}
}

int check(int spanning[max][max],int n)
{
	int i,j,count,m=0;
	
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(spanning[i][j]!=0)
				count++;
			
		}
		if(count==1)
		m++;
		
	}
		if(m==2)
		{
			return 1;
		}
		else
		{
			return 0;	
		}
}
