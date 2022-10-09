#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
#include <string>
#include "LoadBalancer.h"

using namespace std;

class WebServer {

private:
    Request req;
    string server_name;
    bool accept_new_request;
    
public:
    // takes request form load balancer
    WebServer(const string server_name_);

    // process requests
    string process_request(Request req_);

    string get_server_name();

    // asks for another
    bool accept_request();

};

#endif 