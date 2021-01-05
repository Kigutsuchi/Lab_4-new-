#include <iostream>
#include <string>

using namespace std;

class animals {
protected:
    string habitat;
public:
    animals() :habitat(">_empty") {}
    animals(string tHabitat) :habitat(tHabitat) {}
    ~animals() {};

    void animals_out() {
        cout << "Habitat: " << this->habitat << endl;
    }
};

class predator :virtual public animals {
protected:
    string mainFood;
public:
    predator(string tHabitat, string tMainFood) :mainFood(tMainFood), animals(tHabitat) {}
    ~predator() {};

    void predator_out() {
        cout << "MainFood of predator: " << mainFood << endl;
    }
};

class herbivore :virtual public animals {
protected:
    string genus;
public:
    herbivore(string tHabitat, string tGenus) :genus(tGenus), animals(tHabitat) {}
    ~herbivore() {};

    void herbivore_out() {
        cout << "Genus of herbivore: " << genus << endl;
    }
};

class lion :public predator {
protected:
    int flock;
public:
    lion(string tHabitat, string tMainFood, int tFlock) : flock(tFlock), predator(tHabitat, tMainFood), animals(tHabitat) {}
    ~lion() {};

    void lion_out() {
        cout << "Number of individuals in a flock: " << flock << endl;
    }
};

class zebra :public herbivore {
protected:
    string kAnim;
public:
    zebra(string tHabitat, string tGenus, string tKAnim) : kAnim(tKAnim), herbivore(tHabitat, tGenus), animals(tHabitat) {}
    ~zebra() {};

    void zebra_out() {
        cout << "Kind of animal: " << kAnim << endl;
    }
};

class number :public zebra, public lion {
protected:
    int numInd;
public:
    number(string tHabitat, string tMainFood, string tGenus, string tKAnim, int tFlock, int tNumInd) :
        numInd(tNumInd), zebra(tHabitat, tGenus, tKAnim), lion(tHabitat, tMainFood, tFlock), animals(tHabitat) {}
    ~number() {};

    void out() {
        animals_out();
        predator_out();
        herbivore_out();
        zebra_out();
        lion_out();
        cout << "Number of individuals: " << numInd << " " << endl;
    }
};

void input(string& str) {
    while (true) {
        rewind(stdin);
        cout << "Input string" << endl;
        getline(cin, str);
        if (str.length() < 2) {
            cout << "\nPlease, describe this topic in more details" << endl;
            continue;
        }
        else break;
    }
}

int input() {
    int i;
    bool fail = true;
    cout << "\nInput:";
    do
    {
        cin >> i;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            if (i > 0)
                fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

int main()
{
    string tHabitat, tMainFood, tGenus, tKAnim;
    int tFlock, tNum;

     string tHabitat, tMainFood, tGenus, tKAnim;
    int tFlock, tNum;
    cout << "Input habitat" << endl;
    input(tHabitat);
    cout << "Input main food" << endl;
    input(tMainFood);
    cout << "Input genus" << endl;
    input(tGenus);
    cout << "Input king of animal" << endl;
    input(tKAnim);
    cout << "Input num individuals" << endl;
    tNum = input();
    cout << "Input num of flock" << endl;
    tFlock = input();

    number a1(tHabitat, tMainFood, tGenus, tKAnim, tFlock, tNum);

    cout << "Input habitat" << endl;
    input(tHabitat);
    cout << "Input main food" << endl;
    input(tMainFood);
    cout << "Input genus" << endl;
    input(tGenus);
    cout << "Input king of animal" << endl;
    input(tKAnim);
    cout << "Input num individuals" << endl;
    tNum = input();
    cout << "Input num of flock" << endl;
    tFlock = input();

    number a2(tHabitat, tMainFood, tGenus, tKAnim, tFlock, tNum);

    a1.out();
    a2.out();
}