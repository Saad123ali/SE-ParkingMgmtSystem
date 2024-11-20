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
    bool paymentSuccess;
    double fine;
    unordered_map<int, bool> generatedTokens; // Map to store unique tokens

protected:
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
        do
        {
            token = rand() % 90000 + 100000; // Generate a token in the range 100000 to 999999
        } while (generatedTokens.find(token) != generatedTokens.end()); // Check for duplicates
        generatedTokens[token] = true; // Store the newly generated token
    }
    int getToken() const
    {
        return token;
    }

    double getAmount()
    {
        return totalAmount;
    }

    double calculateOverstayTime(time_t entryTime, int allocatedHours, int allocatedDays)
    {
        // Get the current time
        time_t currentTime;
        time(&currentTime);

        // Calculate total parked time in seconds
        double secondsParked = difftime(currentTime, entryTime);

        // Convert parked time to hours and days
        double hoursParked = ceil(secondsParked / 3600.0);
        double daysParked = ceil(secondsParked / (24 * 3600.0));

        // Calculate overstay time in hours and days
        double overstayHours = hoursParked - allocatedHours;
        double overstayDays = daysParked - allocatedDays;

        // Ensure overstay time is not negative
        if (overstayHours < 0)
        {
            overstayHours = 0;
        }
        if (overstayDays < 0)
        {
            overstayDays = 0;
        }

        // Return the maximum overstay time
        return max(overstayHours, overstayDays);
    }

    void calculateBill(string vehicleType, const RateConfig &rates)
    {
        time_t currentTime;
        time(&currentTime);
        double overstayHours = 0;
        double overstayDays = 0;

        if (parkingType == "1")
        {
            // Calculate overstay for hourly parking
            overstayHours = calculateOverstayTime(getParkTime(), hours, 0);
        }
        else if (parkingType == "2")
        {
            // Calculate overstay for daily parking
            overstayDays = calculateOverstayTime(getParkTime(), 0, days);
        }

        if (vehicleType == "Car")
        {
            if (parkingType == "2")
            {
                if (overstayDays > 0)
                {
                    fine = overstayDays * rates.carDailyFineRate;
                    totalAmount = (days * rates.carDailyRate) + fine;
                }
                else
                {
                    totalAmount = days * rates.carDailyRate;
                }
            }
            else if (parkingType == "1")
            {
                if (overstayHours > 0)
                {
                    fine = overstayHours * rates.carHourlyFineRate;
                    totalAmount = (hours * rates.carHourlyRate) + fine;
                }
                else
                {
                    totalAmount = hours * rates.carHourlyRate;
                }
            }
        }
        else if (vehicleType == "Bus")
        {
            if (parkingType == "2")
            {
                if (overstayDays > 0)
                {
                    fine = overstayDays * rates.busDailyFineRate;
                    totalAmount = (days * rates.busDailyRate) + fine;
                }
                else
                {
                    totalAmount = days * rates.busDailyRate;
                }
            }
            else if (parkingType == "1")
            {
                if (overstayHours > 0)
                {
                    fine = overstayHours * rates.busHourlyFineRate;
                    totalAmount = (hours * rates.busHourlyRate) + fine;
                }
                else
                {
                    totalAmount = hours * rates.busHourlyRate;
                }
            }
        }
        else if (vehicleType == "Bike")
        {
            if (parkingType == "2")
            {
                if (overstayDays > 0)
                {
                    fine = overstayDays * rates.bikeDailyFineRate;
                    totalAmount = (days * rates.bikeDailyRate) + fine;
                }
                else
                {
                    totalAmount = days * rates.bikeDailyRate;
                }
            }
            else if (parkingType == "1")
            {
                if (overstayHours > 0)
                {
                    fine = overstayHours * rates.bikeHourlyFineRate;
                    totalAmount = (hours * rates.bikeHourlyRate) + fine;
                }
                else
                {
                    totalAmount = hours * rates.bikeHourlyRate;
                }
            }
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
                cout << "Days Parked       : " << days << " Days" << "\n";
            else if (parkingType == "1")
                cout << "Hours Parked      : " << hours << " Hours" << "\n";
            cout << "Token Number      : " << token << "\n";
            cout << "Amount            : Rs." << totalAmount << "\n"; // Show amount when parked
        }
        else
        {
            cout << "Exit Time         : " << GetCurrentTime() << "\n";
            cout << "Phone Number      : " << cellNo << "\n";
            cout << "Plate Number      : " << plateNo << "\n";
            if (parkingType == "2")
            {
                cout << "Days Parked       : " << days << " Days" << "\n";
                double overstayDays = ceil(difftime(time(0), getParkTime()) / (24 * 3600.0)) - days;
                if (overstayDays > 0)
                {
                    cout << "Overstay Days     : " << overstayDays << " Days" << "\n";
                    cout << "Fine Amount       : Rs." << fine << "\n";
                }
            }
            else if (parkingType == "1")
            {
                cout << "Hours Parked      : " << hours << " Hours" << "\n";
                double overstayHours = ceil(difftime(time(0), getParkTime()) / 3600.0) - hours;
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

