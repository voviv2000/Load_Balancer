
#include "WebServer.h"

using namespace std;   

WebServer::WebServer(const string server_name_) : server_name(server_name_) {
    // constructor, leave empty
    accept_new_request = true;
}

// process requests
string WebServer::process_request(Request req_)  {
    accept_new_request = false;
    cout << "At Webserver " << server_name << " processing request from: " << req_.in_IP_address << " to " << req_.out_IP_address << endl;
    // cout << "In IP Address: " << req_.in_IP_address << endl;
    // cout << "Out IP Address: " << req_.out_IP_address << endl;
    // cout << "Time to Process: " << req_.rand_time << endl;

    return "Done Processing...";
    accept_new_request = true;
}


string WebServer::get_server_name(){
    return server_name;
}


bool WebServer::accept_request(){
    return accept_new_request;
}