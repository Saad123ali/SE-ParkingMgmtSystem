#include <string>
#include <unordered_map>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <iomanip>

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

    void setUnparkTime(time_t unparkTime)

    template <typename T>
    void parkVehicle(unordered_map<string, T> &parkedVehicles)
    {
        while (true)

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

        pass[i] = '\0';
        password = pass;
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
