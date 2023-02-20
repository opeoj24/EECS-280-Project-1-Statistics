//
//  stats.cpp
//  p1-stats
//
//  Created by Ope Ojubanire on 1/8/22.
//

#include <stdio.h>
// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath>
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    vector<vector<double>> summary;
    double num = 1;
    sort(v);

    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] != v[i - 1]) {
            vector<double> z;
            z.push_back(v[i - 1]);
            z.push_back(num);
            num = 1;
        summary.push_back(z);
        }
        else {
           num++;
        }
        if (i == (int)v.size() - 1) {
            vector<double> z;
            z.push_back(v[i]);
            z.push_back(num);
            summary.push_back(z);
        }
    }
    return summary;
}
            
int count(vector<double> v) {
    int num = static_cast<int>(v.size());
    return num;

}
double sum(vector<double> v) {
    double sum_num = 0.0;
    for (int i = 0; i < (int)v.size(); i++) {
        sum_num += v[i];
    }
    return sum_num;
}
double mean(vector<double> v) {
    return sum(v) / count(v);
    
}
double median(vector<double> v) {
    double median;
    if (v.size() % 2 == 0) {
        median = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2;
    }
    else {
        median = v[v.size() / 2];
    }
    return median;
}
double mode(vector<double> v) {
    double mode = v[0];
    double freq = 0;
    vector<vector<double>> sum = summarize(v);
    for (int i = 0; i < (int)sum.size(); i++){
        if ( freq < sum[i][1]){
            mode = sum[i][0];
            freq = sum[i][1];
        }
    }
    return mode;
}
double min(vector<double> v) {
    sort(v);
    return v[0];
}
double max(vector<double> v) {
    sort(v);
    return v[v.size() - 1];
}
double stdev(vector<double> v) {
    double ovrnum = 0;
    double diffmean = 0;
    for (int i = 0; i < v.size(); i++) {
        double temp = abs(v[i] - mean(v));
    
        double diffnum = pow(temp, 2);
        ovrnum += diffnum;
}
    diffmean = (ovrnum)/ (v.size() - 1);
    double stdev = sqrt(diffmean);
    
    return stdev;
}

double percentile(vector<double> v, double p) {
    int size = count(v);
    sort(v);
    double frtnum = p * (size - 1) + 1;
    double countc = 0;
    double secnum = 0;
    secnum = modf(frtnum, &countc);
    if (p!=1) {
        return(v[countc - 1] + secnum * (v[countc]
        - v[frtnum - 1]));
    }
    else {
        return v[v.size() - 1];
    }
}
