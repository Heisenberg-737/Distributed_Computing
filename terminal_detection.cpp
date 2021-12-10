#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of processes: " << endl;
    cin >> n;

    int controlling_process;
    cout << "Enter the controlling process: " << endl;
    cin >> controlling_process;

    unordered_map<int, float> weight;
    for (int i = 1; i <= n; i++)
    {
        if (i == controlling_process)
            weight[i] = 1;
        else
            weight[i] = 0;
    }
    
    while (1)
    {
        int sender, reciever;
        float w;
        cout << "For a message, Enter the sender process, reciever process and weight associated : " << endl;
        cin >> sender >> reciever >> w;
        if (weight[sender] == 0)
            cout << "Process " << sender << " is inactive ! Cannot send message !!!" << endl;
        else
        {
            weight[sender] = (weight[sender] <= w ? 0 : weight[sender] - w);
            weight[reciever] += w;
            if (weight[controlling_process] == 1)
            {
                cout << "Termination Detected !" << endl;
                break;
            }
            else
                cout << "Process not terminated yet ..." << endl;
        }
    }
    return 0;
}