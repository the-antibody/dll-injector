#pragma once

#ifndef INJECTOR_H
#define INJECTOR_H
#endif

#include <iostream>
#include <Windows.h>

#include "exceptions.h"

// injector class
class injector
{
	LPCSTR dll_path;
	int process_id;

	public:
		// constructor
		injector(LPCSTR dll_path, int process_id);

		// getters
		LPCSTR get_dll_path() { return this->dll_path; }
		int get_process_id() { return this->process_id; }

		// functions
		void inject();
};

// functions
void inject();
