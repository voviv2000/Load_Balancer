#ifndef _LOADBALANCER_H_
#define _LOADBALANCER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <iterator>
#include <map>

using namespace std;

/**
 * @brief Struct object called Request
 * Two string attributes serve as an in and out IP address
 * One int attribute acts as a randomized runtime for the request
 */

struct Request {
    // generate random IP address
    string in_IP_address;
    string out_IP_address;
    int rand_time; //randomize this
};

/**
 * @brief LoadBalancer class, keeps a queue of requests
 * Has other queue functionalities to access and modify
 * Keeps track of time for each request
 * 
 */

class LoadBalancer {

private:  

    // queue of type request NEEDS TO BE PRIORITY BASED ON TIME
    queue<Request> requestqueue;

    int time_count = 0;
    int num_req;
    int request_time;

public:
    
    // constructor
    LoadBalancer( const int num_reqs_, const int request_time_ );


    // generates num_servers * 2 amount of requests
    void generate_reqs( int num_reqs_ , int request_time_ );

    Request front();

    // pop out a request and put into WebServer
    void pop_queue();

    bool empty();

    int queue_size();

    // creates random IP addresses
    string randomize_ip();

    // creates random time to run load balacner TAKE THIS INTO CONSIDERATION WHEN DISTRIB   
    int randomize_time( int request_time_ );

};

#endif 