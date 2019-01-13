#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); //skraca czas działania pierun wie co to robi dokładnie
    short n, r; //n - liczba kraników, r - zasięg
    cin >> n >> r;
    bool istap[1000]; //True albo False czy jest kranik na danej pozycji
    bool open[1000] = {0}; //Na początku wszystkie kraniki są zamknięte
    for (int i = 0; i < n; i++){ //Ładujemy do tablicy gdzie są kraniki
        cin >> istap[i];
    }

    /*************************************************************************
    /Na początku sprawdzamy czy wgl sie da.
    /Dla każdej pozycji sprawdzamy, czy istnieje kranik w zasięgu r
    /Jeśli jakaś pozycja nie ma kranika w zasięgu r, zwracamy -1 bo się nie da
    /jej zaopatrzyć w żaden sposób
    /*************************************************************************/
    for (int pos = 0; pos < n; pos++){
        bool inRange = false;
        //Iterujemy od (pozycja-r) do (pozycja+r) w prawo
        for (int i = max(pos-r+1, 0); i <= min(pos+r-1, n-1); i++){
            if (istap[i]) {
                inRange = true;
                break;
            }
        }
        if (inRange) continue;
        cout << -1;
        return 0;

    }


    /*************************************************************************
    /Teraz przesuwamy się po pozycjach od lewej do prawej
    /(1) Jeśli dana pozycja jest już zaopatrzona, idziemy dalej
    /(2) Jeśli nie jest, otwieramy kranik który jest najbardziej wysunięty
    /    prawo i może zaopatrzyć badaną pozycję
    /************************************************************************/
    for (int pos = 0; pos < n; pos++){ //Iteracja po pozycjach od lewej do prawej
        bool supplied = false;

        for (int i = max(pos-r+1, 0); i <= min(pos+r-1, n-1); i++){
            //Jeśli w zasięgu r od pozycji jest otwarty kranik, jest ona zaopatrzona
            if (open[i]){
                supplied = true;
                break;
            }
        }

        if (supplied) continue; //Jeśli pozycja jest zaopatrzona, idziemy dalej

        
        //Jeśli nie, musimy otworzyć nowy kranik.
        //Najoptymalniej będzie otworzyć taki który jest najbardziej w prawo
        //Iterujemy się od (pozycja+zasięg) w lewo
        for (int i = min(pos+r-1, n-1); i >= max(pos-r+1, 0); i--){
            if (istap[i]){ //i otwieramy pierwszy napotkany kranik
                open[i] = true;
                break;
            }
        }
    }

    //W tablicy open[] mamy zaznaczone, które kraniki są otwarte
    //Pozostaje je policzyć
    int amount = 0;
    for (int i = 0; i < n; i++){
        if (open[i]) amount++;
    }
    cout << amount;
}
