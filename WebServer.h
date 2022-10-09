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

public:
    // takes request form load balancer
    WebServer(Request req){
        cout << req.rand_time;
    }

    // process requests

    // asks for another
    // is queue of requests empty?

};

#endif 