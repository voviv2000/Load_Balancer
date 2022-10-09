#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <string>
#include "LoadBalancer.h"

using namespace std;

LoadBalancer::LoadBalancer(const int num_servers_ , const int num_reqs_ ) : num_servers( num_servers_), num_req( num_reqs_ ) {
    // constructor leave empty
    generate_reqs(num_req);
}



// generates num_servers * 2 amount of requests
void LoadBalancer::generate_reqs( int num_servers_ ){
    /*
    */
   for ( int i = 0; i < num_req; i++ ){
       Request new_request;
       new_request.in_IP_address = randomize_ip();
       new_request.out_IP_address = randomize_ip();
       new_request.rand_time = randomize_time();

       requestqueue.push(new_request);
   }
}

// pop out a request and put into WebServer

Request LoadBalancer::front(){
    return requestqueue.front();
}

void LoadBalancer::pop_queue(){
    return requestqueue.pop();
}

bool LoadBalancer::empty(){
    return requestqueue.empty();
}

// refills queue with new requests
void LoadBalancer::refill_queue(int num_reqs_){

    for ( int i = 0; i < num_reqs_; i++ ){
        Request new_request;
        new_request.in_IP_address = randomize_ip();
        new_request.out_IP_address = randomize_ip();
        new_request.rand_time = randomize_time();

        requestqueue.push(new_request);
    }
}

// creates random IP addresses
string LoadBalancer::randomize_ip(){

    int num1 = (rand() % 1000);
    int num2 = (rand() % 1000);
    int num3 = (rand() % 1000);
    int num4 = (rand() % 1000);

    return to_string(num1) + "." + to_string(num2) + "." + to_string(num3)+ "." + to_string(num4);
}

// creates random time to run load balacner TAKE THIS INTO CONSIDERATION WHEN DISTRIB   
int LoadBalancer::randomize_time(){

    int time1 = rand() % 25;
    int time2 = rand() % 10;
    int time3 = rand() % 10;
    string fulltime = to_string(time1) + to_string(time2) + to_string(time3);
    return stoi(fulltime);
}










