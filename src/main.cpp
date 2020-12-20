#include <iostream>
#include <string>
#include "hourly_payroll.h"
#include "salary_payroll.h"
#include "commission_payroll.h"
#include <fstream>

// author Richard Heiner

using namespace std;

int main() {
  // create HourlyPayroll objects and use the associated methods
  cout << "The HourlyPayroll class demonstration.\n";

  // Create HourlyPayroll objects using the default and non-default
  // constructors.
  HourlyPayroll ted;
  HourlyPayroll tom(40,10.5,"Tom Cruz");

  // Use the HourlyPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  ted.set_hours(40);
  ted.set_pay_rate(10.5);
  ted.set_name("Ted Mosby");
  cout << ted.get_hours() << " " << ted.get_pay_rate() << " " << ted.get_first_name() << " " << ted.get_last_name()
  << endl;
  cout << tom.get_hours() << " " << tom.get_pay_rate() << " " << tom.get_first_name() << " " << tom.get_last_name()
  << endl;

  // Use the HourlyPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  ted.WriteData(cout);
  ted.ComputeGross();
  ted.WriteReport(cout);
  tom.WriteData(cout);
  tom.WriteReport(cout);
  ted.ComputeGross();

  // Use the HourlyPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.


  // create SalaryPayroll objects and use the associated methods
  cout << "The SalaryPayroll class demonstration.\n";

  // Create SalaryPayroll objects using the default and non-default
  // constructors.
  SalaryPayroll rob;
  SalaryPayroll bob(2000.10, "Bob Haris");

  // Use the SalaryPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // Notice that the SalaryPayroll does not define any new getters and
  // setters but still use the ones that are defined in the PayrollData class.
  rob.set_name("Turd, Rob");
  rob.set_pay_rate(1023.66);
  rob.WriteReport(cout);
  bob.WriteReport(cout);

  // Use the SalaryPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  cout << rob.ComputeGross() << " " << bob.ComputeGross() << endl;

  // Use the SalaryPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.
  rob.WriteReport(cout);
  rob.WriteData(cout);
  bob.WriteReport(cout);
  bob.WriteData(cout);


  // create CommissionPayroll objects and use the associated methods
  cout << "The CommissionPayroll class demonstration.\n";

  // Create CommissionPayroll objects using the default and non-default
  // constructors.
  CommissionPayroll raider;
  CommissionPayroll roxi(20.00,20,1000.0,"Roxi Shiba");

  // Use the CommissionPayroll objects to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  raider.set_pay_rate(20.00);
  raider.set_how_many(20);
  raider.set_base_pay(1000.0);
  raider.set_name("Raider Shiba");

  cout << "This should be Raider: " << raider.get_pay_rate() << " " << raider.get_how_many()
       << " " << raider.get_base_pay() << " " << raider.get_first_name()
       << " " << raider.get_last_name() << endl;

    cout << "This should be Raider: " << roxi.get_pay_rate() << " " << roxi.get_how_many()
         << " " << roxi.get_base_pay() << " " << roxi.get_first_name()
         << " " << roxi.get_last_name() << endl;

  // Use the CommissionPayroll objects to call the ComputeCommission method.
  //  Print out the results to see that the method is doing what is expected.
  cout << raider.get_first_name() << "'s  commission is $" << raider.ComputeCommission() << endl;
  cout << roxi.get_first_name() << "'s  commission is $" << roxi.ComputeCommission() << endl;

  // Use the CommissionPayroll objects to call the ComputeGross method. Print
  // out the results to see that the method is doing what is expected.
  cout << raider.get_first_name() << "'s  gross pay is $" << raider.ComputeGross() << endl;
  cout << roxi.get_first_name() << "'s  gross pay is $" << roxi.ComputeGross() << endl;

  // Use the CommissionPayroll objects to call the WriteData and WriteReport
  // methods to see they are working as expected.
  cout << endl;
  raider.WriteData(cout);
  roxi.WriteData(cout);
  cout << endl;
  raider.WriteReport(cout);
  roxi.WriteReport(cout);


    std::ofstream out("test.out");

    CommissionPayroll commission1(63, 28, 975.6, "Johnson, Kim");
    CommissionPayroll commission2(14.92, 61, 455.80, "John Jones");
    commission1.WriteReport(out);
    commission2.WriteReport(out);
    out.close();

//    std::ifstream in("test.out");
//    if (in.fail()) {
//        REQUIRE("File Opened" == "Unable to open file");
//    }
//    std::string line;
//
//    getline(in, line);
//    REQUIRE(line == "Kim Johnson");
//    getline(in, line);
//    REQUIRE(line == "   Pay Rate: $63.00");
//    getline(in, line);
//    REQUIRE(line == "   How Many: 28");
//    getline(in, line);
//    REQUIRE(line == "   Commission: $1764.00");
//    getline(in, line);
//    REQUIRE(line == "   Base Pay: $975.60");
//    getline(in, line);
//    REQUIRE(line == "   Gross Pay: $2739.60");
//    getline(in, line);
//    REQUIRE(line == "John Jones");
//    getline(in, line);
//    REQUIRE(line == "   Pay Rate: $14.92");
//    getline(in, line);
//    REQUIRE(line == "   How Many: 61");
//    getline(in, line);
//    REQUIRE(line == "   Commission: $910.12");
//    getline(in, line);
//    REQUIRE(line == "   Base Pay: $455.80");
//    getline(in, line);
//    REQUIRE(line == "   Gross Pay: $1365.92");
//    getline(in, line);
//    REQUIRE(line == "");
//    in.close();

    // run the ProcessPayroll function
  cout << "The ProcessPayroll function.\n";

  // In main, call the  ProcessPayroll function.
  // See that it is producing the expected report.



  return 0;
}