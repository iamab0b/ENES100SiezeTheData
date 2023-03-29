#include "Enes100.h"

void setup() {
    // Initialize Enes100 library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Crash Site Team", CRASH_SITE, 3, 10, 11);
    
    Enes100.print("Destination is at (");
    Enes100.print(Enes100.missionSite.x);
    Enes100.print(", ");
    Enes100.print(Enes100.missionSite.y);
    Enes100.println(")");
    // Transmit the height of the payload in mm
    Enes100.mission(HEIGHT, 270);
    // Transmit the length of the payload in mm
    Enes100.mission(LENGTH, 180);
    // Transmit the direction of the abnormality for +x
    Enes100.mission(DIRECTION, POS_X);
    // Any other setup code...
}

void loop() {
    // Update the OSV's current location
    while(!Enes100.updateLocation()) {
	// OSV's location was not found
        Enes100.println("404 Not Found");
    }
    Enes100.print("OSV is at (");
    Enes100.print(Enes100.location.x);
    Enes100.print(", ");
    Enes100.print(Enes100.location.y); 
    Enes100.print(", ");
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");
}
