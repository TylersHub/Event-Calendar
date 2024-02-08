#ifndef Calendar_header
#define Calendar_header
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
#include <ctime>

//Event Class for Event Objects
class Event{
private:
  int eventNo[5];
  std::string eventNoStr[5];
  int month;
  int day;
  int year;
  int hour;
  int minute;
  std::string details;

public:
  Event()
  {
    month=01;
    day=01;
    year=1753;
    hour=00;
    minute=00;
  }
  void setMonth(int mon)
  {
    month=mon;
  }
  void setDay(int dy)
  {
    day=dy;
  }
  void setYear(int yr)
  {
    year=yr;
  }
  void setHour(int hr)
  {
    hour=hr;
  }
  void setMinute(int min)
  {
    minute=min;
  }

  //Gets Object Month Name
  std::string monthName()
  {
    switch(month)
    {
      case 1:
        return "January";
      break;
      case 2:
        return "Febuary";
      break;
      case 3:
        return "March";
        break;
      case 4:
        return "April";
      break;
      case 5:
        return "May";
      break;
      case 6:
        return "June";
      break;
      case 7:
        return "July";
      break;
      case 8:
        return "August";
      break;
      case 9:
        return "September";
      break;
      case 10:
        return "October";
      break;
      case 11:
        return "November";
      break;
      case 12:
        return "December";
      break;
    }
  }

  //Gets Object Day Name
  std::string DayName()
  {
    switch(month)
    {
      case 1:
        return "January";
      break;
      case 2:
        return "Febuary";
      break;
      case 3:
        return "March";
        break;
      case 4:
        return "April";
      break;
      case 5:
        return "May";
      break;
      case 6:
        return "June";
      break;
      case 7:
        return "July";
      break;
      case 8:
        return "August";
      break;
      case 9:
        return "September";
      break;
      case 10:
        return "October";
      break;
      case 11:
        return "November";
      break;
      case 12:
        return "December";
      break;
    }
  }

  void setDetails(std::string det)
  {
    details=det;
  }
  void setEventNo(int YYYY, int MM, int DD, int hh, int mm)
  {
    YYYY=year;
    MM=month;
    DD=day;
    hh=hour;
    mm=minute;

    std::string str_year = std::to_string(YYYY);
    std::string str_mon = std::to_string(MM);
    std::string str_day = std::to_string(DD);
    std::string str_hour = std::to_string(hh);
    std::string str_min = std::to_string(mm);
    
    eventNoStr[0]=str_year;
    eventNoStr[1]=str_mon;
    eventNoStr[2]=str_day;
    eventNoStr[3]=str_hour;
    eventNoStr[4]=str_min;

      if(eventNoStr[1]=="1")
      {eventNoStr[1]="01";}
      else if(eventNoStr[1]=="2")
      {eventNoStr[1]="02";}
      else if(eventNoStr[1]=="3")
      {eventNoStr[1]="03";}
      else if(eventNoStr[1]=="4")
      {eventNoStr[1]="04";}
      else if(eventNoStr[1]=="5")
      {eventNoStr[1]="05";}
      else if(eventNoStr[1]=="6")
      {eventNoStr[1]="06";}
      else if(eventNoStr[1]=="7")
      {eventNoStr[1]="07";}
      else if(eventNoStr[1]=="8")
      {eventNoStr[1]="08";}
      else if(eventNoStr[1]=="9")
      {eventNoStr[1]="09";}

      if(eventNoStr[2]=="1")
      {eventNoStr[2]="01";}
      else if(eventNoStr[2]=="2")
      {eventNoStr[2]="02";}
      else if(eventNoStr[2]=="3")
      {eventNoStr[2]="03";}
      else if(eventNoStr[2]=="4")
      {eventNoStr[2]="04";}
      else if(eventNoStr[2]=="5")
      {eventNoStr[2]="05";}
      else if(eventNoStr[2]=="6")
      {eventNoStr[2]="06";}
      else if(eventNoStr[2]=="7")
      {eventNoStr[2]="07";}
      else if(eventNoStr[2]=="8")
      {eventNoStr[2]="08";}
      else if(eventNoStr[2]=="9")
      {eventNoStr[2]="09";}

      if(eventNoStr[3]=="1")
      {eventNoStr[3]="01";}
      else if(eventNoStr[3]=="2")
      {eventNoStr[3]="02";}
      else if(eventNoStr[3]=="3")
      {eventNoStr[3]="03";}
      else if(eventNoStr[3]=="4")
      {eventNoStr[3]="04";}
      else if(eventNoStr[3]=="5")
      {eventNoStr[3]="05";}
      else if(eventNoStr[3]=="6")
      {eventNoStr[3]="06";}
      else if(eventNoStr[3]=="7")
      {eventNoStr[3]="07";}
      else if(eventNoStr[3]=="8")
      {eventNoStr[3]="08";}
      else if(eventNoStr[3]=="9")
      {eventNoStr[3]="09";}

      if(eventNoStr[4]=="1")
      {eventNoStr[4]="01";}
      else if(eventNoStr[4]=="2")
      {eventNoStr[4]="02";}
      else if(eventNoStr[4]=="3")
      {eventNoStr[4]="03";}
      else if(eventNoStr[4]=="4")
      {eventNoStr[4]="04";}
      else if(eventNoStr[4]=="5")
      {eventNoStr[4]="05";}
      else if(eventNoStr[4]=="6")
      {eventNoStr[4]="06";}
      else if(eventNoStr[4]=="7")
      {eventNoStr[4]="07";}
      else if(eventNoStr[4]=="8")
      {eventNoStr[4]="08";}
      else if(eventNoStr[4]=="9")
      {eventNoStr[4]="09";}
  }
  std::string getEventNo()
  {  
    std::string fullEventNo;
    
    for(int x=0;x<5;x++)
      {fullEventNo+=eventNoStr[x];}
    return fullEventNo;
  }

  std::string getDetails()
  {
    return details;
  }

  int getYear()
  {
    return year;
  }
  std::string getYear0()
  {
    return eventNoStr[0];
  }

  int getMonth()
  {
    return month;
  }
  std::string getMonth0()
  {
    return eventNoStr[1];
  }

  int getDay()
  {
    return day;
  }
  std::string getDay0()
  {
    return eventNoStr[2];
  }

  int getHour()
  {  
    return hour;
  }
  std::string getHour0()
  {  
    return eventNoStr[3];
  }

  int getMinute()
  {
    return minute;
  }
  std::string getMinute0()
  {
    return eventNoStr[4];
  }

  

};

//Function for getting Day of Week using real time
std::string getDayOfWeek(int Dyr, int Dmon, int Dday) 
{
  struct tm timeinfo = {0};

  timeinfo.tm_year = Dyr - 1900; // years since 1900
  timeinfo.tm_mon = Dmon - 1;    // months since January [0-11]
  timeinfo.tm_mday = Dday;         // day of the month [1-31]

  // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
  const char* weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  // Use mktime to convert the tm structure to time_t
  time_t time = mktime(&timeinfo);

  // Use localtime to convert the time_t to tm structure with day of the week
  const struct tm* result = localtime(&time);

  return weekdays[result->tm_wday];
}

//Finding Month name without Event Class
std::string monthName(int monN)
  {
    switch(monN)
    {
      case 1:
        return "January";
      break;
      case 2:
        return "Febuary";
      break;
      case 3:
        return "March";
        break;
      case 4:
        return "April";
      break;
      case 5:
        return "May";
      break;
      case 6:
        return "June";
      break;
      case 7:
        return "July";
      break;
      case 8:
        return "August";
      break;
      case 9:
        return "September";
      break;
      case 10:
        return "October";
      break;
      case 11:
        return "November";
      break;
      case 12:
        return "December";
      break;
    }
  }

  //Event Validation
  bool isValid(int isM, int isD, int isY, int isH, int ism)
  {
    if(isM<1 || isM>12)
    {
      std::cout << "\nThat is not a month" << std::endl;
      return false;
    }
    switch(isM)
    {
      case 1:
        if(isD<1 || isD>31)
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
      break;
      case 2:
        if(isD<1 || isD>29)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
        if(isD==29)
        {
          if(isY%4!=0 && isY%400!=0)
          {
            std::cout << "\nA Leap Day only exists in a Leap Year" << std::endl;
            return false;
          }
        }
      break;
      case 3:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 4:
        if(isD<1 || isD>30)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 5:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 6:
        if(isD<1 || isD>30)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 7:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 8:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 9:
        if(isD<1 || isD>30)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 10:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 11:
        if(isD<1 || isD>30)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
      case 12:
        if(isD<1 || isD>31)
        {
          std::cout << "\nThat Day does not exist in " << monthName(isM) << std::endl;
          return false;
        }
      break;
    }
    if(isY < 1753 || isY > 9999)
    {
      std::cout << "\nYear must be in range" << std::endl;
      return false;
    }
    if(isH < 0 || isH > 23)
    {
      std::cout << "\nThere's only 24 hours in a day" << std::endl;
      return false;
    }
    if(ism < 0 || ism > 59)
    {
      std::cout << "\nThere's only 60 minutes in an hour" << std::endl;
    }
    return true;
  }

  //Bubble Sort Algorithm for Vector
  void bubbleSortAlg(std::vector<Event> &eventList)
  {
    int s = eventList.size();
    for(int x = 0; x < s-1; ++x)
    {
      for(int y = 0; y < s-x-1; ++y)
      {
        if(eventList[y].getDay() > eventList[y + 1].getDay())
        {
          std::swap(eventList[y], eventList[y + 1]);
        }
        else if(eventList[y].getDay() == eventList[y + 1].getDay())
        {
          if(eventList[y].getHour() > eventList[y + 1].getHour())
          {
            std::swap(eventList[y], eventList[y + 1]);
          }
          else if(eventList[y].getHour() == eventList[y + 1].getHour())
          {
            if(eventList[y].getMinute() > eventList[y + 1].getMinute())
            {
            std::swap(eventList[y], eventList[y + 1]);
            }
          }
        }   
      }
    }
  }

  //Main Menu Output
  void Menu()
  {
    std::cout << "\n======== Menu ========\n" << std::endl;
    std::cout << "    " << " A. Add New Event" << std::endl;
    std::cout << "    " << " B. View Daily Events" << std::endl;
    std::cout << "    " << " C. View Monthly Events" << std::endl;
    std::cout << "    " << " D. Update Event" << std::endl;
    std::cout << "    " << " E. Delete Event" << std::endl;
    std::cout << "    " << " F. Exit" << std::endl;
    std::cout << " " << "\n Enter your Choice (A - F)\n\n" << std::endl;
  }

#endif