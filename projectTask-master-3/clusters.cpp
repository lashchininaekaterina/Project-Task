#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include "clusters.h"

using namespace std;

namespace mycluster
{

const int CLUST_NUM = 7; // кол-во кластеров

void normalize_column(int ind, vector<point>& points)
{
    // implement this function
    // it normalises the vector of points BY COLUMNS (!!!)
    return ;
}


double dist2(const point &a, const point &b)
{
    return 0;
}

double dist(const point &a, const point &b)
{
    // implement this function
    // it counts distance NOT squared !!! between two points
    return 0;
}

double cost(vector<point>& points, vector<int>& m_ind, bool ischange)
{
    // ** erase this code and implement the algorithm yourself if you want a better grade
    double total = 0;
    for(int i = 0; i < points.size(); i++)
    {
        double min_dist2 = dist2(points[i], points[m_ind[0]]);
        if (ischange) points[i].setCluster(0);

        for(int j = 1; j < m_ind.size(); j++)
        {
            double cur_dist2 = dist2(points[i], points[m_ind[j]]);
            if (min_dist2 > cur_dist2)
            {
                min_dist2 = cur_dist2;
                if (ischange)
                    points[i].setCluster(j);
            }
        }
        total += sqrt(min_dist2);
    }

    return total;
}


void clusteringPAM(vector<point>& points)
{
    // ** erase this code and implement the algorithm yourself if you want a better grade

    // generating CLUST_NUM random medoids
    vector<int> medoid_ind;
    set<int> s;
    for(int i = 0; s.size() < CLUST_NUM; i++){
        s.insert( rand() % points.size());
    }

    for(auto x:s)
    {
        medoid_ind.push_back(x);
        points[x].setMedian(true);
    }

    // counting the cost
    double total_cost = cost(points, medoid_ind, true);

    // iterating until the cost is minimum
    for(int i = 0; i < medoid_ind.size(); i++)
    {
        //std::cout << __LINE__ << " " << i << std::endl;
        for(int j = 0; j < points.size(); j++)
        {
            if (points[j].getMedian() == false )
            {
                int old = medoid_ind[i];
                points[old].setMedian(false);
                points[j].setMedian(true);
                medoid_ind[i] = j;
                double cur_cost = cost(points, medoid_ind, true);

                if (cur_cost >= total_cost)
                {
                    medoid_ind[i] = old;
                    points[j].setMedian(false);
                    points[old].setMedian(true);
                } else {
                    total_cost = cur_cost;
                }
            }
        }
    }

    return ;
}

void interpreting(vector<point>& points, vector<cluster>& clusters)
{
    // ** erase this code and implement the algorithm yourself if you want a better grade

    std::map<int, double> M;
    std::map<int, int> Cluster_sizes;
    clusters.resize(CLUST_NUM, {0, 0});

    for(int i = 0; i < points.size(); i++)
        Cluster_sizes[points[i].getCluster()] += 1; // counting cluster sizes

    for (int i = 0; i < clusters.size(); i++)
        clusters[i].id = i;

    for(int i = 0; i < points.size(); i++)
    {
        //std::cout << i << std::endl;
        double total = 0;
        int num = 0;
        for(int j = 0; j < points.size(); j++)
        {
            if (i == j) continue;
            if (points[i].getCluster() == points[j].getCluster())
            {
                total += dist(points[i], points[j]); // cohesion
                num++;
            }
            else
            {
                M[points[j].getCluster()] += dist(points[i], points[j]); // separation
            }
        }

        double minb = 1000; // min separation
        for(auto p:M)
        {
            if (minb > (p.second / Cluster_sizes[p.first]))
            {
                minb = p.second / Cluster_sizes[p.first];
            }
        }


        points[i].setB(minb);

        if (num > 0)
        {
            points[i].setA(total / num);
            points[i].setSiluette( (points[i].getB() - points[i].getA()) / max(points[i].getA(), points[i].getB()) );
        }
        else
            points[i].setSiluette(0);

        //std::cout << points[i].getSiluette() << std::endl;

        clusters[points[i].getCluster()].siluette += points[i].getSiluette();
        M.clear();
    }

    for(int i = 0; i < clusters.size(); i++)
        clusters[i].siluette /= Cluster_sizes[i];

}

}


