#include <cmath>
#include <iostream>
#include "clusters.h"
#include <fstream>
#include <sstream>
#include <map>
#include <QFile>
#include <QTextStream>

void readpoints(std::ifstream& in, std::vector<mycluster::point>& points)
{
    // implement a function that takes in an ifstream variable and a vector of points
    // the ifstream in variable is an opened .csv table
    // the function should read data from the table, fill in the vector of points and normalize the vector of points by column.
    // in each column the data should be a double number from the range [0, 1]

    return ;
}



void write_clusters(std::string outfilename, std::vector<mycluster::point>& points)
{
    // implement a function that takes in the name of the output .txt file and a vector of points.
    // the function should output data from the vector to the .txt file in the following format "point ID", "cluster"
    // the first line of the output file should be "id cluster" as the title.
    //  for example:
    //  id cluster
    //  1 3
    //  2 4
    //  3 1
    //  4 4

    QString result;
    result += "id cluster\n";
    for(int i = 0; i < points.size(); ++i){
        result += QString::fromStdString(std::to_string(i+1));
        result += " ";
        result += QString::fromStdString(std::to_string(points[i].getCluster()));
        result += "\n";
    }

    QString filename = QString::fromStdString(outfilename);
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << result << endl;
    }

    return ;
}

void write_siluettes(std::string outfilename, std::vector<mycluster::cluster>& clusters)
{

    QString result;
    for(auto c: clusters){
        result += "cluster";
        result += QString::fromStdString(std::to_string(c.id));
        result += " ";
        result += QString::fromStdString(std::to_string(c.siluette));
        result += "\n";
    }

    QString filename = QString::fromStdString(outfilename);
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << result << endl;
    }
    //  number of clusters: 6, siluette coefficients values:
    //  cluster1 0.697248
    //  cluster2 1.5
    //  cluster3 1.1521
    //  cluster4 0.507674
    //  cluster5 1.5
    //  cluster6 1.5
    return;
}



