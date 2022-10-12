#include "LoadBalancer.h"

using namespace std;

LoadBalancer::LoadBalancer(const int num_reqs_ ) : num_req( num_reqs_ ) {
    generate_reqs(num_req);
}


// generates num_servers * 2 amount of requests
void LoadBalancer::generate_reqs( int num_reqs_ ){
  
   map<int, Request> m;
   //srand(time(0));
  
   for ( int i = 0; i < num_reqs_; i++ ){
       Request new_request;
       new_request.in_IP_address = randomize_ip();
       new_request.out_IP_address = randomize_ip();
       new_request.rand_time = randomize_time();

       //sort queue by smallest server start time first
       //requestqueue.push(new_request);
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


// creates random IP addresses
string LoadBalancer::randomize_ip(){
    //srand(time(0));
    int num1 = (rand() % 1000);
    int num2 = (rand() % 1000);
    int num3 = (rand() % 1000);
    int num4 = (rand() % 1000);

    return to_string(num1) + "." + to_string(num2) + "." + to_string(num3)+ "." + to_string(num4);
}

// creates random time to run load balacner TAKE THIS INTO CONSIDERATION WHEN DISTRIB   
int LoadBalancer::randomize_time(){
    //srand(time(0));
    int time1 = rand() % 25;
    int time2 = rand() % 10;
    int time3 = rand() % 10;
    string fulltime = to_string(time1) + to_string(time2) + to_string(time3);
    return stoi(fulltime);
}











