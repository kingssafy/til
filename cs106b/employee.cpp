




Employee::Employee(string name, int years) {
    myname = name;
    myyears = years;
}

int Employee::hours() {
    return 40;
}

string Employee:name() {
    return myname;
}

double Employee::salary() {
    return 40000.0 + (500 * myyears);
}

int Employee::vacationDays() {
    return 10;
}

string Employee::vacationForm() {
    return "yellow"
}

int Employee::years() {
    return myyears;
}
