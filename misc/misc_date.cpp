const string WEEK[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int DAYS_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DAYS = 365;
const int MAX_YEAR = 100030;

class Date {
public:

    int prefix_days[MAX_YEAR];

    Date() {
        fill(prefix_days, prefix_days + MAX_YEAR, 0);
        prefix_days[0] = 0;
        for(int y = 1; y < MAX_YEAR; ++y) {
            if(is_leap_year(y))  {
                prefix_days[y] = prefix_days[y-1] + DAYS + 1;
            } else {
                prefix_days[y] = prefix_days[y-1] + DAYS;
            }
        }
    }

    string dayOfTheWeek(int day, int month, int year) {
        int cnt_days = day;
        cnt_days += prefix_days[year];
        for(int m = 0; m < month-1; ++m) {
            cnt_days += DAYS_MONTH[m];
        }
        if(is_leap_year(year) && month > 2)
            cnt_days++;
        int start = 5; // Year 0 starts on a Friday
        return WEEK[(cnt_days+start)%7];
    }

    bool is_leap_year(int year) {
        return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    }
};