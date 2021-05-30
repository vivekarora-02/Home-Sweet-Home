

//Following are the header files we have used in our project

#include<iostream>

#include<stdlib.h>

#include<time.h>

#include<map>

#include<string>

#include<cstring>

#include<utility>

#include<unordered_map>

using namespace std;

void delay(unsigned int mseconds) {
  clock_t goal = mseconds + clock();
  while (goal > clock());
}

//We have created the class namely, User

class User {
  string username;
  string password;
  bool exist;
public:
  User() {
    exist = false;
  }
  int checkExist() {
    if (!exist)
      return 1;
    else
      return 0;
  }

  //Created a function to create a new User

  void createUser() {

    string pass2;
    char ch = 'n';
    if (!exist)
      do {
        cout << "Enter username: ";
        cin>>username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> pass2;

        //Verification for password

        if (pass2 == password) {
          cout << "\n Successfully added user\n";
          ch = 'y';
          exist = true;
        } else {
          cout << "\nPasswords do not match\n";
          system("cls");
        }
      } while (ch == 'n');
    else
      cout << "Account already exists!";
  }

  //Created a function to delete the existing User.

  void deleteUser() {
    exist = false;
  }
  friend bool loginUser();
}
u[10]; //Creating an object of class User

int currentLogin;

//Created a boolean function to check if the Admin/User exist.

bool loginUser() {
  string user, pwd;
  double flag = 0;
  cout << "Enter username: ";
  cin >> user;
  cout << "Enter password: ";
  cin >> pwd;

  for (int i = 0; i < 10; i++) {
    if (user == u[i].username && pwd == u[i].password) {
      cout << "\nLogged in successfully\n";
      flag = 1;
      currentLogin = i;
      break;
    }
  }

  //Returns true or false.

  if (flag)
    return true;
  else
    return false;
}

// Created a Global Map to store price and address of various locations.
//We have initialized this Map with some values.
//We have created the Map for three cities as follows.

unordered_map < double, string > mumbai {
  {
    120000,
    "Flat no.201, West bandra,Mumbai"
  }, {
    190000,
    "Flat no.302,Santa Cruz,Mumbai"
  }, {
    340000,
    "flat no.401,East Bandra,Mumbai"
  }
};

unordered_map < double, string > delhi {
  {
    200000,
    "House no.21,West Saket,New Delhi"
  }, {
    180000,
    "flat no.345,Greater Kailash,New Delhi"
  }, {
    400000,
    "House no.34,Karol bagh,New Delhi"
  }
};

unordered_map < double, string > gurgaon {
  {
    170000,
    "House No.312,Sector 40 , Gurgaon"
  }, {
    250000,
    "House No.45,Sushant Lok-II, Gurgaon"
  }, {
    340000,
    "Flat no.456 ,Raheja Apartment, Gurgaon"
  }
};

/*

Created a Parent/Base class namely Property.
We have created this class to be parent
so that we shouldn't declare same variable
in every class again and again

(THE CONCEPT OF INHERITANCE)

*/

class Property {
public:
  string city;
  string address;
  double type_number;
  int choice;
  double price;
  bool rented;
  virtual void add_detail() {}; //Created a Virtual Function.
  Property() {
    rented = false;
  }
};

// 1st Child/Derived class namely Seller which is used if someone wants to sell their property.

class Seller: public Property {
public:
  //Creating a function to add detail about the property.
  void add_detail() {
    cout << " Enter your preferred location: " << endl;
    cout << " 1) Mumbai " << endl << " 2) Gurgaon " << endl << " 3) Delhi" << endl;
again:
    cout << "Choose preferred city number: " << endl;
    cin >> choice;

    //Using switch case to take user choice.

    switch (choice) {
    case 1:
      cout << "Your preferred location is Mumbai " << endl;
      cout << "Enter address " << endl;

      cin.ignore();

      getline(cin, address);
      cout << "Enter price" << endl;
      cin >> price;

      //adding address to existing map

      mumbai.insert(pair < double, string > (price, address));

      cout << "Successfully added" << endl;
      break;

    case 2:

      cout << "Your preferred location is Gurgaon" << endl;
      cout << "Enter address " << endl;

      cin.ignore();

      getline(cin, address);
      cout << "Enter price" << endl;

      cin >> price;

      //adding address to existing map

      delhi.insert(pair < double, string > (price, address));

      cout << "Successfully added" << endl;
      break;

    case 3:

      cout << "Your preferred location is Delhi" << endl;
      cout << "Enter address " << endl;

      cin.ignore();

      getline(cin, address);
      cout << "Enter price" << endl;

      cin >> price;

      //adding address to existing map

      mumbai.insert(pair < double, string > (price, address));

      cout << "Successfully added" << endl;

      break;

    default:
      cout << "Invalid choice, please select again!";
      goto again; //Goto statement

      break;
    }
  }

};

// 2nd Child/Derived class namely Buyer which is used if someone wants to buy a property.

class Buyer: public Property {
public:
  //Creating a function to add detail about the property.
  void add_details() {

    cout << " Enter your preferred location " << endl;
    cout << " 1) Mumbai " << endl << " 2) Gurgaon " << endl << " 3) Delhi" << endl;

again3: //Goto Jump statement

    cout << "Choose preferred city number" << endl;

    cin >> choice;

    if (choice == 1) {

      cout << "Available options are: " << endl;
      cout << "Price " << "  Address " << endl;
      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = mumbai.begin(); it != mumbai.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again2: //Goto Jump statement

      cout << "Enter the price of the preferred property" << endl;

      cin >> price;
      it = mumbai.find(price);

      if (it != mumbai.end()) {

        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ?\n1) Yes\n2) No" << endl;
        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property sold to you " << endl;
          mumbai.erase(price);
        } else {

          cout << "Sorry wrong option please try again :( " << endl;
          goto again2; //Goto statement

        }

      }
    } else if (choice == 2) {

      cout << "Available options are:" << endl;
      cout << "Price " << "  Address " << endl;
      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = gurgaon.begin(); it != gurgaon.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again5: //Goto Jump statement

      cout << "Enter the price of the preferred property: " << endl;
      cin >> price;
      it = gurgaon.find(price);
      if (it != gurgaon.end()) {
        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ?\n1) Yes\n2) No" << endl;
        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property sold to you " << endl;
          gurgaon.erase(price);
        } else {

          cout << "Sorry wrong option try again " << endl;
          goto again5; //Goto statement
        }

      }

    } else if (choice == 3) {
      cout << "Available options are:" << endl;
      cout << "Price " << "  Address " << endl;

      //Creating the Map iterator, for iterating over the Map.

      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = delhi.begin(); it != delhi.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again6: //Goto Jump statement

      cout << "Enter the price of the preferred property" << endl;
      cin >> price;
      it = delhi.find(price);
      if (it != delhi.end()) {
        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ? \n1) Yes\n2) No" << endl;
        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property sold to you " << endl;
          delhi.erase(price);
        } else {

          cout << "Sorry wrong option try again " << endl;
          goto again6; //Goto statement
        }

      }
    } else {
      cout << "Choice entered is wrong. choose again." << endl;
      goto again3; //Goto statement
    }
  }
};

// 3rd Child/Derived class namely Rent, which is used if someone wants to get a property on rent.

class Rent: public Property {
public:
  //Creating a function to add detail about the property.
  void add_details() {
    cout << " Enter your preferred location " << endl;
    cout << " 1) Mumbai " << endl << " 2) Gurgaon " << endl << " 3) Delhi" << endl;
again3: //Goto Jump statement
    cout << "Choose preferred city number" << endl;
    cin >> choice;
    if (choice == 1)

    {
      cout << "Options available for renting are:" << endl;
      cout << "Price " << "  Address " << endl;

      //Creating the Map iterator, for iterating over the Map.

      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = mumbai.begin(); it != mumbai.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again2: //Goto Jump statement

      cout << "Enter the price you can pay for the rent : " << endl;
      cin >> price;

      //Using find function to search in Map.

      it = mumbai.find(price);

      if (it != mumbai.end()) {
        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ?\n1) Yes\n2) No" << endl;
        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property rented to you " << endl;

          //Using the erase function to delete the content of Map.

          mumbai.erase(price);
        } else {

          cout << "Sorry wrong option please try again " << endl;
          goto again2; //Goto statement
        }

      }
    } else if (choice == 2)

    {

      cout << "Options available for renting are: " << endl;
      cout << "Price " << "  Address " << endl;

      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = gurgaon.begin(); it != gurgaon.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again5: //Goto Jump statement

      cout << "Enter the price you can pay for the rent : " << endl;
      cin >> price;

      it = gurgaon.find(price);

      if (it != gurgaon.end()) {
        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ?\n1) Yes\n2) No" << endl;
        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property rented to you " << endl;

          //Using the erase function to delete the content of Map.

          gurgaon.erase(price);
        } else {

          cout << "Sorry wrong option try please again " << endl;
          goto again5; //Goto statement
        }

      }

    } else if (choice == 3) {
      cout << "Options available for renting are : " << endl;
      cout << "Price " << "  Address " << endl;

      unordered_map < double, string > ::iterator it;

      /*Printing the complete Map so that user can view
      available options.*/

      for (it = delhi.begin(); it != delhi.end(); it++) {
        cout << it -> first << " - " << it -> second << endl;
      }

again6: //Goto Jump statement

      cout << "Enter the price you can pay for the rent : " << endl;
      cin >> price;

      //Using find function to search in Map.

      it = delhi.find(price);

      if (it != delhi.end()) {

        cout << "Your preferred property is   ";
        cout << it -> second << endl;
        cout << "Do you want to confirm ?\n1) Yes\n2) No" << endl;

        double answer;
        cin >> answer;

        if (answer == 1) {
          cout << "Property rented to you " << endl;

          //Using the erase function to delete the content of Map.

          delhi.erase(price);
        } else {

          cout << "Sorry wrong option please try again " << endl;
          goto again6; //Goto statement
        }

      }
    } else {
      cout << "Choice entered is wrong. choose again." << endl;
      goto again3; //Goto statement
    }
  }
};

//The main function.

int main() {
  //Welcome Message

  cout << "\n           \"I still think buying a home is the best investment any individual can make.\" - John Paulson, Billionaire                   \n";
  cout << "\n                               WELCOME TO HOME SWEET HOME CORPORATION                                           \n";
  cout << "\n                     LOOKING FOR YOUR DREAM HOUSE? DON'T WORRY, WE ARE HERE TO HELP!                                  \n\n";

  int c, userCount = 0;
  int ch;
  int flag1 = 0;

Menu1:

  cout << "\n1. User Register\n2. User Login\n3. Exit\nEnter choice: ";
  cin >> c;
  system("cls");

  //Using switch case to take user choice.

  switch (c) {
  case 1:
    if (userCount < 10) //Checking user count
    {
      u[userCount].createUser();
      userCount++;
      delay(2000);
      system("cls");
    } else {
      for (userCount = 0; userCount < 10; userCount++) {
        if (u[userCount].checkExist()) {
          u[userCount].createUser();
          flag1 = 1;
          break;
        }
      }
      if (!flag1)
        cout << "User limit exceeded!";

      delay(2000);
    }

    goto Menu1;
    break;

  case 2:
    system("cls");
    if (loginUser()) //If the function loginUser() doesn't returns 0.
    {
Menu2:
      cout << "1. Buy \n2. Sell  \n3. Rent \n4. Delete User \n5. Logout \nEnter choice: ";
      cin >> ch;
      system("cls");
      switch (ch) {

      case 1: {
        Buyer b1; //Creating an object of Buyer class.
        b1.add_details();
        break;
      }
      case 2: {
        Seller s1; //Creating an object of Seller class.
        s1.add_detail();
        break;
      }
      case 3: {
        Rent r1; //Creating an object of Rent class.
        r1.add_details();
        break;
      }
      case 4: {
        u[currentLogin].deleteUser(); //Calling delete user function to delete the user.
        delay(2000);
        goto Menu1;
        break;
      }
      case 5: {
        goto Menu1;
        break;
      }
      default: {
        cout << "Wrong choice";
        goto Menu1;
      }
      }
      system("cls");
      goto Menu2;
    } else {
      cout << "User does not exist or invalid credentials!";
    }

    break;
  case 3:

    exit(0);
    break;

  default:
    cout << "Invalid Choice";
    delay(2000);
    goto Menu1;
  }

  return 0;
}


