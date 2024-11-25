#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <sstream>

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
        string cellNumber; // New field for cell number
    };

    unordered_map<string, PaymentInfo> payments;
    double totalAmount;
    double withDrawAmount;

    string timeTostring(time_t time) const
    {
        char buffer[80];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", timeinfo);
        return string(buffer);
    }

    

public:
    PaymentRecord() : totalAmount(0.0) {}

    void recordPayment(const string &plateNo, const string &vehicleType, int token, double amount, time_t parkTime, time_t unparkTime, bool isPaid, const string &cellNumber)
    {
        string key = vehicleType + "-" + plateNo;
        payments[key] = {token, amount, isPaid, parkTime, unparkTime, vehicleType, cellNumber};
        if (isPaid)
        {
            totalAmount += amount;
        }
    }

    void updatePaymentRecord(const string &plateNo, const string &vehicleType, int token, double amount, time_t unparkTime)
    {
        string key = vehicleType + "-" + plateNo;
        if (payments.find(key) != payments.end() && payments[key].token == token)
        {
            payments[key].paid = true;
            payments[key].unparkTime = unparkTime;
            totalAmount += amount;
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
                 << setw(12) << entry.first.substr(entry.first.find('-') + 1) // Extract plate number from key
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
        cout << "\n\tTotal Amount: Rs : " << totalAmount << "\n";
    }

    void deleteAllRecords()
    {
        if (payments.empty())
        {
            cout << "No payments recorded yet." << endl;
            return;
        }

        payments.clear();
        totalAmount = 0.0;
        cout << "All payment records have been deleted." << endl;
    }

    void deleteSpecificRecord(const string &plateNo, const string &vehicleType)
    {
        string key = vehicleType + "-" + plateNo;
        auto it = payments.find(key);
        if (it != payments.end())
        {
            totalAmount -= it->second.amount;
            payments.erase(it);
            cout << "Payment record for plate number " << plateNo << " has been deleted." << endl;
        }
        else
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
                            return;       // Exit the function after successful withdrawal
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
