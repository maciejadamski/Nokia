#include <boost/asio.hpp>
#include <iostream>
#include <string>

std::string time_string()
{
  std::cout<<"The user connected to the server...\n";
}

int main () {

  try 
  {
    boost::asio::io_service io_service; //tworzenie obiektu io_service klasy io_service

    boost::asio::ip::tcp::acceptor acceptor(
    io_service, 
    boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 80));

    for (;;) 
    {
      std::cout<<"Waiting for users.."<<std::endl;
      boost::asio::ip::tcp::socket socket(io_service);
      acceptor.accept(socket);

      std::string message = time_string();
      boost::system::error_code ignored_error;
      boost::asio::write(
      socket, 
      boost::asio::buffer(message), 
      boost::asio::transfer_all(), 
      ignored_error);
      socket.close();

    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;

}
