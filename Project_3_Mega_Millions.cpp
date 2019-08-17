//Prject_3_Mega_Millions E. Morales
#include <iostream>
#include <time.h>
using namespace std;

int randNumber(int range);
void setWinningNumbers(int a[], const int& SIZE);
bool isUniqueValue(int a[],int val, int i);
void setPlayerNumbers(int a[], const int& SIZE);
void checkNumbers(int win[], int play[], const int& SIZE);
void displayResults(int win[], int play[], const int& SIZE);

int main( )
{
  srand(time(NULL));

  const int SIZE = 6;
  int winningNumbers[SIZE];
  int playerNumbers[SIZE];

  setWinningNumbers(winningNumbers, SIZE);

  //prints out the winnig numbers for testing
  for(int i = 0; i < SIZE; i++)
  {
    cout << winningNumbers[i] << " ";
  }
  cout << endl;

  setPlayerNumbers(playerNumbers,SIZE);
  displayResults(winningNumbers, playerNumbers, SIZE);

  return 0;
}

int randNumber(int range)
{
  int num;
  num = rand() % range + 1;
  //(range) + 1;
  return num;
}

void setWinningNumbers(int a[], const int& SIZE)
{
  int val;
  for(int i = 0; i < (SIZE - 1); i++)
  {
    a[i] = randNumber(75);
    val = a[i];

    if( i > 0 )
    {

      if(isUniqueValue(a, val, i))
      {
	a[i] = randNumber(75);
	i--;
      }
    }
  }
  a[SIZE - 1] = randNumber(15);
}

bool isUniqueValue(int a[],int val, int i)
{
  for(int x = 0; x < i; x++)
  {
    if (a[x] == val)
    {
      return true;
    }
  }
  return false;
}

void setPlayerNumbers(int a[], const int& SIZE)
{ //Use a vaildtion loop to check nums are within range

  int i = 0;
  do
  {
    int val;

    cout << "Enter the " << i + 1 << " number (1 to 75): ";
    cin >> a[i];
    val = a[i];
    if(a[i] < 0 || a[i] > 76)
    {
      cout << "Invalid value.\n";
      cout << endl;
      continue;
      //i = i - 1;
    }
    if(isUniqueValue(a, val, i))
    {
      cout << "Invalid, number must be unique.\n";
      cout << endl;
      continue;
    }
    i = i + 1;
    if (i == (SIZE - 1))
      break;
  } while(a[i] > 0 || a[i] < 76);

  do
  {
    cout << "Enter a number (1 to 15): ";
    cin  >> a[SIZE - 1];

    if(a[SIZE - 1] < 0 || a[SIZE - 1] > 16)
    {
      cout << "Invalid value.\n";
      cout << endl;
      continue;
    }
  } while (a[SIZE - 1] < 0 || a[SIZE - 1] > 16);
}


void displayResults(int win[], int play[], const int& SIZE)
{
  cout << endl;
  cout << "Prize Results\n-------------------------------------\n";
  cout << "Winning Numbers:\n";
  for(int i = 0; i < (SIZE-1); i++)
  {
    cout << win[i] << " ";
  }
  cout << "Mega Ball: " << win[SIZE-1] << endl;
  cout << endl;

  cout << "Your Numbers:\n";
  for(int i = 0; i < (SIZE-1); i++)
  {
    cout << play[i] << " ";
  }
  cout << "Mega Ball: " << play[SIZE-1] << endl;
  cout << endl;

  checkNumbers(win, play, SIZE);

}

void checkNumbers(int win[], int play[], const int& SIZE)
{
  int match = 0, megaball = 0;
  string MoneyWon;
  for(int i = 0; i < (SIZE-1); i++)
  {
    for(int x = 0; x < (SIZE-1); x++)
    {
      if(play[i] == win[x])
      {
	match++;
      }
    }
  }
  if(play[SIZE-1] == win[SIZE-1])
  {
    megaball++;
  }

  if((match == 0 && megaball == 0) || (match == 1&& megaball == 0) ||(match == 2 && megaball ==0))
  {
    MoneyWon = "winning numbers: you win nothing.";
  }else if(match == 0 && megaball == 1)
  {
    MoneyWon = "winning numbers , plus Mega Ball: you win $1";
  }else if(match == 1 && megaball == 1)
  {
    MoneyWon = "winning number, plus Mega Ball: You win $2";
  }else if(match == 2 && megaball == 1)
  {
    MoneyWon = "winning numbers , plus Mega Ball: You win $5";
  } else if(match == 3 && megaball == 0)
  {
    MoneyWon = "winnings number: You win $5";
  } else if(match == 3 && megaball == 1)
  {
    MoneyWon = "winnings number, plus Mega Ball: You win $50";
  } else if(match == 4 && megaball == 0)
  {
    MoneyWon = "winnings number: You win $500";
  }else if(match == 4 && megaball == 1)
  {
    MoneyWon = "winnings number, plus Mega Ball: You win $5,000";
  }else if(match == 5 && megaball == 0)
  {
    MoneyWon = "winnings number: You win $1,000,000";
  }else if (match == 5 && megaball == 1)
  {
    MoneyWon = "winnings number, plus Mega Ball: JACKPOT";
  }
  // cout << play[SIZE-1] << " " << win[SIZE-1] << endl;
  // cout << match << " " << megaball << endl;
  cout << match << " " << MoneyWon;
}
