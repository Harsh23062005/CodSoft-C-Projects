#include <iostream>

int main(){
    double Number1, Number2;
    char operation;

    std::cout << "Enter the First Number: ";
    std::cin >> Number1;
    
    std::cout << "Enter the Second Number: ";
    std::cin >> Number2;
    
    std::cout << "Enter the operation which you want to perform: ";
    std::cin >> operation;
    
    switch (operation){
        case '+':
        std::cout << "Sum: " << Number1 + Number2 << std::endl;
        break;
        
        case '-':
        std::cout << "Sub: " << Number1 - Number2 << std::endl;
        break;
        
        case '*':
        std::cout << "Mul: " << Number1 * Number2 << std::endl;
        break;
        
        case '/':
        if(Number2 !=0){
            std::cout << "Div: " << Number1/Number2 << std::endl;
        }else{
            std::cout << "Infinity" << std::endl;
        }
        break;
        
        default:
        std::cout << "Invalid Operation" << std::endl;
        break;
        }
    
    return 0;
}