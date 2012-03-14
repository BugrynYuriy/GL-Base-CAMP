#pragma once

#ifndef _INC_NODE_
#define _INC_NODE_

#include "Main.h"


//structure that describes the node of Word_ list

struct NODE
{
	Word_ value;
	NODE * next;
	NODE * prev;

	NODE ()
	{
		NODE::value;
		NODE::prev = NULL;
		NODE::next = NULL;
	}

	NODE (Word_& value)
	{
		NODE::value = value;
		NODE::prev = NULL;
		NODE::next = NULL;
	}
};

#endif