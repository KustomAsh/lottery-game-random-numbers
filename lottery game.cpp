#include<iostream>
#include<ctime>
using namespace std;
void selection_Sort(int arr[], int size);
int main()
{
	int real[5], guess[5];
	srand(time(NULL));
	while (real[0]!=-999)
	{
		cout << "\t\t\tWelcome to the game\nGuess 5 numbers to win the lottery\n";
		for (int i = 0; i < 5;i++) { real[i] = rand() % 40 + 1; }
		selection_Sort(real, 5);
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter number (1 to 40) : ";
			do 
			{
				cin >> guess[i];
			} while (guess[i] < 0 || guess[i]>40);
		}

		int flag = true, matches = 0;
		for (int i = 0,high=4,low=0,mid; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				if (guess[j] == real[i]) { matches++; }
			if (matches != i+1) { flag = false; }
		}
		if (flag == false)
			cout << "\nYou Lose!\n";
		else cout << "\nYou Win!\n";
		cout << "Quit or play again ? (enter -999 to exit) : "; cin >> real[0]; cout << endl;
	}
	system("pause>0");
}
void selection_Sort(int arr[], int size)
{
	int s_index, temp;
	for (int i = 0; i < size - 1; i++)
	{
		s_index = i;
		for (int j = s_index + 1; j < size; j++)
		{
			if (arr[s_index]<arr[j])
				s_index = j;
		}
		temp = arr[s_index];
		arr[s_index] = arr[i];
		arr[i] = temp;
	}
}
