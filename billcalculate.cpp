
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
