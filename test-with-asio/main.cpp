
#include <iostream>
#include <asio.hpp>
#include "MyServer.hpp"

int main(int ac, char **av) {
  MyServer myserver;
  asio::io_context io;
  std::cout << "bonjour" << std::endl;
  
  asio::steady_timer t(io, asio::chrono::seconds(5));

  t.wait();

  std::cout << "fin" << std::endl;
  return 0;
}
