#ifndef HOURLY_PAYROLL_H
#define HOURLY_PAYROLL_H
#include <string>
#include "payroll_data.h"

using namespace std;

class HourlyPayroll: public PayrollData{
private:
    double hours_;
public:
    static const double kMinHours;
    static const double kMaxHours;
    static const double kRegularHours;
    static const double kOvertimeRate;
    static const double kMinWage;

    HourlyPayroll();
    HourlyPayroll(double hours_worked, double pay_rate, std::string name);
    virtual~HourlyPayroll(){};

    double get_hours() const;
    void set_pay_rate(double pay_rate);
    void set_hours(double hours_worked);

    double ComputeGross() const override;
    void WriteData(std::ostream& out) const override;
    void WriteReport(std::ostream& out) const override;

};


#endif