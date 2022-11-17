#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n;
   
    scanf("%d", &n);
    double values[1000];
    double sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%lf", &values[i]);
        sum += values[i];
    }
    double average = sum / n;
    double dispersion = 0;
    for(int i = 0; i < n; i++){
        dispersion += (values[i] - average) * (values[i] - average);
    }
    dispersion = sqrt(dispersion / n);
    double larger = 0;
    for(int i = 0; i < n; i++) {
        if(values[i] >= average - dispersion  && values[i] <= average + dispersion)
        larger++;
    }
    printf("%.2lf", 100 * larger / n);
    return 0;
}