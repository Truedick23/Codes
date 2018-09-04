#include<iostream>
#include<iomanip>
using namespace std;

class CD {
public:
    CD(string name, string song[6]);
    CD(){

    }
    CD(const CD&);
    string getSinger();
    string getSong(int index);
    void listSongs();
private:
    string singer;
    string songs[6];
};

class CDPlayer {
public:
    CDPlayer(CD *cd = NULL, bool in = false);
    CDPlayer(const CDPlayer&);
    void showMenu();
    void insertCD(CD *cd);
    CD *ejectCD();
    void play();
    int getChoice();
private:
    CD *cd;
    bool cdIn;
};

int main() {
    string name, name2;
    string songs[6], songs2[6];
    cout << "Constructing a CD.....:" <<endl;
    cout << "Singer's name: " << endl;
    cin >> name;
    for(int i = 0; i < 6; i++) {
        cout << " song" << (i+1) << "#: ";
        cin >> songs[i];
    }
    CD cd(name, songs);
    cout << endl;
    cd.listSongs();
    cout << endl;
    CDPlayer player;
    cout << endl;
    player.showMenu();
    /*while(1){
        cin >> choice;
        if(choice == 1) {
            cout << "Artist: ";
            cin >> nuname;
            for(int i = 0; i < 6; i++) {
                cout << " song" << (i+1) << "#: ";
                cin >> nusongs[i];
            }
            CD nucd(nuname, nusongs);
            player.insertCD(&nucd);
        }
        else if(choice == 2) player.play();
        else if(choice == 3) player.ejectCD();
        else if(!choice) break;
        player.showButtons();
    }*/
    cout << endl;
    player.play();
    cout << endl;
    player.insertCD(&cd);
    cout << endl;
    player.play();
    cout << endl;
    if(player.ejectCD() == NULL)  cout << "Empty now" <<endl;

    cout << "Constructing another CD.....:" <<endl;
    cout << "Singer's name: " << endl;
    cin >> name2;
    for(int i = 0; i < 6; i++) {
        cout << " song" << (i+1) << "#: ";
        cin >> songs2[i];
    }
    CD cd2(name2, songs2);
    cout << endl;
    player.insertCD(&cd2);
    cout << endl;
    player.play();
    return 0;
}

string CD::getSinger() {
    return singer;
}

string CD::getSong(int index) {
    return songs[index];
}

void CD::listSongs() {
    cout << "About this CD: \nSinger: "<< singer << endl;
    for(int i = 0; i < 6; i++)
        cout << " " << (i+1) << ". " << songs[i] << endl;
    return;
}

void CDPlayer::showMenu() {
    cout << "*************************";
    cout << endl;
    cout << "*  1. Insert CD         *" << endl;
    cout << "*  2. Eject CD          *" << endl;
    cout << "*  3. Play CD           *" << endl;
    cout << "*  0. Power Off         *" << endl;
    cout << "*************************" << endl;
}

int CDPlayer::getChoice() {
    int choice;
    cin >> choice;
    return choice;
}

void CDPlayer::play(){
    if(!cdIn)   cout << "Please insert CD first." << endl;
    else cd->listSongs();
    return;
}

CD *CDPlayer::ejectCD() {
    if(!cdIn)    return NULL;
    cout << "Successfully ejected " << cd->getSinger() << "'s CD" << endl;
    cdIn = false;
    return cd;
}

void CDPlayer::insertCD(CD *anotherCD) {
    cd = anotherCD;
    cout << "Successfully insert new album!" << endl;
    cdIn = true;
    cout << "This CD is performed by " << anotherCD->getSinger() << endl;
}

CD::CD(string name, string song[6]) {
    singer = name;
    for(int i = 0; i < 6; i++)
    songs[i] = song[i];
}

CD::CD(const CD& cd1){
    singer = cd1.singer;
    for(int i = 0; i < 6; i++)
    songs[i] = cd1.songs[i];
}

CDPlayer::CDPlayer(CD *nucd, bool In) {
    cd = nucd;
    cdIn = In;
}

CDPlayer::CDPlayer(const CDPlayer& cdp) {
    cd = cdp.cd;
    cdIn = cdp.cdIn;
}


