#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <chrono>


void read_fifo(std::string fname){
  std::ifstream fifo(fname);
  std::string content;
  size_t num = 0;
  if(fifo.is_open()){
    std::cout << "Reading the fifo\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::getline(fifo, content);
    std::cout << "Read" << num << " Content: " << content << '\n';
    if(fifo.eof()){
      fifo.clear();
    }
  } else {
    std::cout << " Fifo was not open\n";
  }
  fifo.close();
}

void write_fifo(const std::string fname, const std::string input){
  std::ofstream wrfifo(fname);
  std::cout << "Will wite to fifo: " << input << '\n';
  if(wrfifo.is_open()){
    wrfifo << input << '\n';
    wrfifo.close();
  } else {
    std::cerr << "Error opening the wr fifo\n";
  }
  std::this_thread::sleep_for(std::chrono::seconds(2));
}


void create_fifo(const std::string name){
  struct stat fifo_stat;
  if(stat(name.c_str(), &fifo_stat)){
    std::cout << "stat\n";
    if(!S_ISFIFO(fifo_stat.st_mode)){
      return; // fifo already exists
    }
  } else {
    std::cout << "File does not exists\n";
  }

  if(mkfifo(name.c_str(), 0666)){
    std::cerr << "Error opening fifo\n";
  } else {
    std::cout << "Fifo created\n";
  }
}

int main(){
  create_fifo("fifo_test");

  std::thread writter(write_fifo, "fifo_test", "qwertzuiop");

  std::thread reader (read_fifo, "fifo_test");

  writter.join();
  reader.join();
  return 0;

}