#pragma once
class Alien {
private:
    int height, weight;
    char gender;

public:
    Alien(float defNum = 0, char defGender = 'z') { height = defNum, weight = defNum, gender = defGender; }
    Alien(int h, int w, char g) {
        height = h, weight = w, gender = g;
    }

    int getHeight() { return height; } // This function returns the height of the alien
    int getWeight() { return weight; } // This function returns the weight of the alien
    char getGender() { return gender; } // This function returns the gender of the alien
    void setHeight(int h) { height = h; } // This function sets the height of the alien
    void setWeight(int w) { weight = w; } // This function sets the weight of the alien
    void setGender(char g) { gender = g; } // This function sets the gender of the alien

    //This function returns the Prestige of the alien
    int getPrestige() { 
        int genderPoints;
        if (getGender() == 'M')
            genderPoints = 2;
        else
            genderPoints = 3;
        return height * weight * genderPoints;
    }
    //This operator allows two objects to be added
    Alien operator+(const Alien& a) {
        Alien alien;
        int randNum;
        srand(time(0));
        randNum = rand() % 100 + 1;

        alien.height = (this->height + a.height) / 2;
        alien.weight = (this->weight + a.weight) / 2;
        alien.gender = (randNum <= 50) ? 'M' : 'F';
        return alien;
    }
    //This operator allows an object to assigend to another object
    Alien& operator=(const Alien& a) {
        if (this == &a)
            return *this;//this handles self asignment

        this->height = a.height;
        this->weight = a.weight;
        this->gender = a.gender;

        return *this;
    }
    //This operator allows an object to be compared to another object
    bool operator==(Alien& a) {
        Alien alien;
        if (alien.getPrestige() == a.getPrestige())
            return true;
        else
            return false;
    }
    //This operator allows an object to be compared to another object
    bool operator!=(Alien& a) {
        Alien alien;
        if (alien.getPrestige() != a.getPrestige())
            return true;
        else
            return false;
    }
    //This operator checks if the object is greater than the other object
    bool operator>(Alien& a) {
        Alien alien;
        if (alien.getPrestige() > a.getPrestige())
            return true;
        else
            return false;
    }
    //This operator checks if the object is less than the other object
    bool operator<(Alien& a) {
        Alien alien;
        if (alien.getPrestige() < a.getPrestige())
            return true;
        else
            return false;
    }
    //This operator checks if the object is greater than or equal the other object
    bool operator>=(Alien& a) {
        Alien alien;
        if (alien.getPrestige() >= a.getPrestige())
            return true;
        else
            return false;
    }
    //This operator checks if the object is less than or equal the other object
    bool operator<=(Alien& a) {
        Alien alien;
        if (alien.getPrestige() <= a.getPrestige())
            return true;
        else
            return false;
    }
    //This function allows the user to create an alien
    Alien& createAlien(Alien& a) {
        int h, w, choice;
        bool isTrue;
        char g;
        Graphics graphics;

        system("cls");
        graphics.printAlienTitle();

        cout << "\n" << string(9, '\t') << "|--------------------------|"
             << "\n" << string(9, '\t') << "|       Alien Creation     |"
             << "\n" << string(9, '\t') << "|--------------------------|";
        cout << "\n" << string(9, '\t') << "| Enter Alien Height: ";
        cin >> h;

        cout << "\n" << string(9, '\t') << "| Enter Alien Weight: ";
        cin >> w;

        do {
            isTrue = true;
            cout << "\n" << string(9, '\t') << "|--------------------------|"
                 << "\n" << string(9, '\t') << "|       Choose Gender      |"
                 << "\n" << string(9, '\t') << "|--------------------------|"
                 << "\n" << string(9, '\t') << "| Press 1 For Male         |"
                 << "\n" << string(9, '\t') << "| Press 2 For Female       |"
                 << "\n" << string(9, '\t') << "|--------------------------|"
                 << "\n" << string(9, '\t') << "| Choose option: ";
            cin >> choice;

            switch (choice) {
            case 1: g = 'M'; isTrue = false; break;
            case 2: g = 'F'; isTrue = false; break;
            default: cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again..\n"; break;
            }
        } while (isTrue);

        a.setHeight(h);
        a.setWeight(w);
        a.setGender(g);

        cout << "\n" << string(9, '\t') << "|-----------------------------|"
             << "\n" << string(9, '\t') << "|  New Alien has been created |"
             << "\n" << string(9, '\t') << "|-----------------------------|" << "\n" << string(9, '\t');
        return a;
    }
    //This function will create 4 default alien
    vector<Alien>& createDefaultAlien(vector<Alien>& alien) {
        Alien a1(50, 40, 'M');
        Alien a2(39, 60, 'F');
        Alien a3(30, 20, 'F');
        Alien a4(60, 90, 'M');
        alien.push_back(a1);
        alien.push_back(a2);
        alien.push_back(a3);
        alien.push_back(a4);

        return alien;
    }
    //This function shows the list of specified gender of aliens
    void showListOfAliens(const vector<Alien>& alien, char g) {
        Graphics graphic;

        system("cls");
        graphic.printAlienTitle();
        int i = 1;
        for (auto a : alien) {
            if (a.gender == g) {
                cout << "\n" << string(6, '\t') << "|-----------------------------------------------------------------------------|"
                    << "\n" << string(6, '\t') << "| Alien ID\t| Alien Height |\t| Alien Weight |\t|Alien Gender |"
                    << "\n" << string(6, '\t') << "|-----------------------------------------------------------------------------|"
                    << "\n" << string(6, '\t') << "    " << i
                    << string(3, '\t') << a.height
                    << string(3, '\t') << a.weight
                    << string(3, '\t') << a.gender;
            }
            i++;
        }
        cout << "\n\n" << string(9, '\t');
    }
    //This function shows all the list of aliens
    void showListOfAliens(const vector<Alien>& alien) {
        Graphics g;

        system("cls");
        g.printAlienTitle();
        int i = 1;
        for (auto a : alien) {
            cout << "\n" << string(6, '\t') << "|-----------------------------------------------------------------------------|"
                << "\n" << string(6, '\t') << "| Alien ID\t| Alien Height |\t| Alien Weight |\t|Alien Gender |"
                << "\n" << string(6, '\t') << "|-----------------------------------------------------------------------------|"
                << "\n" << string(6, '\t') << "    " << i
                << string(3, '\t') << a.height
                << string(3, '\t') << a.weight
                << string(3, '\t') << a.gender;
            i++;
        }
        cout << "\n\n" << string(9, '\t');
    }
    //This function shows the details of an alien
    bool showAlienStat(const vector<Alien>& alien, int id) {
        bool isFound = true;

        for (int i = 0; i < alien.size(); i++) {
            if (i == id) {
                cout << "\n" << string(9, '\t') << "|----------------------------|"
                    << "\n" << string(9, '\t') << "|       Alien Details        |"
                    << "\n" << string(9, '\t') << "|----------------------------|"
                    << "\n" << string(9, '\t') << "| Alien " << i
                    << "\n" << string(9, '\t') << "| Alien Height: " << alien[i].height
                    << "\n" << string(9, '\t') << "| Alien Weight: " << alien[i].weight
                    << "\n" << string(9, '\t') << "| Alien Gender: " << alien[i].gender << endl;
                isFound = true;
                break;
            }
            else
                isFound = false;
        }
        return isFound;
    }
    //This function uses the overloaded + operator that enable two objects to be combined
    Alien mateAliens(vector<Alien>& alien, int m, int f) {
        Alien a;
        a = alien[m] + alien[f];
        return a;
    }
    //This function shows the prestige of aliens
    void comparePrestige(vector<Alien>& alien, int m, int f) {
        cout << boolalpha << "\n" << string(9, '\t') << "|--------------------------------------------------|"
            << "\n" << string(9, '\t') << "|            Alien Prestige Comparison             |"
            << "\n" << string(9, '\t') << "|--------------------------------------------------|"
            << "\n" << string(9, '\t') << "|      Alien" << m + 1 << "             |            " << "Alien" << f + 1 << "      |"
            << "\n" << string(9, '\t') << "|--------------------------------------------------|";
        cout << "\n\n" << string(11, '\t') << "Alien " << m + 1 << " == " << "Alien " << f + 1 << " = " << (alien[m].getPrestige() == alien[f].getPrestige());
        cout << "\n" << string(11, '\t') << "Alien " << m + 1 << " != " << "Alien " << f + 1 << " = " << (alien[m].getPrestige() != alien[f].getPrestige());
        cout << "\n" << string(11, '\t') << "Alien " << m + 1 << " > " << " Alien " << f + 1 << " = " << (alien[m].getPrestige() > alien[f].getPrestige());
        cout << "\n" << string(11, '\t') << "Alien " << m + 1 << " >= " << "Alien " << f + 1 << " = " << (alien[m].getPrestige() >= alien[f].getPrestige());
        cout << "\n" << string(11, '\t') << "Alien " << m + 1 << " < " << " Alien " << f + 1 << " = " << (alien[m].getPrestige() < alien[f].getPrestige());
        cout << "\n" << string(11, '\t') << "Alien " << m + 1 << " <= " << "Alien " << f + 1 << " = " << (alien[m].getPrestige() <= alien[f].getPrestige()) << "\n" << string(9, '\t');;
    }
    //This function checks if alien exist 
    bool isAlienExist(vector<Alien>& alien, int id, char gender) {
        if (alien.size() >= id) {
            if (id == 0) return false;
            if (alien[id - 1].gender == gender)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    //This function prompts the user to pick two aliens to be mated
    vector<Alien>& selectAlien(vector<Alien>& alien) {
        Alien a;
        Graphics g;
        int male, female;
  
        do {
            system("cls");
            showListOfAliens(alien, 'M');
            cout << "\n\n" << string(8, '\t') << "To mate start by choosing the aliens";
            cout << "\n" << string(8, '\t') << "Choose male alien by entering the ID number: ";
            cin >> male;

            if (isAlienExist(alien, male, 'M'))
                break;
            else
                cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again....\n" << string(9, '\t');
            system("pause");
        } while (true);

        do {
            system("cls");
            showListOfAliens(alien, 'F');
            cout << "\n\n" << string(8, '\t') << "To mate start by choosing the aliens";
            cout << "\n" << string(8, '\t') << "Choose female alien by entering the ID number: ";
            cin >> female;

            if (isAlienExist(alien, female, 'F'))
                break;
            else
                cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again....\n" << string(9, '\t');
            system("pause");
        } while (true);

        alien.push_back(a = a.mateAliens(alien, male - 1, female - 1));

        system("cls");
        g.playHeart();
        g.printAlienTitle();

        cout << "\n" << string(9, '\t') << "***New Alien has been born***"
            << "\n" << string(9, '\t') << "Alien " << alien.size()
            << "\n" << string(9, '\t') << "Alien Height: " << a.height
            << "\n" << string(9, '\t') << "Alien Weight: " << a.weight
            << "\n" << string(9, '\t') << "Alien Gender: " << a.gender << "\n\n" << string(9, '\t');;

        return alien;
    }
    //This function prompts the user to pick two aliens to be compared
    void selectAlien(vector<Alien>& alien, Alien& a) {
        int male, female;
        Graphics g;

        do {
            system("cls");
            showListOfAliens(alien, 'M');
            cout << "\n\n" << string(8, '\t') << "To compare prestige start by choosing the aliens";
            cout << "\n" << string(8, '\t') << "Choose male alien by entering the ID number: ";
            cin >> male;

            if (isAlienExist(alien, male, 'M'))
                break;
            else
                cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again....\n" << string(9, '\t');
            system("pause");
        } while (true);

        do {
            system("cls");
            showListOfAliens(alien, 'F');
            cout << "\n\n" << string(8, '\t') << "To compare prestige start by choosing the aliens";
            cout << "\n" << string(8, '\t') << "Choose female alien by entering the ID number: ";
            cin >> female;

            if (isAlienExist(alien, female, 'F'))
                break;
            else
                cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again....\n" << string(9, '\t');
            system("pause");
        } while (true);

        a.comparePrestige(alien, male - 1, female - 1);
    }
};