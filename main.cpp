#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

class ErrorHandling
{

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
        // Remove spaces for easier processing
        plateNo.erase(remove(plateNo.begin(), plateNo.end(), ' '), plateNo.end());

        // Convert to uppercase for consistency
        transform(plateNo.begin(), plateNo.end(), plateNo.begin(), ::toupper);

        // Format checks
        if (plateNo.length() == 6)
        {
            // Format 1: ABC123
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) && isalpha(plateNo[2]) &&
                isdigit(plateNo[3]) && isdigit(plateNo[4]) && isdigit(plateNo[5]))
            {
                return true;
            }
            // Format 2: AB1234
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) &&
                isdigit(plateNo[2]) && isdigit(plateNo[3]) && isdigit(plateNo[4]) && isdigit(plateNo[5]))
            {
                return true;
            }
            // Format 3: ABCD12
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) && isalpha(plateNo[2]) && isalpha(plateNo[3]) &&
                isdigit(plateNo[4]) && isdigit(plateNo[5]))
            {
                return true;
            }
            // Format 6: A1234B
            if (isalpha(plateNo[0]) &&
                isdigit(plateNo[1]) && isdigit(plateNo[2]) && isdigit(plateNo[3]) && isdigit(plateNo[4]) &&
                isalpha(plateNo[5]))
            {
                return true;
            }
        }
        else if (plateNo.length() == 7)
        {
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) && isalpha(plateNo[2]) &&
                isdigit(plateNo[3]) && isdigit(plateNo[4]) && isdigit(plateNo[3]) && isdigit(plateNo[4]))
            {
                return true;
            }
        }
        else if (plateNo.length() == 8) // Format 4: ABC12DEF
        {
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) && isalpha(plateNo[2]) &&
                isdigit(plateNo[3]) && isdigit(plateNo[4]) &&
                isalpha(plateNo[5]) && isalpha(plateNo[6]) && isalpha(plateNo[7]))
            {
                return true;
            }
        }
        else if (plateNo.length() == 7) // Format 5: AB123CD
        {
            if (isalpha(plateNo[0]) && isalpha(plateNo[1]) &&
                isdigit(plateNo[2]) && isdigit(plateNo[3]) && isdigit(plateNo[4]) &&
                isalpha(plateNo[5]) && isalpha(plateNo[6]))
            {
                return true;
            }
        }

        return false;
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

    bool ratesValid(string &amount)
    {
        if (amount.empty())
        {
            return false;
        }

        for (char c : amount)
        {
            if (!isdigit(c)) // Only digits are allowed
            {
                return false;
            }
        }

        return true;
    }

    void passLogic(string &password, string promptText)
    {
        char pass[32] = {0};
        char ch;
        bool enter = false;
        int i = 0;
        bool show = false;

        cout << promptText;

        while (!enter)
        {
            ch = _getch();

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            {
                pass[i] = ch;
                if (show)
                {
                    cout << ch;
                }
                else
                {
                    cout << "*";
                }
                i++;
            }

            if (ch == '\b' && i >= 1)
            {
                cout << "\b \b";
                i--;
            }

            if (ch == '\r')
            {
                enter = true;
            }

            if (ch == '\t')
            {
                show = !show;
                cout << "\r" << promptText;
                for (int j = 0; j < i; j++)
                {
                    cout << (show ? pass[j] : '*');
                }
            }
        }

        pass[i] = '\0';
        password = pass;
    }

    bool passwordValidation(const string &str)
    {
        bool isLengthValid = str.length() >= 6;

        if (!isLengthValid)
        {
            cout << "\n\n\tPassword must be at least 6 characters long.\n\n";
        }

        return isLengthValid;
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

    template <typename T>
    void parkVehicle(unordered_map<string, T> &parkedVehicles)
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
                cout << "\n\t\tEnter hours b/w ( 1 - 24 ) \n"
                     << endl;
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
                cout << "\n\t\tEnter days b/w ( 1 - 31 ) \n"
                     << endl;
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
        cout << "\n\t\tEnter Phone No Format ( 03XX-XXXXXXX ) \n"
             << endl;
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
        cout << "\n\t\tEnter PlateNo Format ( ABC123, A1234B, ABCD12, ABC1234, ABC12DEF, AB123CD ) \n"
             << endl;
        while (true)
        {
            cout << "\n\t\tEnter the plate no of the Vehicle: ";
            getline(cin, plateNo);
            for (int i = 0; i < plateNo.size(); i++)
            {
                plateNo[i] = toupper(plateNo[i]);
            }
            if (plateNoValidation(plateNo))
            {
                if (parkedVehicles.find(plateNo) == parkedVehicles.end())
                {
                    parkedVehicles[plateNo] = static_cast<T &>(*this);
                    break;
                }
                else
                {
                    cout << "\n\t\tPlate number already in the database for this vehicle type.\n";
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

class BillCalculate : public Vehicle
{
public:
    struct RateConfig
    {
        double carHourlyRate;
        double carDailyRate;
        double busHourlyRate;
        double busDailyRate;
        double bikeHourlyRate;
        double bikeDailyRate;
        double carHourlyFineRate;
        double carDailyFineRate;
        double busHourlyFineRate;
        double busDailyFineRate;
        double bikeHourlyFineRate;
        double bikeDailyFineRate;
    };

private:
    int token;
    double amount;
    double extraAmount;
    double fine;
    unordered_map<int, bool> generatedTokens;

protected:
    double totalAmount;

public:
    BillCalculate(int _token = 0, double _fine = 0.0, double _amount = 0.0, double _totalAmount = 0.0, double _extraAmount = 0.0)
        : Vehicle(), token(_token), fine(_fine), amount(_amount), totalAmount(_totalAmount), extraAmount(_extraAmount) {}

    string GetCurrentTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return to_string(1900 + ltm->tm_year) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    }

    void GenerateToken()
    {
        srand(time(0));
        do
        {
            token = rand() % 90000 + 100000;
        } while (generatedTokens.find(token) != generatedTokens.end());
        generatedTokens[token] = true;
    }

    int getToken() const
    {
        return token;
    }

    double calculateOverstayTime(time_t entryTime, int allocatedHours, int allocatedDays)
    {
        time_t currentTime;
        time(&currentTime);

        double secondsParked = difftime(currentTime, entryTime);
        double hoursParked = secondsParked / 3600.0;
        double daysParked = secondsParked / (24 * 3600.0);

        double overstayHours = max(0.0, hoursParked - allocatedHours);
        double overstayDays = max(0.0, daysParked - allocatedDays);

        return (allocatedDays > 0) ? overstayDays : overstayHours;
    }
    void calculateBill(string vehicleType, const RateConfig &rates)
    {
        double overstayHours = 0;
        double overstayDays = 0;
        double totalHoursParked = 0;
        double totalDaysParked = 0;

        time_t currentTime;
        time(&currentTime);

        double secondsParked = difftime(currentTime, getParkTime());
        totalHoursParked = secondsParked / 3600.0;
        totalDaysParked = secondsParked / (24 * 3600.0);

        if (parkingType == "1")
        {                                                  // Hourly Parking
            totalHoursParked = max(1.0, totalHoursParked); // Ensure at least one hour is charged
            overstayHours = max(0.0, totalHoursParked - hours);
            totalAmount = (min(totalHoursParked, (double)hours) * rates.carHourlyRate) + (overstayHours * rates.carHourlyFineRate);
        }
        else if (parkingType == "2")
        {                                                // Daily Parking
            totalDaysParked = max(1.0, totalDaysParked); // Ensure at least one day is charged
            overstayDays = max(0.0, totalDaysParked - days);
            totalAmount = (min(totalDaysParked, (double)days) * rates.carDailyRate) + (overstayDays * rates.carDailyFineRate);
        }

        // Apply the appropriate rates based on vehicle type
        if (vehicleType == "Car")
        {
            totalAmount += overstayHours * rates.carHourlyFineRate + overstayDays * rates.carDailyFineRate;
        }
        else if (vehicleType == "Bus")
        {
            totalAmount += overstayHours * rates.busHourlyFineRate + overstayDays * rates.busDailyFineRate;
        }
        else if (vehicleType == "Bike")
        {
            totalAmount += overstayHours * rates.bikeHourlyFineRate + overstayDays * rates.bikeDailyFineRate;
        }
    }

    void displayBill(bool isParked)
    {
        system("CLS");
        cout << "\n*************** Parking Bill ***************\n";

        if (isParked)
        {
            cout << "Time of Entry     : " << GetCurrentTime() << "\n";
            cout << "Phone Number      : " << cellNo << "\n";
            cout << "Plate Number      : " << plateNo << "\n";
            if (parkingType == "2")
                cout << "Allocated Days    : " << days << " Days" << "\n";
            else if (parkingType == "1")
                cout << "Allocated Hours   : " << hours << " Hours" << "\n";
            cout << "Token Number      : " << token << "\n";
            // cout << "Amount            : Rs." << totalAmount << "\n"; // Show amount when parked
        }
        else
        {
            cout << "Exit Time         : " << GetCurrentTime() << "\n";
            cout << "Phone Number      : " << cellNo << "\n";
            cout << "Plate Number      : " << plateNo << "\n";

            time_t currentTime;
            time(&currentTime);

            double secondsParked = difftime(currentTime, getParkTime());
            double totalHoursParked = secondsParked / 3600.0;
            double totalDaysParked = secondsParked / (24 * 3600.0);

            if (parkingType == "2")
            {
                double parkedDays = max(1.0, totalDaysParked); // Ensure at least one day is charged
                cout << "Allocated Days    : " << days << " Days" << "\n";
                cout << "Days Parked       : " << parkedDays << " Days" << "\n";

                double overstayDays = ceil(totalDaysParked) - days;
                if (overstayDays > 0)
                {
                    cout << "Overstay Days     : " << overstayDays << " Days" << "\n";
                    cout << "Fine Amount       : Rs." << fine << "\n";
                }
            }
            else if (parkingType == "1")
            {
                double parkedHours = max(1.0, totalHoursParked); // Ensure at least one hour is charged
                cout << "Allocated Hours   : " << hours << " Hours" << "\n";
                cout << "Hours Parked      : " << parkedHours << " Hours" << "\n";

                double overstayHours = ceil(totalHoursParked) - hours;
                if (overstayHours > 0)
                {
                    cout << "Overstay Hours    : " << overstayHours << " Hours" << "\n";
                    cout << "Fine Amount       : Rs." << fine << "\n";
                }
            }
            cout << "Token Number      : " << token << "\n";
            cout << "Total Amount      : Rs." << totalAmount << "\n"; // Show total amount when unparked
        }
        cout << "********************************************\n";
    }

    void AskForPayment()
    {
        string amountStr;
        while (true)
        {
            cout << "Enter the payment amount: Rs.";
            getline(cin, amountStr);

            if (amountValid(amountStr))
            {
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
            else
            {
                cout << "Invalid amount!\n";
            }
        }
    }

    double getAmount() const
    {
        return totalAmount;
    }
};

class Car : public BillCalculate
{
private:
    double fine = 0.0;

public:
    void setFine(double fineAmount)
    {
        fine = fineAmount;
    }

    void updateTotalAmount()
    {
        totalAmount = getAmount() + fine;
    }

    double getFine() const
    {
        return fine;
    }

    void carPark(unordered_map<string, Car> &cars, const RateConfig &rates)
    {
        parkVehicle(cars);
        GenerateToken();
        calculateBill("Car", rates);
        displayBill(true);
    }
};

class Bus : public BillCalculate
{

private:
    double fine = 0.0;

public:
    void setFine(double fineAmount)
    {
        fine = fineAmount;
    }

    void updateTotalAmount()
    {
        totalAmount = getAmount() + fine;
    }

    double getFine() const
    {
        return fine;
    }

    void busPark(unordered_map<string, Bus> &buses, const RateConfig &rates)
    {
        parkVehicle(buses);
        GenerateToken();
        calculateBill("Bus", rates);
        displayBill(true);
    }
};

class Bike : public BillCalculate
{
private:
    double fine = 0.0;

public:
    void setFine(double fineAmount)
    {
        fine = fineAmount;
    }

    void updateTotalAmount()
    {
        totalAmount = getAmount() + fine;
    }

    double getFine() const
    {
        return fine;
    }

    void bikePark(unordered_map<string, Bike> &bikes, const RateConfig &rates)
    {
        parkVehicle(bikes);
        GenerateToken();
        calculateBill("Bike", rates);
        displayBill(true);
    }
};

class PaymentRecord : public ErrorHandling
{
private:
    struct PaymentInfo
    {
        int token;
        double amount;
        bool paid;
        time_t parkTime;
        time_t unparkTime;
        string vehicleType;
        string cellNumber;
    };

    unordered_map<string, PaymentInfo> payments;
    double totalAmount;
    int parkedCount;
    int unparkedCount;
    double withDrawAmount;

    string timeTostring(time_t time) const
    {
        char buffer[80];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", timeinfo);
        return string(buffer);
    }

public:
    PaymentRecord() : totalAmount(0.0), parkedCount(0), unparkedCount(0) {}

    void recordPayment(const string &plateNo, const string &vehicleType, int token, double amount, time_t parkTime, time_t unparkTime, bool isPaid, const string &cellNumber)
    {
        string keyBase = vehicleType + " " + plateNo;
        string key = keyBase;

        // Ensure unique key by appending a counter if necessary
        int counter = 1;
        while (payments.find(key) != payments.end())
        {
            key = keyBase + "-" + std::to_string(counter);
            counter++;
        }

        payments[key] = {token, amount, isPaid, parkTime, unparkTime, vehicleType, cellNumber};

        if (isPaid)
        {
            totalAmount += amount;
            unparkedCount++; // If payment is made, the vehicle is considered unparked
        }
        else
        {
            parkedCount++; // If payment is not made, the vehicle is considered parked
        }
    }

    void updatePaymentRecord(const string &plateNo, const string &vehicleType, int token, double amount, time_t unparkTime)
    {
        string keyBase = vehicleType + " " + plateNo;
        bool recordFound = false;

        for (int counter = 0;; counter++)
        {
            string key = (counter == 0) ? keyBase : keyBase + "-" + std::to_string(counter);

            auto it = payments.find(key);
            if (it != payments.end() && it->second.token == token)
            {
                recordFound = true;

                if (!it->second.paid) // If previously unpaid
                {
                    parkedCount--;   // Decrement parked count
                    unparkedCount++; // Increment unparked count
                }

                it->second.paid = true;
                it->second.unparkTime = unparkTime;
                totalAmount += amount;
                break;
            }
            if (it == payments.end() && counter > 0) // Break if no more records with appended numbers are found
            {
                break;
            }
        }

        if (!recordFound)
        {
            cout << "No payment record found for plate number " << plateNo << " and vehicle type " << vehicleType << " with token " << token << "." << endl;
        }
    }

    void displayPayments() const
    {
        if (payments.empty())
        {
            cout << "No payments recorded yet." << endl;
            return;
        }

        cout << "\n\n\t\t\t*************** Payment Records ***************\n\n";
        cout << setw(10) << "Type" << setw(12) << "Plate No" << setw(18) << "Token No" << setw(15) << "Amount" << setw(10) << "Paid" << setw(30) << "Park Date & Time" << setw(30) << "Unpark Date & Time" << setw(15) << "Cell No " << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        for (const auto &entry : payments)
        {
            const PaymentInfo &info = entry.second;
            cout << setw(10) << info.vehicleType
                 << setw(12) << entry.first.substr(entry.first.find(' ') + 1) // Extract plate number from key
                 << setw(18) << info.token
                 << setw(12) << "Rs : " << info.amount << setw(10) << (info.paid ? "Yes" : "No")
                 << setw(32) << timeTostring(info.parkTime); // Park Time

            if (info.paid)
            {
                cout << setw(30) << timeTostring(info.unparkTime); // Unpark Time
            }
            else
            {
                cout << setw(30) << "N/A"; // Unpark time is not available
            }
            cout << setw(20) << info.cellNumber << endl; // Display Cell Number
            cout << endl;
        }

        cout << "\n***********************************************************************************************************************************************\n";
        cout << "\n\tTotal Amount: Rs : " << totalAmount << "\t" << "Parked Vehicles: " << parkedCount << "\t" << "Unparked Vehicles: " << unparkedCount << "\n";
    }

    void deleteAllRecords()
    {
        if (payments.empty())
        {
            cout << "No payments recorded yet." << endl;
            return;
        }

        bool hasPaidRecords = false;
        for (auto it = payments.begin(); it != payments.end();)
        {
            if (it->second.paid)
            {
                it = payments.erase(it);
                unparkedCount--;
                hasPaidRecords = true;
            }
            else
            {
                ++it;
            }
        }

        if (hasPaidRecords)
        {
            cout << "All paid payment records have been deleted." << endl;
        }
        else
        {
            cout << "No paid payment records to delete." << endl;
        }
    }

    void deleteSpecificRecord(const string &plateNo, const string &vehicleType)
    {
        string keyBase = vehicleType + " " + plateNo;
        bool recordFound = false;

        for (int counter = 0;; counter++)
        {
            string key = (counter == 0) ? keyBase : keyBase + "-" + std::to_string(counter);

            auto it = payments.find(key);
            if (it != payments.end())
            {
                if (!it->second.paid)
                {
                    cout << "Cannot delete unpaid payment record for plate number " << plateNo << "." << endl;
                    return;
                }
                else
                {
                    unparkedCount--;
                    totalAmount -= it->second.amount;
                    payments.erase(it);
                    recordFound = true;
                    cout << "Paid payment record for plate number " << plateNo << " has been deleted." << endl;
                    break;
                }
            }
            if (it == payments.end() && counter > 0) // Break if no more records with appended numbers are found
            {
                break;
            }
        }

        if (!recordFound)
        {
            cout << "No payment record found for plate number " << plateNo << "." << endl;
        }
    }

    void withdrawPayment(const string &adminPassword)
    {
        int attempts = 0;
        string enteredPassword;

        // Admin authentication
        while (attempts < 3)
        {
            passLogic(enteredPassword, "Enter admin password: ");
            if (enteredPassword == adminPassword)
            {
                // Proceed with withdrawal if the password is correct
                string amountstr;
                if (totalAmount <= 0)
                {
                    cout << "\n\n\tNo funds available for withdrawal." << endl;
                    return;
                }
                else
                {
                    cout << "\nTotal Amount available for withdrawal: Rs" << totalAmount << endl;
                    while (true)
                    {
                        while (true)
                        {
                            cout << "Enter amount to withdraw: Rs";
                            getline(cin, amountstr);
                            if (amountValid(amountstr)) // Assuming amountValid is a function that checks if input is a valid amount.
                            {
                                break;
                            }
                            cout << "Invalid amount! Please enter a valid number.\n";
                        }
                        withDrawAmount = stod(amountstr);
                        if (withDrawAmount <= 0)
                        {
                            cout << "\nPlease enter a correct amount for withdrawal.\n";
                        }
                        else if (withDrawAmount > totalAmount)
                        {
                            cout << "Insufficient funds. You can withdraw up to Rs " << totalAmount << "." << endl;
                        }
                        else
                        {
                            totalAmount -= withDrawAmount;
                            cout << "Rs " << withDrawAmount << " has been successfully withdrawn. Remaining balance: Rs " << totalAmount << endl;
                            return; // Exit the function after successful withdrawal
                        }
                    }
                }
            }
            else
            {
                attempts++;
                if (attempts < 3)
                {
                    cout << "Incorrect password. Try again.\n";
                }
                else
                {
                    cout << "Incorrect password entered three times. Withdrawal process terminated.\n";
                }
            }
        }
    }
};

class ParkAndUnPark : public ErrorHandling
{

    // Declarations
    unordered_map<string, Car> cars;   // Stores currently parked cars with their plate number as the key
    unordered_map<string, Bus> buses;  // Stores currently parked buses with their plate number as the key
    unordered_map<string, Bike> bikes; // Stores currently parked bikes with their plate number as the key

    unordered_map<string, Car> unparkedCars;   // Stores unparked cars
    unordered_map<string, Bus> unparkedBuses;  // Stores unparked buses
    unordered_map<string, Bike> unparkedBikes; // Stores unparked bikes

    unordered_map<string, int> blockedVehicles; // Key: "PlateNo-Token", Value: Token number (for blocked vehicles)
    vector<string> parkedPlateNumbers;          // Stores the plate numbers of all currently parked vehicles

    PaymentRecord payment;           // Object for managing payment records
    BillCalculate::RateConfig rates; // Configuration for billing rates

    int token;          // Token number used for vehicle validation
    string plateNumber; // Plate number of the vehicle being processed
    bool found;         // Flag to indicate if a vehicle was found during search
    string unParkToken; // The token number entered during the unpark process
    int plateAttempts;
    int tokenAttempts;

    string formatTime(time_t time)
    {
        char buffer[80];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", timeinfo);
        return string(buffer);
    }

    template <typename T>
    void quickSort(vector<T> &list, int left, int right)
    {
        int i = left, j = right;
        T tmp;
        T pivot = list[(left + right) / 2];

        while (i <= j)
        {
            while (list[i].getPlateNo() < pivot.getPlateNo())
                i++;
            while (list[j].getPlateNo() > pivot.getPlateNo())
                j--;
            if (i <= j)
            {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
                i++;
                j--;
            }
        }

        if (left < j)
            quickSort(list, left, j);
        if (i < right)
            quickSort(list, i, right);
    }

    template <typename T>
    void deleteRecord(unordered_map<string, T> &records, const string &plateNo)
    {
        auto it = records.find(plateNo);
        if (it != records.end())
        {
            records.erase(it);
            cout << "\n\t\tRecord with plate number " << plateNo << " has been deleted.\n";
        }
        else
        {
            cout << "\n\t\tRecord with plate number " << plateNo << " not found.\n";
        }
    }

    template <typename T>
    void deleteAllRecords(unordered_map<string, T> &records, const string &type)
    {
        records.clear();
        cout << "\n\t\tAll " << type << " records have been deleted.\n";
    }

    void blockVehicle(const string &plateNo, int blockToken)
    {
        string key = plateNo + "-" + std::to_string(blockToken);
        blockedVehicles[key] = blockToken;
    }

    bool isTokenBlocked(const string &plateNo, int token)
    {
        string key = plateNo + "-" + std::to_string(token);
        return blockedVehicles.find(key) != blockedVehicles.end();
    }

public:
    ParkAndUnPark() : payment()
    {
        // Initialize default rates
        rates.carHourlyRate = 70;
        rates.carDailyRate = 70;
        rates.busHourlyRate = 100;
        rates.busDailyRate = 100;
        rates.bikeHourlyRate = 50;
        rates.bikeDailyRate = 50;
        rates.carHourlyFineRate = 50;
        rates.carDailyFineRate = 50;
        rates.busHourlyFineRate = 70;
        rates.busDailyFineRate = 70;
        rates.bikeHourlyFineRate = 30;
        rates.bikeDailyFineRate = 30;
    }

    // Add methods to set rates
    void setCarRates(double hourlyRate, double dailyRate, double hourlyFineRate, double dailyFineRate)
    {
        rates.carHourlyRate = hourlyRate;
        rates.carDailyRate = dailyRate;
        rates.carHourlyFineRate = hourlyFineRate;
        rates.carDailyFineRate = dailyFineRate;
    }
    void setBusRates(double hourlyRate, double dailyRate, double hourlyFineRate, double dailyFineRate)
    {
        rates.busHourlyRate = hourlyRate;
        rates.busDailyRate = dailyRate;
        rates.busHourlyFineRate = hourlyFineRate;
        rates.busDailyFineRate = dailyFineRate;
    }
    void setBikeRates(double hourlyRate, double dailyRate, double hourlyFineRate, double dailyFineRate)
    {
        rates.bikeHourlyRate = hourlyRate;
        rates.bikeDailyRate = dailyRate;
        rates.bikeHourlyFineRate = hourlyFineRate;
        rates.bikeDailyFineRate = dailyFineRate;
    }

    BillCalculate::RateConfig getRates() const
    {
        return rates;
    }

    void unblockVehicle(const string &plateNo, int unblockToken)
    {
        string key = plateNo + "-" + std::to_string(unblockToken);
        if (blockedVehicles.find(key) != blockedVehicles.end())
        {
            blockedVehicles.erase(key);
            cout << "\nVehicle with plate number " << plateNo << " and token " << unblockToken << " successfully unblocked.\n";
        }
        else
        {
            cout << "\nError: Vehicle with plate number " << plateNo << " and token " << unblockToken << " not found in the blocked list.\n";
        }
    }

    void parkCar()
    {
        Car car;
        car.carPark(cars, rates);
        cars[car.getPlateNo()] = car;
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(car.getPlateNo(), "Car", car.getToken(), car.getAmount(), parkTime, 0, false, car.getCellNo());
    }

    void parkBus()
    {
        Bus bus;
        bus.busPark(buses, rates);
        buses[bus.getPlateNo()] = bus;
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(bus.getPlateNo(), "Bus", bus.getToken(), bus.getAmount(), parkTime, 0, false, bus.getCellNo());
    }

    void parkBike()
    {
        Bike bike;
        bike.bikePark(bikes, rates);
        bikes[bike.getPlateNo()] = bike;
        time_t parkTime;
        time(&parkTime);
        payment.recordPayment(bike.getPlateNo(), "Bike", bike.getToken(), bike.getAmount(), parkTime, 0, false, bike.getCellNo());
    }

    // Unpark logic with blocking after failed attempts
    void unparkCar()
    {
        plateAttempts = 0;
        tokenAttempts = 0;
        found = false;
        auto carIt = cars.end();

        if (cars.empty())
        {
            cout << "\n\t\tNo cars currently parked!\n";
            return;
        }

        // Get the plate number
        while (plateAttempts < 3)
        {
            cout << "\n\t\tEnter the plate number of the car to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }

            if (plateNoValidation(plateNumber))
            {
                carIt = cars.find(plateNumber);
                if (carIt != cars.end())
                {
                    found = true;
                    break;
                }
                else
                {
                    cout << "\n\t\tInvalid plate number. Please try again.\n";
                    plateAttempts++;
                }
            }
            else
            {
                cout << "\n\t\tInvalid input. Please enter a valid plate number.\n";
                plateAttempts++;
            }
        }

        if (!found)
        {
            cout << "\n\t\tFailed to enter a valid plate number after three attempts.\n";
            return;
        }

        // Get the token
        while (tokenAttempts < 3)
        {
            cout << "\n\t\tEnter the token number of the car to unpark: ";
            getline(cin, unParkToken);
            if (tokenValid(unParkToken))
            {
                int token = stoi(unParkToken);

                if (!isTokenBlocked(plateNumber, token))
                {
                    if (carIt != cars.end() && carIt->second.getToken() == token)
                    {
                        // Handle overstay fine
                        double overstayTime = carIt->second.calculateOverstayTime(carIt->second.getParkTime(), carIt->second.getHours(), carIt->second.getDays());
                        if (overstayTime > 0)
                        {
                            if (carIt->second.getParkingType() == "2")
                            { // Daily parking
                                carIt->second.setFine(overstayTime * rates.carDailyFineRate);
                            }
                            else if (carIt->second.getParkingType() == "1")
                            { // Hourly parking
                                carIt->second.setFine(overstayTime * rates.carHourlyFineRate);
                            }

                            carIt->second.updateTotalAmount();
                        }

                        // Process payment
                        carIt->second.displayBill(false);
                        carIt->second.AskForPayment();

                        // Record payment
                        time_t unparkTime;
                        time(&unparkTime);
                        carIt->second.setUnparkTime(unparkTime);
                        payment.updatePaymentRecord(carIt->second.getPlateNo(), "Car", token, carIt->second.getAmount(), carIt->second.getUnparkTime());

                        // Generate unique key for unpark records
                        string unparkKey = plateNumber + "-" + to_string(unparkedCars.size() + 1) + "-" + to_string(unparkTime);
                        unparkedCars[unparkKey] = carIt->second;
                        cars.erase(carIt);

                        cout << "\n\t\tCar unparked successfully!\n";
                        return;
                    }
                    else
                    {
                        cout << "\n\t\tInvalid token number. Please try again.\n";
                        tokenAttempts++;
                    }
                }
                else
                {
                    cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                    return;
                }
            }
            else
            {
                cout << "\n\t\tInvalid input. Please enter a valid token number.\n";
                tokenAttempts++;
            }
        }

        if (tokenAttempts >= 3)
        {
            cout << "\n\t\tFailed to enter a valid token number after three attempts. Blocking the car.\n";
            blockVehicle(plateNumber, carIt->second.getToken());
        }
    }

    void unparkBus()
    {
        plateAttempts = 0;
        tokenAttempts = 0;
        found = false;
        auto busIt = buses.end();
        if (buses.empty())
        {
            cout << "\n\t\tNo buses currently parked!\n";
            return;
        }

        while (plateAttempts < 3)
        {
            cout << "\n\t\tEnter the plate number of the bus to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }
            if (plateNoValidation(plateNumber))
            {
                busIt = buses.find(plateNumber);
                if (busIt != buses.end())
                {
                    found = true;
                    break;
                }
                else
                {
                    cout << "\n\t\tInvalid plate number. Please try again.\n";
                    plateAttempts++;
                }
            }
            else
            {
                cout << "\n\t\tInvalid input. Please enter a valid plate number.\n";
                plateAttempts++;
            }
        }

        if (!found)
        {
            cout << "\n\t\tFailed to enter a valid plate number after three attempts.\n";
            return;
        }

        // If found the correct plate number, now ask for the token number
        if (found)
        {
            while (tokenAttempts < 3)
            {
                cout << "\n\t\tEnter the token number of the bus to unpark: ";
                getline(cin, unParkToken);
                if (tokenValid(unParkToken))
                {
                    token = stoi(unParkToken);

                    if (!isTokenBlocked(plateNumber, token))
                    {
                        if (busIt != buses.end() && busIt->second.getToken() == token)
                        {
                            // Calculate overstay time using the Car instance
                            double overstayTime = busIt->second.calculateOverstayTime(busIt->second.getParkTime(), busIt->second.getHours(), busIt->second.getDays());

                            // Apply fines if there is overstay
                            if (overstayTime > 0)
                            {
                                if (busIt->second.getParkingType() == "2")
                                {
                                    busIt->second.setFine(overstayTime * rates.carDailyFineRate);
                                }
                                else if (busIt->second.getParkingType() == "1")
                                {
                                    busIt->second.setFine(overstayTime * rates.carHourlyFineRate);
                                }
                                busIt->second.updateTotalAmount();
                            }

                            busIt->second.displayBill(false);
                            busIt->second.AskForPayment();
                            time_t unparkTime;
                            time(&unparkTime);
                            busIt->second.setUnparkTime(unparkTime);
                            payment.updatePaymentRecord(busIt->second.getPlateNo(), "Bus", token, busIt->second.getAmount(), busIt->second.getUnparkTime());

                            // Generate unique key for unpark records
                            string unparkKey = plateNumber + "-" + to_string(unparkedBuses.size() + 1) + "-" + to_string(unparkTime);
                            unparkedBuses[unparkKey] = busIt->second;
                            buses.erase(busIt);

                            cout << "\n\t\tBus unparked successfully!\n";
                            return;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid token number. Please try again.\n";
                            tokenAttempts++;
                        }
                    }
                    else
                    {
                        cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                        return;
                    }
                }
                else
                {
                    cout << "\n\t\tInvalid input. Please enter a valid token number.\n";
                    tokenAttempts++;
                }
            }

            if (tokenAttempts >= 3)
            {
                cout << "\n\t\tFailed to enter a valid token number after three attempts. Blocking the car.\n";
                blockVehicle(plateNumber, busIt->second.getToken());
            }
        }
    }

    void unparkBike()
    {
        plateAttempts = 0;
        tokenAttempts = 0;
        found = false;
        auto bikeIt = bikes.end();
        if (bikes.empty())
        {
            cout << "\n\t\tNo bikes currently parked!\n";
            return;
        }

        while (plateAttempts < 3)
        {
            cout << "\n\t\tEnter the plate number of the bike to unpark: ";
            getline(cin, plateNumber);
            for (int i = 0; i < plateNumber.size(); i++)
            {
                plateNumber[i] = toupper(plateNumber[i]);
            }
            if (plateNoValidation(plateNumber))
            {
                bikeIt = bikes.find(plateNumber);
                if (bikeIt != bikes.end())
                {
                    found = true;
                    break;
                }
                else
                {
                    cout << "\n\t\tInvalid plate number. Please try again.\n";
                    plateAttempts++;
                }
            }
            else
            {
                cout << "\n\t\tInvalid input. Please enter a valid plate number.\n";
                plateAttempts++;
            }
        }

        if (!found)
        {
            cout << "\n\t\tFailed to enter a valid plate number after three attempts.\n";
            return;
        }

        // If found the correct plate number, now ask for the token number
        if (found)
        {
            while (tokenAttempts < 3)
            {
                cout << "\n\t\tEnter the token number of the bus to unpark: ";
                getline(cin, unParkToken);
                if (tokenValid(unParkToken))
                {
                    token = stoi(unParkToken);

                    if (!isTokenBlocked(plateNumber, token))
                    {
                        if (bikeIt != bikes.end() && bikeIt->second.getToken() == token)
                        {
                            // Calculate overstay time using the Car instance
                            double overstayTime = bikeIt->second.calculateOverstayTime(bikeIt->second.getParkTime(), bikeIt->second.getHours(), bikeIt->second.getDays());

                            // Apply fines if there is overstay
                            if (overstayTime > 0)
                            {
                                if (bikeIt->second.getParkingType() == "2")
                                {
                                    bikeIt->second.setFine(overstayTime * rates.carDailyFineRate);
                                }
                                else if (bikeIt->second.getParkingType() == "1")
                                {
                                    bikeIt->second.setFine(overstayTime * rates.carHourlyFineRate);
                                }
                                bikeIt->second.updateTotalAmount();
                            }

                            bikeIt->second.displayBill(false);
                            bikeIt->second.AskForPayment();
                            time_t unparkTime;
                            time(&unparkTime);
                            bikeIt->second.setUnparkTime(unparkTime);
                            payment.updatePaymentRecord(bikeIt->second.getPlateNo(), "Bike", token, bikeIt->second.getAmount(), bikeIt->second.getUnparkTime());

                            // Generate unique key for unpark records
                            string unparkKey = plateNumber + "-" + to_string(unparkedBikes.size() + 1) + "-" + to_string(unparkTime);
                            unparkedBikes[unparkKey] = bikeIt->second;
                            bikes.erase(bikeIt);
                            cout << "\n\t\tBike unparked successfully!\n";
                            return;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid token number. Please try again.\n";
                            tokenAttempts++;
                        }
                    }
                    else
                    {
                        cout << "\n\t\tToken is currently blocked. Please contact admin to unblock.\n";
                        return;
                    }
                }
                else
                {
                    cout << "\n\t\tInvalid input. Please enter a valid token number.\n";
                    tokenAttempts++;
                }
            }

            if (tokenAttempts >= 3)
            {
                cout << "\n\t\tFailed to enter a valid token number after three attempts. Blocking the car.\n";
                blockVehicle(plateNumber, bikeIt->second.getToken());
            }
        }
    }

    void displayParkedCars()
    {
        if (cars.empty())
        {
            cout << "\n\t\tNo Cars Parked found!\n";
        }
        else
        {
            vector<Car> carList;
            for (const auto &entry : cars)
            {
                carList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(carList, 0, carList.size() - 1);

            cout << "\n\t\t\t--------------------- Parked Cars ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < carList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << carList[i].getCellNo() << setw(20) << carList[i].getPlateNo() << setw(20) << carList[i].getToken();
                cout << setw(11) << (carList[i].getParkingType() == "2" ? carList[i].getDays() : carList[i].getHours())
                     << (carList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(carList[i].getParkTime()) << setw(20) << (isTokenBlocked(carList[i].getPlateNo(), carList[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            carList.clear(); // Clear the vector after displaying
        }
    }

    void displayParkedBuses()
    {
        if (buses.empty())
        {
            cout << "\n\t\tNo Buses Parked found!\n";
        }
        else
        {
            vector<Bus> busList;
            for (const auto &entry : buses)
            {
                busList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(busList, 0, busList.size() - 1);

            cout << "\n\t\t\t--------------------- Parked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < busList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << busList[i].getCellNo() << setw(20) << busList[i].getPlateNo() << setw(20) << busList[i].getToken();
                cout << setw(11) << (busList[i].getParkingType() == "2" ? busList[i].getDays() : busList[i].getHours())
                     << (busList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(busList[i].getParkTime()) << setw(20) << (isTokenBlocked(busList[i].getPlateNo(), busList[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            busList.clear(); // Clear the vector after displaying
        }
    }

    void displayParkedBikes()
    {
        if (bikes.empty())
        {
            cout << "\n\t\tNo Bikes Parked found!\n";
        }
        else
        {
            vector<Bike> bikeList;
            for (const auto &entry : bikes)
            {
                bikeList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(bikeList, 0, bikeList.size() - 1);

            cout << "\n\t\t\t--------------------- Parked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Park Date & Time" << setw(19) << "Status" << "\n\n";
            for (int i = 0; i < bikeList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << bikeList[i].getCellNo() << setw(20) << bikeList[i].getPlateNo() << setw(20) << bikeList[i].getToken();
                cout << setw(11) << (bikeList[i].getParkingType() == "2" ? bikeList[i].getDays() : bikeList[i].getHours())
                     << (bikeList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(bikeList[i].getParkTime()) << setw(20) << (isTokenBlocked(bikeList[i].getPlateNo(), bikeList[i].getToken()) ? "Blocked " : "Available") << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            bikeList.clear(); // Clear the vector after displaying
        }
    }

    void displayUnparkedCars()
    {
        if (unparkedCars.empty())
        {
            cout << "\n\t\tNo Unparked Cars found!\n";
        }
        else
        {
            vector<Car> carList;
            for (const auto &entry : unparkedCars)
            {
                carList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(carList, 0, carList.size() - 1);

            cout << "\n\t\t\t--------------------- Unparked Cars ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Unpark Date & Time" << "\n\n";
            for (int i = 0; i < carList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << carList[i].getCellNo() << setw(20) << carList[i].getPlateNo() << setw(20) << carList[i].getToken();
                cout << setw(11) << (carList[i].getParkingType() == "2" ? carList[i].getDays() : carList[i].getHours())
                     << (carList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(carList[i].getUnparkTime()) << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            carList.clear(); // Clear the vector after displaying
        }
    }

    void displayUnparkedBuses()
    {
        if (unparkedBuses.empty())
        {
            cout << "\n\t\tNo Unparked Buses found!\n";
        }
        else
        {
            vector<Bus> busList;
            for (const auto &entry : unparkedBuses)
            {
                busList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(busList, 0, busList.size() - 1);

            cout << "\n\t\t\t--------------------- Unparked Buses ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Unpark Date & Time" << "\n\n";
            for (int i = 0; i < busList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << busList[i].getCellNo() << setw(20) << busList[i].getPlateNo() << setw(20) << busList[i].getToken();
                cout << setw(11) << (busList[i].getParkingType() == "2" ? busList[i].getDays() : busList[i].getHours())
                     << (busList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(busList[i].getUnparkTime()) << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            busList.clear(); // Clear the vector after displaying
        }
    }

    void displayUnparkedBikes()
    {
        if (unparkedBikes.empty())
        {
            cout << "\n\t\tNo Unparked Bikes found!\n";
        }
        else
        {
            vector<Bike> bikeList;
            for (const auto &entry : unparkedBikes)
            {
                bikeList.push_back(entry.second);
            }

            // Sort the list using quick sort
            quickSort(bikeList, 0, bikeList.size() - 1);

            cout << "\n\t\t\t--------------------- Unparked Bikes ----------------------\n\n";
            cout << setw(10) << "Serial No" << setw(17) << "Cell No" << setw(22) << "Plate No" << setw(21) << "Token No" << setw(20) << "Parking Type" << setw(23) << "Unpark Date & Time" << "\n\n";
            for (int i = 0; i < bikeList.size(); i++)
            {
                cout << setw(4) << i + 1 << setw(25) << bikeList[i].getCellNo() << setw(20) << bikeList[i].getPlateNo() << setw(20) << bikeList[i].getToken();
                cout << setw(11) << (bikeList[i].getParkingType() == "2" ? bikeList[i].getDays() : bikeList[i].getHours())
                     << (bikeList[i].getParkingType() == "2" ? " day(s)" : " hour(s)")
                     << setw(28) << formatTime(bikeList[i].getUnparkTime()) << "\n";
            }
            cout << "\n-------------------------------------------------------------------------------------------------------------\n\n\n";
            bikeList.clear(); // Clear the vector after displaying
        }
    }

    void Payments()
    {
        payment.displayPayments();
    }

    void deletePayRecords()
    {
        payment.deleteAllRecords();
    }

    void withDraw(const string &adminPassword)
    {
        payment.withdrawPayment(adminPassword);
    }

    void deleteSpecificPaymentRecord(const string &plateNo, const string &vehicleType)
    {
        payment.deleteSpecificRecord(plateNo, vehicleType);
    }

    void deleteUnparkedCar(const string &plateNo)
    {
        deleteRecord(unparkedCars, plateNo);
    }

    void deleteUnparkedBus(const string &plateNo)
    {
        deleteRecord(unparkedBuses, plateNo);
    }

    void deleteUnparkedBike(const string &plateNo)
    {
        deleteRecord(unparkedBikes, plateNo);
    }

    void deleteAllUnparkedCars()
    {
        deleteAllRecords(unparkedCars, "unparked cars");
    }

    void deleteAllUnparkedBuses()
    {
        deleteAllRecords(unparkedBuses, "unparked buses");
    }

    void deleteAllUnparkedBikes()
    {
        deleteAllRecords(unparkedBikes, "unparked bikes");
    }

    void deleteUnParkedRecords()
    {
        bool anyRecordsDeleted = false;

        if (!unparkedCars.empty())
        {
            unparkedCars.clear();
            anyRecordsDeleted = true;
        }

        if (!unparkedBuses.empty())
        {
            unparkedBuses.clear();
            anyRecordsDeleted = true;
        }

        if (!unparkedBikes.empty())
        {
            unparkedBikes.clear();
            anyRecordsDeleted = true;
        }

        if (anyRecordsDeleted)
        {
            cout << "\n\t\tAll unparked vehicle records have been deleted.\n";
        }
        else
        {
            cout << "\n\t\tNo unparked vehicle records found to delete.\n";
        }
    }
};

void changeAdminPassword(string &adminPassword, ParkAndUnPark &parking)
{
    system("CLS");
    string oldPassword;
    string newPassword;

    parking.passLogic(oldPassword, "Enter old password: ");

    if (oldPassword == adminPassword)
    {
        while (true)
        {
            cout << "\n";
            parking.passLogic(newPassword, "Enter new password: ");

            if (parking.nameValid(newPassword))
            {
                adminPassword = newPassword;
                cout << "\n\t\tPassword changed successfully!\n";
                break;
            }
            cout << "\n\t\tInvalid new password\n";
        }
    }
    else
    {
        cout << "\n\t\tIncorrect old password. Password change failed!\n";
    }
}
void setRates(ParkAndUnPark &parking)
{
    string choice;
    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     Set Car Rates" << setw(22) << "|\n";
        cout << "\t\t| [2]   |     Set Bus Rates" << setw(22) << "|\n";
        cout << "\t\t| [3]   |     Set Bike Rates" << setw(21) << "|\n";
        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t||_|\n";

        while (true)
        {
            cout << "\n\t\tEnter your choice: ";
            getline(cin, choice);
            if (parking.menuChoice(choice))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }

        if (choice == "1")
        {
            string carHourlyRate, carDailyRate, carHourlyFineRate, carDailyFineRate;

            do
            {
                cout << "\n\t\tEnter Car Hourly Rate: ";
                getline(cin, carHourlyRate);
                if (parking.ratesValid(carHourlyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Car Daily Rate: ";
                getline(cin, carDailyRate);
                if (parking.ratesValid(carDailyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Car Hourly Fine Rate: ";
                getline(cin, carHourlyFineRate);
                if (parking.ratesValid(carHourlyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Car Daily Fine Rate: ";
                getline(cin, carDailyFineRate);
                if (parking.ratesValid(carDailyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            parking.setCarRates(stod(carHourlyRate), stod(carDailyRate), stod(carHourlyFineRate), stod(carDailyFineRate));
        }
        else if (choice == "2")
        {
            string busHourlyRate, busDailyRate, busHourlyFineRate, busDailyFineRate;

            do
            {
                cout << "\n\t\tEnter Bus Hourly Rate: ";
                getline(cin, busHourlyRate);
                if (parking.ratesValid(busHourlyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bus Daily Rate: ";
                getline(cin, busDailyRate);
                if (parking.ratesValid(busDailyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bus Hourly Fine Rate: ";
                getline(cin, busHourlyFineRate);
                if (parking.ratesValid(busHourlyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bus Daily Fine Rate: ";
                getline(cin, busDailyFineRate);
                if (parking.ratesValid(busDailyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            parking.setBusRates(stod(busHourlyRate), stod(busDailyRate), stod(busHourlyFineRate), stod(busDailyFineRate));
        }
        else if (choice == "3")
        {
            string bikeHourlyRate, bikeDailyRate, bikeHourlyFineRate, bikeDailyFineRate;

            do
            {
                cout << "\n\t\tEnter Bike Hourly Rate: ";
                getline(cin, bikeHourlyRate);
                if (parking.ratesValid(bikeHourlyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bike Daily Rate: ";
                getline(cin, bikeDailyRate);
                if (parking.ratesValid(bikeDailyRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bike Hourly Fine Rate: ";
                getline(cin, bikeHourlyFineRate);
                if (parking.ratesValid(bikeHourlyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            do
            {
                cout << "\n\t\tEnter Bike Daily Fine Rate: ";
                getline(cin, bikeDailyFineRate);
                if (parking.ratesValid(bikeDailyFineRate))
                {
                    break;
                }
                cout << "\n\t\tInvalid input. Please enter a valid rate without decimals or invalid characters.\n";
            } while (true);

            parking.setBikeRates(stod(bikeHourlyRate), stod(bikeDailyRate), stod(bikeHourlyFineRate), stod(bikeDailyFineRate));
        }
        else if (choice == "0")
        {
            system("CLS");
            break;
        }
        else
        {
            system("CLS");
            cout << "\n\t\tInvalid choice!\n";
        }
    }
}

void adminInterface(ParkAndUnPark &parking, string &adminPassword)
{
    // Main admin menu
    int adminAttempt = 0;
    while (true)
    {
        string passcode;

        parking.passLogic(passcode, "Enter the passcode to access the administration: ");
        if (passcode == adminPassword)
        {
            system("CLS");
            cout << "\n\t\tAccess granted! Welcome Admin.\n";
            string tokenStr;
            int token;
            string admin;
            while (true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Show Vehicle Data" << setw(18) << "|\n";
                cout << "\t\t| [2]   |     Delete Vehicle Data" << setw(16) << "|\n";
                cout << "\t\t| [3]   |     Restricted Data" << setw(20) << "|\n";
                cout << "\t\t| [4]   |     Set Parking Rates" << setw(18) << "|\n";
                cout << "\t\t| [5]   |     Payment Record" << setw(21) << "|\n";
                cout << "\t\t| [6]   |     Change Password" << setw(20) << "|\n";
                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                while (true)
                {
                    cout << "\n\t\tEnter your choice: ";
                    getline(cin, admin);
                    if (parking.menuChoice(admin))
                    {
                        break;
                    }
                    cout << "\n\t\tInvalid input.\n";
                }
                if (admin == "1")
                {
                    string data;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Park Data" << setw(26) << "|\n";
                        cout << "\t\t| [2]   |     Unpark Data" << setw(24) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, data);
                            if (parking.menuChoice(data))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (data == "1")
                        {
                            system("CLS");
                            cout << "\n\t\t ______________________________________________\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                            cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|_______|______________________________________|\n";
                            while (true)
                            {
                                cout << "\n\t\tEnter your choice: ";
                                getline(cin, data);
                                if (parking.menuChoice(data))
                                {
                                    break;
                                }
                                cout << "\n\t\tInvalid input.\n";
                            }
                            if (data == "1")
                            {
                                parking.displayParkedCars();
                            }
                            else if (data == "2")
                            {
                                parking.displayParkedBuses();
                            }
                            else if (data == "3")
                            {
                                parking.displayParkedBikes();
                            }
                            else if (data == "0")
                            {
                                system("CLS");
                                break;
                            }
                            else
                            {
                                system("CLS");
                                cout << "\n\t\tInvalid choice.\n";
                            }
                        }
                        else if (data == "2")
                        {
                            system("CLS");
                            cout << "\n\t\t ______________________________________________\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                            cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                            cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                            cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                            cout << "\t\t|       |" << setw(40) << "|\n";
                            cout << "\t\t|_______|______________________________________|\n";
                            while (true)
                            {
                                cout << "\n\t\tEnter your choice: ";
                                getline(cin, data);
                                if (parking.menuChoice(data))
                                {
                                    break;
                                }
                                cout << "\n\t\tInvalid input.\n";
                            }
                            if (data == "1")
                            {
                                parking.displayUnparkedCars();
                            }
                            else if (data == "2")
                            {
                                parking.displayUnparkedBuses();
                            }
                            else if (data == "3")
                            {
                                parking.displayUnparkedBikes();
                            }
                            else if (data == "0")
                            {
                                system("CLS");
                                break;
                            }
                            else
                            {
                                system("CLS");
                                cout << "\n\t\tInvalid choice.\n";
                            }
                        }
                        else if (data == "0")
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                }

                else if (admin == "2")
                {

                    string delReco;
                    string Plate;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Delete Specific Car Record" << setw(9) << "|\n";
                        cout << "\t\t| [2]   |     Delete Specific Bus Record" << setw(9) << "|\n";
                        cout << "\t\t| [3]   |     Delete Specific Bike Record" << setw(8) << "|\n";
                        cout << "\t\t| [4]   |     Delete All UnPark Record" << setw(11) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, delReco);
                            if (parking.menuChoice(delReco))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (delReco == "1")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of car to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedCar(Plate);
                        }
                        else if (delReco == "2")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bike to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedBus(Plate);
                        }
                        else if (delReco == "3")
                        {
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate number of bike to delete record : ";
                                getline(cin, Plate);
                                parking.upperCase(Plate);
                                if (parking.plateNoValidation(Plate))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid input\n";
                                }
                            }
                            parking.deleteUnparkedBike(Plate);
                        }
                        else if (delReco == "4")
                        {
                            parking.deleteUnParkedRecords();
                        }
                        else if (delReco == "0")
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                }

                else if (admin == "3")
                {
                    while (true)
                    {
                        string block;
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     UnBlock Vehicle " << setw(19) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, block);
                            if (parking.menuChoice(block))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (block == "1")
                        {
                            system("CLS");
                            string plateno;
                            while (true)
                            {
                                cout << "\n\t\tEnter the plate no to unblock the vehicle: ";
                                getline(cin, plateno);
                                parking.upperCase(plateno);
                                if (parking.plateNoValidation(plateno))
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "\n\t\tInvalid plate no\n";
                                }
                            }
                            while (true)
                            {
                                cout << "\n\t\tEnter the token to unblock the vehicle: ";
                                getline(cin, tokenStr);
                                if (parking.tokenValid(tokenStr))
                                {
                                    token = stoi(tokenStr);
                                    break;
                                }
                                cout << "\n\t\tInvalid token.\n";
                            }
                            parking.unblockVehicle(plateno, token);
                        }
                        else if (block == "0")
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "\n\t\tInvalid choice.\n";
                        }
                    }
                }

                else if (admin == "4")
                {
                    system("CLS");
                    setRates(parking);
                }

                else if (admin == "5")
                {
                    string pay;
                    while (true)
                    {
                        cout << "\n\t\t ______________________________________________\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t| [1]   |     Display AllPayment Record " << setw(9) << "|\n";
                        cout << "\t\t| [2]   |     Withdraw Money " << setw(20) << "|\n";
                        cout << "\t\t| [3]   |     Delete Specific Payment Record" << setw(5) << "|\n";
                        cout << "\t\t| [4]   |     Delete AllPayment Record" << setw(11) << "|\n";
                        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                        cout << "\t\t|       |" << setw(40) << "|\n";
                        cout << "\t\t|_______|______________________________________|\n";
                        while (true)
                        {
                            cout << "\n\t\tEnter your choice: ";
                            getline(cin, pay);
                            if (parking.menuChoice(pay))
                            {
                                break;
                            }
                            cout << "\n\t\tInvalid input.\n";
                        }
                        if (pay == "1")
                        {
                            system("CLS");
                            parking.Payments();
                        }
                        else if (pay == "2")
                        {
                            system("CLS");
                            parking.withDraw(adminPassword);
                        }
                        else if (pay == "3")
                        {
                            string plateNo, type;
                            while (true)
                            {
                                system("cls");
                                cout << "\n\t\t ______________________________________________\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                                cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                                cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                                cout << "\t\t|       |" << setw(40) << "|\n";
                                cout << "\t\t|_______|______________________________________|\n";
                                while (true)
                                {
                                    cout << "\n\t\tEnter your choice: ";
                                    getline(cin, type);
                                    if (parking.menuChoice(type))
                                    {
                                        break;
                                    }
                                    cout << "\n\t\tInvalid Type.\n";
                                }
                                if (type == "1")
                                {
                                    cout << "\n\t\tEnter the plate number of vehicle to delete records along : ";
                                    getline(cin, plateNo);
                                    parking.upperCase(plateNo);
                                    if (parking.plateNoValidation(plateNo))
                                    {
                                        parking.deleteSpecificPaymentRecord(plateNo, "Car");
                                        break;
                                    }
                                    else
                                    {
                                        cout << "\n\t\tInvalid Plate No\n";
                                    }
                                }
                                else if (type == "2")
                                {
                                    cout << "\n\t\tEnter the plate number of vehicle to delete records along : ";
                                    getline(cin, plateNo);
                                    parking.upperCase(plateNo);
                                    if (parking.plateNoValidation(plateNo))
                                    {
                                        parking.deleteSpecificPaymentRecord(plateNo, "Bus");
                                        break;
                                    }
                                    else
                                    {
                                        cout << "\n\t\tInvalid Plate No\n";
                                    }
                                }
                                else if (type == "3")
                                {
                                    cout << "\n\t\tEnter the plate number of vehicle to delete records along : ";
                                    getline(cin, plateNo);
                                    parking.upperCase(plateNo);
                                    if (parking.plateNoValidation(plateNo))
                                    {
                                        parking.deleteSpecificPaymentRecord(plateNo, "Bike");
                                        break;
                                    }
                                    else
                                    {
                                        cout << "\n\t\tInvalid Plate No\n";
                                    }
                                }
                                else if (type == "0")
                                {
                                    system("CLS");
                                    break;
                                }
                                else
                                {
                                    cout << "\n\tInvalid choice!\n"
                                         << endl;
                                }
                            }
                        }
                        else if (pay == "4")
                        {
                            system("CLS");
                            parking.deletePayRecords();
                        }
                        else if (pay == "0")
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\tInvalid choice!\n";
                        }
                    }
                }

                else if (admin == "6")
                {
                    changeAdminPassword(adminPassword, parking);
                }
                else if (admin == "0")
                {
                    system("CLS");
                    break;
                }
                else
                {
                    system("CLS");
                    cout << "\n\t\tInvalid choice!\n";
                }
            }
            break;
        }
        else
        {
            adminAttempt++;
            if (adminAttempt >= 3)
            {
                system("CLS");
                cout << "\n\t\tYou attempted the password many times. Please wait.\n";
                break;
            }
            else
            {
                cout << "\n\t\tInvalid Passcode. Try Again!\n";
            }
        }
    }
}

void userInterface(ParkAndUnPark &parking)
{
    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     Park Vehicle" << setw(23) << "|\n";
        cout << "\t\t| [2]   |     Unpark Vehicle" << setw(21) << "|\n";
        cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        string user;
        while (true)
        {
            cout << "\n\t\tEnter your choice: ";
            getline(cin, user);
            if (parking.menuChoice(user))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }

        if (user == "1")
        {
            system("CLS");
            while (true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                string park;
                while (true)
                {
                    cout << "\n\t\tEnter your choice: ";
                    getline(cin, park);
                    if (parking.menuChoice(park))
                    {
                        break;
                    }
                    cout << "\n\t\tInvalid input.\n";
                }

                if (park == "1")
                {
                    system("CLS");
                    parking.parkCar();
                }
                else if (park == "2")
                {
                    system("CLS");
                    parking.parkBus();
                }
                else if (park == "3")
                {
                    system("CLS");
                    parking.parkBike();
                }
                else if (park == "0")
                {
                    system("CLS");
                    break; // Return to the previous menu
                }
                else
                {
                    system("CLS");
                    cout << "\n\t\tInvalid choice\n";
                }
            }
        }
        else if (user == "2")
        {
            system("CLS");
            while (true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Car" << setw(32) << "|\n";
                cout << "\t\t| [2]   |     Bus" << setw(32) << "|\n";
                cout << "\t\t| [3]   |     Bike" << setw(31) << "|\n";
                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                string unpark;
                while (true)
                {
                    cout << "\n\t\tEnter your choice: ";
                    getline(cin, unpark);
                    if (parking.menuChoice(unpark))
                    {
                        break;
                    }
                    cout << "\n\t\tInvalid input.\n";
                }

                if (unpark == "1")
                {
                    system("CLS");
                    parking.unparkCar();
                }
                else if (unpark == "2")
                {
                    system("CLS");
                    parking.unparkBus();
                }
                else if (unpark == "3")
                {
                    system("CLS");
                    parking.unparkBike();
                }
                else if (unpark == "0")
                {
                    system("CLS");
                    break; // Return to the previous menu
                }
                else
                {
                    system("CLS");
                    cout << "\n\t\tInvalid choice\n";
                }
            }
        }
        else if (user == "0")
        {
            system("CLS");
            break;
        }
        else
        {
            system("CLS");
            cout << "\n\t\tInvalid choice!\n";
        }
    }
}

int main()

{
    string adminPassword = "pasha123";
    string choice;
    ParkAndUnPark ParkingSystem;
    system("CLS");

    cout << "\n\n\t\tWelcome to the Parking  Management System\n\n";
    while (true)
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     User" << setw(31) << "|\n";
        cout << "\t\t| [2]   |     Admin" << setw(30) << "|\n";
        cout << "\t\t| [0]   |     Exit" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        while (true)
        {
            cout << "\n\t\tEnter your choice: ";
            getline(cin, choice);
            if (ParkingSystem.menuChoice(choice))
            {
                break;
            }
            cout << "\n\t\tInvalid input.\n";
        }
        if (choice == "1")
        {
            system("CLS");
            userInterface(ParkingSystem);
        }
        else if (choice == "2")
        {
            system("CLS");
            adminInterface(ParkingSystem, adminPassword);
        }
        else if (choice == "0")
        {
            cout << "\n\n\t\tThanks for using......\n\n\n";
            break;
        }
        else
        {
            system("CLS");
            cout << "\n\t\tInvalid choice!\n";
        }
    }
    return 0;
}
