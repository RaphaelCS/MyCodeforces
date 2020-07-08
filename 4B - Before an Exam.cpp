// Difficulty:  1200
// Category:    constructive algorithms, greedy

#include <iostream>

using namespace std;

int main()
{
    int d, sumTime;
    int minTime[32], maxTime[32];
    cin >> d >> sumTime;
    int sumMinTime = 0, sumMaxtime = 0, dTime[32];
    for (int i = 0; i < d; i++) {
        cin >> minTime[i] >> maxTime[i];
        sumMinTime += minTime[i];
        sumMaxtime += maxTime[i];
        dTime[i] = maxTime[i] - minTime[i];
    }
    
    if (sumTime < sumMinTime || sumTime > sumMaxtime) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    sumTime -= sumMinTime;
    for (int i = 0; i < d; i++) {
        if (sumTime > dTime[i]) {
            cout << maxTime[i] << " ";
            sumTime -= dTime[i];
        } else if (sumTime > 0) {
            cout << sumTime + minTime[i] << " ";
            sumTime -= sumTime;
        } else {
            cout << minTime[i] << " ";
        }
    }
}