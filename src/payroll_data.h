#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H
#include <string>

class PayrollData{
private:
    int pay_rate_;
    std::string first_name;
    std::string last_name;

public:
    PayrollData();
    PayrollData(double pay_rate, std::string name);
    ~PayrollData(){};


    double get_pay_rate() const;
    std::string get_first_name() const;
    std::string get_last_name() const;

    void set_pay_rate(double pay_rate);
    void set_name(std::string name);

    static const double kMinimumWage;
    static const double kRegularHours;
    static const double kOvertimeRate;

};

#endif