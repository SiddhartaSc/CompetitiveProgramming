#include <iostream>
#include <string>

using namespace std;

//arreglo espacial
char keys[4][10][2]=
{
	{{'q', 'Q'}, {'w', 'W'}, {'e', 'E'}, {'r', 'R'}, {'t', 'T'}, {'y', 'Y'}, {'u', 'U'}, {'i', 'I'}, {'o', 'O'}, {'p', 'P'}},
	{{'a', 'A'}, {'s', 'S'}, {'d', 'D'}, {'f', 'F'}, {'g', 'G'}, {'h', 'H'}, {'j', 'J'}, {'k', 'K'}, {'l', 'L'}, {';', ':'}},
	{{'z', 'Z'}, {'x', 'X'}, {'c', 'C'}, {'v', 'V'}, {'b', 'B'}, {'n', 'N'}, {'m', 'M'}, {',', '<'}, {'.', '>'}, {'/', '?'}},
	{{'^', '^'}, {'^', '^'}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {' ', ' '}, {'^', '^'}, {'^', '^'}},
};

//fila x columna
int pos1[2]={3,0};
int pos2[2]={3,9};

//pos movimientos
int dirs[8][2]={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

string poem,tpoem;
string low = "qwertyuiopasdfghjkl;zxcvbnm,./ ";
string up = "QWERTYUIOPASDFGHJKL:ZXCVBNM<>? ";

int main()
{
    //for(long long i=0;i<4;i++){
      //  for(long long j=0;j<10;j++){
        //    cout << keys[i][j][1];
        //}
        //cout << endl;
    //}

    //cout << keys[3][8][0];

    getline(cin,poem);

    //int plen=poem.size();
    //if(poem.find('s')<=plen-1)
      //  cout << "found";
    //else
      //  cout << "not found";

    //if(low.find(poem.at(0))<=low.size()-1)
      //  cout << "ta";
    //else
      //  cout << "pos no ta";

    //cout << poem;

    for(int i=0;i<poem.size();i++){
        if(low.find(poem.at(i))<=low.size()-1)
            tpoem=tpoem + poem.at(i);
        else if(up.find(poem.at(i))<=up.size()-1)
            tpoem=tpoem + '^' + low.at(up.find(poem.at(i)));
        else
            cout << "no mms";
    }

    cout << tpoem;


    return 0;
}
