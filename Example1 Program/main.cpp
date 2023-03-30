#include <iostream>
#include <string>

using namespace std;

class Sales_Info_Learn {
    
    friend Sales_Info_Learn add(const Sales_Info_Learn &entry_add1, const Sales_Info_Learn &entry_add2);
    friend std::ostream &print(std::ostream &entry_print1, const Sales_Info_Learn &entry_print2);
    friend std::istream &read(std::istream &entry_read1, Sales_Info_Learn &entry_read2);

    public:
        // Constructors
        Sales_Info_Learn() = default;
        Sales_Info_Learn(const string &entry_constructor1) : number(entry_constructor1) {}
        Sales_Info_Learn(const string &entry_constructor1, unsigned int &entry_constructor2, double &entry_constructor3) : number(entry_constructor1),
            units_sold(entry_constructor2), revenue(entry_constructor2 * entry_constructor3) {}
        Sales_Info_Learn(std::istream &constructor1): Sales_Info_Learn() {
            read(constructor1, *this);
        }

        // Methods
        string display_number() const {
            return number;
        }
        Sales_Info_Learn &combine(const Sales_Info_Learn &entry_combine) {
            units_sold += entry_combine.units_sold;
            revenue += entry_combine.revenue;
            return *this;
        }

        // Setters and getters
        void set_number(string entry_set) {
            number = entry_set;
        }

        string get_number() {
            return number;
        }

    private:
        inline double avg_price() const {
            return units_sold ? (revenue / units_sold) : 0;
        }

        // Member variables
        string number;
        unsigned int units_sold = 0;
        double revenue = 0;
};

Sales_Info_Learn add(const Sales_Info_Learn &entry_add1, const Sales_Info_Learn &entry_add2) {
    Sales_Info_Learn sum = entry_add1;
    sum.combine(entry_add2);
    return sum;
}

std::ostream &print(std::ostream &entry_print1, const Sales_Info_Learn &entry_print2) {
    entry_print1 << entry_print2.display_number() << " " << entry_print2.units_sold << " " 
    << entry_print2.revenue << " " << entry_print2.avg_price();
    return entry_print1;
}

std::istream &read(std::istream &entry_read1, Sales_Info_Learn &entry_read2) {
    double price = 0;
    entry_read1 >> entry_read2.number >> entry_read2.units_sold >> price;
    entry_read2.revenue = price * entry_read2.units_sold;
    return entry_read1;
}

int main() {
    Sales_Info_Learn item1(cin);
    print(cout, item1);
}