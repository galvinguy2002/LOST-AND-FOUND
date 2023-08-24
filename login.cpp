#include <iostream>
using namespace std;

void pattern()
{
      int size = 5;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int k = 0; k < (size - i) * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  for (int i = 2; i <= size; i++) {
    for (int j = size; j > i; j--) {
      cout << " ";
    }
    for (int k = 0; k < i * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
}
int main ()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "lostfound" && userPassword == "lostfound")
        {
            cout<<"Login successful"<<endl;
            pattern();
            cout << "Welcome to the PROJECT!\n";
            break;
        }
        else if (userName == "project" && userPassword == "project")
        {
            cout<<"Login Successful"<<endl;
            pattern();
            cout << "Welcome to the PROJECT!\n";
            break;
        }
        else
        {
            cout << "\n\nInvalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "\n\t\tToo many login attempts! The program will now terminate.\t\t\n";
            return 0;
    }

    cout << "\nThank you for logging in.\n";
}
