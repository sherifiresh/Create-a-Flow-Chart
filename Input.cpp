#include "Input.h"
#include "Output.h"




Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}
void Input::GetMouseLocation(Point &P)
{
	pWind->GetMouseCoord(P.x, P.y);  
}
void Input::GetCoords(Input *pIn, Output *pOut) //**********I made this so I can easily know which pixels I'm targeting in my functions**********
{
	int iX, iY;
	Point P;
	while (pIn->pWind->GetMouseClick(iX, iY) == NO_CLICK)
	{
		pIn->GetMouseLocation(P);
		string s;
		pOut->ClearDrawArea();
		pOut->PrintMessage2(P.x, 100, 500);
		pOut->PrintMessage2(P.y, 150, 500);
		Sleep(20);
	}
}
string Input::GetString(Output *pO) const 
{
	string Str;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Str;
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
	
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D (DONE)
	double D = 0;
	char Key;
	string Str;
	pO->PrintMessage("Please enter a value");
	//**********Get the double from the user as a string**********
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return 0;	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return atof(Str.c_str());//**********Change string to double**********
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
	return D;
}


/*ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.TlBrWdth)
		{	//Check whick Menu item was clicked
			if( x >= 0 && x < UI.MnItWdth  )
				return ADD_SMPL_ASSIGN;
			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
				return ADD_CONDITION;
			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
				return EXIT;

			return DSN_TOOL;	//a click on empty part of the tool bar
		
		}
		
		//[2] User clicks on the drawing area
		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}*/


ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.TlBrWdth)
		{	
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN; //**********Assigns a state**********
				break;
			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;  //**********Assigns a variable**********
				break;
			case ITM_COND: return ADD_COND;  //**********Adding a condition**********
				break;
			case ITM_BEGIN_END: return ADD_BEGIN_END; //**********Adding a begin/end chart**********
				break;
			case ITM_INPUT_OUTPUT: return ADD_IN_OUT; //**********Adding an input/output chart**********
				break;
			case ITM_CONDITION: return ADD_CONDITION; //**********Adding a conditional chart**********
				break;
			case ITM_ACTION: return ADD_ACTION; //**********Adding an action chart**********
				break;
			case ITM_CONNECT: return ADD_CONNECTOR; //**********Adding/Editing a connection between charts**********
				break;
			case ITM_EDIT: return EDIT_STAT; //**********Edit Statement**********
				break;
			case ITM_DEL: return DEL; //**********Delete a chart/statement/connection**********
				break;
			case ITM_MOVE: return MOVE; //**********Move a figure**********
				break;
			case ITM_RESIZE: return RESIZE; //**********Resize a chart**********
				break;
			case ITM_SAVE: return SAVE; //**********Save progress**********
				break;
			case ITM_LOAD: return LOAD; //**********Load project**********
				break;
			case ITM_COMMENT: return COMMENT; //**********Comment a statement/chart**********
				break;
			case ITM_COPY: return COPY; //**********Copy anything to clipboard**********
				break;
			case ITM_PASTE: return PASTE; //**********Paste from clipboard**********
				break;
			case ITM_UNDO: return UNDO; //**********Undo last action**********
				break;
			case ITM_EXIT: return EXIT; //**********Exit from project**********
				break;
			default: return DSN_TOOL; //**********Empty click**********
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}
Input::~Input()
{
}
