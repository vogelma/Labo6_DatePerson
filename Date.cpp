//
// Created by Maëlle on 04.01.2021.
//

#include "Date.h"
Date::Date(unsigned d, unsigned m, unsigned y){
day = d;
month = m;
year = y;
}
Date::Date(std::string){
    //to do
}
unsigned Date::getDay(){
    return day;
}
unsigned Date::getMonthNo(){
    return month;
}

unsigned Date::getYear(){
    return year;
}

//enum avec mois
unsigned Date::getMonthEnum(){

}
std::string Date::getMonthString(){

}
