#ifndef READWRITE_H
#define READWRITE_H

#include "clusters.h"


void readpoints(std::ifstream& in, std::vector<mycluster::point>& points);
void write_points(std::string outfilename, std::vector<mycluster::point>& points);
void write_clusters(std::string outfilename, std::vector<mycluster::point>& points);
void write_siluettes(std::string outfilename, std::vector<mycluster::cluster>& clusters);


#endif // READWRITE_H
