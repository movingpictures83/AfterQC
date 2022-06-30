#ifndef AFTERQCPLUGIN_H
#define AFTERQCPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class AfterQCPlugin : public Plugin
{
public: 
 std::string toString() {return "AfterQC";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> fastqFiles;
};

#endif
