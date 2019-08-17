//Project_2_Sailing_The_Seas - E. Morales
#include <iostream>
using namespace std;

void initMap();
void displayMap();
void validate(char x);
void menu();

void moveShip(int selection);
string map[10][10];
char selection;
int positionX = 5, positionY = 5;
bool crash = false, Offmap = false;

int main()
{
  cout << "Sailing the Seas\n---------------\n";

  do
  {
    if (crash == true || Offmap == true)
    {
      break;
    }
    menu();
    moveShip(selection);
  } while((crash == false) && Offmap == false);
  //cout << "ARGGGH!!!...you have been lost at sea!!!";
  return 0;
}

void initMap()
{
  string map[10][10];
  for(int y = 0; y < 10; y++)
  {
    for(int x = 0; x < 10; x++)
    {
      if (x <= y)
      {
	map[x][y] = "~";
      }
      else
      {
	map[x][y] = ".";
      }
    }
  }
  map[5][5] = 'S';

  for(int i = 0; i < 10; i++)
  {
    for(int x = 0; x < 10; x++)
    {
      cout << map[x][i] << " ";
    }
    cout << endl;
  }
}

void displayMap()
{

  for(int i = 0; i < 10; i++)
  {
    for(int x = 0; x < 10; x++)
    {
      if (x <= i)
      {
	map[x][i] = "~";
      }
      else
      {
	map[x][i] = ".";
      }
    }
  }

  map[positionX][positionY] = 'S';

  for(int i = 0; i <= 10; i++) //rows
  {
    if (i < 10)
    {
      cout << i << " ";
    }
    else
    {
      cout << " ";
    }
    for(int x = 0; x < 10; x++) //columns
    {
      if (i == 10)
      {
	cout << " " << x;
      }
      else
      {
	cout << map[x][i] << " ";
      }
    }
    cout << endl;
  }
}

void validate(char x) //returns letter as an uppercase
{
  int i;
  i = x;
  //cout << i;

  if (i >= 65 && i <= 90)
  {
    i += 32;
  }
  x = i;
  //cout << x;
}

void menu()
{


  displayMap();
  cout << endl;
  cout << "(n)orth\n(s)outh\n(e)ast\n(w)est\n";
  cout << endl;
  cout << "Which way, Captain? ";
  cin >> selection;
  validate(selection);

}
void moveShip( int selection)
{
  switch (selection)
  {
  case 110:   //North
    //cout << "works";
    positionY -= 1;
    if(map[positionX][positionY] == ".")
    {
      cout << "CRASH!!! You boat begins to sink!\n";
      crash = true;
      break;
    }

    if(positionY < 0 || positionY > 9)
    {
      cout << "ARGGGH!!!...you have been lost at sea!!!";
      Offmap = true;
      break;
    }
    else
    {
      main();
    }
    break;
  case 115:   //South
    //cout << "works";
    positionY += 1;

    if(positionY < 0 || positionY > 9)
    {
      cout << "ARGGGH!!!...you have been lost at sea!!!";
      Offmap = true;
      break;
    }
    else
    {
      main();
    }
    break;
  case 101:   //East
    //cout << "works";
    positionX += 1;
    if(map[positionX][positionY] == ".")
    {
      cout << "CRASH!!! You boat begins to sink!\n";
      crash = true;
      break;
    }

    if(positionX < 0 || positionX > 9)
    {
      cout << "ARGGGH!!!...you have been lost at sea!!!";
      Offmap = true;
      break;
    }
    else
    {
      main();
    }
    break;
  case 119:   //West
    //cout << "works";
    positionX -= 1;

    if(positionX < 0 || positionX > 9)
    {
      cout << "ARGGGH!!!...you have been lost at sea!!!";
      Offmap = true;
      break;
    }
    else
    {
      main();
    }
    break;
  default:
    cout << "Invaild input\n";
    main();
    break;
  }
}
