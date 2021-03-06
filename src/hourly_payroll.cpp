#include "hourly_payroll.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "payroll_data.h"

using namespace std;


const double HourlyPayroll::kMinHours = 0;
const double HourlyPayroll::kMaxHours = 168;
const double HourlyPayroll::kRegularHours = 40;
const double HourlyPayroll::kOvertimeRate = 1.5;
const double HourlyPayroll::kMinWage = 7.25;

//How do I reference the variables in payroll_data.cpp?
HourlyPayroll::HourlyPayroll() : PayrollData() {
    set_pay_rate(kMinWage);
    set_hours(kMinHours);

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
    if(pay_rate < kMinWage){
        PayrollData::set_pay_rate(kMinWage);
    }else{PayrollData::set_pay_rate(pay_rate);}
}
void HourlyPayroll::set_hours(double hours_worked){
    if(hours_worked < kMinHours){
        hours_ = kMinHours;
    }else if (kMaxHours < hours_worked){
        hours_ = kMaxHours;
    }else {hours_ = hours_worked;}
}
double HourlyPayroll::ComputeGross() const{
    double gross_pay = 0.0;
    double payRate = get_pay_rate();//should or could this be a pointer?
    double over_hours = 0;
    if (hours_<= kRegularHours){
        gross_pay = hours_ * payRate;
    }else {
        over_hours = hours_-kRegularHours;
        gross_pay = (kRegularHours*payRate)+((over_hours * payRate) * kOvertimeRate);

    }
//    cout << gross_pay << endl;
    return gross_pay;
}
void HourlyPayroll::WriteData(std::ostream &out) const{
    out << "H " << std::fixed << std::setprecision(2)
    << get_hours() << " " << get_pay_rate() << " " << ComputeGross()
    << "\n" << get_last_name() << ", " << get_first_name() << endl;
}
void HourlyPayroll::WriteReport(std::ostream &out) const{
    double pay = ComputeGross();
    out << get_first_name() << " " << get_last_name() << "\n"
    << std::fixed << std::setprecision(2)
    << "   Hours Worked: " << get_hours() << "\n"
    << "   Pay Rate: $" << get_pay_rate() << "\n"
    << "   Gross Pay: $" << ComputeGross() << endl;
}