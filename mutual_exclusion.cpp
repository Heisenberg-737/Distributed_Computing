#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int process_id;
    int count = 0;
    bool flag = true;
    cout << "Lamport's Distributed Mutual Exclusion Algorithm: " << endl;
    cout << "Enter no of processes:" << endl;
    cin >> n;
    vector<int> waiting_queue;

    do
    {
        int choice;
        cout << "Enter the process which wants to execute Critical Section:" << endl;
        cin >> process_id;
        waiting_queue.push_back(process_id);
        cout << "Any other process wants to execute Critical Section?:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        if (choice == 2)
            flag = false;
    } while (flag);

    for (int j = 0; j < waiting_queue.size(); j++)
    {
        printf("\nCritical Section executing for the Process %d .....",
               waiting_queue[j]);
        printf("\nCritical Section is finished for the Process %d",
               waiting_queue[j]);
        printf("\nRelease Message has been sent by the Process %d\n",
               waiting_queue[j]);
    }
    return 0;
    
}