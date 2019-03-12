

class Employee {
public:
    Employee(string name,
            int years);
    int hours();
    string name();
    double salary();
    int vacationDays();
    string vacationForm();
    int years();

private:
    string myname;
    int myyears;
};
