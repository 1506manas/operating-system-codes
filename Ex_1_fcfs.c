 #include<stdio.h>

int main(){
    
    //let arrival time for all the process is 0
    int n_process, bt[20]={0},at=0, ct[20]={0}, wt[20]={0}, tat[20]={0},i;
    float avgwt=0.0, avgtat=0.0;
    // no of process
    printf("No of process:");
    scanf("%d",&n_process);
    //burst time input
    for(i=0; i<n_process; i++){
        printf("\nEnter burst time for process P%d: ",i);
        scanf("%d", &bt[i]);
    }

    //main logic
    for ( i=0; i<n_process; i++){
        ct[i] = ct[i-1]+bt[i];
        wt[i] = ct[i]-bt[i];
        tat[i] = ct[i]-at;
        avgwt = avgwt+wt[i];
        avgtat = avgtat+tat[i];
    }
    //final avg calculation
    avgwt = avgwt/n_process;
    avgtat = avgtat/n_process;
    //Output
    printf("\nProcess\tArrival Time\tCompletion Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for ( i = 0; i<n_process; i++){
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at,ct[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time: %f",avgwt);
    printf("\nAverage turnaround time: %f",avgtat);
    return 0;    
}
