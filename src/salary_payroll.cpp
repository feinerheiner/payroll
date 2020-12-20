#include "salary_payroll.h"
#include <iomanip>
#include <iostream>

using namespace std;

SalaryPayroll::SalaryPayroll(){}
SalaryPayroll::SalaryPayroll(double pay_rate, std::string name){
    PayrollData::set_pay_rate(pay_rate);
    PayrollData::set_name(name);
}


double SalaryPayroll::ComputeGross() const{
    return pay_rate;
}
void SalaryPayroll::WriteData(std::ostream &out) const{
    out << "S " << std::fixed << std::setprecision(2) << pay_rate << endl;
    out << get_last_name() << ", " << get_first_name() << endl;
}
void SalaryPayroll::WriteReport(std::ostream &out) const{
    out << std::fixed << std::setprecision(2) << get_first_name() << " " << get_last_name() << '\n'
    << "   Pay Rate: $" << pay_rate << "\n"
    << "   Gross Pay: $" << ComputeGross() << endl;
}
