#include "hourly_payroll.h"
#include <fstream>
#include <iostream>
#include <iomanip>


static const double kMinHours = 0;
static const double kMaxHours = 168;
static const double kRegularHours = 40;
static const double kOvertimeRate = 1.5;
static const double kMinimumWage = 7.25;

//How do I reference the variables in payroll_data.cpp?
HourlyPayroll::HourlyPayroll() : pay_rate_(0), first_name("it is"), last_name("unknown"){
    pay_rate_ = kMinimumWage;
    hours_ = kMinHours;
}
HourlyPayroll::HourlyPayroll(double hours_worked, double pay_rate, std::string name) {
    set_pay_rate(pay_rate);
    set_hours(hours_worked);
    set_name(name);
}


double HourlyPayroll::get_hours() const {
    return hours_;
}
void HourlyPayroll::set_pay_rate(double pay_rate){
    if(pay_rate < kMinimumWage){
        set_pay_rate(kMinimumWage);
    }else{set_pay_rate(pay_rate);}
}
void HourlyPayroll::set_hours(double hours_worked){
    if(hours_worked < kMinHours){
        hours_ = kMinHours;
    }else if (kMaxHours < hours_worked){
        hours_ = kMaxHours;
    }else {hours_ = hours_worked;}
}
double HourlyPayroll::ComputeGross() const{
    double gross_pay;
    double over_pay;
    double payRate = get_pay_rate();//should or could this be a pointer?
    int over_hours;
    if (hours_<= kRegularHours){
        gross_pay = hours_ * payRate;
    }
    if (kRegularHours < hours_){
        over_hours = hours_-kRegularHours;
        over_pay = over_hours*payRate*kOvertimeRate;
        gross_pay = kRegularHours*payRate+over_pay;
    }
    return gross_pay;
}
void HourlyPayroll::WriteData(std::ostream &out) const{
    out << "H " << get_hours() << " " << get_pay_rate() << " " << ComputeGross() <<
    "\n" << get_last_name() << ", " << get_first_name() << endl;
}
void HourlyPayroll::WriteReport(std::ostream &out) const{
    out << get_first_name() << " " << get_last_name() << "\n"
    << std::setprecision(2)
    << "   Hours Worked: " << get_hours() << "\n"
    << "   Pay Rate: $" << get_pay_rate() << "\n"
    << "   Gross Pay: $" << ComputeGross() << endl;
}