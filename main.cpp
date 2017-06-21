#include <iostream>

using namespace std;

class Player
{
   friend ostream & operator <<(ostream &, const Player &);

public:
    Player(const string &name = "");
    string GetName() const;
    Player* GetNext() const;
    void SetNext(Player* next);
private:
    string m_Name;
    Player *m_pNext; //Вказівник на наступного гравця в списку
};
            std:: ostream & operator <<(ostream &os, const Player &aPlayer)
            {
                    os<<aPlayer.GetName();
                    return os;
            }

            Player::Player(const string &name):m_Name(name),m_pNext(0)
            {}

            string Player::GetName() const
            {
                return m_Name;
            }

            Player *Player::GetNext() const
            {
                return m_pNext;
            }

            void Player::SetNext(Player *next)
            {
                m_pNext= next;
            }

class Lobby
{
public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void PrintPlayers(Lobby &aLobby);
    void Clear();

private:
    Player* m_pHead; //перший елемент в лобі
    Player* m_pTail; //останній елемент
};

            void Lobby::PrintPlayers(Lobby &aLobby)
            {
                 Player *pIter = aLobby.m_pHead;        //ітератор, який вказує на перший елемент

                 cout<<"Here is who is in the game: "<<endl;

                 if(pIter==0)                           //якщо перший елемент 0, то лобі пусте
                     cout<<"Lobby is empty"<<endl;
                 else
            {
                     while(pIter!=0)                    //поки ітератор не вкаже на 0
                     {
                        cout<<*pIter;                   //розміновуємо ітератор і виводимо елемент
                        cout<<endl;
                        pIter=pIter->GetNext();         //присвоюємо ітератору наступний елемент
                     }
            }
            }


            Lobby::Lobby():m_pHead(0)
            {}

            Lobby::~Lobby()
            {
                Clear();
            }

            void Lobby::AddPlayer()
            {
                                                         //створення нового гравця
                cout<<"Enter a name of new player: ";
                string name;
                cin>>name;
                Player* pNewPlayer = new Player(name);

                                                         //якщо список пустий, поставимо його на початок
                if(m_pHead==0)
                {
                    m_pHead=pNewPlayer;
                    m_pTail=m_pHead;
                }

                                                         //в іншому випадку шукаємо кінець списку і добавляємо туди гравця
                else
                {
                    Player *pIter=m_pTail; //вказівник вказує на останнього

                    pIter->SetNext(pNewPlayer); //наступним ставимо наш елемент
                    pIter=pIter->GetNext();     //вказівник вказуєн а ще наступний
                    m_pTail=pIter;              //той ще наступний - пустий - буде останнім
                }
            }

            void Lobby::RemovePlayer()
            {
                if(m_pHead==0)
                    cout<<"Lobby is empty"<<endl;
                else
                {
                    Player* pTemp=m_pHead;
                    m_pHead= m_pHead->GetNext();
                    delete pTemp;
                }
            }

            void Lobby::Clear()
            {
                    while(m_pHead!=0)
                    RemovePlayer();
            }


int main()
{
    Lobby mylobby;
    int choise;

do{
    cout<<"0 - exit"<<endl;
    cout<<"1 - Add player"<<endl;
    cout<<"2 - Remove player"<<endl;
    cout<<"3 - PrintPlayers"<<endl;
    cout<<"4 - Clear Lobby"<<endl;

    cin>>choise;
    switch (choise) {
    case 0: cout<<"Bye";
        break;
    case 1: mylobby.AddPlayer();
        break;
    case 2: mylobby.RemovePlayer();
        break;
    case 3: mylobby.PrintPlayers(mylobby);
        break;
    case 4: mylobby.Clear();
        break;
    default: cout<<"Enter your choise"<<endl;
        break;
    }

}while(choise!=0);
}
