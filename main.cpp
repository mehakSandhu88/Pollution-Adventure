#include <chrono>  // For time-related operations
#include <cstdlib> // For general-purpose functions
#include <ctime> // For manipulating time and date
#include <iostream> // For standard input/output operations
#include <string> // For string manipulation
#include <thread> // For multi-threading support
#include <vector> // For dynamic arrays


using namespace std;

//color codes 
#define RESET   "\033[0m"  
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;5;208m"

 
void chooseLocation(); // Function to choose a location

int pollutionLevel = 0; // Initialize pollution level variable to 0

// Function to print ASCII art
void printAsciiArt(const string& art) {
    cout << art <<endl; // command in the standard library 
  /*The printAsciiArt function is a C++ function that takes a const string& argument (a reference to a string object whose contents will not be changed) named art. The function
simply prints the art string to the console using the cout statement. */
}

// Structure to represent a location
struct Location {
    string name;
    void (*visitFunction)();
/*The Location struct is a C++ struct that has two members: a string name and a function pointer visitFunction.
The name member is a string that stores the name of the location. The visitFunction member is a function pointer
that points to a function that takes no arguments and returns nothing. This function is intended to be called when
someone visits the location.

In the main function, we call the visitFunction of each Location object to simulate visiting the locations.
When we run the program, we get the following output
*/
};

// Function to clear the screen
void clearScreen() {
  cout << "\033[2J\033[H"; // Clear screen in Replit
  /*The code cout << "\033[2J\033[H" is a C++ command that clears the terminal screen. It does this by sending a
special character sequence to the terminal emulator. The sequence consists of two parts: \033[2J and \033[H. 
The first part, \033[2J, is an escape sequence that instructs the terminal to clear the screen. The 2 in the
sequence means to clear the entire screen.
The second part, \033[H, is another escape sequence that instructs the terminal to move the cursor to the top-left
corner of the screen. The H in the sequence stands for "home".*/
}

// Function to wait for the Enter key to be pressed
void waitForEnter() {
  cin.ignore(); // Wait for Enter key
  /*The cin.ignore() function takes two optional arguments: n and delimiter. If n is specified, it discards the
next n characters in the input buffer. If delimiter is specified, it discards all characters in the input buffer
up to and including the next occurrence of the delimiter character.*/
}

// Function to print text with a delay
void printDelayed(const string &text, int milliseconds) {
  //for each loop type of for loop
  for (char c : text) {
    //This line initiates a loop that iterates over each character in the string "text." It declares a new variable "c" of type "char" that represents each character in the string.
    cout << c << flush; // Flush the output stream
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
  }
  /*The printDelayed function takes a string text and an integer milliseconds as arguments. It then iterates over
each character in the text string and prints it to the console using cout. The flush method is called on the
output stream to ensure that the character is immediately printed to the console.

After printing each character, the function waits for the specified number of milliseconds using the
this_thread::sleep_for function. The sleep_for function is a command in the <chrono> library 
This creates a delay between each character being printed.

The function continues this process until all characters in the text string have been printed.*/
}

// Function for the introduction section
void introduction() {
  clearScreen();
  cout << RED << R"(


.-=~=-.                                                                                                                                                                   .-=~=-.
(__  _)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.--._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.--._.-=-._.-=-._.-=-._.-=-._.-=-._(__  _)
( _ __)                                                                                                                                                                   ( _ __)
(__  _)                                                                                                                                                                   (__  _)
(_ ___)                                                                                                                                                                   (_ ___)
(__  _)                                              ██████╗  ██████╗ ██╗     ██╗     ██╗   ██╗████████╗██╗ ██████╗ ███╗   ██╗                                            (__  _)
( _ __)                                              ██╔══██╗██╔═══██╗██║     ██║     ██║   ██║╚══██╔══╝██║██╔═══██╗████╗  ██║                                            ( _ __)
(__  _)                                              ██████╔╝██║   ██║██║     ██║     ██║   ██║   ██║   ██║██║   ██║██╔██╗ ██║                                            (__  _)
(_ ___)                                              ██╔═══╝ ██║   ██║██║     ██║     ██║   ██║   ██║   ██║██║   ██║██║╚██╗██║                                            (_ ___)
(__  _)                                              ██║     ╚██████╔╝███████╗███████╗╚██████╔╝   ██║   ██║╚██████╔╝██║ ╚████║                                            (__  _)
( _ __)                                              ╚═╝      ╚═════╝ ╚══════╝╚══════╝ ╚═════╝    ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝                                            ( _ __)
(__  _)                                                                                                                                                                   (__  _)
(_ ___)                                               █████╗ ██████╗ ██╗   ██╗███████╗███╗   ██╗████████╗██╗   ██╗██████╗ ███████╗                                        (_ ___)
(__  _)                                              ██╔══██╗██╔══██╗██║   ██║██╔════╝████╗  ██║╚══██╔══╝██║   ██║██╔══██╗██╔════╝                                        (__  _)
( _ __)                                              ███████║██║  ██║██║   ██║█████╗  ██╔██╗ ██║   ██║   ██║   ██║██████╔╝█████╗                                          ( _ __)
(__  _)                                              ██╔══██║██║  ██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║   ██║   ██║   ██║██╔══██╗██╔══╝                                          (__  _)
(_ ___)                                              ██║  ██║██████╔╝ ╚████╔╝ ███████╗██║ ╚████║   ██║   ╚██████╔╝██║  ██║███████╗                                        (_ ___)
(__  _)                                              ╚═╝  ╚═╝╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═══╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝                                        (__  _)
( _ __)                                                                                                                                                                   ( _ __)
(__  _)                  .:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:.                  (__  _)
( _ __)                                                                                                                                                                   ( _ __)
(__  _)                                                                                                                                                                   (__  _)
(_ ___)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.(___       _       _       _       _       _       _       _       ___)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.(_ ___)
`-._.-'                                              (__  _) ( __ _) (__  _) (__ _ ) `-._.-' ( _ __) (_  __) (_ __ ) (_  __)                                              `-._.-'
                                                     ( _ __) (_  __) (__ __) `-._.-'         `-._.-' (__ __) (__  _) (__ _ )
                                                     (__  _) (_ _ _) `-._.-'                         `-._.-' (_ _ _) (_  __)
                                                     (_ ___) `-._.-'                                         `-._.-' (___ _)
                                                     `-._.-'                                                         `-._.-'
  )"<< RESET <<endl;
    // Introduction text displayed to the player
  string introductionText[] = {
      "You, a young traveler, have arrived in South Shilmol, a town filled "
      "with wonders and mysteries. Guided by your Oompa Loompa companion, you "
      "embark on a journey to explore various locations and uncover the "
      "secrets of this enchanting realm.",
      "",
      "Press enter to begin your journey...",
      "",
      "   ",
      ""};
  /*Each string in the array represents a line of text in an introduction to a game or story. The first string describes the setting and the goal of the journey, while the remaining strings provide instructions to the player or reader.

The "" strings are empty strings that are used to add blank lines between the text. The last string in the array is an empty string that is used to terminate the array.

The introductionText array can be accessed using its index to retrieve a specific string. For example, introductionText[0] returns the first string in the array, which is "You, a young traveler, have arrived in South Shilmol, a town filled with wonders and mysteries. Guided by your Oompa Loompa companion, you embark on a journey to explore various locations and uncover the secrets of this enchanting realm."

If you want to print the entire introduction text, you can use a loop to iterate over the array and print each string on a new line.

*/
  // Print the introduction text with a delay
  //for each loop This line initiates a loop that iterates over each element in the collection introductionText. In this case, introductionText is a collection of strings. The loop variable text is declared as a reference to a const string, meaning it refers to each string element in introductionText without allowing modification.
  for (const string &text : introductionText) {
    printDelayed(text, 30);
    cout << endl;
  }
waitForEnter(); // Wait for the player to press Enter
}

void continueExploring() {
  clearScreen();
  cout << endl;
  printDelayed("Do you want to continue exploring? (Y/N):", 40); // Prompt user to continue exploring
  cout << endl;
  char choice;
  //In programming, a char is a data type that represents a single character. It can store characters like letters, digits, symbols, or even special control characters like newline or tab. By declaring char choice;, you are creating a variable choice that can hold a single character value.
  cin >> choice;
//conditional statement 
  if (choice == 'Y' || choice == 'y') { // If user chooses to continue
    clearScreen();
    chooseLocation(); // Go back to chooseLocation() function to select next location
  } else if (choice == 'N' || choice == 'n') { // If user chooses to end exploration
    cout << endl;
    clearScreen();
    waitForEnter();
    cout << MAGENTA << R"(
   ___                       _    _        _  _          
  / __|    ___     ___    __| |  | |__    | || |   ___   
 | (_ |   / _ \   / _ \  / _` |  | '_ \    \_, |  / -_)  
  \___|   \___/   \___/  \__,_|  |_.__/   _|__/   \___|  
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_| """"|_|"""""| 
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
    
    )"<< RESET <<endl;
    printDelayed("You decide to end your exploration.", 40); // Display end message
    cout << endl;
  } else {  // If user enters an invalid choice
    cout << endl;
    clearScreen();
    waitForEnter();
    printDelayed("You decide to end your exploration.", 40); // Display end message
    cout << endl; 
    continueExploring(); // Recursively call continueExploring() function to get valid choice
  } 
}

void visitForest() { // location-specific function, called from the gameLoop()
                     // function and provide different scenarios and information
                     // related to pollution in each location.
  
// Clear the screen
clearScreen();
  // Print forest ASCII art
  
cout << GREEN << R"(
            ,@@@@@@@,                                 ,@@@@@@@,                               ,@@@@@@@,                              ,@@@@@@@,
    ,,,.   ,@@@@@@/@@,  .oo8888o.             ,,,.   ,@@@@@@/@@,  .oo8888o.           ,,,.   ,@@@@@@/@@,  .oo8888o.          ,,,.   ,@@@@@@/@@,  .oo8888o.
 ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o         ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o       ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o      ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'       ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'     ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'    ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
%&&%&%&/%&&%@@\@@/ /@@@88888\88888'       %&&%&%&/%&&%@@\@@/ /@@@88888\88888'     %&&%&%&/%&&%@@\@@/ /@@@88888\88888'    %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
%&&%/ %&%%&&@@\ V /@@' `88\8 `/88'        %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'      %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'     %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
`&%\ ` /%&'    |.|        \ '|8'          `&%\ ` /%&'    |.|        \ '|8'        `&%\ ` /%&'    |.|        \ '|8'       `&%\ ` /%&'    |.|        \ '|8'
    |o|        | |         | |                |o|        | |         | |              |o|        | |         | |             |o|        | |         | |
    |.|        | |         | |                |.|        | |         | |              |.|        | |         | |             |.|        | |         | |      
 \\/ ._\//_/__/  ,\_//__\\/.  \_//__/______\\/ ._\//_/__/  ,\_//__\\/.  \_//__/____\\/ ._\//_/__/  ,\_//__\\/.  \_________\\/ ._\//_/__/  ,\_//__\\/.  \_//___.___.____.__.





  
)" << RESET << endl;
  cout << endl;
  
  printDelayed("You are in a beautiful forest. As you walk along, you notice a "
               "stream with discolored water.",
               40);
  cout << endl;
    // Prompt user to choose an action
  printDelayed("What would you like to do?", 40);
  cout << endl;
  printDelayed("1. Investigate the water pollution", 40);
  cout << endl;
  printDelayed("2. Continue exploring the forest", 40);
  cout << endl;
  printDelayed(
      "3. Help out the ecosystem and pick up all the garbage you see as "
      "best as you can!",
      40);
  cout << endl;
  printDelayed("4. Do nothing and instead eat a sandhwich and relax", 40);
  cout << endl;
  printDelayed("5. You realize you've been carrying alot of wrapers on you and "
               "decided to let them join the rest of the garbage in the water!",
               40);
  cout << endl;
  cout << endl;

  int choice;
  cin >> choice;
clearScreen();
  /*A switch statement in C++ is a control structure that allows you to check the value of a variable and execute different code blocks based on its value, similar to a multiple choice decision. It provides a concise way to handle multiple possible outcomes without the need for multiple if-else statements.
  The default case prints an error message if the player's choice is invalid and prompts the player to try again by recusrivly calling itself again.

*/
  switch (choice) { // choice = variable (store user input)
  case 1:
  //operates based on the value of the variable choice. The switch statement allows you to perform different actions based on the value of a variable, type of conditional 
      // Scenario 1: Investigate the water pollution
    cout << endl;
    clearScreen();
    printDelayed(
        "You investigate the water pollution and find out that it's caused "
        "by industrial waste being dumped into the stream.",
        40);
    cout << endl;
    printDelayed("This pollution is harmful to the aquatic life and can have "
                 "long-term effects on the ecosystem.",
                 40);
    cout << endl;
    printDelayed(
        "It is toxic water that cannot be drunk or used for essential "
        "purposes like agriculture, and which also causes diseases like "
        "diarrhoea, cholera, dysentery, typhoid and poliomyelitis that "
        "kill more than 500,000 people worldwide every year",
        40);
    cout << endl;
    printDelayed(
        "Destruction of biodiversity. Water pollution depletes aquatic "
        "ecosystems and triggers unbridled proliferation of phytoplankton "
        "in lakes — eutrophication",
        40);
    cout << endl;
    printDelayed(
        "Contamination of the food chain. Fishing in polluted waters and "
        "the use of waste water for livestock farming and agriculture can "
        "introduce toxins into foods which are harmful to our health when "
        "eaten.",
        40);
    cout << endl;
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
        waitForEnter();
    continueExploring();
    break;
  case 2:
    // Scenario 2: Continue exploring the forest
    clearScreen();
    cout << endl;
    printDelayed(
        "You continue exploring the forest and enjoy the serene beauty of "
        "nature. But you can't help feel like you should've done something "
        "to help. As you walk around more you notice that strange animals "
        "like deformed frogs, dead fishes floating on the surface of the "
        "water and dying trees.",
        40);
    cout << endl;
    printDelayed("These are all effects of water pollution.", 40);
    cout << endl;
    cout << endl;
    pollutionLevel += 10; //add 10 to pollution level
    cout << endl;
        waitForEnter();
    continueExploring();
    break;
  case 3:
     // Scenario 3: Help out the ecosystem and pick up garbage
clearScreen();
    cout << endl;
    printDelayed(
        "You decided to help out the forest by picking up litter from the "
        "water, not only are you feeling better by dong something to help "
        "out the ecosystem but the forest is feeling better too!",
        40);

    cout << endl;
    printDelayed(
        "By participating in organized beach or river cleanups, you can "
        "help restore these precious environments, safeguard wildlife, and "
        "preserve the beauty of our natural landscapes",
        40);
    cout << endl;
    printDelayed(
        "Every piece of trash that is taken away to be recycled or "
        "deposited in a landfill means there is one less dangerous item "
        "for birds, turtles or whales to swallow. Cleanups also restore "
        "these creatures' habitats.",
        40);
    cout << endl;
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
        waitForEnter();
    continueExploring();
    break;
  case 4:
    // Scenario 4: Do nothing and eat a sandwich
    clearScreen();
    cout << endl;
    printDelayed(
        "You decided to do nothing and be a bystander to all the litter "
        "and pollution affecting the water",
        40);

    cout << endl;
    printDelayed(
        "The bystander effect takes action when people think someone else "
        "will clean it up for them so they don't worry about it. Or the "
        "phenomenon that a person doesn't think their one act of littering "
        "will affect the earth when in reality, if everyone thought that "
        "we would be swimming in trash everyday.",
        40);
    cout << endl;
    printDelayed("And yet you chose to do nothing when you had the power to "
                 "possible save innocent lives today",
                 40);
    cout << endl;
    pollutionLevel += 10;
    cout << endl;
        waitForEnter();
    continueExploring();
    break;
  case 5:
     // Scenario 5: Adding more garbage to the water
clearScreen();
    cout << endl;
    printDelayed(
        "You chose to contribute to the litter and harm the wildlife and "
        "ecosystem even more out of all things.",
        40);
    cout << endl;
    printDelayed(
        "Animals are innocent victims affected by litter every day. "
        "Researchers estimate that over one million animals die each year "
        "after ingesting, or becoming entrapped in, improperly disposed "
        "trash. Plastic litter is the most common killer of animals and "
        "marine animals are the most notably affected. Each year over "
        "100,000 dolphins, fish, whales, turtles and more drown after "
        "becoming entangled in or digesting plastic litter.",
        40);
    cout << endl;
    printDelayed(
        "And you are one of those who have contributed to the death of "
        "these innocent animals when you had the power to help them.",
        40);
    cout << endl;
    pollutionLevel += 10; // add more to pollution level 
    cout << endl;
        waitForEnter();
    continueExploring();
    break;
  default: //invalid choice 
    clearScreen();
    cout << endl;
    printDelayed("", 40);
    cout << endl;
    cout << "Invalid choice. Please try again." << endl;
    cout << endl;
        waitForEnter();
    visitForest();
    break;
  }
}

void visitCity() {
  clearScreen();
  //print ascii art
  cout << YELLOW << R"(
                                       .
              . .                     -:-             .  .  .
            .'.:,'.        .  .  .     ' .           . \ | / .
            .'.;.`.       ._. ! ._.       \          .__\:/__.
             `,:.'         ._\!/_.                     .';`.      . ' .
             ,'             . ! .        ,.,      ..======..       .:.
            ,                 .         ._!_.     ||::: : | .        ',
     .====.,                  .           ;  .~.===: : : :|   ..===.
     |.::'||      .=====.,    ..=======.~,   |"|: :|::::::|   ||:::|=====|
  ___| :::|!__.,  |:::::|!_,   |: :: ::|"|l_l|"|:: |:;;:::|___!| ::|: : :|
 |: :|::: |:: |!__|; :: |: |===::: :: :|"||_||"| : |: :: :|: : |:: |:::::|
 |:::| _::|: :|:::|:===:|::|:::|:===F=:|"!/|\!"|::F|:====:|::_:|: :|::__:|
 !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]!
 -----------------------------------"---''''```---"-----------------------
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ _
                                     |=    :    =|                Valkyrie
_____________________________________L___________J________________________
--------------------------------------------------------------------------

  
  )" << RESET <<endl;
  cout << endl;
  printDelayed(
      "You arrive at a bustling city. The air feels heavy, and you notice "
      "a layer of smog hanging over the buildings.",
      40);
  waitForEnter();
  cout << endl;
  //prompt options
  printDelayed("What would you like to do?", 40);
  cout << endl;
  printDelayed("1. Learn about air pollution", 40);
  cout << endl;
  printDelayed("2. Explore the city", 40);
  cout << endl;
  printDelayed(
      "3. Take a car to your next location, this one isn't interesting", 40);
  cout << endl;
  printDelayed("4. Plant some trees", 40);
  cout << endl;
  int choice;
  cin >> choice;

  switch (choice) { // Conditional statements are used to make decisions based
                    // on different conditions (switch)
  case 1:
//learn 
clearScreen();
    cout << endl;
    printDelayed(
        " Air pollution is contamination of the indoor or outdoor "
        "environment by any chemical, physical or biological agent that "
        "modifies the natural characteristics of the atmosphere.Household "
        "combustion devices, motor vehicles, industrial facilities and "
        "forest fires are common sources of air pollution. Pollutants of "
        "major public health concern include particulate matter, carbon "
        "monoxide, ozone, nitrogen dioxide and sulfur dioxide.",
        40);
    cout << endl;
    printDelayed(
        " Outdoor and indoor air pollution cause respiratory and other "
        "diseases and are important sources of morbidity and mortality. "
        "Air pollution is caused by various factors such as vehicle "
        "emissions, industrial activities, and burning of fossil fuels.",
        40);
    cout << endl;
    printDelayed(
        "Air quality is closely linked to the earth’s climate and "
        "ecosystems globally. Many of the drivers of air pollution (i.e. "
        "combustion of fossil fuels) are also sources of greenhouse gas "
        "emissions. Policies to reduce air pollution, therefore, offer a "
        "win-win strategy for both climate and health, lowering the burden "
        "of disease attributable to air pollution, as well as contributing "
        "to the near- and long-term mitigation of climate change.",
        40);
    cout << endl;
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 2:
    //explore
clearScreen();
    cout << endl;
    printDelayed(
        "You explore the city and witness the bustling life, but you can't "
        "ignore the impact of pollution on the urban environment.",
        40);
    cout << endl;
    printDelayed(
        "Automobile exhaust produces elevated lead levels in urban air. "
        "Large volumes of uncollected waste create multiple health "
        "hazards. Urban development can magnify the risk of environmental "
        "hazards such as flash flooding. Pollution and physical barriers "
        "to root growth promote loss of urban tree cover.",
        40);
    cout << endl;
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 3:
    //next location
clearScreen();
    cout << endl;
    printDelayed(
        "You've been feeling pretty tired after walking for so long so you "
        "decided to take the car to your next location.",
        40);
    cout << endl;
    printDelayed(
        "Mobile, stationary, area, and natural sources all emit pollution "
        "into the air. Mobile sources account for more than half of all "
        "the air pollution and the primary mobile source of air pollution "
        "is the automobile",
        40);
    cout << endl;
    printDelayed(
        "Vehicular pollutants can be felt and even seen as haze and smog "
        "when walking along the sidewalk. This ready visibility encourages "
        "an awareness of outdoor air pollution. For decades, research has "
        "focused on the air quality outside of vehicles. Research is "
        "beginning to indicate that the air inside vehicle interiors can be "
        "a serious health concern, for causes ranging from elevated heart "
        "rate and blood pressure to increased risk of driver drowsiness.",
        40);
    cout << endl;
    printDelayed(
        "Follow these Tips Every Day to Reduce Pollution:                  "
        "   1. Conserve energy - at home, at work, everywhere.  "
        "   2. Look for the ENERGY STAR label when buying home or office "
        "equipment. "
        "   3. Carpool, use public transportation, bike, or walk whenever "
        "possible"
        "   4. Follow gasoline refueling instructions for efficient vapor "
        "recovery, being careful not to spill fuel and                always "
        "tightening your gas cap securely.                        "
        "   5. Consider purchasing portable gasoline containers labeled "
        "“spill-proof,” where available.        "
        "   6. Keep car, boat, and other engines properly tuned. "
        "   7. Be sure your tires are properly inflated.      "
        "   8. Use environmentally safe paints and cleaning products whenever "
        "possible. "
        "   9. Mulch or compost leaves and yard waste."
        "   10. Consider using gas logs instead of wood.",
        40);
    cout << endl;

    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 4:
    //plant tree
clearScreen();
    cout << endl;

    printDelayed("You decided to plant trees and help out the enviornment!",
                 40);
    cout << endl;
    printDelayed(
        "Do trees help with air pollution? Absolutely. According to the US "
        "National Park Service, planting trees helps to improve air "
        "quality through 3 key impacts: Altering the concentration of "
        "pollutants by reducing air temperatures. Reducing energy "
        "consumption in buildings (particularly for temperature control), "
        "which in turn reduces the consumption of energy from polluting "
        "sources. Directly removing pollutants from the air. These impacts "
        "combine to create powerful, lasting effects for the the "
        "communities where trees are planted.",
        40);
    cout << endl;
    printDelayed(
        "Trees reduce temperatures and mitigate the heat-island effect "
        "through evapotranspiration; they sequester the emission of "
        "greenhouse gasses by removing carbon dioxide from the atmosphere; "
        "they remove air pollutants by trapping particulate matter in "
        "their leaves, needles and bark.",
        40);
    cout << endl;

    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  default:
clearScreen();
    cout << endl;

    printDelayed("Invalid choice. Please try again.", 40);
    cout << endl;
    waitForEnter();
    visitCity();
    break;
  }
}

void visitBeach() {
waitForEnter();
  cout << CYAN << R"(
                                        |
                                      \ _ /
                                    -= (_) =-
   .\/.                               /   \
.\\//o\\                      ,\/.      |              ,~
//o\\|,\/.   ,.,.,   ,\/.  ,\//o\\                     |\
  |  |//o\  /###/#\  //o\  /o\\|                      /| \
^^|^^|^~|^^^|' '|:|^^^|^^^^^|^^|^^^""""""""("~~~~~~~~/_|__\~~~~~~~~~~
 .|'' . |  '''""'"''. |`===`|''  '"" "" " (" ~~~~ ~ ~======~~  ~~ ~
 ^^^
    ^^   ^^^ ^ ^^^ ^^^^ ^^^ ^^ ^^ "" """( " ~~~~~~ ~~~~~  ~~~ ~

  
  )" << RESET << endl;
  cout << endl;
  printDelayed("You reach a beautiful sandy beach. However, you notice trash "
               "scattered around and an oily sheen on the water's surface.",
               40);
  cout << endl;
  waitForEnter();
  printDelayed("What would you like to do?", 40);
  cout << endl;
  printDelayed("1. Investigate water pollution", 40);
  cout << endl;
  printDelayed("2. Relax on the beach and soak up the sun", 40);
  cout << endl;
  printDelayed("3. Call the marina or fuel dock", 40);
  cout << endl;
  printDelayed("4. Participate in a beach cleanup", 40);
  cout << endl;
  int choice;
  cin >> choice;

  switch (choice) {
  case 1:
clearScreen();
    cout << endl;
    printDelayed(
        "You investigate the water pollution and discover that it's caused "
        "by plastic waste and oil spills.",
        40);
    cout << endl;
    printDelayed(
        " Water pollution caused by plastic waste and oil spills has "
        "detrimental effects on aquatic ecosystems. Improper disposal and "
        "inadequate waste management systems lead to the accumulation of "
        "plastic waste in water bodies, posing a threat to marine life. "
        "Animals mistakenly consume plastic debris, resulting in internal "
        "injuries, blockages, malnutrition, and death. ",
        40);
    cout << endl;
    printDelayed(
        "Additionally, plastic items break down into microplastics that "
        "can be ingested by aquatic organisms, further disrupting the food "
        "chain and ecosystem balance. Oil spills, on the other hand, "
        "contaminate water with toxic substances, harming marine plants, "
        "animals, and habitats. Both plastic waste and oil spills require "
        "effective mitigation strategies to protect water resources and "
        "preserve aquatic biodiversity. ",
        40);
    cout << endl;
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 2:
clearScreen();
    cout << endl;

    printDelayed(
        "You decide to enjoy the beach despite the pollution, but a sense "
        "of sadness lingers within you as you witness the environmental "
        "degradation. The sight of trash scattered around and the oily "
        "sheen on the water's surface serves as a reminder of the urgent "
        "need for change. You reflect on the impact of human activities on "
        "our planet and vow to become an advocate for environmental "
        "conservation. By educating others about the consequences of "
        "pollution and promoting sustainable practices, you hope to "
        "inspire a collective effort in preserving our natural resources. "
        "Together, we can make a difference and restore the pristine "
        "beauty of our beaches for generations to come.",
        40);
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 3:
clearScreen();
    cout << endl;
    printDelayed(
        "You decide to call the marina or fuel dock to report the observed "
        "pollution. Recognizing the immediate threat that the oil spills "
        "and plastic waste pose to the marine environment, you take swift "
        "action to protect the beach and its delicate ecosystem. Your call "
        "sets in motion a chain of events aimed at containment and "
        "remediation. You feel a sense of responsibility towards the ocean "
        "and all its inhabitants. In addition to reporting the incident, "
        "you make it a personal mission to raise awareness about the "
        "importance of responsible boating practices, proper waste "
        "disposal, and the hazards of oil spills. Through education and "
        "advocacy, you strive to prevent future pollution incidents and "
        "foster a culture of environmental stewardship among boaters and "
        "beachgoers alike.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 4:
clearScreen();
    cout << endl;
    printDelayed(
        "You decide to contribute to the cleanliness of the beach by "
        "participating in a beach cleanup. Armed with gloves and trash "
        "bags, you join other volunteers in collecting litter and debris "
        "from the shore. Beach cleanups are essential for preserving the "
        "beauty of the beach and protecting marine life from the harmful "
        "effects of pollution. Your efforts make a positive impact on the "
        "environment and help create a cleaner and safer beach for "
        "everyone to enjoy.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  default:
clearScreen();
    cout << endl;
    printDelayed("Invalid choice. Please try again", 40);
    cout << endl;
    waitForEnter();
    visitBeach();
    break;
  }
}

void visitFactory() { // all functions summarive specific tasks and promote code
                      // scalabe and reusability
  //
clearScreen();
  string facArt = R"(
         ) ) )                     ) ) )                                /\
        ( ( (                      ( ( (                               /\/\
      ) ) )                       ) ) )                               _|/\|_
   (~~~~~~~~~)                 (~~~~~~~~~)                           |______|
    | POWER |                   | POWER |                             |\/\/|
    |       |                   |       |                            \|/\/\|   .''`/:
    I      _._                  I       _._                  :\''.    \`'. |  ||  /  :
    I    /'   `\                I     /'   `\                : \ ||   |\ |||  || /    o
    I   |   N   |               I    |   N   |               j _\||__/__\||_\_||/___
    f   |   |~~~~~~~~~~~~~~|    f    |    |~~~~~~~~~~~~~~|     |___________________|
  .'    |   ||~~~~~~~~|    |  .'     |    | |~~~~~~~~|   |      |  |   |   |   |  |
/'______|___||__###___|____|/'_______|____|_|__###___|___|~~~~~~|~~|~~~|~~~|~~~|~~|~~~~~~

  )";
  printAsciiArt(facArt);
  cout << endl;
  printDelayed(
      "You approach a large factory with tall smokestacks. The air carries "
      "a pungent odor, and you see dark smoke billowing into the sky.",
      40);
  waitForEnter();
  cout << endl;
  printDelayed("What would you like to do?", 40);
  cout << endl;
  printDelayed("1. Learn about industrial pollution", 40);
  cout << endl;
  printDelayed("2. Investigate the factory", 40);
  cout << endl;
  printDelayed("3. Talk to the old man hiding in the corner", 40);
  cout << endl;
  printDelayed("4. Report the pollution to the authorities", 40);
  cout << endl;
  printDelayed("5. Go to the next location, this one is ugly nad boring", 40);
  cout << endl;
  int choice;
  cin >> choice;

  switch (choice) { // uses a switch statement to handle different choices and
                // provides appropriate messages based on the selected location.
  case 1:
clearScreen();
    cout << endl;
    printDelayed(
        "Industrial pollution is the pollution caused by the industry. "
        "Together with the industrial revolution, more factories and "
        "technologies were developed, which caused a lot of air, land, and "
        "water pollution on our planet. ",
        40);
    cout << endl;
    printDelayed(
        "This kind of pollution is one of the worst because the smoke that "
        "the industry emits in the air contributes a lot to ozone "
        "depletion, health problems to both animals and humans, and global "
        "warming ",
        40);
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 2:
clearScreen();
    cout << endl;
    printDelayed(
        "You sneak into the factory and witness the disregard for "
        "environmental regulations, with pollutants being released into "
        "the air and water.",
        40);
    cout << endl;
    printDelayed(
        "You decide to investigate the factory even further and discover "
        "that it is releasing toxic chemicals into the air and water. The "
        "pollution from the factory is causing harm to the surrounding "
        "environment and the health of nearby communities.",
        40);
    cout << endl;
    printDelayed(
        "Furthermore, the waste from these industries is being thrown on "
        "land and water, which causes a lot of health problems as well for "
        "both animals and plants. These industrial pollutants release a lot "
        "of harmful and unnatural chemicals into both soil and water, which "
        "eventually lead to the extinction of some plant and animal species.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level

    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 3:
clearScreen();
    cout << endl;
    cout << RESET << R"(
               ,
            ,:' `..;
            `. ,;;'%
            +;;'%%%%%
             /- %,)%%
             `   \ %%
              =  )/ \
              `-'/ / \
                /\/.-.\
               |  (    |
               |  |   ||
               |  |   ||
           _.-----'   ||
          / \________,'|
         (((/  |       |
         //    |       |
        //     |\      |
       //      | \     |
      //       |  \    |
     //        |   \   |
    //         |    \  |
   //          |    |\ |
  //           |    | \|
 //            \    \
c'             |\    \
               | \    \
               |  \    \
               |.' \    \
              _\    \.-' \ 
             (___.-(__.'\/
      
    )"<< endl;
    printDelayed(
        "You approach the old man hiding in the corner and start a "
        "conversation. He tells you that he used to work in the factory "
        "and witnessed the pollution it caused. He warns you about the "
        "dangers of industrial pollution and encourages you to take action "
        "to protect the environment.",
        40);
    cout << endl;
    printDelayed(
        "Industrial pollution takes on many faces. It contaminates several "
        "sources of drinking water, releases unwanted toxins into the air "
        "and reduces the quality of soil all over the world.",
        40);
    cout << endl;
    printDelayed(
        "Industrial pollution is wreaking havoc on the Earth. Every nation "
        "is affected, and there are people who are working tirelessly to "
        "increase awareness and advocate for change. The activities "
        "causing pollution include:                                        "
        "  1. Burning coal                                                     "
        "  "
        "  2. Burning fossil fuels like oil, natural gas, and petroleum        "
        "  "
        "  3.  Chemical solvents used in dyeing and tanning industries         "
        "  "
        "  4. Untreated gas and liquid waste being released into the "
        "environment "
        "  5. Improper disposal of radioactive material                        "
        "  ",
        40);
    cout << endl;
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 4:
clearScreen();
    cout << endl;
    printDelayed(
        " You decide to report the pollution from the factory to the "
        "authorities. You provide them with the necessary information and "
        "evidence to investigate and take appropriate action against the "
        "factory for violating environmental regulations. our action "
        "contributes to holding the factory accountable and protecting the "
        "environment and public health.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 5:
clearScreen();
    cout << endl;
    printDelayed(
        "You decide to move on to the next location, after all who wants "
        "to visit or sightsee at a random old smelly factor that you can "
        "barely breath in properly.",
        40);
    cout << endl;
    printDelayed(
        "Industrial pollution can have various adverse effects on air "
        "quality, which can ultimately impact human health after "
        "breathing. Industrial pollution can effect the air we breathe by "
        "releasing a wide range of pollutants into the air, including "
        "toxic chemicals and fine particles and aiding in smog formation",
        40);
    cout << endl;
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  default:
    clearScreen();
    cout << endl;
    printDelayed("Invalid choice, Please try again!", 40);
    cout << endl;
    waitForEnter();
    visitFactory();
    break;
  }
}

void visitPark() {
clearScreen();
  cout << ORANGE << R"(
  
_\|/__|_\|/____\|/_  _|_|___________________|_|_
_\|/__|_\|/____\|/_ |__:_____________________:__|
_\|/__|_\|/____\|/_ |___________________________|
_\|/__|_\|/____\|/_ |__:_____________________:__|
_\|/__|_\|/____\|/_ |___________________________|
_\|/__|_\|/____\|/_   |_|___________________|_|
_\|/__|_\|/____\|/_  /__.___________________.__\
_\|/__|_\|/____\|/_/__._____________________.__\          (_),,, \^^^^|^^^^/ {{{}}_(_)_   .-"""-.   (_),,, \^^^^|^^^^/ {{{}}_(_)_   .-"""-.
_\|/__|_\|/____\|/_/_____________________________\         |{{{}} \   |   /,  ~Y~(_)@(_) /* * * *\   |{{{}} \   |   /,  ~Y~(_)@(_) /* * * *\
_\|/__|_\|/____\|/_   | |_|               |_| |            | ~Y~(@)\  |  /{}} \|/  (_)  :_.-:`:-._;  | ~Y~(@)\  |  /{}} \|/  (_)  :_.-:`:-._;
_\|/__|_\|/____\|/_   | |                   | |          (\|/)| \Y/ \ | / ~Y~ \|/ (\|/)     (_)    (\|/)| \Y/ \ | / ~Y~ \|/ (\|/)     (_)
_\|/__|_\|/____\|/_   | |                   | |           \|/\|/\|/  \|/  \|/\\|//\\|//     (_)     \|/\|/\|/  \|/  \|/\\|//\\|//     (_)
_\|/__|_\|/____\|/_   |_|                   |_|    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


  )" << RESET <<endl;
  cout << endl;
  printDelayed(
      "You enter a beautiful park with lush greenery and colorful flowers. "
      "However, you notice signs of pollution and degradation.",
      40);
  cout << endl;
  waitForEnter();
  printDelayed("What would you like to do?", 40);
  cout << endl;
  printDelayed("1. Investigate the pollution in the park", 40);
  cout << endl;
  printDelayed("2. Enjoy the scenery and take a walk", 40);
  cout << endl;
  printDelayed("3. Plant some trees or flowers to help improve the park", 40);
  cout << endl;
  printDelayed("4. Talk to the park ranger about the pollution", 40);
  cout << endl;
  cout << endl;
  int choice;
  cin >> choice;

  switch (choice) {
  case 1:
clearScreen();
    cout << endl;
    printDelayed(
        "You decide to investigate the pollution in the park. As you explore "
        "further, you come across discarded plastic bottles, wrappers, and "
        "other litter strewn across the once-pristine grounds. It's "
        "disheartening to witness the impact of irresponsible human behavior "
        "on such a beautiful natural space. You realize that pollution not "
        "only disrupts the aesthetic appeal of the park but also poses a "
        "threat to the local wildlife and ecosystem. Motivated to make a "
        "positive change, you decide to raise awareness about proper waste "
        "disposal and advocate for stricter enforcement of littering laws. By "
        "working together, we can restore the park's splendor and preserve it "
        "for future generations to enjoy.",
        40);
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;

  case 2:
    clearScreen();
    cout << endl;
    printDelayed(
        "You choose to immerse yourself in the park's scenery and take a "
        "leisurely walk. Despite the pollution, you find solace in the "
        "natural beauty that surrounds you. The vibrant flowers, the gentle "
        "rustling of leaves, and the harmonious songs of birds remind you "
        "of the importance of preserving and protecting our green spaces. "
        "Inspired by this experience, you decide to spread awareness about "
        "the significance of parks and their role in promoting mental and "
        "physical well-being. By encouraging others to cherish and respect "
        "these natural havens, we can foster a sense of responsibility and "
        "ensure that parks remain sanctuaries of peace and tranquility.",
        40);
    pollutionLevel += 10; // Add 10 to pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  case 3:
clearScreen();
    cout << endl;
    cout << GREEN << R"(

                    _
                  _(_)_                          wWWWw   _                       _(_)_                          wWWWw   _
      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_         @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
     @@()@@ wWWWw  (_)\    (___)   _(_)_  @@()@@   Y  (_)@(_)       @@()@@ wWWWw  (_)\    (___)   _(_)_  @@()@@   Y  (_)@(_)
      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   (_)\         @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   (_)\
       /      Y       \|    \|/    /(_)    \|      |/      |          /      Y       \|    \|/    /(_)    \|      |/      |
    \ |     \ |/       | / \ | /  \|/       |/    \|      \|/      \ |     \ |/       | / \ | /  \|/       |/    \|      \|/
    \\|//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//     \\|//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//

      
    )" << endl;
    cout << endl;
    printDelayed(
        "You decide to make a positive impact on the park by planting "
        "trees or flowers. With each dig of the soil and gentle placement "
        "of a seedling, you contribute to the park's restoration and "
        "rejuvenation. You recognize that the planting of trees not only "
        "enhances the park's aesthetics but also helps combat air "
        "pollution and provides habitat for wildlife. By actively "
        "participating in park beautification initiatives, you inspire "
        "others to take similar actions and collectively create a greener "
        "and healthier environment. Through your efforts, the park will "
        "flourish once again, attracting more visitors and encouraging a "
        "stronger sense of environmental stewardship.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;

    
  case 4:
    clearScreen();
    cout << endl;
    printDelayed(
        "You decide to approach the park ranger to discuss the pollution "
        "issue. The park ranger is grateful for your concern and shares "
        "valuable insights about ongoing conservation efforts. They "
        "explain that the pollution is a result of both visitors' actions "
        "and limited resources for park maintenance. Inspired by their "
        "dedication, you offer your assistance as a volunteer to help "
        "organize clean-up events and spread awareness among park "
        "visitors. You recognize the significance of community engagement "
        "and vow to collaborate with the park ranger and other like-minded "
        "individuals to develop sustainable solutions that protect and "
        "preserve this cherished park for future generations.",
        40);
    pollutionLevel -= 10; // Subtract 10 from pollution level
    cout << endl;
    waitForEnter();
    continueExploring();
    break;
  default:
    clearScreen();
    cout << endl;
    waitForEnter();
    printDelayed("Invalid choice, Please try again!", 40);
    cout << endl;
    visitPark();
    break;
  }
}

void chooseLocation() { // allows the player to select a location to visit,
  clearScreen();
  cout << endl;
  cout << BLUE << R"(
                                       .         .      /\      .:  *       .          .              .
                                                 *    .'  `.      .     .     *      .                  .
                                  :             .    /      \  _ .________________  .                    .
                                                    `.+-~~-+.'/.' `.^^^^^^^^\~~~~~\.                      .
    |>>> .    -*-   . .                               |u--.|  /     \~~~~~~~|~~~~~|                                                         |>>>
    |                     |>>>                        |   u|.'       `." "  |" " "|                        .          |>>>                  |
    *                     |         :            .    |.u-./ _..---.._ \" " | " " |                                   |                     *
   / \                    *        -*-            *   |    ~-|U U U U|-~____L_____L_                      .           *                    / \
  /___\                 _/ \        :         .   .   |.-u.| |..---..|"//// ////// /\       .            .           / \_                 /___\
  [   ]                |/   \____         .  *        |u   | |       |// /// // ///==\     / \          .      _____/   \|                [   ]
  [ I ]                /     \   .          :         |.--u| |..---..|//////~\////====\   /   \       .            /     \                [ I ]
  [   ]_ _ _          /       \       .               | u  | |       |~~~~/\u |~~|++++| .`+~~~+'  .               /       \          _ _ _[   ]
  [   ] U U |        {#########}                      |.-|~U~U~|---..|u u|u | |u ||||||   |  U|                  {#########}        | U U [   ]
  [   ]====/          \=======/                     /~~~~/-\---.'     |===|  |u|==|++++|  |   |                   \=======/          \====[   ]
  [   ]    |           |   I |_ _          aaa      |===| _ | ||.---..|u u|u | |u ||HH||U~U~U~U~|        aa@@   _ _| I   |           |    [   ]
  [___]    |_ _ _ _ _ _|     | U       aaa@@@@@@aa   |===|||||_||      |===|_.|u|_.|+HH+|_/_/_/_/aa    a@@@@@@ U U |     |_ _ _ _ _ _|    [___]
  \===/  I | U U U U U |     |===  aa@@@@@@@@@@@@@@a |~~|~~~~\---/~-.._|--.---------.~~~`.__ _.@@@@@@a    ~~~~ ====|     | U U U U U | I  \===/
   \=/     |===========| I   | + W   ~~~~~~    ~~~    \_\\ \  \/~ //\  ~,~|  __   | |`.   :||  ~~~~              + |   I |===========|     \=/
    |  I   |           |     |____                     a\`| `   _//  | / _| || |  | `.'  ,''|     aa@@@@@@@a    ___|     |           |   I  |
    |      |           |     ||||| aaa   aaaa       a@@@@\| \  //'   |  // \`| |  `.'  .' | |  aa@@@@@@@@@@@@@  ||||     |           |      |
    |      |           |   I ||vvv@@@@@a@@@@@@a      ~~~~~ \\`//| | \ \//   \`  .-'  .' | '/      ~~~~~~~  ~~  vvv|| I   |           |      |
_-_-|______|-----------|_____||   @@@@@@@@@@@@@@@a          \// |.`  ` ' /~  :-'   .'|  '/~aa                     ||_____|-----------|______|-
   /________\         /______||   ~~~~~~ ~~~~~~         a@@@|   \\ |   // .'    .'| |  |@@@@@@a                   ||______\         /________\
  |__________|-------|________\___                    a@@@@@@@\   | `| ''.'     .' | ' /@@@@@@@@@a       _      __/________|-------|__________|
                                                                     _| |_

  )" << RESET <<endl;
  cout << endl;
  printDelayed("Where would you like to go?", 40);
  waitForEnter();
  cout << endl;
  printDelayed("1. Beach", 40);
  cout << endl;
  printDelayed("2. Forest", 40);
  cout << endl;
  printDelayed("3. Park", 40);
  cout << endl;
  printDelayed("4. City", 40);
  cout << endl;
  printDelayed("5. Factory", 40);
  cout << endl;
  int choice;
  cin >> choice;
  
    // Array of locations and their corresponding visit functions
  /*An array of Location objects is then created, where each object contains the name of a location and a function to visit that location. If the user's input is valid (i.e., between 1 and 5), the corresponding Location object is retrieved from the array, and its visitFunction is called. If the user's input is invalid, an error message is displayed, and the chooseLocation function is called recursively to prompt the user again.*/
   Location locations[] = {
        {"Beach", visitBeach},
        {"Forest", visitForest},
        {"Park", visitPark},
        {"City", visitCity},
        {"Factory", visitFactory}
    };

    if (choice >= 1 && choice <= 5) {
        clearScreen();
        cout << endl;
        printDelayed("You chose to go to the " + locations[choice-1].name + "!", 40);
        waitForEnter();
        locations[choice-1].visitFunction();
    } else {
        clearScreen();
        cout << endl;
        printDelayed("", 40);
        cout << "Invalid Choice, please try again!" << endl;
        waitForEnter();
        chooseLocation();
    } }

// Function representing the game loop
void gameLoop() {
/*The gameLoop function is a void function that runs the main game loop. It calls several functions that are responsible for displaying the game introduction and visiting various locations in the game.
Finally, the gameLoop function returns void, which means it does not return any value.*/
  introduction();
  chooseLocation();
  visitForest();
  visitCity();
  visitBeach();
  visitFactory();
  visitPark();
}

int main() {
/* The introduction function is called to display the game introduction, and the chooseLocation function is called
to allow the user to choose a location. Finally, the main function returns 0 to exit the program.*/
  
    const char* musicFile = "music.mp3";
    // Construct the command to play the music file using the default media player
    string command = "xdg-open ";
    command += musicFile;
    // Execute the command to play the music file
    system(command.c_str());
  
  introduction(); // Display game introduction
  chooseLocation();  // Exit the program
  return 0;  // Exit the program
}
