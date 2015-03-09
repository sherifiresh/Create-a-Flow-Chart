#include "Output.h"
#include <iostream>
#include <sstream>
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1333; //***********Perfect for tool bar***********
	UI.height = 700;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 50;
	UI.TlBrWdth = 50; //***********My toolbar length***********
	UI.MnItWdth = 50; //***********My items width***********

	UI.DrawClr = BLUE;
	UI.HiClr = RED;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Create your own Flowchart!");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
}

void Output::PrintMessage2(string msg, int x, int y) //***********Output text with different coords***********
{
	pWind->SetPen(BLACK); 
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(x, y, msg);
}
void Output::PrintMessage2(int msg, int x, int y)
{
	pWind->SetPen(BLACK); 
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawInteger(x, y, msg);
}
Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i=0;	

	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	pWind->DrawImage("images\\DesignMenu.jpg", 0, 0);
	

	//Draw a line under the toolbar

}


void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}
void Output::PrintMessage(double msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawInteger(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
