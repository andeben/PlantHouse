#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <iostream>

int main()
{
  std::ofstream m_stateFile;
  m_stateFile.open("/tmp/pumpState.dat");
  m_stateFile << "RELAY_STATE=1" << std::endl;
  m_stateFile.close();

  std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
  std::cout<<"<html><body>"<<std::endl;
  std::cout<<"<h1>Hello World!</h1>"<<std::endl;
  std::cout<<"This is HTML formatted Hello World C++ CGI222222222222222"<<std::endl;
  std::cout<<"</body></html>"<<std::endl;
  return 0;
}
