#include <iostream>
int main(){
    int randomnumber = std::rand()%100 + 1;
    int guess = 0;
    
    std::cout << "Guess a random number between 1 to 100 : ";
    
    while (true){
          std::cin >> guess;
          
          if (guess > randomnumber){
                    std::cout << "TOO HIGH! Try Again : ";
                    } else if (guess < randomnumber){
                           std::cout << "TOO LOW! Try Again : ";
                           } else{
                                  std::cout << "CONGRATS! You guessed the right number" << std::endl;
                                  break;
                                  }
                                  }
                                  return 0;
                                  }