#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Player
{
private:
    string playerName;
    int score;
public:
    friend bool score_sorter(const Player&, const Player&);
    string get_playerName() const
    {
        return playerName;
    }
    int getscore() const
    {
        return score;
    }
    void set_playerName(string n)
    {
        playerName = n;
    }
    void setscore(int s)
    {
        score = s;
    }
};
bool score_sorter(const Player& p, const Player& r)
{
    return p.score > r.score;
}

int main()
{
    /*system("chcp 1251 > nul");*/
    size_t n;
    cout << "Enter number of players: ";
    cin >> n;
    
    Player* players = new Player[n];
    for (size_t i = 0; i < n; i++)
    {
        string playerName;
        int score;
        cout << "Enter player's score: " << i << " ";
        cin >> score;
        cout << "Enter player's name: ";
        cin >> playerName;
        players[i].set_playerName(playerName);
        players[i].setscore(score);
    }
    sort(players, players + n, score_sorter);
    for (size_t i = 0; i < n; i++)
    {
        cout << players[i].get_playerName() << "\t" << players[i].getscore() << "\n";
    }
    delete[] players;
}
