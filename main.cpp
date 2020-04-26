//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream>
using namespace std; 

/*
struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};
*/

class MenuItem {
      private:
        string name;
        double itemCost; 
        string desc; 
        char addLetter; 
        char removeLetter;
        int count; 
      public:
        MenuItem() {
          name = "Green Tea";
          itemCost = 3.00;
          desc = "delicious";
          addLetter = 'A';
          removeLetter = 'a';
          count = 0;
        }
        MenuItem(string name, double itemCost, string desc, char addLetter, char removeLetter, int count) {
          this->name = name;
          this->itemCost = itemCost;
          this->desc = desc;
          this->addLetter = addLetter;
          this->removeLetter = removeLetter;
          this->count = count;
        }

        //Setter for name
        void setName(string name) {
          this->name = name;
        }
        void setitemCost(double itemCost){
          this->itemCost = itemCost;
        }
        double getitemCost() {
          return itemCost;
        }
        void setdesc(string desc){
          this->desc = desc;
        }
        string getdesc() {
          return desc;
        }
        void setaddLetter(char addLetter) {
          this->addLetter = addLetter;
        }
        char getaddLetter() {
          return addLetter;
        }
        void setremoveLetter(char removeLetter) {
          this->removeLetter = removeLetter;
        }
        char getremoveLetter() {
          return removeLetter;
        }
        void setcount(int count) {
          this->count = count;
        }
        int getcount() {
          return count;
        }
        //Getter for name
        string getName() {
          return name;
        }
};


//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", " Deshebrada", " Bistec Ranchero", "Carnitas", " Chilaquiles", "Horchata", " Albondigas"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setaddLetter(defaultAddLetters[i]); 
    entireMenu[i].setremoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setitemCost((3.00 + i)); //set a random starter cost for each item
    entireMenu[i].setcount(0); //initialze all counts to 0
    entireMenu[i].setdesc("delicious"); //set all default desc to "delicous"
  }


}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getaddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getitemCost() << setw(5) << "(" << m[i].getremoveLetter()
    << ")" << setw(7) << m[i].getcount() << setw(13) << m[i].getdesc() 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> & m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 
  double tip;
  double total;
  double tender;
  double change;
  string payment;

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getaddLetter())
      {
        cout << "\nMenu Item " << m[i].getaddLetter() << " selected."; 
        m[i].setcount(m[i].getcount() + 1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getitemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getremoveLetter())
      {
        cout << "\nRemove Item " << m[i].getremoveLetter() << " selected."; 
        if(m[i].getcount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setcount(m[i].getcount() - 1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getitemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getaddLetter() && 
                option != m[i].getremoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl;
  //handle the tip process here
  cout << "What is your tip percentage?: ";
  cin >> tip;
  total = subtotal + (subtotal * 0.0825) + (subtotal * (tip / 100));
  //accept payment
  cout << "A: Cash" << endl;
  cout << "B: Credit Card" << endl;
  cout << "What is your payment option?: ";
  cin >> payment;
  //process payment
  if (payment == "A" || payment == "a") {
    do {
      cout << "What is the tender amount?: ";
      cin >> tender;
    }while (tender < total);
    change = tender - total;
  }
  else if (payment == "B" || payment == "b") {
    cout << "Credit card processed! :)" << endl;
    tender = total;
    change = 0;
  }
  //handle reciept generation here
  for (MenuItem mi : m) {
    cout << mi.getName() << ": " << mi.getcount() << endl; 
  }
  cout << "Subtotal: $" << subtotal << endl;
  cout << "Tip: $" << tip << endl;
  cout << "Tax: $" << subtotal * 0.0825 << endl;
  cout << "Change: $" << change << endl;
  cout << "Total: $" << total << endl;
  ofstream file;
  file.open("reciept.html", ios::out);
  file << "<h1>Reciept<h1>";
  file << "<p>Subtotal: $" << subtotal << "<p>";
  file << "<p>Tip: $" << tip << "<p>";
  file << "<p>Tax: $" << subtotal * 0.0825 << "<p>";
  file << "<p>Change: $" << change << "<p>";
  file << "<p>Total: $" << total << "<p>"; 
  file.close();
}

int main() 
{



  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 

 
  
  return 0; 
}