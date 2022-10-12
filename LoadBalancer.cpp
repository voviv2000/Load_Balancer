#include "LoadBalancer.h"

using namespace std;

LoadBalancer::LoadBalancer(const int num_reqs_ , const int request_time_ ) : num_req( num_reqs_ ) , request_time(request_time_) {
    generate_reqs(num_req, request_time );
}


// generates num_servers * 2 amount of requests
void LoadBalancer::generate_reqs( int num_reqs_, int request_time_ ){
  
   map<int, Request> m;
   //srand(time(0));
  
   for ( int i = 0; i < num_reqs_; i++ ){
       Request new_request;
       new_request.in_IP_address = randomize_ip();
       new_request.out_IP_address = randomize_ip();
       new_request.rand_time = randomize_time( request_time_ );

       //sort queue by smallest server start time first
       m[new_request.rand_time] = new_request;
   }

    map<int, Request>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        requestqueue.push(itr->second);
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

int LoadBalancer::queue_size(){
  return requestqueue.size();
}


// creates random IP addresses
string LoadBalancer::randomize_ip(){

    int num1 = (rand() % 1000);
    int num2 = (rand() % 1000);
    int num3 = (rand() % 1000);
    int num4 = (rand() % 1000);

    return to_string(num1) + "." + to_string(num2) + "." + to_string(num3)+ "." + to_string(num4);
}

// creates random time to process request TAKE THIS INTO CONSIDERATION WHEN DISTRIB   
int LoadBalancer::randomize_time( int request_time_ ){
    int time1 = ( rand() % request_time_ ) + 2;
    return time1;
}










