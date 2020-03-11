#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//wyszukiwanie binarne po wyniku
	//dla wygody mnozymy *1000 i wyszukujemy 
	//z dokladnoscia dla liczb calkowitych
	//bellman-ford
	//dla wartosci x, od kazdej wielkosci krawedzi odejmujemy x
	//jesli jest teraz w grafie ujemny cykl (bellman-ford)
	//to znaczy ze jest jakas mniejsza srednia
	//i jeszcze superwierzcholek prowadzacy do wszystkich innych
	//ma on krawedzie o dowolnych wagach bo 
	//i tak nie wejdzie w sklad zadnego cyklu
	return 0;
}
