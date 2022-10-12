#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <queue>
#include <string>
#include <vector>
#include <ctime> 
#include "LoadBalancer.h"
#include "WebServer.h"

using namespace std;


int main() {
    /**
     * @brief User Inputs:
     * 
     * num_servers: Number of servers 
     * 
     * num_requests: Number of initial requests
     * 
     * request_time: Max, upper bound of a request runtime
     * 
     * tick: Number of clock cycles
     * 
     */
    int num_servers;
    int tick;
    int num_requests;
    int request_time;
    int start_queue_size;
    srand(time(0));

    cout << "Enter the number of servers desired: ";
    cin >> num_servers;
    cout << "Enter the number of initial requests desired: ";
    cin >> num_requests;
    cout << "Enter the max time for a request to process: ";
    cin >> request_time;
    cout << "Enter how long you want to run the load balancer for (number of ticks): ";
    cin >> tick;

    start_queue_size = num_requests;

    //num_requests = num_servers * 2;

    //generate num_requests, fill in load balancer
    LoadBalancer requestqueue( num_requests, request_time );
    
    // create num_servers amount of servers
    WebServer servers( num_servers );

    int i = 0;
    while( i < tick ){
        fstream myfile;
        myfile.open("request_log.txt", fstream::app );

        for( int j = 0; j < num_servers; j++ ){
          if( servers.get_status(j) == false ) {
            
            int start = i;
            servers.process_request( j, requestqueue.front(), start);
            servers.set_status(j, true);
            
            if( requestqueue.empty() == true ){

              myfile << "\nGenerating more requests...\n\n"<< endl;
              
              num_requests = (rand() % 10 ) + 1;
              requestqueue.generate_reqs(num_requests, request_time );
            }
            requestqueue.pop_queue();
            
          } else {

            if ( servers.get_process_length(j) == i){
              myfile << "Webserver " << j << " is done processing...\n" << endl;
              servers.set_status(j, false);
            } 
            // else {
            //   myfile << "Server " << j << " is still busy\n" << endl;
            // }
            
          }
          
        }
      
        if( requestqueue.empty() == true ){

          myfile << "\nGenerating more requests...\n\n"<< endl;
          
          num_requests = (rand() % 10 ) + 1;
          requestqueue.generate_reqs(num_requests, request_time );
        }
        // myfile << "tick " << i << ": ";
        myfile.close();
        i++;
    }

    fstream myfile;
    myfile.open("request_log.txt", fstream::app );
  
    myfile << "Starting queue size: " << start_queue_size << endl;
    myfile << "Ending queue size: " << requestqueue.queue_size() << endl;
    myfile << "Range for tasks time are from 0 to " << request_time << endl;
    
    myfile << "\nClock cycle done!\nExiting Program..." << endl;
    myfile.close();
  
    cout << "\nClock cycle done!" << endl;
    
    cout << "\nExiting Program..." << endl;
    return 0;


}