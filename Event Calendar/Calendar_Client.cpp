#include "Calendar_header.h"

std::vector<Event> EventObjVector;

int ObjVectCounter = -1;

//Function Declarations
void setMonth(int);
void setDay(int);
void setYear(int);
void setHour(int);
void setMinute(int);
void setEventNo(int, int, int, int, int);
std::string monthName(int);
bool isValid(int, int, int, int, int);
void bubbleSortAlg(std::vector<Event>&);
void Menu();
std::string getDayOfWeek(int, int, int);

//Variable Meanings: S = Set, G = Get, Mon = Month, Dy = Day, Yr = Year, Hr = Hour, Min = Minute, Det = Details, No/Nu = Number, ob/Obj = Object
int SobMon, SobDy, SobYr, SobHr, SobMin; std::string SobDet; //Variables for object creation
int GobMon, GobDy, GobYr, GobHr, GobMin; std::string GobDet, GobEventNo; //Variables for object search and deletion
char select; //Menu Selection Variable
bool DailyEventFound, MonthlyEventFound ; //Variables for Finding Events
char YoN; //Variable for Yes or No for Event Deletion

int main()
{
  SobMon=SobDy=SobYr=SobHr=SobMin=0; //Set Default Value to 0
  GobMon=GobDy=GobYr=GobHr=GobMin=0; //Set Default Value to 0
  
  do
  {
    Menu();
    std::cin >> select;
    while(toupper(select) < 'A' || toupper(select) > 'F') 
    {
      std::cout << "Make a choice within the selection!\n"; 
      Menu();
      std::cin >> select; 
    } 
  
  switch(select)
    {
      case 'a':
      case 'A':{ 
        
        std::cout << "\nAdding New Event\n================\n" << std::endl;
        std::cout << "    Month : ";
        std::cin >> SobMon;
        std::cout << "    Day : ";
        std::cin >> SobDy;
        std::cout << "    Year : ";
        std::cin >> SobYr;
        std::cout << "    Hour : ";
        std::cin >> SobHr;
        std::cout << "    Minute : ";
        std::cin >> SobMin;
        std::cout << "    Details : ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, SobDet);

        bool validInput = isValid(SobMon, SobDy, SobYr, SobHr, SobMin);

        if(!validInput)
        {
          std::cout << "\nPress Enter key to return to the Menu";
          fgetc(stdin);
          break;
        }

        ++ObjVectCounter;

        EventObjVector.push_back(Event());

        EventObjVector[ObjVectCounter].setMonth(SobMon);
        EventObjVector[ObjVectCounter].setDay(SobDy);
        EventObjVector[ObjVectCounter].setYear(SobYr);
        EventObjVector[ObjVectCounter].setHour(SobHr);
        EventObjVector[ObjVectCounter].setMinute(SobMin);
        EventObjVector[ObjVectCounter].setEventNo(SobYr, SobDy, SobMon, SobHr, SobMin);
        EventObjVector[ObjVectCounter].setDetails(SobDet);

        std::cout << "\nNew event added (Event# " << EventObjVector[ObjVectCounter].getEventNo() << ")\n" << std::endl;
        std::cout << "Press Enter key to return to the Menu";
        
        fgetc(stdin);
        
       break;}
      case 'b':
      case 'B':{

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "\nView Daily Events\n=================\n" << std::endl;

        std::cout << "    Month: ";
        std::cin >> GobMon; 
        std::cout << "\n\n    Day: ";
        std::cin >> GobDy;
        std::cout << "\n\n    Year: ";
        std::cin >> GobYr;
        std::cout << "\n\n";

        DailyEventFound = false;

        bubbleSortAlg(EventObjVector);

        for (Event tempLoopObj : EventObjVector)
        {
          if(tempLoopObj.getMonth() == GobMon && tempLoopObj.getDay() == GobDy && tempLoopObj.getYear() == GobYr)
          {
            std::cout << "\n--> " << tempLoopObj.getHour0() << ":" << tempLoopObj.getMinute0() << " (Event# " << tempLoopObj.getEventNo() << "):\n    " << tempLoopObj.getDetails() << "\n" << std::endl;

            DailyEventFound = true;
          }
        }

        if(!DailyEventFound)
        {
          std::cout << "\nThere are no Events for that Day!\n" << std::endl;
        }

        std::cout << "Press Enter key to return to the Menu";

        fgetc(stdin); fgetc(stdin);
        
      break;}
      case 'c':
      case 'C':{
        
        std::cout << "\nView Monthly Events\n===================\n" << std::endl;
        std::cout << "    Month: ";
        std::cin >> GobMon;
        std::cout << "\n\n    Year: ";
        std::cin >> GobYr;
        std::cout << "\n\n";
        std::cout << "Events of " << monthName(GobMon) << " " << GobYr << " : " << std::endl;

        MonthlyEventFound = false;

        bubbleSortAlg(EventObjVector);

        //std::string dayOfWeek = getDayOfWeek()

        for (Event tempLoopObj : EventObjVector)
        {
          if(tempLoopObj.getMonth() == GobMon && tempLoopObj.getYear() == GobYr)
          {
            int tempYear = tempLoopObj.getYear();
            int tempMonth = tempLoopObj.getMonth();
            int tempDay = tempLoopObj.getDay();

            std::cout << "\n--> " << getDayOfWeek(tempLoopObj.getYear(), tempLoopObj.getMonth(), tempLoopObj.getDay()) << ", " << tempLoopObj.monthName() << " " << tempLoopObj.getDay() << " at " << tempLoopObj.getHour0() << ":" << tempLoopObj.getMinute0() << " (Event# " << tempLoopObj.getEventNo() << "):\n    " << tempLoopObj.getDetails() << "\n" << std::endl;

            MonthlyEventFound = true;
          }
        }

        if(!MonthlyEventFound)
        {
          std::cout << "\nThere are no Events for that Month!\n" << std::endl;
        }

        std::cout << "Press Enter key to return to the Menu";

        fgetc(stdin); fgetc(stdin);
        
      break;}
      case 'd':
      case 'D':{
        
        std::cout << "\nUpdate Event\n============\n" << std::endl;
        std::cout << "    Enter Event Number : ";
        std::cin >> GobEventNo;

        std::string tempEventNo = GobEventNo;
      
          auto ObjIteratorPointer = std::find_if(EventObjVector.begin(), EventObjVector.end(), [tempEventNo] (Event& tempLoopObj) {return tempLoopObj.getEventNo() == tempEventNo;});

          if(ObjIteratorPointer != EventObjVector.end())
          {
            std::cout << "Current Event Details:" << std::endl;
            std::cout << "\n--> " << ObjIteratorPointer->monthName() << " " << ObjIteratorPointer->getDay() << " at " << ObjIteratorPointer->getHour0() << ":" << ObjIteratorPointer->getMinute0() << " (Event# " << ObjIteratorPointer->getEventNo() << "):\n    " << ObjIteratorPointer->getDetails() << "\n" << std::endl;
            std::cout << "\nAre you sure you want to update this event? (Y/N) ";
            std::cin >> YoN;

            if(YoN == 'Y')
            {
              std::cout << "\nEnter New Event Details:\n";
              std::cout << "    Month : ";
              std::cin >> SobMon;
              std::cout << "    Day : ";
              std::cin >> SobDy;
              std::cout << "    Year : ";
              std::cin >> SobYr;
              std::cout << "    Hour : ";
              std::cin >> SobHr;
              std::cout << "    Minute : ";
              std::cin >> SobMin;
              std::cout << "    Details : ";
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              getline(std::cin, SobDet);

              ObjIteratorPointer->setMonth(SobMon);
              ObjIteratorPointer->setDay(SobDy);
              ObjIteratorPointer->setYear(SobYr);
              ObjIteratorPointer->setHour(SobHr);
              ObjIteratorPointer->setMinute(SobMin);
              ObjIteratorPointer->setEventNo(SobYr, SobDy, SobMon, SobHr, SobMin);
              ObjIteratorPointer->setDetails(SobDet);

              std::cout << "\nEvent Updated.\n";
            }
            else if(YoN == 'N')
            {
              break;
            }
          }
          else
          {
            std::cout << "\nThat Event Number doesn't exist!\n" << std::endl;
          }

        std::cout << "Press Enter key to return to the Menu";
        
        fgetc(stdin); fgetc(stdin);
        
      break;}
      case 'e':
      case 'E':{
        
        std::cout << "\nDelete Event\n============\n" << std::endl;
        std::cout << "    Enter Event Number : ";
        std::cin >> GobEventNo;

        std::string tempEventNo = GobEventNo;
      
          auto ObjIteratorPointer = std::find_if(EventObjVector.begin(), EventObjVector.end(), [tempEventNo] (Event& tempLoopObj) {return tempLoopObj.getEventNo() == tempEventNo;});

          //"ObjIteratorPointer->" Points to current object in the vector
          if(ObjIteratorPointer != EventObjVector.end())
          {
            std::cout << "\n--> " << ObjIteratorPointer->monthName() << " " << ObjIteratorPointer->getDay() << " at " << ObjIteratorPointer->getHour0() << ":" << ObjIteratorPointer->getMinute0() << " (Event# " << ObjIteratorPointer->getEventNo() << "):\n    " << ObjIteratorPointer->getDetails() << "\n" << std::endl;
            std::cout << "\nAre you sure you want to delete this event? (Y/N) ";
            std::cin >> YoN;

            if(YoN == 'Y')
            {
              EventObjVector.erase(ObjIteratorPointer);
              std::cout << "\nEvent Deleted.\n";
            }
            else if(YoN == 'N')
            {
              break;
            }
          }
          else
          {
            std::cout << "\nThat Event Number doesn't exist!\n" << std::endl;
          }
        //}

        std::cout << "Press Enter key to return to the Menu";

        fgetc(stdin); fgetc(stdin);
        
      break;}
      case 'f':
      case 'F':{
        std::cout << "Exiting Program... Thank You!";
        return 0;
      break;}
      default:{
      }
    }
  } while(toupper(select)!='F');
  
  return 0;
}