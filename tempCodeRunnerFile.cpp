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