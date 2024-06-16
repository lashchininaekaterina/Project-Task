#ifndef CLUSTERS_H
#define CLUSTERS_H

#include <vector>
#include <cmath>
#include <map>
#include <set>

namespace mycluster
{

class point
{
private:
    std::vector<double> data;
    bool isMedian;
    int cluster;
    double a; // cohesion
    double b; // separation
    double siluette;

public:
    point(std::vector<double>& Data)
    {
        data = Data;
    }

    void setMedian(bool IsMedian)
    {
        isMedian = IsMedian;
    }

    void setCluster(int Cluster)
    {
        cluster = Cluster;
    }

    void setSiluette(double Siluette)
    {
         siluette = Siluette;
    }

    void setA(double A)
    {
         a = A;
    }

    void setB(double B)
    {
        b = B;
    }

    bool getMedian()
    {
        return isMedian;
    }

    int getCluster()
    {
       return cluster;
    }

    double getSiluette()
    {
       return siluette;
    }

    double getA()
    {
         return a;
    }

    double getB()
    {
        return b;
    }

    double& operator[](int i)
    {
         return data[i];
    }

    double operator[](int i) const
    {
        return data[i];
    }

    int size() const
    {
        return data.size();
    }
};


void normalize_column(int ind, std::vector<point>& points);
double dist2(const point &a, const point &b);
double dist(const point &a, const point &b);


struct cluster
{
public:
    int id;
    double siluette;

    bool operator<(const cluster& other);

};

double cost(std::vector<point>& points, std::vector<int>& m_ind, bool ischange = false);
void clusteringPAM(std::vector<point>& points);
void interpreting(std::vector<point>& points, std::vector<cluster>& clusters) ;

}

#endif // CLUSTERS_H

