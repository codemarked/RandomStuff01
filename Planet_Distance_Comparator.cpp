#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

struct Planet {
    string name;
    int x, y, z;
    double distance;

    double getDistance(Planet planet) {
        return sqrt(this->x * planet.x + this->y + planet.y + this->z + planet.z);
    }
};

int planet_size = 1000;
Planet planet_vector[1000];

Planet planet_close[2];
Planet planet_far[2];

int getRandom(int max) {
    return rand() % max + 1;
}

void setPlanetSize(int n) {
    planet_size = n;
}

void initializePlanets(Planet v[], int size) {
    for (int i = 0;i < size;i++) {
        Planet planet;
        planet.name = 'A' + i;
        planet.x = getRandom(10);
        planet.y = getRandom(10);
        planet.z = getRandom(10);
        v[i] = planet;
        cout << "Planet [" << planet.name << "," << planet.x << "," << planet.y << "," << planet.z << "]" << endl;
    }
}

void pairFarPlanets() {
    Planet far1, far2;
    Planet pair1, pair2;
    double highest_distance = 0.00;
    double distance = 0.00;
    for (int i = 0;i < planet_size;i++) {
        pair1 = planet_vector[i];
        for (int f = 0;f < planet_size;f++) {
            pair2 = planet_vector[f];
            if (pair1.name == pair2.name)
                continue;
            distance = pair1.getDistance(pair2);
            
            if (distance > highest_distance) {
                far1 = pair1;
                far2 = pair2;
            }
        }
    }
    far1.distance = far2.distance = far1.getDistance(far2);
    planet_far[0] = far1;
    planet_far[1] = far2;
}

void pairClosePlanets() {
    Planet close1, close2;
    Planet pair1, pair2;
    
    double lowest_distance = -1.00;
    double distance = 0.00;
    for (int i = 0;i < planet_size;i++) {
        pair1 = planet_vector[i];
        for (int f = 0;f < planet_size;f++) {
            pair2 = planet_vector[f];
            if (pair1.name == pair2.name)
                continue;
            
            distance = pair1.getDistance(pair2);
            if (lowest_distance < 0.0)
                lowest_distance = distance;
            else if (distance < lowest_distance) {
                close1 = pair1;
                close2 = pair2;
            }
        }
    }
    close1.distance = close2.distance = close1.getDistance(close2);
    planet_close[0] = close1;
    planet_close[1] = close2;
}



void displayPlanet(Planet v[], int size) {
    Planet planet;
    for (int i = 0;i < size;i++) {
        planet = v[i];
        cout << "Planet [" << planet.name << "," << planet.x << "," << planet.y << "," << planet.z << "]" << endl;
    }
    cout << "Distance: " << v[0].distance << endl;
}

int main() {
    int n = 0;
    cout << "n = ";
    cin >> n;
    setPlanetSize(n);
    initializePlanets(planet_vector, n);
    cout << endl;
    pairFarPlanets();
    pairClosePlanets();
   
    cout << endl;
    cout << "Checking for the closest planet pair:" << endl;
    displayPlanet(planet_close, 2);
    cout << endl;
    cout << "Checking for the furthest planet pair:" << endl;
    displayPlanet(planet_far, 2);
    cout << endl;

}
