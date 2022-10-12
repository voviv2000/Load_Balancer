#include <fstream>
#include "WebServer.h"

using namespace std;   

WebServer::WebServer(const int num_servers_) : num_servers(num_servers_) {
  // constructor
  gen_server_status(num_servers);
}

// process requests
string WebServer::process_request(int server_num, Request req_, int start_time)  {

      fstream myfile;
      myfile.open("request_log.txt", fstream::app );
  
      if( s[server_num].stat == false ){
        s[server_num].stat = true;
        if( !myfile ){
          myfile << "Process " << server_num << " will start at " << start_time << " and end at " << start_time + req_.rand_time << endl;
          s[server_num].process_length = start_time + req_.rand_time;
    
          myfile << "Total time: " << req_.rand_time << endl;
          myfile << "Webserver " << server_num << " processing request from: " << req_.in_IP_address << " to " << req_.out_IP_address << "\n" << endl;
          // FOR TESTING
          // cout << "In IP Address: " << req_.in_IP_address << endl;
          // cout << "Out IP Address: " << req_.out_IP_address << endl;
          // cout << "Time to Process: " << req_.rand_time << endl;
        } else {
          
          myfile << "Process " << server_num << " will start at " << start_time << " and end at " << start_time + req_.rand_time << endl;
          s[server_num].process_length = start_time + req_.rand_time;
          
          myfile << "Total time: " << req_.rand_time << endl;
          myfile << "Webserver " << server_num << " processing request from: " << req_.in_IP_address << " to " << req_.out_IP_address << "\n" << endl;
        }

      } else if(s[server_num].stat == true ) {
        myfile << "Webserver " << server_num << " is busy" << endl;
      }
  
      myfile.close();
      return "";
}


void WebServer::set_isFull(bool isFull_){
  isFull = isFull_;
}

bool WebServer::get_isFull(){
  return isFull;
}

void WebServer::gen_server_status(int num_servers_){
  for( int i = 0; i < num_servers_; i++ ){
    Server new_s;
    new_s.server_num = i;
    new_s.stat = false;
    new_s.start_time = 0;
    new_s.process_length = 0;
    s.push_back(new_s);
  }
}

bool WebServer::get_status(int server){
  return s[server].stat;
}

void WebServer::set_status(int server, bool flag){
  s[server].stat = flag;
}

int WebServer::get_start_time(int server){
  return s[server].start_time;
}

int WebServer::get_process_length(int server){
  return s[server].process_length;
}
