#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <ctime>
#include <iomanip>
#include <cmath>


using namespace std;

class ErrorHandling
{
private:
    int lettersCount;
    int digitsCount;
    bool spaceEncountered;

public:
    bool phoneValidation(string input)
    {
        if (input.empty())
        {
            return false;
        }
        if (input[0] != '0')
        {
            return false;
        }

        if (input.size() > 1 && input[1] != '3')
        {
            return false;
        }

        for (int i = 0; i < input.size(); ++i)
        {
            if (!isdigit(input[i]) && input[i] == ' ')
            {
                return false;
            }
        }
        if (input.size() == 11)
        {
            return true;
        }
        return false;
    }

    bool plateNoValidation(string plateNo)
    {
        if (plateNo.empty())
        {
            return false;
        }

        lettersCount = 0;
        digitsCount = 0;
        spaceEncountered = false;

        for (int i = 0; i < plateNo.size(); i++)
        {
            if (isalpha(plateNo[i]))
            {
                lettersCount++;
            }
            else if (isdigit(plateNo[i]))
            {
                digitsCount++;
            }
            else if (plateNo[i] == ' ')
            {
                if (spaceEncountered || lettersCount < 2 || lettersCount > 6)
                {
                    return false;
                }
                spaceEncountered = true;
            }
            else
            {
                return false;
            }
        }

        if (!spaceEncountered || lettersCount < 2 || lettersCount > 6 || digitsCount < 3 || digitsCount > 4)
        {
            return false;
        }

        return true;
    }

    bool hoursValidation(string idString)
    {
        for (int i = 0; i < idString.size(); ++i)
        {
            if (!isdigit(idString[i]))
            {
                return false;
            }
        }
        if (idString.empty())
        {
            return false;
        }
        for (int i = 0; i < idString.size(); ++i)
        {
            if (idString[i] == ' ')
            {
                return false;
            }
        }
        if (stoi(idString) <= 24 && stoi(idString) >= 1)
        {
            return true;
        }
        return false;
    }

    bool daysValidation(string days)
    {
        for (int i = 0; i < days.size(); ++i)
        {
            if (!isdigit(days[i]))
            {
                return false;
            }
        }
        if (days.empty())
        {
            return false;
        }
        for (int i = 0; i < days.size(); ++i)
        {
            if (days[i] == ' ')
            {
                return false;
            }
        }
        if (stoi(days) <= 31 && stoi(days) >= 1)
        {
            return true;
        }
        return false;
    }

    bool menuChoice(string choice)
    {
        for (int i = 0; i < choice.size(); ++i)
        {
            if (!isdigit(choice[i]))
            {
                return false;
            }
        }
        if (choice.empty())
        {
            return false;
        }
        for (int i = 0; i < choice.size(); ++i)
        {
            if (choice[i] == ' ')
            {
                return false;
            }
        }
        return true;
    }

    bool amountValid(string &amount)
    {
        if (amount.empty())
        {
            return false;
        }

        bool hasDecimalPoint = false;
        for (size_t i = 0; i < amount.size(); ++i)
        {
            if (amount[i] == '.')
            {
                if (hasDecimalPoint) // More than one decimal point is invalid
                    return false;
                hasDecimalPoint = true;
            }
            else if (!isdigit(amount[i]))
            {
                return false;
            }
        }

        return true;
    }

    bool tokenValid(string token)
    {
        if (token.empty())
        {
            return false;
        }
        for (int i = 0; i < token.size(); ++i)
        {
            if (!isdigit(token[i]) && token[i] == ' ')
            {
                return false;
            }
        }
        if (token.size() == 6)
        {
            return true;
        }
        return false;
    }

    bool nameValid(string name)
    {
        if (name.empty())
        {
            return false;
        }
        return true;
    }

    void upperCase(string &plateNo)
    {
        for (int i = 0; i < plateNo.size(); i++)
        {
            plateNo[i] = toupper(plateNo[i]);
        }
    }
};

class Vehicle : public ErrorHandling
{
protected:
    string cellNo;
    string plateNo;
    string parkingType;
    int days;
    int hours;
    time_t parkTime;
    time_t unparkTime;

public:
    Vehicle() {}

    Vehicle(string cellNo, string plateNo, int days, int hours, string parkingType)
        : cellNo(cellNo), plateNo(plateNo), days(days), hours(hours), parkingType(parkingType)
    {
        time(&parkTime); // Initialize parking start time
    }

    void setUnparkTime(time_t unparkTime)
    {
        this->unparkTime = unparkTime;
    }

    void parkVehicle(unordered_map<string, Vehicle> &vehicleMap, LinkedList &parkedVehiclesList)
    {
        while (true)
        {
            cout << "\n\t\t ______________________________________________\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t| [1]   |     Park Per Hour" << setw(22) << "|\n";
            cout << "\t\t| [2]   |     Park Per Day" << setw(23) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|_______|______________________________________|\n";

            while (true)
            {
                cout << "\n\t\tEnter the parking type: ";
                getline(cin, parkingType);
                if (menuChoice(parkingType))
                {
                    break;
                }
                cout << "\n\t\tInvalid input!\n";
            }
            if (parkingType == "1")
            {
                while (true)
                {
                    string hourStr;
                    cout << "\n\t\tEnter the no of hours to park the Vehicle: ";
                    getline(cin, hourStr);
                    if (hoursValidation(hourStr))
                    {
                        hours = stoi(hourStr);
                        break;
                    }
                    cout << "\n\t\tInvalid hours\n";
                }
                break;
            }
            else if (parkingType == "2")
            {
                while (true)
                {
                    string dayStr;
                    cout << "\n\t\tEnter the no of days to park the Vehicle: ";
                    getline(cin, dayStr);
                    if (daysValidation(dayStr))
                    {
                        days = stoi(dayStr);
                        break;
                    }
                    cout << "\n\t\tInvalid days\n";
                }
                break;
            }
            else
            {
                system("CLS");
                cout << "\n\t\tInvalid choice!\n";
            }
        }
        while (true)
        {
            cout << "\n\t\tEnter the (11 digit) Phone Number of the Vehicle holder: ";
            getline(cin, cellNo);
            if (phoneValidation(cellNo))
            {
                break;
            }
            cout << "\n\t\tInvalid Phone no.\n";
        }
        while (true)
        {
            cout << "\n\t\tEnter the plate no of the Vehicle: ";
            getline(cin, plateNo);

            // Correcting the for loop syntax to convert each character to uppercase
            for (int i = 0; i < plateNo.size(); i++)
            {
                plateNo[i] = toupper(plateNo[i]);
            }

            if (plateNoValidation(plateNo))
            {
                if (vehicleMap.find(plateNo) == vehicleMap.end())
                {
                    parkedVehiclesList.addVehicle(*this);
                    vehicleMap[plateNo] = *this;
                    break;
                }
                else
                {
                    cout << "\n\t\tPlate number already in Data-Base.\n";
                }
            }
            else
            {
                cout << "\n\t\tInvalid plate no.\n";
            }
        }

        time(&parkTime); // Set parking start time
    }

    string getPlateNo() const { return plateNo; }
    int getDays() const { return days; }
    int getHours() const { return hours; }
    string getParkingType() const { return parkingType; }
    string getCellNo() const { return cellNo; }
    time_t getParkTime() const { return parkTime; }
    time_t getUnparkTime() const { return unparkTime; }
};

class Node
{
public:
    Vehicle vehicle;
    Node *next;

    Node(Vehicle vehicle) : vehicle(vehicle), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addVehicle(const Vehicle &vehicle)
    {
        Node *newNode = new Node(vehicle);
        newNode->next = head;
        head = newNode;
    }

    Vehicle *findVehicleByPlateNo(const string &plateNo)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->vehicle.getPlateNo() == plateNo)
            {
                return &current->vehicle;
            }
            current = current->next;
        }
        return nullptr; // Not found
    }
};

class BillCalculate : public Vehicle
{
protected:
    int token;
    double amount;
    double extraAmount;
    bool paymentSuccess;
    double fine;
    double totalAmount;

public:
    BillCalculate(int _token = 0, double _fine = 0.0, double _amount = 0.0, double _totalAmount = 0.0, double _extraAmount = 0.0)
        : Vehicle(), token(_token), fine(_fine), amount(_amount), totalAmount(_totalAmount), extraAmount(_extraAmount) {}

    BillCalculate(int _token, string _cellNo, string _plateNo, int _days, int _hours, string _parkingType)
        : Vehicle(_cellNo, _plateNo, _days, _hours, _parkingType), token(_token), fine(0), totalAmount(0) {}

    string GetCurrentTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return to_string(1900 + ltm->tm_year) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    }

    void GenerateToken()
    {
        srand(time(0)); // Seed for random number generator
        token = rand() % 90000 + 100000;
    }

    int getToken()
    {
        return token;
    }

    double getAmount()
    {
        return totalAmount;
    }

    void calculateBill(string vehicleType)
    {
        time_t currentTime;
        time(&currentTime);
        double seconds = difftime(currentTime, getParkTime());
        double hoursParked = ceil(seconds / 3600.0);
        double daysParked = ceil(seconds / (24 * 3600.0));

        if (vehicleType == "Car")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 50;
                    totalAmount = daysParked * 70 + fine;
                }
                else
                {
                    totalAmount = days * 70;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 50;
                    totalAmount = hoursParked * 70 + fine;
                }
                else
                {
                    totalAmount = hours * 70;
                }
            }
        }
        else if (vehicleType == "Bus")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 70;
                    totalAmount = daysParked * 100 + fine;
                }
                else
                {
                    totalAmount = days * 100;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 70;
                    totalAmount = hoursParked * 100 + fine;
                }
                else
                {
                    totalAmount = hours * 100;
                }
            }
        }
        else if (vehicleType == "Bike")
        {
            if (parkingType == "2")
            {
                if (daysParked > days)
                {
                    fine = (daysParked - days) * 30;
                    totalAmount = daysParked * 50 + fine;
                }
                else
                {
                    totalAmount = days * 50;
                }
            }
            else if (parkingType == "1")
            {
                if (hoursParked > hours)
                {
                    fine = (hoursParked - hours) * 30;
                    totalAmount = hoursParked * 50 + fine;
                }
                else
                {
                    totalAmount = hours * 50;
                }
            }
        }
    }

    void displayBill(bool isParked)
    {
        system("CLS");
        cout << "\n*************** Parking Bill ***************\n";
        if (isParked)
            cout << "Time of Entry     : " << GetCurrentTime() << "\n";
        else
            cout << "Exit Time         : " << GetCurrentTime() << "\n";
        cout << "Phone Number      : " << cellNo << "\n";

        cout << "Plate Number      : " << plateNo << "\n";
        if (parkingType == "2")
            cout << "Days Parked       : " << days << " Days" << "\n";
        else if (parkingType == "1")
            cout << "Hours Parked      : " << hours << " Hours" << "\n";
        cout << "Token Number      : " << token << "\n";
        cout << "Fine Amount       : Rs." << fine << "\n";
        cout << "Total Amount      : Rs." << totalAmount << "\n";
        cout << "********************************************\n";
    }

    void AskForPayment()
    {
        string amountStr;
        while (true)
        {
            while (true)
            {
                cout << "Enter the payment amount: Rs.";
                getline(cin, amountStr);
                if (amountValid(amountStr))
                {
                    break;
                }
                cout << "Invalid amount!\n";
            }
            amount = stod(amountStr);
            if (amount >= totalAmount)
            {
                extraAmount = amount - totalAmount;
                if (extraAmount > 0)
                {
                    cout << "Thank you for Parking here!\n --> Your change: Rs. " << extraAmount << "\n";
                }
                else
                {
                    cout << "Thank you for Parking here!\n";
                }
                break;
            }
            else
            {
                cout << "Insufficient payment. Please enter the correct amount.\n";
            }
        }
    }
};

class Car : public BillCalculate
{
public:
    void carPark(unordered_map<string, Vehicle> &vehicleMap, LinkedList &parkedVehiclesList)
    {
        parkVehicle(vehicleMap, parkedVehiclesList);
        GenerateToken();
        calculateBill("Car");
        displayBill(true);
    }
};


class Bus : public BillCalculate
{
public:
    void busPark(unordered_map<string, Vehicle> &vehicleMap, LinkedList &parkedVehiclesList)
    {
        parkVehicle(vehicleMap, parkedVehiclesList);
        GenerateToken();
        calculateBill("Bus");
        displayBill(true);
    }
};


class Bike : public BillCalculate
{
public:
    void bikePark(unordered_map<string, Vehicle> &vehicleMap, LinkedList &parkedVehiclesList)
    {
        parkVehicle(vehicleMap, parkedVehiclesList);
        GenerateToken();
        calculateBill("Bike");
        displayBill(true);
    }
};



int main()
{
    LinkedList parkedVehiclesList;
    unordered_map<string, Vehicle> vehicleMap;

    // Example to park a vehicle
    Vehicle myVehicle("12345678901", "ABC123", 1, 5, "1");
    myVehicle.parkVehicle(vehicleMap, parkedVehiclesList);

    // Example to find a vehicle by plate number
    Vehicle *foundVehicle = parkedVehiclesList.findVehicleByPlateNo("ABC123");
    if (foundVehicle != nullptr)
    {
        cout << "Vehicle Found: " << foundVehicle->getPlateNo() << endl;
    }
    else
    {
        cout << "Vehicle not found." << endl;
    }

    return 0;
}
