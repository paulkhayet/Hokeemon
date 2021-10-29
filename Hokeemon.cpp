//Hw6.cpp
//Paul Khayet, CISP 400
//12/7/2019
// A simple game where you take care of an animal called a "Hokeemon". Try not to let your hokeemon die!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cassert>
using namespace std; 

int happy = 0; 
int Time = 0; 
bool stop = false; 

void takeInput(char k); 
void passtime(); 
void checkBoredom(); 

// Specification C2 - Virtual Class Creature
class creature{
 public:
  int boredom; 
  int hunger; 
  string name; 

  virtual void feed() = 0; 
}; 


// Specification B3 - Second Child Class
class tinyguy: public creature{
  public:
    void feed(){
      hunger--; 
    }

    void dance(){
      cout << "OMG hes dancing look at him :O" << endl; 
    }
};


// Specification C3 - Child Class
class hokeemon: public creature{
public:


  hokeemon(){
      boredom = rand() % 6; 
      hunger = rand() % 6; 
    }

  // Specification A2 - Copy Constructor/Assignment Operator
  hokeemon(const hokeemon &p2){
    name = p2.name; 
    hunger = p2.hunger; 
    boredom = p2.boredom; 
  }

    //Returns the hunger level of your hokeemon
    int getHunger(){
      return hunger; 
    }

    //Returns the boredom level of the hokeemon
    int getBoredom(){
      return boredom; 
    }

    void addHunger(int h){
      hunger = hunger + h; 
    }

    void addBoredom(int b){
      boredom = boredom + b; 
    }

    //Play with the Hokeemon
    void play(){
      cout << "You have played with "<< name << "!" << endl; 
      if (boredom <= 4){
        boredom = 0; 
      }
      else{
        boredom = boredom - 4; 
      }
      
    }

    void feed(){
      cout << "You have fed "<< name << "!" << endl; 
      if (hunger <= 4){
        hunger = 0; 
      }
      else{
        hunger = hunger -4; 
      }
    }

    bool isAlive(){
      if (hunger < 10 && boredom < 20){
        return true; 
      }
      else {
        return false; 
      }
      // Specification A3 - Code Protection
      assert(hunger >= 0); 
    }

    void listen(){
      cout << "Your Hokeemon's stats " << endl; 
      cout << "---------------------" << endl; 
      cout << "Hunger: " << hunger << endl; 
      cout << "Boredom: " << boredom << endl; 
    }

    //Specification B2 - Moods
    int mood(){
      if (boredom > 15){
        return 1; 
      }
      else if (boredom <= 14 && boredom >= 10){
        return 2; 
      }
      else if (boredom <= 9 && boredom >=5){
        return 3; 
      }
      else {
        return 4; 
      }
    }

    void giveName(string n){
      name = n; 
    }

    string getName(){
      return name; 
    }
}; 

 hokeemon bob;  

int main() {
  cout << "Welcome to hokeemon, in this program u take care of a an animal called a hokeemon." << endl;
  cout << "Everytime you do an action, time will pass and your hokeemons boredom and hunger will increase by one." << endl; 
  cout << "If your hokeemon's hunger reaches 10 it will die." << endl; 
  cout << "If your hokeemon's boredom reaches 20 it will go insane then probably die." << endl; 
  cout << "Try and not kill your hokeemon, good luck!" << endl << endl; 

  // Specification A1 - Critter Name
  string temp;
  cout << "Lets name your Hokeemon, what would you like to name it?: " << endl; 
  cin >> temp; 
  bob.giveName(temp); 

  cout << "Wow " << bob.getName() << " is a cool name!." << endl; 


  while(stop == false){
    char input; 
    cout << "\nWhat would you like to do?" << endl; 
    cout << "1. Listen (Hokeemon tells you its hunger and boredom levels)" << endl; 
    cout << "2. Play (Decreases Boredom by 4)" << endl; 
    cout << "3. Feed (Decreases Hunger by 4)" << endl; 

    cin >> input; 

    takeInput(input); 
    

    checkBoredom(); 
    passtime(); 
    if (bob.isAlive() == false){
      cout << endl <<"You are a horrible owner and your Hokeemon is dead." << endl; 
      cout << "G A M E  O V E R!" << endl; 
      cout << bob.getName() << "'s final stats:" << endl; 
      cout << "---------------------" << endl; 
      cout << "Hunger: " << bob.getHunger() << endl; 
      cout << "Boredom: " << bob.getBoredom() << endl; 
      cout << "Turns where " << bob.getName() << " was happy: " << happy << endl; 
                                                   
      stop = true; 
    }
  }

  

}

// Specification C1 - PassTime()
void passtime(){
    int p = 1; 
    bob.addHunger(p); 
    bob.addBoredom(p); 

    Time++; 
  }

void checkBoredom(){
  if (bob.mood() == 4){
    happy++; 
  }
}

void takeInput(char k){
  if (k == '1'){
      bob.listen(); 
    }
    else if (k == '2'){
      bob.play(); 
    }
    else if (k == '3'){
      bob.feed(); 
    }
    // Specification B1 - Validate Input
    else{
      cout << "You did not put in a correct number, please input only one digit." << endl;
      char t; 
      cout << "\nWhat would you like to do?" << endl; 
      cout << "1. Listen (Hokeemon tells you its hunger and boredom levels)" << endl; 
      cout << "2. Play (Decreases Boredom by 4)" << endl; 
      cout << "3. Feed (Decreases Hunger by 4)" << endl;
      cin >> t; 
      takeInput(t); 
    }
}