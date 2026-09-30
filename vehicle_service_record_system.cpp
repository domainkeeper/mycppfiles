#include <iostream>
#include <string>
using namespace std;

class ServiceRecord {
private:
    string serviceName;
    double serviceCost;

public:
    ServiceRecord() : serviceName(""), serviceCost(0.0) {}

    ServiceRecord(string name, double cost) : serviceName(name), serviceCost(cost) {}

    void display() const {
        cout << "- " << serviceName << ": Rs. " << serviceCost << endl;
    }

    double getCost() const {
        return serviceCost;
    }

    string getName() const {
        return serviceName;
    }
};

class Vehicle {
private:
    string vehicleNumber;
    string ownerName;
    int serviceCount;
    ServiceRecord* services;

public:
    Vehicle(string number, string owner, int count)
        : vehicleNumber(number), ownerName(owner), serviceCount(count), services(nullptr) {
        services = new ServiceRecord[serviceCount];
    }

    ~Vehicle() {
        delete[] services;
    }

    void addService(int index, string name, double cost) {
        if (index >= 0 && index < serviceCount) {
            services[index] = ServiceRecord(name, cost);
        }
    }

    void displayServices() const {
        cout << "\nVehicle Number: " << vehicleNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Service Records:" << endl;

        for (int i = 0; i < serviceCount; ++i) {
            services[i].display();
        }

        cout << "Total Service Bill: Rs. " << calculateTotalBill() << endl;
    }

    double calculateTotalBill() const {
        double total = 0.0;
        for (int i = 0; i < serviceCount; ++i) {
            total += services[i].getCost();
        }
        return total;
    }
};

int main() {
    Vehicle* vehicle = new Vehicle("MH-12-AB-1234", "Rahul Sharma", 3);

    vehicle->addService(0, "Oil Change", 1500.0);
    vehicle->addService(1, "Brake Service", 2200.0);
    vehicle->addService(2, "Wheel Alignment", 1800.0);

    vehicle->displayServices();

    delete vehicle;
    return 0;
}
