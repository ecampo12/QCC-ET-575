#include <iostream>
using namespace std;

void DrawMap(int size, int row, int column);

int main()
{
  int size, row, column, selection, intdirection, sign, num;
  char direction;

  while (size < 5 || size > 9)
  {
    cout << "Input the size of the map (between 5 and 9): ";
    cin >> size;

    if (size < 5 || size > 9)
    {
      cout << "Invaild input.\n";
      cout << endl;
    }
  }

  cout << "Map size set to " << size << endl;
  cout << endl;

  while(row > size || row < 0 || column > size || column <0)
  {
    cout << "Input the coordinate of the treasure: ";
    cin >> row >> column;

    if (row > size || row < 0 || column > size || column <0)
    {
      cout << "Coordinates must be between 0 and " << size -1 << ".\n";
      cout << endl;
    }
  }

  DrawMap(size, row, column);

  while (selection != 3)
  {
    int testRow, testColumn;

    cout << endl;
    cout << "1) Update treasure coordinates (row/column)\n";
    cout << "2) Shift X (N S E W)\n";
    cout << "3) Exit Program\n";

    cout << endl;
    cout << "Selection: ";
    cin >> selection;

    switch (selection) {
      case 0: // for testing purposes
        DrawMap(size, row, column);
        break;
      case 1:
        do{
          cout << "Update location of X (row column): ";
          cin >> row >> column;

          if (row >= size || column >= size || row < 0 || column <0)
          {
            cout << "Coordinates must be between 0 and " << size-1 << ".\n";
            cout << endl;
          }
        }while(row >= size || column >= size || row < 0 || column <0);
        DrawMap(size, row, column);
        break;
      case 2:
        do
        {
          testRow = 0;
          testColumn = 0;
          cout << "Shift X (N,S,E,W) and unit number: ";
          cin >> direction >> num;

          intdirection = direction;

          if (intdirection <= 141 || intdirection >= 172) // converts lower case to upper case
          {
            intdirection -= 32;
          }
        //  cout << endl;
          direction = intdirection;
        //  cout << direction;

          if (direction == 'N' || direction == 'W')
          {
            sign = -1;
          }
          else if (direction == 'S' || direction == 'E')
          {
            sign = 1;
          }

          if (direction == 'N' || direction == 'S')
          {
            testRow += sign * num;
          }
          else if (direction == 'E' || direction == 'W')
          {
            testColumn += sign*num;
          }

          if ((testRow + row) < 0 || (testRow + row) >= size || (testColumn + column) < 0 || (testColumn + column) >= size)
          {
            cout << "Treasure cannot move beyond the map.\n";
            //cout << testRow + row << " " << testColumn + column << endl;
            cout << endl;
          }
          else
          {
            break;
          }
        } while (true);
        row += testRow;
        column += testColumn;
        DrawMap(size, row, column);
        break;
      case 3:
        cout << "Ending Program";
        break;
      default:
        cout << "Invaild input.";
    }
  }
  return 0;
}

void DrawMap(int size, int row, int column){
  cout << "Treasure coordinates assigned to row " << row << " column " << row << "." << endl;
  cout << endl;

  for (int i = 0; i <= size; i++) //row
  {
    if (i < size)
    {
        cout << i;
    }
    else if (i == size)
    {
      cout << " ";
    }

    for (int x = 0; x < size; x++) //column
    {
      if (i == size)
      {
        cout << " " << x;
      }
      else if (i == row && x == column)
      {
        cout << " X";
      }
      else
      {
        cout << " -";
      }
    }
    cout << endl;
  }
}
