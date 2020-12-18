#include "hourly_payroll.h"


static const double kMinHours = 0;
static const double kMaxHours = 168;
static const double kRegularHours = 40;
static const double kOvertimeRate = 1.5;
static const double kMinimumWage = 7.25;

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
        pay_rate_ = kMinimumWage;
    }else{pay_rate_ = pay_rate;}
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
    int over_hours;
    if (hours_<= kRegularHours){
        gross_pay = hours_ * pay_rate_;
    }else (kRegularHours < hours_){
        over_hours = hours_-kRegularHours;
        over_pay = over_hours*pay_rate_*kOvertimeRate;
        gross_pay = kRegularHours*pay_rate_+over_pay;
    }
    return gross_pay;
}
void WriteData(std::ostream &out) const;
void WriteReport(std::ostream &out) const;