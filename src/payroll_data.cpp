
#include "payroll_data.h"
#include <string>
#include <iomanip>



PayrollData::PayrollData() : pay_rate(0), first_name("it is"), last_name("unknown") { }
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
 * @param _pay_rate a double that specifies the dolors per hour that is earned.
 */
void PayrollData::set_pay_rate(double _pay_rate) {
    if (_pay_rate < 0){
        pay_rate = 0;
    }else{
        pay_rate = _pay_rate;
    }
}
double PayrollData::get_pay_rate() const{
    return pay_rate;
}
std::string PayrollData::get_first_name() const{
    return first_name;
}
std::string PayrollData::get_last_name() const{
    return last_name;
}