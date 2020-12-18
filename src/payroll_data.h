#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H
#include <string>

class PayrollData{
protected:
    double pay_rate;
    std::string first_name;
    std::string last_name;

public:
    PayrollData();
    PayrollData(double pay_rate, std::string name);
    virtual ~PayrollData(){};


    double get_pay_rate() const;
    std::string get_first_name() const;
    std::string get_last_name() const;

    void set_pay_rate(double);
    void set_name(std::string name);

    virtual double ComputeGross() const = 0;
    virtual void WriteData(std::ostream& output_file) const = 0;
    virtual void WriteReport(std::ostream& output_file) const = 0;

//    static const double kMinWage;
//    static const double kRegularHours;
//    static const double kOvertimeRate;


};

#endif