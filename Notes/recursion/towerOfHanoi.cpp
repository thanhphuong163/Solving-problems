#include <iostream>
#include <string>

using namespace std;

// Goal: move n disks from 1 to 3
// move n-1 disks from 1 to 2
// move nth disk from 1 to 3
// move n-1 disk from 2 to 3

void solveTowerOfHanoi(int n, int src, int des)
{
    if (n == 0)
    {
        cout << "No move." << endl;
    }
    else if (n == 1)
    {
        cout << "Move from " << src << " to " << des << "." << endl;
    }
    else
    {
        int mid = 6 - src - des;
        solveTowerOfHanoi(n - 1, src, mid);
        cout << "Move from " << src << " to " << des << "." << endl;
        solveTowerOfHanoi(n - 1, mid, des);
    }
}

int main(int argc, char const *argv[])
{
    int n, src, des;
    cout << "Enter number of disks: ";
    cin >> n;
    cout << "Enter source: ";
    cin >> src;
    cout << "Enter destination: ";
    cin >> des;
    solveTowerOfHanoi(n, src, des);
    return 0;
}
