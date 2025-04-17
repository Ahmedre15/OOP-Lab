#include <iostream>
#include <string>
using namespace std;

class IFlightService {
public:
    virtual bool reserveSeat(int) = 0;
    virtual bool revokeSeat(int) = 0;
    virtual bool promoteSeat(int) = 0;
};

class AirlineRoute : public IFlightService {
private:
    string routeCode;
    string fromCity;
    string toCity;
    int maxSeats;
    int currentBookings;
    int passengers[100]; // Assuming max 100 passengers per flight

public:
    AirlineRoute(string code, string from, string to, int limit)
        : routeCode(code), fromCity(from), toCity(to), maxSeats(limit), currentBookings(0) {}

    bool reserveSeat(int pid) override {
        if (currentBookings >= maxSeats) {
            cout << "[Reserve Failed] Flight " << routeCode << " is at full capacity.\n";
            return false;
        }
        for (int i = 0; i < currentBookings; ++i) {
            if (passengers[i] == pid) {
                cout << "[Reserve Failed] Passenger already booked on flight.\n";
                return false;
            }
        }
        passengers[currentBookings++] = pid;
        cout << "[Reserve OK] Passenger " << pid << " booked on " << routeCode << ".\n";
        return true;
    }

    bool revokeSeat(int pid) override {
        for (int i = 0; i < currentBookings; ++i) {
            if (passengers[i] == pid) {
                for (int j = i; j < currentBookings - 1; ++j) {
                    passengers[j] = passengers[j + 1];
                }
                currentBookings--;
                cout << "[Revoke OK] Passenger " << pid << " removed from " << routeCode << ".\n";
                return true;
            }
        }
        cout << "[Revoke Failed] Passenger " << pid << " not found on " << routeCode << ".\n";
        return false;
    }

    bool promoteSeat(int pid) override {
        for (int i = 0; i < currentBookings; ++i) {
            if (passengers[i] == pid) {
                cout << "[Promote OK] Passenger " << pid << " upgraded on " << routeCode << ".\n";
                return true;
            }
        }
        cout << "[Promote Failed] Passenger not found on flight.\n";
        return false;
    }

    void showDetails() const {
        cout << "Flight: " << routeCode << " | From: " << fromCity
             << " | To: " << toCity << " | Seats: " << maxSeats
             << " | Booked: " << currentBookings << "\n";
    }
};

class Traveller {
private:
    int userID;
    string fullName;

public:
    Traveller(int uid, string name) : userID(uid), fullName(name) {}

    bool askBooking(AirlineRoute& route) { return route.reserveSeat(userID); }
    bool askCancel(AirlineRoute& route) { return route.revokeSeat(userID); }
    bool askUpgrade(AirlineRoute& route) { return route.promoteSeat(userID); }

    void view() const { cout << "Traveller: " << fullName << " [ID: " << userID << "]\n"; }
};

int main() {
    AirlineRoute route1("AP-404", "Lahore", "Dubai", 2);
    AirlineRoute route2("QA-777", "Doha", "Toronto", 1);

    Traveller t1(1001, "Affan");
    Traveller t2(1002, "Talha");
    Traveller t3(1003, "Izaan");

    route1.showDetails();
    route2.showDetails();
    cout << "\n";

    t1.askBooking(route1);
    t2.askBooking(route1);
    t3.askBooking(route1); // Should fail

    t2.askCancel(route1);
    t3.askBooking(route1); 
    t3.askUpgrade(route1); 

    cout << "\nFinal States:\n";
    route1.showDetails();
    route2.showDetails();

    return 0;
}
