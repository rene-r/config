#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unistd.h>

const std::string NIGHT="/day";
  
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
  
  std::string	periode		= "";
  std::string	nameBackground	= "";
  int		x		= 0;
  std::string	all = exec("cat ~/.fehbg");
  std::string	firstPart;
  for (int i = all.find(".Background/");all[i] != '\'';i++)
    {
      if(all[i] == '/')
	{
	  if (x == 0)
	    firstPart += all.substr(all.find("\'") + 1, i - (all.find("\'") + 1));
	  x+=1;
	}
      if (x == 1)
	periode += all[i];
      if (x == 2)
	nameBackground += all[i];
    }
  std::cout << "firstPart = " << firstPart<< std::endl;
  std::cout << "periode = " << periode<< std::endl;
  std::cout << "name = " << nameBackground << std::endl;
  std::string fileNight = firstPart + NIGHT+ nameBackground;
  std::cout << "AVANT  "<< fileNight<< std::endl;
  if (access( fileNight.c_str(), F_OK ) != -1)
    {
      std::cout << "OOOK" << std::endl;
      fileNight = "feh  --bg-scale '"+ fileNight +"'";
      exec(fileNight.c_str());
    }
  else
    std::cout << "DOWN" << access( fileNight.c_str(), F_OK ) <<std::endl;
  return 1;
}
