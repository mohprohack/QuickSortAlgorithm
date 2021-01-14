#include <iostream>
#include <vector>

using namespace std;

void Replace(int* First, int* Second);
int Partition(int* List, int low, int high);
void QuickSort(int* List, int low, int high);
void OutputList(int* List, unsigned int ListSize);

int globalSize;

int main()
{
    cout << "Enter Your Numbers List (Enter 0 to Stop)" << endl;
    vector<int> Numbers;
    int tempInt;
    string temp;
    do
    {
        cout << ">>>  ";
        cin >> tempInt;
        if(tempInt) Numbers.push_back(tempInt);
    } while(tempInt);
    getline(cin, temp);
    globalSize = Numbers.size();
    system("cls");
    cout << "\n\nThis is Your List: "; OutputList(&Numbers[0], Numbers.size());
    cout << "\nSorting Steps:" << endl;
    QuickSort(&Numbers[0], 0, Numbers.size() - 1);
    cout << "\nAnd This is Your Sorted List: ";OutputList(&Numbers[0], Numbers.size());cout << "\n\n";
    cout << "Press 'Enter' to Exit...";
    cin.get();
    return 0;
}

void Replace(int* First, int* Second)
{
    int Temp = *First;
    *First = *Second;
    *Second = Temp;
}

void OutputList(int* List, unsigned int ListSize)
{
    for(unsigned int i = 0; i < ListSize; i++) cout << List[i] << " ";
    cout << endl;
}

int Partition(int* List, int low, int high)
{
    int pivot = List[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(List[j] < pivot)
        {
            i++;
            Replace(&List[i], &List[j]);
        }
    }
    Replace(&List[i+1], &List[high]);
    return i+1;
}

void QuickSort(int* List, int low, int high)
{
    if(low < high)
    {
        OutputList(List, globalSize);
        int pi = Partition(List, low, high);
        QuickSort(List, low, pi - 1);
        QuickSort(List, pi + 1, high);
    }
}















