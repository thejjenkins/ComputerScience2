#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee
{
    int id;
    string name;
};

struct Customer
{
    int id;
    string name;
    float balance;
};

int main()
{
    int eid, cid, e=0, c=0, index_c, index_e;
    char ch, choice;
    string name;
    float amount;
    struct Employee E[50];
    struct Customer C[50];

    while (cin >> ch)
    {
        if (ch=='e')
        {
            cin >> eid >> name;
            E[e].id=eid;
            E[e].name=name;
            ++e;
        }
        else if (ch=='c')
        {
            cin >> cid >> name >> amount;
            C[c].id=cid;
            C[c].name=name;
            C[c].balance=amount;
            ++c;
        }
        else
        {
            cin >> cid >> eid >> choice >> amount;
            for (int i=0; i<c; ++i)
            {
                if (cid == C[i].id)
                {
                    index_c = i;
                }
            }
            for (int i=0; i<e; ++i)
            {
                if (eid == E[i].id)
                {
                    index_e = i;
                }
            }
            cout << setprecision(2) << fixed;
            if (choice == 'w')
            {
                C[index_c].balance -= amount;
                cout << setw(15) << C[index_c].name << setw(15) << E[index_e].name << " -$" << setw(10) << amount << " $" << setw(10) << C[index_c].balance << endl;
            }
            if (choice == 'd')
            {
                C[index_c].balance += amount;
                cout << setw(15) << C[index_c].name << setw(15) << E[index_e].name << " +$" << setw(10) << amount << " $" << setw(10) << C[index_c].balance << endl;
            }

        }
    }
    return 0;
}
