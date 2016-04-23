#include <iostream>
#include <mysql.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <fstream>

MYSQL *conn, mysql;
MYSQL_RES *res;
MYSQL_ROW row;
int query_state;


double tempInside = 25;
double tempOutside = 29;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

int main()
{
//  std::cout << "PlantHouse(): ";
//  bool run = true;
//  while(run)
//  {
//    int command=0;
//    std::cout << "Choose command: "<< std::endl;
//    std::cout << "Command (1):Print the greatest name "<< std::endl;
//    std::cout << "Command (9):Exit: "<< std::endl;
//    std::cout << "Command: ";
//
//    std::cin >> command;
//
//    if (command ==  1)
//    {
//      std::cout << "Anders "<< std::endl;
//    }
//    else if (command == 9)
//    {
//      run =false;
//    }
//    else{
//      std::cout << "Command not found "<< std::endl;
//    }
//  }
  const char *server="192.168.1.50";
  const char *user="backend";
  const char *password="backendpass";
  const char *database="test";

  mysql_init(&mysql);
  conn=mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
  if(conn==NULL)
  {
    std::cout<<mysql_error(&mysql)<<std::endl<<std::endl;
    return 1;
  }

  for(;;)
  {
//    srand(time(NULL));
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Sleeped for 10 seconds: "<< std::endl;
    double random1 = ((double)rand()/(RAND_MAX+(double)1)*((0 == rand()%2) ? -1 : 1));
    double random2 = ((double)rand()/(RAND_MAX+(double)1)*((0 == rand()%2) ? -1 : 1));
    tempInside = tempInside +random1; // + (double)(rand()/(RAND_MAX + 1)+( rand()%-1 1));
    tempOutside = tempOutside + random2; // + (double)(rand()/(RAND_MAX + 1)+(rand()%-1 1));
    std::cout << "avrTempInside: : "<<  std::setprecision(3) << tempInside << "degrees" << std::endl;
    std::cout << "avrTempOutside: : "<< tempOutside << "degrees" << std::endl;

    std::cout << "Write to sql database: "<< std::endl;

    //MySql interface
    query_state=mysql_query(conn, "select * from temp");
     if(query_state!=0)
     {
        std::cout<<mysql_error(conn)<<std::endl<<std::endl;
        return 1;
     }
     res=mysql_store_result(conn);
     std::cout<<"MySQL Tables in mysql database."<<std::endl<<std::endl;
     while((row=mysql_fetch_row(res))!=NULL)
     {
        std::cout<<std::left;
        std::cout<<std::setw(3)<<row[0]
            <<std::setw(25)<<row[1]
            <<std::setw(5)<<row[2]
            <<std::setw(5)<<row[3]<<std::endl;
     }
     std::cout<<std::endl<<std::endl;
     std::string query;
     query_state=mysql_query(conn, "SELECT * FROM temp ORDER BY temp.index DESC");
     if(query_state!=0)
     {
       std::cout<<mysql_error(conn)<<std::endl<<std::endl;
       return 1;
     }
     res=mysql_store_result(conn);
     if((row=mysql_fetch_row(res))!=NULL)
     {
       int newIndex = std::atoi(row[0]) +1;
       std::cout<<newIndex<<std::endl;
      query = "INSERT INTO `test`.`temp`  (`index`, `time`, `avgTempInside`, `avgTempOutside`) VALUES ( '"+std::to_string(newIndex)+"', '"+currentDateTime()+"', '"+std::to_string(tempInside)+"', '"+std::to_string(tempOutside)+"')";
     }
     query_state=mysql_query(conn, query.c_str());
     if(query_state!=0)
     {
        std::cout<<mysql_error(conn)<<std::endl<<std::endl;
        return 1;
     }
     std::cout<<std::endl<<std::endl;


  }
  mysql_free_result(res);
  mysql_close(conn);


  return 0;
}


