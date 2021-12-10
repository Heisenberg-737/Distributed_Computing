#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inverse(ll e, ll phi)
{
    ll r1 = e, r2 = phi;
    ll s1 = 1, s2 = 0;

    while (r2 > 0)
    {
        ll q = r1 / r2;
        ll r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ll s = s1 - q * s2;
        s1 = s2;
        s2 = s;
    }

    if (s1 < 0)
        s1 += (((-1 * s1) / phi) + 1) * phi;

    return s1;
}

ll Power(ll a, ll b, ll n)
{
    if (a == 0)
        return 0;

    if (b == 0)
        return 1;

    ll val = Power(a, b / 2, n);
    val = (val * val) % n;

    if (b & 1)
        val = (val * a) % n;

    return val;
}

int main(int args, char **argv)
{
    ll a, b, n, e, phi, d, m, c;
    cout << "Enter the value of prime numbers a and b: " << endl;
    cin >> a >> b;
    n = a * b;
    phi = (a - 1) * (b - 1);
    cout << "Enter the value of the public key (e, where 0 < e < " << phi << " and e is coprime to " << phi << "): " << endl;
    cin >> e;
    d = inverse(e, phi);

    while (1)
    {
        int choice;
        cout << "##### Implementing RSA. Enter between 1-3 #####" << endl;
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value of plaintext (less than " << n << ") :" << endl;
            cin >> m;

            c = Power(m, e, n);
            cout << "The ciphertext is: " << c << endl;
            break;

        case 2:
            cout << "Enter the value of ciphertext (less than " << n << ") :" << endl;
            cin >> c;

            m = Power(c, d, n);
            cout << "The plaintext is: " << m << endl;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << "Wrong input !!!" << endl;
            break;
        }
    }
}