#pragma once
class Graphics {
public:
    //This funtion prints the menu
    void printMainMenu() {
        cout << "\n" << string(9, '\t') << "|--------------------------------------------|"
            << "\n" << string(9, '\t') << "|                  Main Menu                 |"
            << "\n" << string(9, '\t') << "|--------------------------------------------|"
            << "\n" << string(9, '\t') << "| Press 1 to Create Alien                    |"
            << "\n" << string(9, '\t') << "| Press 2 to Create Offsprings               |"
            << "\n" << string(9, '\t') << "| Press 3 to Compare Offsprings prestige     |"
            << "\n" << string(9, '\t') << "| Press 4 to Show list of Aliens             |"
            << "\n" << string(9, '\t') << "| Press 5 to exit                            |"
            << "\n" << string(9, '\t') << "|--------------------------------------------|"
            << "\n" << string(9, '\t') << "| Choose options: ";
    }
    //This function prints the title of the game
    void printAlienTitle() {
        string line;
        ifstream myfile;
        myfile.open("AlienTitle/6.txt", ios::in);

        cout << "\n\n\n";
        while (getline(myfile, line)) {
            cout << "\t\t\t" << line << endl;
        }
        myfile.close();
    }
    //This function plays the heart animation
    void playHeart() {
        string line;
        ifstream myfile;
        string filename = "1";
        system("Color 04");
        for (int i = 0; i < 2; i++) {
            for (int i = 1; i <= 18; i++) {
                filename = "AlienAnimation/" + to_string(i) + ".txt";
                myfile.open(filename, ios::in);

                cout << "\n\n";
                while (getline(myfile, line)) {
                    stringstream ss(line);
                    cout << line << endl;
                }

                myfile.close();
                Sleep(30);
                system("cls");
            }
        }
        system("Color 0A");
    }
    //This function plays the intro of the game
    void playIntro() {
        string line;
        ifstream myfile;
        string filename = "1";

        for (int i = 0; i < 4; i++) {
            for (int i = 1; i <= 4; i++) {
                filename = "AlienTitle/" + to_string(i) + ".txt";
                myfile.open(filename, ios::in);

                cout << "\n\n\n\n\n\n\n\n\n";
                while (getline(myfile, line)) {
                    cout << "\t\t\t\t\t\t\t";
                    stringstream ss(line);
                    cout << line << endl;
                }

                myfile.close();
                Sleep(40);
                system("cls");
            }
        }
    }
};