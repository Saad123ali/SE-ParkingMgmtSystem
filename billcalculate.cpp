
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