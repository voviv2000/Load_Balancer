#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include "LoadBalancer.h"

using namespace std;

class WebServer {

struct Server{
  int server_num;
  int start_time;
  int process_length;
  bool stat;
};

private:
    Request req;
    int num_servers;
    int server_num;
    bool isFull;
    vector<Server> s;
    
public:
    // takes request form load balancer
    WebServer(const int num_servers_);

    // process requests
    string process_request(int server_num, Request req_, int start_time_);

    // int get_server_num();

    // asks for another
    void set_isFull(bool isFull);
    bool get_isFull();

    void gen_server_status(int num_servers_);

    bool get_status(int server);
    void set_status(int server, bool flag);

    int get_start_time(int server);

    int get_process_length(int server);

};

#endif 