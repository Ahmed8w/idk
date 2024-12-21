#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation

	if (v >= 0 && v <= 4)
	{
		vCell = v;
		return true;
	}
	return false;
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	return false; // this line sould be changed with your implementation

}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if (0 <= hCell && hCell < 11 && 0 <= vCell && vCell < 5)
	{
		return true;
	}
	else
	{
		return false; // this line sould be changed with your implementation
	}
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file

	if (cellPosition.IsValidCell())
	{
		int v = cellPosition.VCell();
		int h = cellPosition.HCell();
		int cellnum = 45 - (v * 11) + h;
		return cellnum;
	}
	return 0;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	if (cellNum >= 1 && cellNum <= 55)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				int x = 45 - (i * 11) + j;
				if (x == cellNum)
				{
					position.SetVCell(i);
					position.SetHCell(j);
					break;
				}

			}

		}

		return position;
	}
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{

	/// TODO: Implement this function as described in the .h file


	// Note: this function updates the data members (vCell and hCell) of the calling object

	int currcellnum = GetCellNum();
	int newcellnum;
	switch (direction)
	{
	case Direction::UP:
		newcellnum = currcellnum + (addedNum * 11);
		break;

	case Direction::DOWN:
		newcellnum = currcellnum - (addedNum * 11);
		break;

	case Direction::RIGHT:
		newcellnum = currcellnum + (addedNum);
		break;

	case Direction::LEFT:
		newcellnum = currcellnum - (addedNum);
		break;

	}
	if (newcellnum >= 1 && newcellnum <= 55)
	{
		GetCellPositionFromNum(newcellnum);
	}
}