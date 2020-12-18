#include "hourly_payroll.h"


static const double kMinHours = 0;
static const double kMaxHours = 168;
static const double kRegularHours = 40;
static const double kOvertimeRate = 1.5;
static const double kMinimumWage = 7.25;


double HourlyPayroll::get_hours() const {
    return hours_;
}
void HourlyPayroll::set_pay_rate(double pay_rate){
    pay
}
void set_hours(double hours_worked);
double ComputeGross() const;
void WriteData(std::ostream &out) const;
void WriteReport(std::ostream &out) const;