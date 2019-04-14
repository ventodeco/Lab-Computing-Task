
#include<iostream>
 
using namespace std;
 
int ary[10][10],completed[10],n,cost=0;
 
void takeInput()
{
	int i,j;
 
	cout<<"Enter the number of edge: ";
	cin>>n;
 
	cout<<"\nEnter the Cost Matrix\n";
 
	for(i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
		for( j=0;j < n;j++)
			cin>>ary[i][j];
 
		completed[i]=0;
	}
 
	cout<<"\n\nThe cost list is:";
 
	for( i=0;i < n;i++)
	{
		cout<<"\n";
 
		for(j=0;j < n;j++)
			cout<<"\t"<<ary[i][j];
	}
}
 
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
 
void mincost(int edge)
{
	int i,nedge;
 
	completed[edge]=1;
 
	cout<<edge+1<<"--->";
	nedge=least(edge);
 
	if(nedge==999)
	{
		nedge=0;
		cout<<nedge+1;
		cost+=ary[edge][nedge];
 
		return;
	}
 
	mincost(nedge);
}
 
int main()
{
	takeInput();
 
	cout<<"\n\nThe Path is:\n";
	mincost(0); //passing 0 because starting vertex
 
	cout<<"\n\nMinimum cost is "<<cost;
 
	return 0;
}
