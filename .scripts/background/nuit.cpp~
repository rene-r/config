#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unistd.h>


std::string exec(const char* cmd)
{
  char buffer[128];
  std::string result = "";
  FILE* pipe = popen(cmd, "r");
  
  if (!pipe) throw std::runtime_error("popen() failed!");
  try {
    while (!feof(pipe)) {
      if (fgets(buffer, 128, pipe) != NULL)
	result += buffer;
    }
  } catch (...) {
    pclose(pipe);
    throw;
  }
  pclose(pipe);
  return result;
}

int main()
{
  // for (;;)
  //   {
  //     sleep (1);
  
      std::string lux = "";
      std::string all = exec("brightnessctl g");
      for (int i = all.find("(") + 1;all[i] != ')';i++)
	{
	  lux+=all[i];
	}
      std::cout<<lux<<std::endl;
      //    }
  return 5;
}
