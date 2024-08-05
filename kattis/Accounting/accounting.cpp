#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main() {

    int N, Q;
    std::cin >> N >> Q;

    // read in blocks of restarts
    // if you see a SET word, then then update the "changed" map accordingly
    // if you see a PRINT word, then check to see if the person's wealth changed (from teh SET set)

    int x = 0;
    std::unordered_set<int> people_who_changed;
    std::unordered_map<int,int> person_to_alteration;
    std::string q;
    for (int i = 0 ; i < Q; i++)
    {
        std::cin >> q;
        if (q[0] == 'R') // restart
        {
            std::cin >> x;
            people_who_changed.clear();
            person_to_alteration.clear();
        }
        else if (q[0] == 'S') {
            int person, amount;
            std::cin >> person >> amount;
            people_who_changed.insert(person);
            person_to_alteration[person] = amount;
        }
        else { // print
            int person;
            std::cin >> person;
            if (people_who_changed.find(person) != people_who_changed.end()) {
                // person changed
                std::cout << person_to_alteration[person] << std::endl;
            }
            else {
                std::cout << x << std::endl;
            }
        }
    }

}
