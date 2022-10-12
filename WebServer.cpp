#include <fstream>
#include "WebServer.h"

using namespace std;   

/**
 * @brief Construct a new Web Server:: Web Server object
 * 
 * @param num_servers_ 
 * takes in integer for number of servers to generate
 */

WebServer::WebServer(const int num_servers_) : num_servers(num_servers_) {
  // constructor
  gen_server_status(num_servers);
}


/**
 * @brief Processes a request
 * 
 * @param server_num 
 * takes in a server number (the server that will hold a request)
 * 
 * @param req_ 
 * takes in one Request that will be processed
 * 
 * @param start_time 
 * the starting time of the current clock cycle
 * 
 * @return string 
 * returns when the Request is done processing
 * 
 */
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


/**
 * @brief Generates x input of servers and defaults status to false or empty
 * 
 * @param num_servers_ 
 * Number of servers to generate
 */

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


/**
 * @brief Gets status of a server
 * 
 * @param server 
 * The server we want the status of 
 * 
 * @return true 
 * @return false 
 */

bool WebServer::get_status(int server){
  return s[server].stat;
}


/**
 * @brief Sets the status of a server
 * 
 * @param server 
 * The server we want to change status of
 * 
 * @param flag 
 * What status we want to change to
 */

void WebServer::set_status(int server, bool flag){
  s[server].stat = flag;
}


/**
 * @brief Gets the total time a request will take from x server
 * 
 * @param server 
 * The server we want to see the request from
 * 
 * @return int 
 * The runtime of the request
 * 
 */

int WebServer::get_process_length(int server){
  return s[server].process_length;
}
