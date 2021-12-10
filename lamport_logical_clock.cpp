#include <bits/stdc++.h>
using namespace std;

int d = 1;

class process
{
    int n;                  // No. of events
    vector<int> timestamps; // timestamp for each event
public:

    process(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i += d) // Implementation Rule 1
            timestamps.push_back(i + 1);
    }

    int get_events()
    {
        return n;
    }

    int get_timestamp(int event_no)
    {
        return timestamps[event_no];
    }

    void adjust_timestamp(int Ci, int recieve_event) // Implementation Rule 2
    {
        int &Cj = timestamps[recieve_event];
        Cj = max(Cj, Ci + d);
        for (int i = recieve_event + 1; i < timestamps.size(); i++)
        {
            if (timestamps[i - 1] < timestamps[i])
                break;
            timestamps[i] = timestamps[i - 1] + d;
        }
    }
    
    void print_timestamps()
    {
        for (int i = 0; i < n; i++)
            cout << timestamps[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the no. of processes: " << endl;
    cin >> n; // No. of processes
    vector<process> processes;
    for (int i = 0; i < n; i++)
    {
        int events;
        cout << "Enter the no. of events in process " << i + 1 << endl;
        cin >> events;
        process p(events);
        processes.push_back(p);
    }

    int m;
    cout << "Enter the no. of messages sent: " << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int send_process, send_event, recieve_process, recieve_event;
        cout << "Enter the process no. and event no. of sender for message " << i + 1 << endl;
        cin >> send_process >> send_event;
        cout << "Enter the process no. and event no. of reciever for message " << i + 1 << endl;
        cin >> recieve_process >> recieve_event;
        process sender = processes[send_process - 1];
        process &reciever = processes[recieve_process - 1];
        // to adjust causal dependencies
        reciever.adjust_timestamp(sender.get_timestamp(send_event - 1), recieve_event - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "The timestamps of events in Process " << i + 1 << " are :" << endl;
        processes[i].print_timestamps();
    }
    return 0;
}