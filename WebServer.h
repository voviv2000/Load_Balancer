#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include "LoadBalancer.h"

using namespace std;

class WebServer {

private:
    Request req;
    string server_name;
    bool isFull;
    
public:
    // takes request form load balancer
    WebServer(const string server_name_);

    // process requests
    string process_request(Request req_);

    string get_server_name();

    // asks for another
    void set_isFull(bool isFull);
    bool get_isFull();

};

#endif 