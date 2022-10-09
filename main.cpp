#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <string>
#include "LoadBalancer.cpp"

using namespace std;


int main() {
    int num_servers;
    int time_run_load;

    cout << "Enter the number of servers desired: ";
    cin >> num_servers;
    cout << "Enter the time you want to run the load balancer: ";
    cin >> time_run_load;
    cout << "Number of servers: " << num_servers << " and number of load balancers: " << time_run_load << endl << endl;

    LoadBalancer requestqueue( num_servers, (num_servers *2) );

    int i = 0;
    //cout << "size of queueu: " << requestqueue.size() << endl;
    while(!requestqueue.empty()){
        
        //LoadBalancer::Request temp = requestqueue.pop();

        cout << "\n\nRequest # " << i << endl;
        cout << "In IP Address: " << requestqueue.front().in_IP_address << endl;
        cout << "Out IP Address: " << requestqueue.front().out_IP_address << endl;
        cout << "Random Time: " << requestqueue.front().rand_time << endl << endl;
        requestqueue.pop_queue();
        i+=1;
    }

    if( requestqueue.empty() == 1 ){
        cout << "Exiting Program..." << endl;
        exit(0);
    }

    // DONT FORGET TO RUN BUILD TASK EACH TIME  

}