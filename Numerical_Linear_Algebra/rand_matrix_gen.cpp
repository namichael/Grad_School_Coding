#include <iostream>
#include "random.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    u_short n = stoi(argv[1]);  // Max rng value
    u_short m = stoi(argv[2]);  // Dimension of Matrix

    cout << endl;
    for (u_short j = 0; j < m; j++)
        cout << "d: " << j+1 << '\t';
        // Header in command line
    cout << endl;

    for (u_short j = 0; j < m; j++)
        cout << "----\t";
    cout << endl;

    for (u_short i = 0; i < m; i++)
    {
        u_short p = u_short(rng(n));
        cout << p << '\t';
        for (u_short j = 1; j < m-i; j++)
        {
            u_short q = u_short(rng(n));
            int err = 0;
            while( q >= p )
            {
                if (err > 100)
                    throw 1;

                ++err;
                q = u_short(rng(n));
            }
            cout << q << '\t';
        }
        cout << endl;   // Print values of diagonal by column
    }
    cout << endl;
}