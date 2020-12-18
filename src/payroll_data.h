#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H
#include <string>

class PayrollData{
protected:
    double pay_rate_;
    std::string first_name;
    std::string last_name;

public:
    PayrollData();
    PayrollData(double pay_rate, std::string name);
    virtual ~PayrollData(){};


    double get_pay_rate() const;
    std::string get_first_name() const;
    std::string get_last_name() const;

    void set_pay_rate(double pay_rate);
    void set_name(std::string name);
    virtual double ComputeGross() = 0;
    virtual void WriteData(std::string output_file) = 0;
    virtual void WriteReport(std::string output_file) = 0;

//    static const double kMinimumWage;
//    static const double kRegularHours;
//    static const double kOvertimeRate;


};

#endif