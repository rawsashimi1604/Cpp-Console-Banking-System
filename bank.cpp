#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <stdio.h>
#include <sstream>
#include <iomanip>

using namespace std;

/*
    THINGS TO DO :
        
 */

string getFileContents(ifstream& File) // Solution from http://www.cplusplus.com/forum/general/58945/ TheMassiveChipmunk 
{   
    // Returns string to print header to CONSOLE.
    string Lines = "";                  // Output
    
    if (File) 
    {
	while (File.good ())
	{
	    string TempLine;
	    getline (File , TempLine);
	    TempLine += "\n";
	    
	    Lines += TempLine;
	}
	return Lines;
    }
    else
    {
	return "ERROR File does not exist.";
    }
}

string readLine(string &filename, int n)
{
    ifstream file(filename);
    string output;

    // Skip lines
    for (int i = 0; i < n; i++)
    {
        getline(file, output);
    }
    // Actual output
    getline(file, output);
    file.close();
    return output;
}

class Bank
{
    public:
        void header();
        // MENUS
        void mainMenu();
        void loginScreen();
        void registerScreen();
        void infoScreen();
        void bankMenuScreen();
        void bankBalanceScreen();
        void bankWithdrawScreen();
        void bankDepositScreen();
        void bankTransferScreen();

        // OTHER FUNCTIONS
        bool createUser(const string username, const string password);
        bool authenticateUser(const string usernameAttempt);
        bool authenticatePassword(const string usernameAttempt, const string passwordAttempt);
        bool withdraw(const string username, float amount);
        bool deposit(const string username, float amount);
        bool transfer(const string username1, const string username2, float amount);

    private:
        bool authenticated;
        string unAttempt;
        string pwAttempt;
};

void Bank::header()
{
    ifstream fileRead("header.txt");
    string output = getFileContents(fileRead);
    cout << output << endl;
    fileRead.close();    
}

void Bank::mainMenu()
{   
    int option;

    do
    {   
        system("cls"); // clear console.
        header();
        cout << "   Please choose your option." << endl;
        cout << "   1 : LOGIN" << endl;
        cout << "   2 : REGISTER" << endl;
        cout << "   3 : INFO" << endl;
        cout << "   4 : QUIT" << endl;
        cout << "\n\n";
        cout << "   Option : "; cin >> option;

        switch(option)
        {
            case 1:
                cout << "   LOGIN INITIALIZED...\n";
                Sleep(500);
                loginScreen();
                break;

            case 2:
                cout << "   REGISTER INITIALIZED...\n";
                Sleep(500);
                registerScreen();
                break;

            case 3:
                cout << "   INFO INITIALIZED...\n";
                Sleep(500);
                infoScreen();
                break;
            
            case 4:
                cout << "   QUIT INITIALIZED...\n";
                Sleep(500);
                option = 4;
                exit(0);

            default:
                cout << "   INVALID OPTION.\n";
                cout << "   Please choose an option from 1 to 4.\n";
                Sleep(500);
                mainMenu();
                break;
        }
    } while (option != 4);
}

void Bank::loginScreen()
{       
    system("cls"); // clear console.
    header();
    cout << "   Please enter your username. " << endl << "  Username : "; cin >> unAttempt;
    if (authenticateUser(unAttempt))
    {
        cout << "   Please enter your password. " << endl << "  Password : "; cin >> pwAttempt;
        if (authenticatePassword(unAttempt, pwAttempt))
        {   
            authenticated = true;
            cout << "   Login Successful!" << endl;
            Sleep(500);
            bankMenuScreen();
        }
        else
        {
            cout << "   Wrong password. Please try another password." << endl;
            Sleep(500);
            loginScreen();
        }
    }
    else
    {
        cout << "   Username does not exist. Please try another username." << endl;
        cout << "\n\n";
        system("PAUSE");
        Sleep(500);
        mainMenu();
    }
}

void Bank::registerScreen()
{   
    system("cls"); // clear console.
    header();
    string un, pw;
    cout << "   Please enter an unused username. " << endl << " Username : "; cin >> un;
    cout << "   Please enter a password. " << endl << " Password : "; cin >> pw;

    if(createUser(un, pw)) // If successful.
    {
        cout << "   SUCCESS! User " << un << " created.\n";
        Sleep(500);
        mainMenu();
    }
    else
    {
        cout << "   Username already taken. Please try another username.\n";
        Sleep(500);
        registerScreen();
    }
}

void Bank::infoScreen()
{   

    system("cls");
    header();
    cout << "   Made by Gavin Loo / rawsashimi1604 " << endl;
    cout << "   Github Link : https://github.com/rawsashimi1604/" << endl;
    cout << "   Version : v0.02" << endl;
    cout << "   Version Made : 08-07-2021 " << endl;

    cout << " \n\n";
    cout << "   ABC Bank is a beginner banking system project I made to learn C++." << endl;
    cout << "   It allows the user to create a username and password, withdraw, deposit and transfer money." << endl;
    cout << "   Do enjoy and leave feedback on my github!." << endl;

    cout << "\n\n\n";

    system("PAUSE");
    mainMenu();
}

void Bank::bankMenuScreen()
{
    system("cls");
    header();

    int option;
    while(1)
    {
        cout << "   Please choose your option." << endl;
        cout << "   1 : BANK BALANCE" << endl;
        cout << "   2 : DEPOSIT MONEY" << endl;
        cout << "   3 : WITHDRAW MONEY" << endl;
        cout << "   4 : TRANSFER MONEY" << endl;
        cout << "   5 : LOGOUT" << endl;
        cout << "\n\n";
        cout << "   Option : "; cin >> option;

        switch(option)
        {
            case 1:
                cout << "   BANK BALANCE INITIALIZED...\n";
                Sleep(500);
                // bankbalance
                bankBalanceScreen();
                break;

            case 2:
                cout << "   DEPOSIT MONEY INITIALIZED...\n";
                Sleep(500);
                // despositmoney
                bankDepositScreen();
                break;
            
            case 3:
                cout << "   WITHDRAW MONEY INITIALIZED...\n";
                Sleep(500);
                // withdrawmoney
                bankWithdrawScreen();
                break;
            
            case 4:
                cout << "   TRANSFER MONEY INITIALIZED...\n";
                Sleep(500);
                // transfermoney
                bankTransferScreen();
                break;
            
            case 5:
                cout << "   LOGOUT INITIALIZED...\n"; // Go back to MAIN MENU
                Sleep(500);
                mainMenu();
                break;

            default:
                cout << "   INVALID OPTION.\n";
                cout << "   Please choose an option from 1 to 5.\n";
                Sleep(1000);
                bankMenuScreen();
                break;   
        }
    }
}

void Bank::bankBalanceScreen()
{
    system("cls");
    header();

    if (authenticated)
    {   
        string fileName = "data\\" + unAttempt + ".dat";
        string amt = readLine(fileName, 2);
        float Amt = stof(amt);

        stringstream stream;
        stream << fixed << setprecision(2) << Amt;
        amt = stream.str();

        cout << "   Bank Balance available : $" << amt;
        cout << "\n\n";

        system("PAUSE");
        bankMenuScreen();
    }
}

void Bank::bankWithdrawScreen()
{
    system("cls");
    header();

    if (authenticated)
    {   
        string userInput;
        float amt;
        cout << "   Please key in your withdrawal amount: $"; cin >> userInput;
        cout << "\n\n";

        if (userInput.find_first_not_of("1234567890.") != string::npos )
        {
            cout << "   Invalid input: " << userInput << endl;
            cout << "\n\n";
            system("PAUSE");
            bankWithdrawScreen();
        }

        amt = stof(userInput);
        if (amt <= 0)
        {
            cout << "   Please key in only positive values.\n";
        }

        if (withdraw(unAttempt, amt))
        {
            cout << "   Successfully withdrawed $" << amt << " from account.\n";
            Sleep(1000);
            bankMenuScreen();
        }
        else
        {
            cout << "   Not enough money to withdraw from account. Please check your balance and try again.\n";
            system("PAUSE");
            bankMenuScreen();
        }
    }
}

void Bank::bankDepositScreen()
{
    system("cls");
    header();
    if (authenticated)
    {   
        string userInput;
        float amt;
        cout << "   Please key in your deposit amount: $"; cin >> userInput;
        cout << "\n\n";

        if (userInput.find_first_not_of("1234567890.") != string::npos )
        {
            cout << "   Invalid input: " << userInput << endl;
            cout << "\n\n";
            system("PAUSE");
            bankDepositScreen();
        }

        amt = stof(userInput);
        if (amt <= 0)
        {
            cout << "   Please key in only positive values.\n";
        }

        if (deposit(unAttempt, amt))
        {
            cout << "   Successfully deposited $" << amt << " from account.\n";
            Sleep(1000);
            bankMenuScreen();
        }
    }
}

void Bank::bankTransferScreen()
{
    system("cls");
    header();
    if (authenticated)
    {   
        string amtInput;
        string toInput;
        float amt;
        cout << "   Please key in your transfer amount: $"; cin >> amtInput;
        cout << "\n";

        cout << "   Please key in your transfer recipient: "; cin >> toInput;
        cout << "\n";

        if (amtInput.find_first_not_of("1234567890.") != string::npos )
        {
            cout << "   Invalid input: " << amtInput << endl;
            cout << "\n\n";
            system("PAUSE");
            bankTransferScreen();
        }

        amt = stof(amtInput);
        if (amt <= 0)
        {
            cout << "   Please key in only positive values.\n";
        }

        if (transfer(unAttempt, toInput, amt))
        {   
            cout << "   Successfully transferred $" << amt << " from account to " << toInput << ".\n";
            Sleep(1000);
            bankMenuScreen();
        }
        else
        {
            cout << "   Please check your balance or recipient.\n";
            system("PAUSE");
            bankMenuScreen();
        }
    }
}

bool Bank::withdraw(const string username, float amount)
{   
    float initialBal;
    string fileName = "data\\" + username + ".dat";
    initialBal = stof(readLine(fileName, 2)); // Convert str to float.

    if (amount > initialBal) // FAIL, not enough money.
    {   
        return false;
    }
    else
    {   
        string buffer;
        ifstream currentFile(fileName);
        string bufferName = "data\\buffer.dat";
        ofstream bufferFile(bufferName);

        for (int i = 0; i < 2; i++) // Copy username and password
        {
            getline(currentFile, buffer);
            bufferFile << buffer + '\n';
        }

        getline(currentFile, buffer); // Put bal into buffer
        float newBal = initialBal - amount;
        string printBal = to_string(newBal);
        bufferFile << printBal + '\n';

        currentFile.close();
        bufferFile.close();
        remove(fileName.c_str());
        rename("data\\buffer.dat", fileName.c_str());
        
        return true;
    }
}

bool Bank::deposit(const string username, float amount)
{
    float initialBal;
    string fileName = "data\\" + username + ".dat";
    initialBal = stof(readLine(fileName, 2)); // Convert str to float.

    string buffer;
    ifstream currentFile(fileName);
    string bufferName = "data\\buffer.dat";
    ofstream bufferFile(bufferName);

    for (int i = 0; i < 2; i++) // Copy username and password
    {
        getline(currentFile, buffer);
        bufferFile << buffer + '\n';
    }

    getline(currentFile, buffer); // Put bal into buffer
    float newBal = initialBal + amount;
    string printBal = to_string(newBal);
    bufferFile << printBal + '\n';

    currentFile.close();
    bufferFile.close();
    remove(fileName.c_str());
    rename("data\\buffer.dat", fileName.c_str());
    
    return true;
}

bool Bank::transfer(const string from_user, const string to_user, float amount)
{
    // Check user exists
    string fileName = "data\\" + to_user + ".dat";
    ifstream isFile;
    isFile.open(fileName);
    if(isFile) // to_user Exists
    {   
        isFile.close();
        if (withdraw(from_user, amount)) // If withdraw success.
        {
            deposit(to_user, amount);
            return true;
        }
    }
    return false;
}

bool Bank::createUser(const string username, const string password)
{   
    string fileName = username + ".dat";
    string pathName = "data\\" + fileName;
    
    if (!ifstream(pathName)) // If file does not exist, create
    {   
        ofstream file(pathName, ios::out);
        file << username << endl; // un
        file << password << endl; // pw
        file << 0 << endl; // balance
        
        file.close();
        return true; // SUCCESS.
    }
    else
    {   
        return false; // username already exists. Thus do not create.
    }
}

bool Bank::authenticateUser(const string usernameAttempt)
{
    string fileName = usernameAttempt + ".dat";
    string pathName = "data\\" + fileName;
    
    if (ifstream(pathName)) // If user exists
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bank::authenticatePassword(const string usernameAttempt, const string passwordAttempt)
{
    string fileName = usernameAttempt + ".dat";
    string pathName = "data\\" + fileName;
    string password = readLine(pathName, 1);

    if (password == passwordAttempt)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

int main ()
{   
    Bank app;
    app.mainMenu();
    return 0;
}

