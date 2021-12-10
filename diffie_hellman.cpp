#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll n)
{
    if (a == 0)
        return 0;

    if (b == 0)
        return 1;

    ll val = power(a, b / 2, n);
    val = (val * val) % n;

    if (b & 1)
        val = (val * a) % n;

    return val;
}

int main(int args, char **argv)
{
    ll p, q, x_a, x_b, y_a, y_b;
    cout << "Enter the value of prime number p: " << endl;
    cin >> p;
    cout << "Enter the value of q where q < p and q is a primitive root of p: " << endl;
    cin >> q;
    cout << "Enter the value of the private key of person A : " << endl;
    cin >> x_a;
    y_a = power(q, x_a, p);

    cout << "Enter the value of the private key of person B : " << endl;
    cin >> x_b;
    y_b = power(q, x_b, p);

    cout << "The public key of A is: " << y_a << endl;
    cout << "The public key of B is: " << y_b << endl;

    ll k1 = power(y_b, x_a, p), k2 = power(y_a, x_b, p);

    cout << "The key calculated by A is: " << k1 << endl;
    cout << "The key calculated by B is: " << k2 << endl;

    if (k1 == k2)
        cout << "The key has been exchanged successfully !!!" << endl;

    else
        cout << "Key exchange failed !!!" << endl;

    return 0;
}