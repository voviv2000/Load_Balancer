#include <fstream>
#include "WebServer.h"

using namespace std;   

WebServer::WebServer(const string server_name_) : server_name(server_name_) {
    // constructor, leave empty
}

// process requests
string WebServer::process_request(Request req_)  {
      
      fstream myfile;
      myfile.open("request_log.txt", fstream::app );

      if( !myfile ){
        myfile << "At time: " << req_.rand_time << endl;
        myfile << "Webserver " << server_name << " processing request from: " << req_.in_IP_address << " to " << req_.out_IP_address << endl;
        // cout << "In IP Address: " << req_.in_IP_address << endl;
        // cout << "Out IP Address: " << req_.out_IP_address << endl;
        // cout << "Time to Process: " << req_.rand_time << endl;
        myfile << "Webserver " << server_name << " is done processing...\n" << endl;
      } else {
        myfile << "At time: " << req_.rand_time << endl;
        myfile << "Webserver " << server_name << " processing request from: " << req_.in_IP_address << " to " << req_.out_IP_address << endl;
        myfile << "Webserver " << server_name << " is done processing...\n" << endl;
      }

      myfile.close();
      return "Done Processing...";
}


string WebServer::get_server_name(){
    return server_name;
}


void WebServer::set_isFull(bool isFull_){
  isFull = isFull_;
}

bool WebServer::get_isFull(){
  return isFull;
}