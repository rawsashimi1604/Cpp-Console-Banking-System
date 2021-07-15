# C-Console-Banking-System
Hey guys :blush: ! This is a simple banking console system I made using C++. I learnt the basics on W3Schools and various youtube tutorials and then decided to try to create a
banking system to apply what I have learnt on a project. I also learnt Object Oriented Programming on C++ through this project. The font art was made using [ASCII Art](https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20)
.

## How does it work?
Simply run main.exe and use the program :relaxed:! Enter options as stated by the instructions.

## Bank Class
```cpp
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
```

Firstly, I started out creating the menu functions. The menu functions allow us to cout to console, and display instructions and frontend to the user.
To authenticate the user, I created a registration and login feature. After registering the user, the list of users and their data are stored in "/data/<user_name>" as .dat files.

Here is the content of each .dat file.
```
<username>
<password>
<balance>
```

Then, I created the backend functions to withdraw, deposit and transfer money. They search the .dat files to edit their values.
