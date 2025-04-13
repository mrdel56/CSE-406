#include <iostream>
using namespace std;
int main()
{
int processes[3][3];
int processNumber[3] = {1, 2, 3};
int turnaround[3], waiting[3];

for (int i = 0; i < 3; i++)
{
cout << "Enter arrival time for Process P" << i + 1 << ":";
cin >> processes[i][0];
cout << "Enter burst time for Process P" << i + 1 << ": ";
cin >> processes[i][1];
}

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3 - i - 1; j++)
{
if (processes[j][0] > processes[j + 1][0])
{
int tempArrival = processes[j][0];
int tempBurst = processes[j][1];
int tempProcessNumber = processNumber[j];

processes[j][0] = processes[j + 1][0];
processes[j][1] = processes[j + 1][1];
processNumber[j] = processNumber[j + 1];
processes[j + 1][0] = tempArrival;
processes[j + 1][1] = tempBurst;
processNumber[j + 1] = tempProcessNumber;
}
}
}
int time = 0;
for (int i = 0; i < 3; i++)
{
if (processes[i][0] > time)
{
time = processes[i][0];
}
time += processes[i][1];
processes[i][2] = time;

turnaround[i] = processes[i][2] - processes[i][0];

waiting[i] = turnaround[i] - processes[i][1];
}

cout << "\nProcess\tArrival Time\tBurst Time\tCompletionTime\tTurnaround Time\tWaiting Time\n";
for (int i = 0; i < 3; i++)
{
cout << "P" << processNumber[i] << "\t"
<< processes[i][0] << "\t\t"
<< processes[i][1] << "\t\t"
<< processes[i][2] << "\t\t"
<< turnaround[i] << "\t\t"
<< waiting[i] << endl;
}
return 0;

}