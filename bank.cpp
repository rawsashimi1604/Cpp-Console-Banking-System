#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

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

        // OTHER FUNCTIONS
        bool createUser(const string username, const string password);
        bool authenticateUser(const string usernameAttempt);
        bool authenticatePassword(const string usernameAttempt, const string passwordAttempt);
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
                Sleep(1000);
                mainMenu();
                break;
        }
    } while (option != 4);
}

void Bank::loginScreen()
{       
    system("cls"); // clear console.
    header();
    cout << "   Please enter your username. " << endl << "Username : "; cin >> unAttempt;
    if (authenticateUser(unAttempt))
    {
        cout << "   Please enter your password. " << endl << "Password : "; cin >> pwAttempt;
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
        Sleep(500);
        loginScreen();
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
        cout << "   SUCCESS! User " << un << "created.\n";
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
    cout << "   Version : v0.01" << endl;
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
        cout << "   5 : QUIT" << endl;
        cout << "\n\n";
        cout << "   Option : "; cin >> option;

        switch(option)
        {
            case 1:
                cout << "   BANK BALANCE INITIALIZED...\n";
                Sleep(500);
                // bankbalance
                bankMenuScreen();
                break;

            case 2:
                cout << "   DEPOSIT MONEY INITIALIZED...\n";
                Sleep(500);
                // despositmoney
                bankMenuScreen();
                break;
            
            case 3:
                cout << "   WITHDRAW MONEY INITIALIZED...\n";
                Sleep(500);
                // withdrawmoney
                bankMenuScreen();
                break;
            
            case 4:
                cout << "   TRANSFER MONEY INITIALIZED...\n";
                Sleep(500);
                // transfermoney
                bankMenuScreen();
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

