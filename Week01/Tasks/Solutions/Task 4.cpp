#include <iostream>

const int MAX_SIZE_OF_NAME = 50;
const int MAX_SIZE_OF_PASSWORD = 30;

int findLenOfString(const char* str) {
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

struct Student {
    char name[MAX_SIZE_OF_NAME];
    int facultyNumber;
    char password[MAX_SIZE_OF_PASSWORD];
   
    bool checkPassword() const {
        char inputPassword[MAX_SIZE_OF_PASSWORD];
        std::cin >> inputPassword;
        int lenOfNew = findLenOfString(inputPassword);
        int lenOfOld = findLenOfString(password);
        if (lenOfNew != lenOfOld)
        {
            std::cout << "Password is incorrect. ";
            return false;
        }
        for (int i = 0; i < lenOfNew; i++)
        {
            if (inputPassword[i] != password[i])
            {
                std::cout << "Password is incorrect. ";
                return false;
            }
        }
        std::cout << "Access granted. ";
        return true;
    }

    void printInfoAboutStudent() const {
        std::cout << "This is " << name << " with faculty number " << facultyNumber;
    }

    void createNewPassword() {
        if (!checkPassword())
        {
            std::cout << "Old password is incorrect.";
            return;
        }
        char newPassword[MAX_SIZE_OF_PASSWORD];
        std::cin >> newPassword;
        int len = findLenOfString(newPassword);
        for (int i = 0; i < len; i++)
        {
            password[i] = newPassword[i];
        }
        password[len] = '\0';
        std::cout << "Password is changed successfully." << " Your new password is " << password;

    }
};

int main()
{
    Student a;
    std::cin.getline(a.name, MAX_SIZE_OF_NAME);
    std::cin >> a.facultyNumber >> a.password;
   // a.checkPassword("Hello");
    //a.printInfoAboutStudent();
    a.createNewPassword();
    
}
