#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
// Constants
int const roomcount = 10;
// Functions Prototypes Start
void header();
void login();
void clear();
int who();
int userMenue();
int adminMenue();
void displaySortedRooms(int roomprice[roomcount]); // Sorting Function
void viewAllRooms();
void viewAvailableRooms();
void bookRoom();
int cancelBooking(int registrationNumbers[]);
void viewbooking();
int modifyBooking(int registrationNumbers[]);
void modifyRoomDetails();
void viewallBookings();
void changeAdmin();
int billCalculate(int registrationNumbers[roomcount]);
void billSubMenue();
void allroomssubmenue();
void Help_Centre();
// File Handling Functions
void saveBookingsToFile();
void loadBookingsFromFile();
void saveAdminPasswordToFile();
void loadAdminPasswordFromFile();
void loadNamesFromFile();
void saveNamestoFile();
// File Handling Functions END
// Functions Prototypes END
// Arrays and Data Structures START
int roomnumbers[roomcount] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
string name[roomcount];
int registrationNumbers[roomcount] = {501, 502, 503, 504, 505, 506, 507, 508, 509, 510};
int roomprice[roomcount] = {2000, 2000, 2000, 4000, 4000, 4000, 6000, 6000, 10000, 10000};
string roomType[roomcount] = {"Single", "Single", "Single", "Double", "Double", "Double", "Triple", "Triple", "Elite", "Elite"};
string adminPassword[2] = {"admin123", "123"};
bool isbooked[roomcount] = {false}; // Initially, No room is Booked
// Correct
// Arrays END
main()
{
  loadNamesFromFile();
  loadAdminPasswordFromFile();
  loadBookingsFromFile();
  system("cls");
  int mainOption;
  while (true)
  {

    header();
    mainOption = who();
    if (mainOption == 1)
    {
      string pass;
      cout << "Enter Admin Password:" << endl;
      cout << "Password Hint: " << adminPassword[1] << endl;
      cin >> pass;
      if (pass == adminPassword[0])
      {
        cout << "Correct Password..." << endl;
      Menue:
        int admin = adminMenue();
        if (admin == 1)
        {
          clear();
          viewAllRooms();
        }
        else if (admin == 2)
        {
          clear();
          modifyRoomDetails();
        }
        else if (admin == 3)
        {
          clear();
          viewallBookings();
        }
        else if (admin == 4)
        {
          clear();
          system("color 0C");

          cout << "logged Out Successfully" << endl;
          cout << "You have log out the Hotel Management System..." << endl;
          cout << "Thank You for using Hotel Management System... Good Bye\n\n\n\n"
               << endl;
          break;
        }
        else if (admin == 5)
        {

          clear();
          goto Menue;
        }

        else if (admin == 6)
        {
          clear();
          cout << "Enter New Admin Password: " << endl;
          cin >> adminPassword[0];
          cout << "Enter New Password Hint :  " << endl;
          cin >> adminPassword[1];
          saveAdminPasswordToFile(); // New Admin Password will also be saved in a file admin.txt
          cout << "Password Updated Successfully....." << endl;
        }

        else if (admin == 7)
        {
          clear();
          displaySortedRooms(roomprice);
        }
        /*
       else if (admin == 8)
       {
         clear();
       }
       */
        else
        {
          cout << "Invalid Option" << endl;
        }
      }
      else
      {
        cout << "Wrong Password" << endl;
      }
    }

    else if (mainOption == 2)
    {
    Usermain:
      int user = userMenue();
      if (user == 1)
      {
        // View Available
        clear();
        viewAvailableRooms();
      }
      else if (user == 2)
      {
        // Book a Room
        clear();
        bookRoom();
      }
      else if (user == 3)
      {
        // Cancel Booking
        clear();
        cancelBooking(registrationNumbers);
      }
      else if (user == 4)
      {
        // View Booking
        clear();
        viewallBookings();
      }
      else if (user == 5)
      {
        // Logout
        clear();
        system("color 0C");
        cout << "logged Out Successfully..." << endl;
        cout << "You have log out the Hotel Management System..." << endl;
        cout << "Thank You for using Hotel Management System... Good Bye\n\n\n\n"
             << endl;
        break;
      }
      else if (user == 6)
      {
        clear();
        // Back to main Menue
        goto Usermain;
      }
      else if (user == 7)
      {
        // Modify Booking
        clear();
        modifyBooking(registrationNumbers);
      }
      else if (user == 8)
      {
        // Bill
        clear();
        billCalculate(registrationNumbers);
      }
    }
    else if (mainOption == 3)
    {
      clear();
      Help_Centre();
    }
    else if (mainOption == 4)
    {
      cout << "You have exited the Hotel Management System..." << endl;

      cout << "Thank You for using Hotel Management System... Good Bye\n\n\n\n"
           << endl;
      break;
    }
    else
    {
      clear();
      cout << "Invalid Option......\n Try Again." << endl;
    }
  }
} // END of Main

void header()
{
  system("color 0B");
  cout << "*************************************************" << endl;
  cout << "*  ======Hotel Management System======            *" << endl;
  cout << "*************************************************" << endl;

  cout << "Welcome to Hotel management system of Developed by Asim......." << endl;
  cout << "Welcome Asim Grand Resorts Sir! Our system is designed to provide a seamless and efficient experience for booking, managing, and modifying your hotel stay." << endl;
  cout << "Key Factors" << endl;
  cout << "-> Instantly book available rooms" << endl;
  cout << "-> Easily make changes to your reservations." << endl;
  cout << "-> Check your total charges" << endl;
}
void clear()
{
  system("color 0A");
  cout << "Press any key to Continue...." << endl;
  getch();
  system("cls");
}
int who()
{
  int op;
  cout << "1.Admin Login" << endl;
  cout << "2.User Login" << endl;
  cout << "3.Help/Information" << endl;
  cout << "3.Exit" << endl;
  cout << "Enter your option  : ";
  cin >> op;
  return op;
}
int adminMenue()
{
  system("color 0B");
  cout << "===Admin Dashboard===" << endl;
  cout << "1.View All Rooms " << endl;
  cout << "2.Modify Room Details" << endl;
  cout << "3.View Bookings" << endl;
  cout << "4.Logout" << endl;
  cout << "5.Back to Main Menu " << endl;
  cout << "6.Change Admin Password" << endl;
  cout << "7.Display Sorted Rooms w.r.t Price" << endl;
  cout << "Enter Your choice.." << endl;
  int option;
  cin >> option;
  return option;
}
// ADMIN Features START
void viewAllRooms()
{

  cout << "\nRoom No\tType\tPrice\tStatus\tReg No\n";
  for (int i = 0; i < roomcount; i++)
  {
    cout << roomnumbers[i] << "\t" << roomType[i] << "\t"
         << roomprice[i] << "\t" << (isbooked[i] ? "Booked" : "Available")
         << "\t" << registrationNumbers[i] << endl;
  }
}

void modifyRoomDetails()
{
  system("color 0E");

  int modify;
  cout << "Enter Room Number You Want to Modify: " << endl;
  cin >> modify;
  for (int i = 0; i < roomcount; i++)
  {
    if (roomnumbers[i] == modify)
    {
      cout << "Enter New Room Number : " << endl;
      cin >> roomnumbers[i];
      cout << "Enter New Room Type: " << endl;
      cin >> roomType[i];
      cout << "Enter New Room Price: " << endl;
      cin >> roomprice[i];
      cout << "Room Details Updated  " << endl;
    }
  }
}
void viewBooking()
{
  system("color 0F");

  cout << "===All Available Rooms===" << endl;
  for (int i = 0; i < roomcount; i++)
  {
    if (!isbooked[i])
    {
      cout << "Room\tType\tRoom_Type\tRoomPrice\tRegistrationNumbers\tName" << endl;
      cout << roomnumbers[i] << "\t" << roomType[i] << "\t" << roomprice[i] << "\t" << registrationNumbers[i] << name[i] << endl;
    }
  }
}

// ADMIN Features END

// USER Features START
int userMenue()
{
  system("color 0A");

  cout << "===User Dashboard===" << endl;
  cout << "1.View Available Rooms " << endl;
  cout << "2.Book a room " << endl;
  cout << "3.Cancel Booking " << endl;
  cout << "4.View Booking " << endl;
  cout << "5.Logout " << endl;
  cout << "6.Back to Main Menu " << endl;
  cout << "7.Modify Booking " << endl;
  cout << "8.View Bill " << endl;
  cout << "Your choice.... ";
  int choice;
  cin >> choice;
  return choice;
}
// 1.
void viewAvailableRooms()
{
  allroomssubmenue();
  system("color 0E");

  cout << "Room No.\tType\tPrice\tStatus\n"
       << endl;
  for (int i = 0; i < roomcount; i++)
  {
    cout << roomnumbers[i] << "\t " << roomType[i] << "\t " << roomprice[i] << "\t " << (isbooked[i] ? "Booked " : "Available ") << "\t" << endl;
  }
}
// 2.
void bookRoom()
{
  system("color 0F");

  string Name;
  int roomnum;
  system("cls");
  viewAvailableRooms();
  cout << "Enter Your Name : " << endl;
  cin >> Name;
  cout << "Enter Room Number You want to Book : " << endl;
  cin >> roomnum;
  for (int i = 0; i < roomcount; i++)
  {
    if (roomnumbers[i] == roomnum && !isbooked[i])
    {
      isbooked[i] = true;
      name[i] = Name;
      cout << "Room " << roomnumbers[i] << "  Is Booked by   " << name[i] << endl;
      cout << "  And Your Registration Number is  " << registrationNumbers[i] << endl;
      cout << "Always Remember It..."
           << endl;
      saveNamestoFile();
      cout << "Do you want to book another Room?(yes/no)" << endl;
      string button;
      cin >> button;
      if (button == "Yes")
      {
        cout << "Enter Room Number You want to Book : " << endl;
        for (int i = 0; i < roomcount; i++)
        {
          if (roomnumbers[i] == roomnum && !isbooked[i])
          {
            isbooked[i] == true;
            cout << "Room " << roomnumbers[i] << " Is Booked by  " << name << endl;
            cout << "And Your Registration Number is  " << registrationNumbers[i];
          }
        }
      }
      else
      {
        cout << "Thank You for using Hotel Management System... Good Bye\n\n\n\n"
             << endl;
      }
    }
  }
  saveBookingsToFile(); // Booking will be saved in a Separate File
}
//  3.
int cancelBooking(int registrationNumbers[])
{
  bool roomfound;
  int reg;
  cout << "Enter Your Registration Number: " << endl;
  cin >> reg;
  for (int i = 0; i < roomcount; i++)
  {
    if (reg == registrationNumbers[i])
    {
      isbooked[i] = false;
      roomfound = true;
    }
  }
  if (roomfound == true)
  {
    cout << "Booking  Cancelled..." << endl;
  }
  else
  {
    cout << "Wrong Registration Number.." << endl;
  }
  saveBookingsToFile(); // Booking cancellation will be saved in a separate file
}
//  4.
void viewallBookings()
{
  system("color 0B");
  cout << "===All Bookings===" << endl;
  cout << "Room No\tType\tPrice\tReg No\tName\n";
  for (int i = 0; i < roomcount; i++)
  {
    if (isbooked[i])
    {
      cout << roomnumbers[i] << "\t" << roomType[i] << "\t"
           << roomprice[i] << "\t" << registrationNumbers[i] << "\t" << name[i] << endl;
    }
  }
}
// 5. Done
// 6. Done

// 8.
int billCalculate(int registrationNumbers[roomcount])
{
  billSubMenue();
  int reg1;
  int bill = 0, room_service = 1000;
  bool found = false;
  cout << "Enter Your Room Registration Number:  " << endl;
  cin >> reg1;
  for (int i = 0; i < roomcount; i++)
  {
    if (reg1 == registrationNumbers[i])
    {
      found = true;
      if (isbooked[i])
      {
        bill = roomprice[i] + room_service;
        cout << "Your Total Bill is :" << bill << endl;
      }
      else
      {
        cout << "This room is not booked. Bill cannot be generated." << endl;
      }
      break;
    }
  }
  if (!found)
  {
    cout << "Registration number not found!" << endl;
  }
  return bill;
}
void billSubMenue()
{
  cout << "===Bill Calculator===" << endl;
  cout << "Welcome To Bill Calculator of Asim Resorts.." << endl;
  cout << "____________________________________________________" << endl;
}
void displaySortedRooms(int roomprice[])
{
  for (int i = 0; i < roomcount; i++)
  {
    for (int j = i + 1; j < roomcount; j++)
    {
      if (roomprice[i] > roomprice[j])
      {
        // Swap  Prices
        int temp = roomprice[i];
        roomprice[i] = roomprice[j];
        roomprice[j] = temp;

        // Swap Room Numbers
        int tempNum = roomnumbers[i];
        roomnumbers[i] = roomnumbers[j];
        roomnumbers[j] = tempNum;

        // Swap Room Types
        string tempType = roomType[i];
        roomType[i] = roomType[j];
        roomType[j] = tempType;

        // Swap Registration Numbers
        int tempReg = registrationNumbers[i];
        registrationNumbers[i] = registrationNumbers[j];
        registrationNumbers[j] = tempReg;

        // Booking Status
        bool tempBooked = isbooked[i];
        isbooked[i] = isbooked[j];
        isbooked[j] = tempBooked;
      }
    }
  }

  // Print sorted rooms
  cout << "\nRoom No\tType\tPrice\tStatus\tReg No\n";
  for (int i = 0; i < roomcount; i++)
  {
    cout << roomnumbers[i] << "\t" << roomType[i] << "\t"
         << roomprice[i] << "\t" << (isbooked[i] ? "Booked" : "Available")
         << "\t" << registrationNumbers[i] << endl;
  }
}
// 7.
int modifyBooking(int registrationNumbers[])
{

  string change;
  string change2;
  cout << "Do you want to change your name (yes/no) : " << endl;
  cin >> change;
  if (change == "yes")
  {
    cout << "Enter Your Registration Number First: ";
    int reg;
    cin >> reg;
    for (int i = 0; i < roomcount; i++)
    {
      if (reg == registrationNumbers[i])
      {
        cout << "Enter Your New name :" << endl;
        cin >> name[i];
        saveNamestoFile();
        cout << "Name Changed Successfully..." << endl;
      }
    }
  }
  else if (change == "no")
  {
    goto out;
  }
  else
  {
    cout << "Wrong Choice..." << endl;
  }
out:
  cout << "Do you also want to change your Room (yes/no) : " << endl;
  cin >> change2;
  if (change2 == "yes")
  {
    cout << "Enter Your Registration Number: ";
    int reg;
    cin >> reg;
    for (int i = 0; i < roomcount; i++)
    {
      if (reg == registrationNumbers[i])
      {
        cout << "Enter Your New Room Number :" << endl;
        cin >> roomnumbers[i];
        cout << "Room No Changed Successfully..." << endl;
      }
    }
  }
  else if (change2 == "no")
  {
    cout << "Good Bye Sir......." << endl;
  }
  else
  {
    cout << "Wrong Choice..." << endl;
  }
}

void allroomssubmenue()
{
  cout << "====All Rooms====" << endl;
  cout << "Here You Can find All Available Rooms of Asim Resorts......" << endl;
  cout << "__________________________________________________________________________" << endl;
}
void Help_Centre()
{
  cout << "====================================================" << endl;
  cout << "          Hotel Management System Guide \n";
  cout << "====================================================" << endl;
  cout << "Welcome to the User Help Desk! Here's how you can interact\n";
  cout << "with the system easily and enjoy your stay with us \n";
  cout << "_________________________________________________________________" << endl;
  cout << "1.View Available Rooms\n";
  cout << "Displays all rooms with type, price, and current status.\n";
  cout << "Helps you pick the best room for your needs.\n\n";
  cout << "2.Book a Room\n";
  cout << "Reserve a room under your name.\n";
  cout << " You'll receive a registration number for future reference.\n\n";

  cout << "3.Cancel Booking\n";
  cout << "Change of plans? Cancel your room using your room number and Registration Number.\n\n";

  cout << "4.View Booking\n";
  cout << "See which rooms are currently booked and by whom.\n\n";

  cout << "5. Logout\n";
  cout << "Ends your current session securely.\n\n";

  cout << "6.Back to Main Menu\n";
  cout << "Returns you to the login screen.\n\n";

  cout << "7. Modify Booking\n";
  cout << "Need to change your room or name? Use this option.\n\n";
  cout << "8. View Bill\n";
  cout << " Displays your charges based on the room you've booked.\n\n";
  cout << "====================================================\n";
  cout << "Pro Tip : Always remember your registration number!\n";
  cout << "====================================================\n\n";
  cout << "Press any key to return to the User Menu..." << endl;
  getch();
}
// File Handling Functions Definitions
void loadBookingsFromFile()
{
  fstream file;
  file.open("bookings2.txt", ios::in);
  int status;
  for (int i = 0; i < roomcount; i++)
  {
    if (file >> status) // This line reads a int number (1 or 0)and stores in it status Variable
    // If reading from file is successful then it will move inside if block
    {
      if (status == 1)
      {
        isbooked[i] = true;
      }
      else
      {
        isbooked[i] = false;
      }
      if (isbooked[i])
      {
        cout << "Room " << roomnumbers[i] << ": Not Available" << endl;
      }
      else
      {
        cout << "Room " << roomnumbers[i] << ": Available" << endl;
      }
    }
  }
  file.close();
}
void saveBookingsToFile()
{
  fstream file;
  file.open("bookings2.txt", ios::out); // Overwrites the file with current booking status
  for (int i = 0; i < roomcount; i++)
  {
    file << (isbooked[i] ? 1 : 0) << endl;
  }
  file.close();
}
void saveAdminPasswordToFile()
{
  fstream file1;
  file1.open("admin.txt", ios::out);
  file1 << adminPassword[0] << "\n";
  file1 << adminPassword[1] << endl; // Password Hint
  file1.close();
}

void loadAdminPasswordFromFile()
{
  fstream file1;
  file1.open("admin.txt", ios::in);
  file1 >> adminPassword[0];
  file1 >> adminPassword[1]; // Password Hint
  file1.close();
}
void saveNamestoFile()
{
  fstream file1;
  file1.open("names.txt", ios::out);
  for (int i = 0; i < roomcount; i++)
  {
    file1 << name[i] << endl;
    // file1 << name[i]<<"\n";
  }

  file1.close();
}

void loadNamesFromFile()
{
  fstream file1;
  file1.open("names.txt", ios::app);
  for (int i = 0; i < roomcount; i++)
  {
    file1 >> name[i];
  }

  file1.close();
}
// void loadNamesFromFile()
// void saveNamestoFile()
// Correct Code
// int billCalculate(int registrationNumbers[roomcount])
// {
//    billSubMenue();
//   int reg1;
//   bool booking;
//   int bill, room_service = 1000;
//   cout << "Enter Your Room Registration Number:  " << endl;
//   cin >> reg1;
//   for (int i = 0; i < roomcount; i++)
//   {
//     if (isbooked[i] && reg1 == registrationNumbers[i])
//     {
//       booking = true;
//     }
//     else
//     {
//       booking=false;
//     }

//   }
//   if (booking == true)
//   {
//     for (int i = 0; i < roomcount; i++)
//     {
//       if (reg1 == registrationNumbers[i])
//       {
//         bill = roomprice[i] + room_service;
//       }
//     }
//     cout << "Your Total Bill is :" << bill << endl;
//     return bill;
//   }
//   else if(booking== false)
//   {
//     cout << "Your Registration Number is Wrong.." << endl;
//     cout << "So, Your bill is not Generated.." << endl;
//   }
// }