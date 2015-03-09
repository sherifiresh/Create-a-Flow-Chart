#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	//************Added everything in the tool bar************
	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_COND, //Add a conditional statement (for if and while-loop statements)
	ADD_BEGIN_END,
	ADD_IN_OUT,
	ADD_CONDITION,
	ADD_ACTION,
	ADD_CONNECTOR, //Add a connector between two statements

	EDIT_STAT,	//Edit a statement
	
	SELECT,		//Select a statement, a connector

	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)

	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	COMMENT,
	COPY,
	PASTE,
	UNDO,
	EXIT,		//Exit the application
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE	//Switch to simulatiom mode
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	//************Added everything in my tool bar************
	ITM_SMPL_ASSIGN,
	ITM_VAR_ASSIGN,
	ITM_COND,
	ITM_BEGIN_END,
	ITM_INPUT_OUTPUT,
	ITM_CONDITION,
	ITM_ACTION,
	ITM_CONNECT,
	ITM_EDIT,
	ITM_DEL,
	ITM_MOVE,
	ITM_RESIZE,
	ITM_SAVE,//simple assignment statement
	ITM_LOAD,
	ITM_COMMENT,
	ITM_COPY,
	ITM_PASTE,
	ITM_UNDO,
	ITM_EXIT, //conditional statement
	

			//Exit
	
	//TODO: Add more items names here (DONE)
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_RUN,	//Run
	ITM_STP,	//Step by step
	
	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};




#ifndef NULL
#define NULL 0
#endif

#endif
