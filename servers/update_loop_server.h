/**************************************************************************/
/*  camera_server.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef UPDATE_LOOP_SERVER_H
#define UPDATE_LOOP_SERVER_H

#include "core/object/class_db.h"
#include "core/os/thread_safe.h"
#include "core/variant/variant.h"

#include <functional>
#include <vector>

/*

 Create server generic class with virtual update functions.
	When server is created, get ServerUpdate and add type to it.

 Create ServerUpdate  object.
 **/

class UpdateServer : public Object {
	GDCLASS(UpdateServer, Object);

protected:
	UpdateServer();
	~UpdateServer();
public:

	virtual void OnUpdate(float realTime, float gameTime){;}
	virtual void PrePhysicsUpdate(float realTime, float gameTime){;}
	virtual void PhysicsUpdate(float realTime, float gameTime){;}
	virtual void PostPhysicsUpdate(float realTime, float gameTime){;}
	virtual void PreRenderUpdate(float realTime, float gameTime){;}
	virtual void PostUpdate(float realTime, float gameTime){;}
};


class UpdateLoopServer : public Object {
	GDCLASS(UpdateLoopServer, Object);

public:
	//Adds function to
	void AddToUpdate(UpdateServer* server);
	void RemoveFromUpdate(UpdateServer* server);
	void Update(double realTime, double gameTime);
	void OnUpdate(float realTime, float gameTime);
	void PrePhysicsUpdate(float realTime, float gameTime);
	void PhysicsUpdate(float realTime, float gameTime);
	void PostPhysicsUpdate(float realTime, float gameTime);
	void PreRenderUpdate(float realTime, float gameTime);
	void PostUpdate(float realTime, float gameTime);
private:
	std::vector<UpdateServer*> updateList;
protected:

	static UpdateLoopServer *singleton;

	//static void _bind_methods();

public:
	static UpdateLoopServer *get_singleton();

	UpdateLoopServer();
	~UpdateLoopServer();
};

#endif // UPDATE_LOOP_SERVER_H
