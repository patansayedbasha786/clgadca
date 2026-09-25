#include <stdio.h>
#include <string.h>
struct job{
	char id[10];
	int deadline;
	int profit;
   );
   void structjobs(struct job jobs[],int n){
	   int i,int j
    struct job temp;
    for(int i=0;i<n-1;i++)
    {
    for(int j=0;j<n-1;j++)
    {
    if(jobs[j].profit<jobs[j+1].profit){
    temp=jobs[j];
    jobs[j]=jobs[j+1];
    jobs[j+1]=temp;
    }
    }
    }
    int main(){
		int n;
		printf("enter the number of jobs:");
		scanf("%d",&n);
		struct jobs jobs[n];
		for(int i=0;i<n;i++){
			printf("\\enter the details of the job %d:\\n",i+1);
			printf("job id:");
			scanf("%ds",jobs[i].id);
			printf("deadline:");
			scanf("%d",&jobs[i].deadline);
			printf("profit:");
			scanf("%d",&jobs[i].profit);
		}
		scortjobs(jobs,n);
		int maxdeadline=0;
		for(jobs[i].deadline>maxdeadline){
			maxdeadline=jobs[i].deadline;
		}
	}
	char schedule[maxdeadline][10];
	int slot[maxdeadline];
	for(int i=0;i<maxdeadline;i++){
		slot[i]=0;
	}
	int totalprofit=0;
	for(int i=0;i<n;i++){
		for(int j=jobs[i].deadline-1;j>=0;j--){
			if(slot[j]==0{
				slot[j]=1;
				strcpy(schdule[j],jobs[i].id);
				totalprofit+=jobs[i].profit;
				break;
			}
		}
	}
	printf("\\--job schedule---\\n");
	for(int i=0;i<maxdeadline;i++){
		if(slot[i])
		printf("time slot%d:job%ds\\n",i+1,schedule[i];
		else
		printf("time slot%d:empty\\n",i+1);
	}
	
			
