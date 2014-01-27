#include <boost/asio.hpp>
#include <iostream>

int main () 
{
   try {
      boost::asio::io_service io_service;
      boost::asio::ip::tcp::resolver::query query("localhost", "80");
      boost::asio::ip::tcp::resolver resolver(io_service);
      boost::asio::ip::tcp::resolver::iterator destination = resolver.resolve(query);
      boost::asio::ip::tcp::resolver::iterator end ;
      boost::asio::ip::tcp::endpoint endpoint;

      while ( destination != end ) {
         endpoint = *destination++;
         std::cout<<endpoint<<std::endl;
      }

      boost::asio::ip::tcp::socket socket(io_service);
      socket.connect(endpoint);
   }
   catch (std::exception& e)
   {
      std::cerr << e.what() << std::endl;
   }
   return 0;
}

