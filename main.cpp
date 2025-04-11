#include <iostream>
#include <list>
#include <map>
#include <sstream>

using namespace std;

class structor_game {
public:
    string name = " ";
    int quantity = 0;
    int quality = 0;
    list<string> type;
    list<string> platform = {};
    map<string, list<string> > map_platform;

    structor_game(string plat_name = " ") {
        this->map_platform["ps"] = {"ps3", "ps4", "ps5"};
        this->map_platform["xbox"] = {"xbox360", "xbox1"};
        this->map_platform["ps3"] = {"ps3"};
        this->map_platform["ps4"] = {"ps4"};
        this->map_platform["ps5"] = {"ps5"};
        this->map_platform["xbox1"] = {"xbox1"};
        this->map_platform["xbox360"] = {"xbox360"};
        this->map_platform["all"] = {"ps3", "ps4", "ps5", "xbox1", "xbox360"};
        list<string> chosen = map_platform[plat_name];
    }
};

class list_game : public structor_game {
public:
    /*Games *list = new Games[20]*/;
    vector<structor_game> listname;
    void addGame(structor_game& game) {
        listname.push_back(game);
    }


    void get_list() {

        list_game g1;

        g1.name = "the last of us";
        g1.quantity = 0;
        g1.quality = 0;
        g1.type = {"adventure"};
        g1.platform = g1.map_platform["all"]; // remember to declare on platform
        this->listname.push_back(g1);
        list_game g2;
        g2.name = "fifa";
        g2.quantity = 0;
        g2.quality = 0;
        g2.type = {"adventure"};
        g2.platform = g2.map_platform["all"];
        this->listname.push_back(g2);
        list_game g3;
        g3.type = {"sport"};
        g3.name = "pes";
        g3.quantity = 0;
        g3.quality = 0;
        g3.type = {"sport"};
        g3.platform = g3.map_platform["xbox"];
        this->listname.push_back(g3);
        list_game g4;
        g4.name = "need for speed";
        g4.quantity = 0;
        g4.quality = 0;
        g4.type = {"sport", "adventure"};
        g4.platform = g4.map_platform["ps"];
        this->listname.push_back(g4);
    }
};


class Administrator : public list_game {
    //  static Game games ; error
    string name = "administrator";
    string password = "1234";

public:
    list_game game;

    Administrator() {
    }

    int safe = 1000;




    void search_console(string console_name) {

        for (auto &it: game.listname) {
            if (it.map_platform[console_name].size() > 0) {
                cout << it.name << ", " << it.quantity << ", " << it.quality << endl;
            }
            // cout<<g2.map_platform.find(plat_name)->second; //able to access the second part of the map!
            //if (g.list[i].map_platform[plat_name]){

            //   }
        }
    }


    void buy() {
        structor_game structer;
        //listname by its own does not actually use anything
        // handling and emptying buffer by hand;
        cout<< "how many games:" << game.listname.size() << endl;
        cout << "pls enter the name of your game: ";
        cin >> structer.name;
        bool found = false;
        for (auto &it: game.listname) {
            if(found == false){
                if (structer.name == it.name) {
                    found = true;
                    int quantity;
                    cout << "pls enter how many games you want to sell:";
                    cin >> structer.quantity;

                    it.quantity += quantity;
                    safe -= quantity*it.quality;
                    for(vector<structor_game>::iterator iter = game.listname.begin(); iter != game.listname.end(); iter++) {
                        if(iter->name == structer.name) {
                            game.listname.erase(iter);
                            game.listname.push_back(structer);
                            break;
                        }

                    }
                    cout<<R"(your safe:)"<<safe<<endl;// ممکنه ایراد داشته باشه!
                }
                //break;
            }
        }
        if (!found) {
                string plat_name;

                cout << "pls enter the name of your platform: choose from: all ps3 ps4 ps5 ps xbox xbox360 xbox1 ";
                cin >> plat_name;
                if (map_platform[plat_name].size() > 0) {
                        structer.platform = map_platform[plat_name];
                    }

                 cout<<"pls enter quantity:"<<endl;
                 cin >> structer.quantity;

                 cout<<"pls enter quality:"<<endl;
                 cin >> structer.quality;
                 string quality_word;
                 getline(cin, quality_word);
                 stringstream s(quality_word);
                 int i = 0;
                 while(s >> quality_word) {
                     structer.type.push_back(quality_word);
                 }
            game.addGame(structer);
                    }

                }





    bool verify() {
        while(password != "admin1admin" || password != "exit") {
            cout << "enter exit" ;
            cout<<" or password: "<<endl;

            cin >> password;
            if (password == "admin1admin") {
                return true;
            }if (password == "exit") {
                return false;
            }
        }
    }

    void display() {
        if(verify()){
            game.get_list();
            cout <<"games we have"<< game.listname.size() << endl;
            string what;
            while (true) {
                cout <<
                        " for search with console pls enter: 1 \n for search with platform pls enter: 2 \n for search with name pls enter: 3 \n for selling pls enter:4 \n to see your wallet enter:5 \n to exit: 6 "
                        << endl;
                cin >> what;
                if (what == "3") {
                    cout << "enter the name of the game!" << endl;
                    string name;
                    cin >> name;
                  //  search_name(name);
                }
                if (what == "1") {
                    cout << "enter which console you have in mind!: all,ps5,ps4,ps3,ps(all of them),xbox,xbox1,xbox360" << endl;
                    //todo ps should be able to have ps5 and ps4 shown
                    string console_name;
                    cin >> console_name;
                    search_console(console_name);
                }
                if (what == "2") {
                    cout << "enter which platform you have in mind!" << endl;
                    string platform;
                    cin >> platform;
                   // search_platform(platform);
                }
                if (what == "4") {
                    buy();

                }
                if (what == "5") {
                    cout<<safe <<endl;
                }
                if(what == "6") {
                    break;
                }
            }
        }
    }
};


int main() {
    Administrator administrator;
    administrator.display();

    return 0;
}
