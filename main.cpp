//
// Created by Eden Bar on 01/01/2023.
//

#include <iostream>
using namespace std;
#include "Roads.h"

void getDataFromUser(int& sizeOfRoads, Roads& roads) {
    int actions, road;
    char c;
    float h;
    cout << "Please enter the number of Actions: " << endl;
    cin >> actions;

    cout << "Enter the First action: " << endl;
    cin >> c;
    if (c != 'A' && c != 'a')
        throw "invalid input";
    if (c == 'A' || c == 'a') {
        roads.init();
    }

    for (int i = 1; i < actions; i++) {
        cin >> c;

        if (c == 'A' || c == 'a') {
            throw "invalid input";
        }
        else if (c == 'B' || c == 'b') {
            cin >> h >> road;
            if (road > sizeOfRoads-1)
                throw "invalid input";
         roads.addBridge(h, road);
        }
        else if (c == 'C' || c == 'c') {
            cin >> h;
            roads.whichRoad(h);
        }
        else if (c == 'D' || c == 'd') {
            cin >> road;
            roads.print(road);
        }

        else {
            throw "invalid input";
        }

    }

}


int main() {
    int sizeOfRoads;
    cout << "Enter number of roads: " << endl;
    cin >> sizeOfRoads;

    if (sizeOfRoads < 0) {
        cout << "invalid input" << endl;
        return 0;
    }
    sizeOfRoads++;
    Roads roads(sizeOfRoads);

    try {
        getDataFromUser(sizeOfRoads, roads);
    }
    catch (const char* msg) {
        cout << msg << endl;
    }


    return 0;
}