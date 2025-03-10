#include <iostream>
#include "../include/CaesarCipher.hpp"
#include <limits>
#include "../include/VigenereCipher.hpp"




int main(){
    int option {};
    std::string CiphersMenu = "CHOOSE A CIPHER YOU WANT TO USE \n"
"(1. CaesarCipher),(2. VigenereCipher)";
   
    std::cout<<CiphersMenu<<std::endl;
    while(1){
        std::cout<<"Choose your cipher, press '0' to end"<<std::endl;
        std::cin>>option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string file;
        std::string data;
        if (option == 0){
            std::cout<<"Exiting the program"<<std::endl;
            break;
        }
        switch(option){
            case 0:{
                std::cout<<"Exiting the program"<<std::endl;
                break;
            }

            case 1:{
                int shift {};
                
                std::cout<<"You choose Caesar Cipher"<<std::endl;
                std::cout<<"Set a shift"<<std::endl;
                std::cin>>shift;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Choose a filename to save your data"<<std::endl;
                std::getline(std::cin, file);
                kb::CaesarCipher x(shift,file);
                std::cout<<"Enter your data"<<std::endl;
                data = x.getDataFromUser();
                x.encryptData(data);
                x.writeToFile(x.encryptData(data),"C:\\Projects\\CipherLib-project");
                break;
            }
            case 2:{
                std::string key {};
                
                std::cout<<"You choose Vigenere Cipher"<<std::endl;
                std::cout<<"Set a key"<<std::endl;
                std::cin>>key;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Choose a filename to save your data"<<std::endl;
                std::getline(std::cin, file);
                kb::VigenereCipher x(key,file);
                std::cout<<"Enter your data"<<std::endl;
                data = x.getDataFromUser();
                x.encryptData(data);
                x.writeToFile(x.encryptData(data),"C:\\Projects\\CipherLib-project\\Data");
                break;
            }
            
            default:
                std::cout<<"Invalid option, please try again"<<std::endl;
                break;
        }
        return 0;
        
    }
    
}
