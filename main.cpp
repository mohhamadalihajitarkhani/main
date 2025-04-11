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



int main() {
    //Administrator administrator;
   // administrator.display();

    return 0;
}
