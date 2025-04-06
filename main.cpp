#include <iostream>
#include <iostream>
#include <list>
#include <map>


using namespace std;


struct Games {
    string name = " ";
    int quantity = 0;
    int quality = 0;
    list<string> type;
    list<string> platform = {};
    map<string, list<string> > map_platform;

    Games(string plat_name = " ") {
        map_platform["ps"] = {"ps3", "ps4", "ps5"};
        map_platform["xbox"] = {"xbox360", "xbox1"};
        map_platform["ps3"] = {"ps3"};
        map_platform["ps4"] = {"ps4"};
        map_platform["ps5"] = {"ps5"};
        map_platform["xbox1"] = {"xbox1"};
        map_platform["xbox360"] = {"xbox360"};
        map_platform["all"] = {"ps3", "ps4", "ps5", "xbox1", "xbox360"};

        list<string> chosen = map_platform[plat_name];
    }
};

class Game {
public:
    /*Games *list = new Games[20]*/;
    vector<Games> list;

    Game() {
        new Games[20];
    } //needs a count!

    void set_list() {
        Games g1;

        g1.name = "the last of us";
        g1.quantity = 0;
        g1.quality = 0;
        g1.type = {"adventure"};
        g1.platform = g1.map_platform["all"]; // remember to declare on platform
        list.push_back(g1);
        Games g2;
        g2.name = "fifa";
        g2.quantity = 0;
        g2.quality = 0;
        g2.type = {"adventure"};
        g2.platform = g2.map_platform["all"];
        list.push_back(g2);
        Games g3;
        g3.type = {"sport"};
        g3.name = "pes";
        g3.quantity = 0;
        g3.quality = 0;
        g3.type = {"sport"};
        g3.platform = g3.map_platform["xbox"];
        list.push_back(g3);
        Games g4;
        g4.name = "need for speed";
        g4.quantity = 0;
        g4.quality = 0;
        g4.type = {"sport", "adventure"};
        g4.platform = g4.map_platform["ps"];
        list.push_back(g4);
    }
};

/*
class Player: public Game {
public:
    int wallet = 50;
    Games* games = list;
    Game current_game;
    int size = 4;

    static void display(const Games* list,int size) {
        for (int i = 0; i < size;i++) {
            cout << list[i].name << endl;
        }
    }

    static void search_platform(platforms &p,string plat_name) {
        for(auto p2 : p) {
            if(p2.name == plat_name) {
                cout << p2.name << endl;
            }

        }

    }
};
*/

class Administrator : public Game {
    //  static Game games ; error
    string name = "administrator";
    string password = "1234";

public:
    int safe = 1000;

    static void search_name(string name) {
        //search by name
        static Game games; // needed for putting data in it!

        games.set_list(); // not efficient
        for (int i = 0; i < games.list.size(); i++) {
            if (games.list[i].name == name) {
                cout << games.list[i].name << ", " << games.list[i].quantity << ", " << games.list[i].quality << endl;
                for (int j = 0; j < games.list[i].platform.size(); j++) {
                    //  cout<<games.list[i].platform[j];
                }
            }
        }
    }
    static void search_platform(string plat_name) {
        Game games;
        games.set_list();
        for(auto &it : games.list) {
            for (auto &it1 : it.type) {
                if(it1 == plat_name) {
                    cout <<it.name << ", " << it.quantity << ", " << it.quality;
                    for(auto it2 = it.type.begin(); it2 != it.type.end(); it2++) { //doesn't work without iterator and with type[i]
                         cout<<" "<<*it2;
                    }
                    cout<<endl;

                }
            }
        }
    }


    static void search_console(string console_name) {
        Game g;
        //   g.map_platform.
        // for()
        //}
        g.set_list();
        for (auto &it: g.list) {
            if (it.map_platform[console_name].size() > 0) {
                cout << it.name << ", " << it.quantity << ", " << it.quality << endl;
            }
            // cout<<g2.map_platform.find(plat_name)->second; //able to access the second part of the map!
            //if (g.list[i].map_platform[plat_name]){

            //   }
        }
    }


    static void display() {
        static Game games;
        games.set_list();
        cout << games.list.size() << endl;
        string what;
        cout <<
                " for search with console pls enter: 1 \n for search with platform pls enter: 2 \n for search with name pls enter: 3 " << endl;
        cin >> what;
        if (what == "3") {
            cout << "enter the name of the game!" << endl;
            string name;
            cin >> name;
            search_name(name);
        }
        if (what == "1") {
            cout << "enter which console you have in mind!: all,ps5,ps4,ps3,ps(all of them),xbox,xbox1,xbox360" << endl; //todo ps should be able to have ps5 and ps4 shown
            string console_name;
            cin >> console_name;
            search_console(console_name);
        }
        if (what == "2") {
            cout << "enter which platform you have in mind!" << endl;
            string platform;
            cin >> platform;
            search_platform(platform);

        }
    }
};


int main() {
    Administrator administrator;
    administrator.set_list(); // have to call it so size of list wouldn't be zero
    administrator.display();

    return 0;
}
