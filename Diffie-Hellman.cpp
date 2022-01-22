#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int P = rand() % 10 + 1;
    int G = rand() % 10 + 1;
   /* int P = 8;
    int G = 13;*/

    cout << "P = " << P << endl;
    cout << "G = " << G << endl;

   /* int A_key = 4;
    int B_key = 14;*/
    int A_key = rand() % 10 + 1;
    int B_key = rand() % 10 + 1;
    
    cout << "Сгенерированный ключ Алисы: " << A_key << endl;
    cout << "Сгенерированный ключ Боба: " << B_key << endl;

    unsigned long long int p1 = (unsigned long long int)pow(G, A_key);
    unsigned long long int p2 = (unsigned long long int)pow(G, B_key);

    int new_A_key = p1 % P;
    int new_B_key = p2 % P;

    cout << "Промежуточный ключ Алисы: " << new_A_key << endl;
    cout << "Промежуточный ключ Боба: " << new_B_key << endl;

    p1 = (unsigned long long int)pow(new_B_key, A_key);
    p2 = (unsigned long long int)pow(new_A_key, B_key);

    int final_A_key = p1 % P;
    int final_B_key = p2 % P;

    cout << "Ключ Алисы: " << final_A_key << endl;
    cout << "Ключ Боба:" << final_B_key << endl;
            
   
}


