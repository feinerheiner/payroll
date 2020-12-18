
#include "payroll_data.h"
#include <string>
#include <iomanip>


// /**
// * @brief Sets the values to these static constant variables.
// * @remark These values can not be changed.
// */
//const double PayrollData::kMinimumWage = 7.25;
//const double PayrollData::kRegularHours = 40;
//const double PayrollData::kOvertimeRate = 1.5;

PayrollData::PayrollData() : pay_rate_(0), first_name("it is"), last_name("unknown") { }
PayrollData::PayrollData(double pay_rate, std::string name){
    set_name(name);
    set_pay_rate(pay_rate);
}

void PayrollData::set_name(std::string name) {
    int position = name.find(',');
    if (position != std::string::npos) {
        last_name = name.substr(0, position);
        first_name = name.substr(position + 2);
    } else {
        first_name = name.substr(0, name.find_last_of(" "));
        last_name = name.substr(name.find_last_of(" ") + 1);
    }
}

/**
 * @brief Sets the pay rate for the individual
 * @remark If pay_rate is less than the minimum wage than the pay_rate will be set to minimum wage
 * @param pay_rate a double that specifies the dolors per hour that is earned.
 */
void PayrollData::set_pay_rate(double pay_rate) {
    if (pay_rate < 0){
        pay_rate_ = 0;
    }else{
        pay_rate_ = pay_rate;
    }
}