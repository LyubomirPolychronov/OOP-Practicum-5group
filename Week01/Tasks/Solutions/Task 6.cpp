#include <iostream>

const int MAX_SIZE_OF_NAME = 100;
const int MAX_SIZE_OF_POS = 50;

//enum class position {
//    SoftwareEngineer;
//};

bool isPositionValid(const char* str) {
    if (strcmp(str, "Software Engineer") == 0) return true;
    if (strcmp(str, "Senior Software Engineer") == 0) return true;
    if (strcmp(str, "Engineer Manager") == 0) return true;
    if (strcmp(str, "Lead Software Engineer") == 0) return true;
    return false;
}


int findLenOfStr(const char* str) {
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void copyString(const char* src, char* dest) {
    int len = findLenOfStr(src);
    if (len > MAX_SIZE_OF_POS)
    {
        return;
    }
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

struct Employee {
    char name[MAX_SIZE_OF_NAME];
    char position[MAX_SIZE_OF_POS];
    float salary;
    int assessment;

    void initialise() {
        std::cout << "Enter name: " ;
        std::cin.getline(name, MAX_SIZE_OF_NAME);
      
        std::cout << "Enter position: ";
        std::cin.getline(position, MAX_SIZE_OF_POS);
        while (!isPositionValid(position))
        {
            std::cout << "Invalid position, try again: ";
            std::cin.getline(position, MAX_SIZE_OF_POS);
        
        }
        std::cout << "Enter salary: ";
        std::cin >> salary;
        
        std::cout << "Enter assessment: ";
        std::cin >> assessment;

        std::cin.ignore();
    }

    void printInfo() {
        std::cout << "Name of the employee: " << name << " ,who is on position: " << position << " ,with assessment: " << assessment << std::endl;
    }

    void changeSalary(float nextSalary) {
        if (nextSalary > 0)
        {
           salary = nextSalary;
        }
    }

    void changeAssessment(int nextAssessment) {
        assessment = nextAssessment;
    }

    void changePosition(const char* nextPosition) {
        if (!isPositionValid(nextPosition))
        {
            std::cout << "New position is invalid.";
            return;
        }
        copyString(nextPosition, position);
    }
};

int main()
{
    Employee a;
    a.initialise();
    a.printInfo();
   
    a.changeAssessment(6);
    a.changePosition("Senior Software Engineer");
    a.changeSalary(3.5500);
    
    a.printInfo();
}
