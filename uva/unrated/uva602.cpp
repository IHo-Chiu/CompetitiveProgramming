# include <stdio.h>

char monthToStr[13][10] =
{   "",
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};
char weekDayToStr[7][10] =
{   
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayOne = 6; // 1/1/1 is Sat.

bool isLeapYear(int y)
{
    if (y%4) return false;
    if (y > 1752 && y%100 == 0 && y%400 != 0) return false;
    return true;
}

bool isVaild(int m, int d, int y)
{
    if (isLeapYear(y) && m == 2 && d == 29)
        return true;
    if (dayOfMonth[m] < d) return false;
    if (y == 1752 && m == 9 && d >= 3 && d <= 13)
        return false;
    return true;
}

int daysBetweenDayOne(int m, int d, int y)
{
    int ans = 0;
    ans += d-1;
    for (int i = 1; i < m; i++)
        ans += dayOfMonth[i];
    ans += 365*(y-1);
    ans += y/4;
    if (isLeapYear(y) && m <= 2)
        ans -= 1;
    if (y > 1752 || 
       (y == 1752 && m > 9) ||
       (y == 1752 && m == 9 && d >= 3))
        ans -= y/100 - y/400 - 2;

    return ans;
}

int main()
{
    int m, d, y, weekDay;
    while (scanf("%d %d %d", &m, &d, &y) != EOF)
    {
        if (m == 0 && d == 0 && y == 0)
            break;

        if (isVaild(m, d, y))
        {
            weekDay = (daysBetweenDayOne(m, d, y) + dayOne) %7;
            printf("%s %d, %d is a %s\n", monthToStr[m], d, y, weekDayToStr[weekDay]);
        }
        else
        {
            printf("%d/%d/%d is an invalid date.\n", m, d, y);
        }
    }

    return 0;
}