#include "commission_payroll.h"
#include "payroll_data.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

CommissionPayroll::CommissionPayroll(): PayrollData(), how_many(0), base_pay(0){}
CommissionPayroll::CommissionPayroll(double pay_rate, int how_many_, double base_pay_, std::string name): PayrollData(){
    PayrollData::set_pay_rate(pay_rate);
    set_how_many(how_many_);
    set_base_pay(base_pay_);
    PayrollData::set_name(name);

}

int CommissionPayroll::get_how_many() const{return how_many;}
double CommissionPayroll::get_base_pay() const{return base_pay;}
void CommissionPayroll::set_how_many(int how_many_){
    if(how_many_ < 0){
        how_many = 0;
    }else{how_many = how_many_;}
}
void CommissionPayroll::set_base_pay(double base_pay_){
    if(base_pay_ < 0){
        base_pay = 0;
    }else{base_pay = base_pay_;}
}
double CommissionPayroll::ComputeCommission() const{
    double makeItRain = PayrollData::pay_rate*how_many;
    return makeItRain;
}
double CommissionPayroll::ComputeGross() const{
    double gross;
    double makeItRain = ComputeCommission();
    gross = makeItRain + base_pay;
    return gross;
}
void CommissionPayroll::WriteData(std::ostream &out) const{
    out << fixed << setprecision(2)
    << "C " << PayrollData::get_pay_rate() << " " << how_many << " " << base_pay << " " << ComputeGross()
    << "\n" << PayrollData::get_last_name() << ", " << PayrollData::get_first_name() << endl;
}
void CommissionPayroll::WriteReport(std::ostream &out) const{
    out << fixed << setprecision(2)
    << PayrollData::get_first_name() << " " << PayrollData::get_last_name()
    << "\n   Pay Rate: $" << PayrollData::get_pay_rate()
    << setprecision(0) << "\n   How Many: " << how_many
    << setprecision(2) << "\n   Commission: $" << ComputeCommission()
    << "\n   Base Pay: $" << base_pay
    << "\n   Gross Pay: $" << ComputeGross() << endl;
}