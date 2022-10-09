#ifndef _LOADBALANCER_H_
#define _LOADBALANCER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <string>

using namespace std;

struct Request {
    // generate random IP address
    string in_IP_address;
    string out_IP_address;
    int rand_time; //randomize this
};


class LoadBalancer {

private:  

    // queue of type request NEEDS TO BE PRIORITY BASED ON TIME
    queue<Request> requestqueue;

    int time_count = 0;

    int num_servers;
    int num_req = num_servers * 2;

public:
    
    // constructor
    LoadBalancer(const int num_servers_ , const int num_reqs_ );



    // class functions

    // generates num_servers * 2 amount of requests
    void generate_reqs( int num_servers_ );

    Request front();

    // pop out a request and put into WebServer
    void pop_queue();

    bool empty();

    // refills queue with new requests
    void refill_queue(int num_reqs_);

    // creates random IP addresses
    string randomize_ip();

    // creates random time to run load balacner TAKE THIS INTO CONSIDERATION WHEN DISTRIB   
    int randomize_time();


};

#endif 