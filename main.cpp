#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <string>
#include <vector>
#include "LoadBalancer.h"
#include "WebServer.h"

using namespace std;


int main() {

    vector<WebServer> servers;
    int num_servers;
    int tick;
    int num_requests;

    cout << "Enter the number of servers desired: ";
    cin >> num_servers;
    cout << "Enter how long you want to run the load balancer for (number of ticks): ";
    cin >> tick;
    cout << "Number of servers: " << num_servers << " and number of ticks: " << tick << endl << endl;

    num_requests = num_servers * 2;

    //generate num_requests, fill in load balancer
    LoadBalancer requestqueue( num_requests );
    
    // create num_servers amount of servers
    for ( int i = 0; i < num_servers; i++ ){
        string name = "server " + to_string(i);
        WebServer new_server(name); // give name to server
        servers.push_back(new_server);
    }
  
    while( tick > 0 ){
        for ( int i = 0; i < servers.size(); i++ ) {
            servers[i].process_request( requestqueue.front() );
            requestqueue.pop_queue();
          
            if( requestqueue.empty() == true ){
              cout << "\n\n Generating more requests...\n\n"<< endl;
              num_requests = (rand() % 100 ) + 1;
              requestqueue.generate_reqs(num_requests);
            }
            tick--;
        }
    }

    cout << "Exiting Program..." << endl;
    return 0;
  
    // int i = 0;
    // while(!requestqueue.empty()){

    //     cout << "\n\nRequest # " << i << endl;
    //     cout << "In IP Address: " << requestqueue.front().in_IP_address << endl;
    //     cout << "Out IP Address: " << requestqueue.front().out_IP_address << endl;
    //     cout << "Random Time: " << requestqueue.front().rand_time << endl << endl;
    //     requestqueue.pop_queue();
    //     i+=1;
    // }
///////////////////////////////////////////////////////
    // create num_servers amount of servers
    // for ( int i = 0; i < num_servers; i++ ){
    //     string name = "server " + to_string(i);
    //     WebServer new_server(name); // give name to server
    //     servers.push_back(new_server);
    // }

    // while(!requestqueue.empty()){
    //     for ( int i = 0; i < servers.size(); i++ ) {
    //         servers[i].process_request( requestqueue.front() );
    //         requestqueue.pop_queue();
    //     }
    // }
////////////////////////////////////////////////////////////

    // DONT FORGET TO RUN BUILD TASK EACH TIME  
    // return 0;

}