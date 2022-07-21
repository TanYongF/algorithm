void NextDate(int &year, int &month, int &day)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
        if(day == 31){
            month++;
            day = 1;
        }else{
            day++;
        }
    }else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day == 30){
            day = 1;
            month++;
        }else{
            day++;
        }
    }
    else if(month == 12){
        if(day == 31){
            month = 1;
            year++;
            day = 1;
        }else{
            day++;
        }
    }
    else{
        if(isLeapYear(year)){
            if(day == 29){
                month++;
                day = 1;
            }else{
                day++;
            }
        }else{
            if(day == 28){
                month++;
                day = 1;
            }else day++;
        }
    }
}