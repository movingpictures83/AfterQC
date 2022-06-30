#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AfterQCPlugin.h"

void AfterQCPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   fastqFiles.push_back(filename);
 }
}

void AfterQCPlugin::run() {
   
}

void AfterQCPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   std::string command = "python2 plugins/AfterQC/AfterQC/after.py ";
   if (fastqFiles[0][0] != '/')
    command += " -1 "+ std::string(PluginManager::prefix())+"/"+fastqFiles[0];
   else
    command += " -1 "+ fastqFiles[0];
   if (fastqFiles[1][0] != '/')
    command += " -2 "+ std::string(PluginManager::prefix())+"/"+fastqFiles[1];
   else
    command += " -2 "+ fastqFiles[1];
 command += " -g "+file+"/good -b "+file+"/bad -r "+file+"/report; cp "+file+"/good/* "+file+"; cp "+file+"/bad/* "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<AfterQCPlugin> AfterQCPluginProxy = PluginProxy<AfterQCPlugin>("AfterQC", PluginManager::getInstance());
